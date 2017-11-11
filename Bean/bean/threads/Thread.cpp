#include "Thread.h"
#include <algorithm>
#include <chrono>
#include <iostream>
#include <memory>
#include <string>
#include "../Debug.h"
#include "../launch/Bean.h"
#include "../ast/BeanRuntimeException.h"
#include "../env/ClassFormatException.h"
#include "../env/CodeBlock.h"
#include "../ast/CodeSyntaxException.h"
#include "../env/Delegate.h"
#include "../ast/InterpretExitException.h"
#include "../env/Exception.h"
#include "../env/Package.h"
#include "../util/Console.h"
#include "../util/IO.h"
#include "../util/TimeSpan.h"
#include "../env/gc/Block.h"
#include "../env/gc/Heap.h"
#include "../ast/visitor/ASTInterpretVisitor.h"
#include "../ast/visitor/ASTPreInterpretVisitor.h"
#include "../env/user/UserDelegate.h"
#include "../env/user/UserSystem.h"
#include "../env/user/UserThread.h"

std::recursive_mutex Thread::thread_sync;
std::vector<ThreadSPtr> Thread::threads = std::vector<ThreadSPtr>();
ThreadSPtr Thread::systemThread = std::make_shared<Thread>("system-thread", -1, true);

//public method---
Thread::Thread(std::string name, int runtimeID)
 : Thread(name, runtimeID, false) {
	this->owner = nullptr;
}

Thread::~Thread() {
	this->queue->clear();
	while (!classLoaderStack.empty()) classLoaderStack.pop();
	if (!isSystemThread() && impl.joinable()) {
		impl.detach();
	}
}

void Thread::registerThread() {
	checkPush();
}

void Thread::sleep(long l) {
	std::this_thread::sleep_for(std::chrono::milliseconds(l));
}

int Thread::getThreadCount() {
	return threads.size();
}

ThreadSPtr Thread::getSystemThread() {
	return Thread::systemThread;
}

ThreadSPtr Thread::getThreadAt(int index) {
	return Thread::threads.at(index);
}

ThreadSPtr Thread::getCurrent() {
	std::lock_guard<std::recursive_mutex> lock(Thread::thread_sync);
	for (ThreadSPtr t : threads) {
		if (t->getThreadID() != std::this_thread::get_id()) {
			continue;
		}
		if (t->getState() != ThreadState::RUNNING &&
			!t->isSystemThread()) {
			continue;
		}
		return t;
	}
	return nullptr;
}

ThreadSPtr Thread::getCurrentOrSystem() {
	ThreadSPtr th = getCurrent();
	if (th == nullptr) {
		th = getSystemThread();
	}
	return th;
}

void Thread::destroy(int runtimeID) {
	for (int i = threads.size() - 1; i >= 0; i--) {
		ThreadSPtr th = threads.at(i);
		if (th->getRuntimeID() == runtimeID) {
			threads.erase(threads.begin() + i);
			//break;
		}
	}
}

void Thread::destroy() {
	threads.clear();
	systemThread.reset();
}

void Thread::start(std::string fileName) {
	this->state = ThreadState::RUNNING;
	if (!isSystemThreadFlag) {
		throw std::logic_error("�v���O�����̎��s�̓V�X�e���X���b�h�ł̂݉\�ł�");
	} else {
		checkPush();
		runFile(fileName);
	}
}

void Thread::start(UserDelegate * d) {
	this->state = ThreadState::RUNNING;
	if (isSystemThreadFlag) {
		throw std::logic_error("�V�X�e���X���b�h������s���邱�Ƃ͏o���܂���");
	}
	checkPush();
	std::vector<Object_*> args = std::vector<Object_*>();
	ThreadSPtr parent = Thread::getCurrent();
	BlockSPtr parentBuff = parent->getBuffer();
	//�X���b�h�̊J�n
	this->impl = std::thread([this, d, args, parentBuff]() {
		//FIXME:�蔲��
		std::this_thread::sleep_for(std::chrono::microseconds(10));
		ClassLoaderSPtr cll = d->getCapture();
		//�����_����`���ꂽ�Ƃ���̃N���X���[�_�[�Ŏ��s
		pushCurrentClassLoader(cll);
		d->getDelegate()->call(shared_from_this(), cll, args);
		popCurrentClassLoader();
		this->state = ThreadState::TERMINATE;
	});
	this->threadID = impl.get_id();
}

void Thread::join() {
	if (getState() == ThreadState::RUNNABLE ||
		getState() == ThreadState::TERMINATE) {
		return;
	}
	if (impl.joinable()) {
		impl.join();
	}
}

void Thread::exit() {
	if (this->state != ThreadState::RUNNING) {
		return;
	}
	UserThread* ut = getOwner();
	setException(Exception::new_e_simple("api.exc.ThreadExitException", "thread was don't terminated on user program"));
	if (impl.joinable()) {
		impl.join();
	}
}

void Thread::pushCurrentClassLoader(ClassLoaderSPtr classLoader) {
	classLoaderStack.push(classLoader);
}

void Thread::popCurrentClassLoader() {
	classLoaderStack.pop();
}

ClassLoaderSPtr Thread::getCurrentClassLoader() {
	if (classLoaderStack.empty()) {
		return NULL;
	}
	return classLoaderStack.top();
}

void Thread::setExceptionListener(ExceptionListener listener) {
	this->listener = listener;
}

ExceptionListener Thread::getExceptionListener() {
	return this->listener;
}

void Thread::setOwner(UserThread * owner) {
	this->owner = owner;
}

UserThread * const Thread::getOwner() {
	if (owner == nullptr) {
		this->owner = new UserThread(shared_from_this());
	}
	return this->owner;
}

void Thread::setException(Object_ * ex) {
	assert(ex != nullptr);
	this->exception = ex;
	this->throwState++;
	getExceptionListener()(this, ex);
}

Object_ * Thread::getException() const {
	return this->exception;
}

bool Thread::wasThrownException() {
//	return (catchCount == 0) && this->throwState > 0;
	return catchCount < throwState;
}

void Thread::catchExceptionStart() {
	this->catchCount++;
}

void Thread::catchExceptionEnd() {
	this->catchCount--;
}

void Thread::clearException() {
	this->throwState = 0;
	this->catchCount = 0;
	this->exception = nullptr;
}

std::string Thread::getName() const {
	return this->name;
}

int Thread::getRuntimeID() const {
	return this->runtimeID;
}

ThreadState Thread::getState() const {
	return this->state;
}

ThreadID Thread::getThreadID() const {
	return this->threadID;
}

MessageQueueSPtr Thread::getQueue() {
	return queue;
}

BlockSPtr Thread::getBuffer() {
	return block;
}

std::vector<ThreadSPtr> Thread::getThreads() {
	return Thread::threads;
}

bool Thread::isSystemThread() const {
	return this->isSystemThreadFlag;
}
//---public method

//private method---
Thread::Thread(std::string name, int runtimeID, bool isSystemThreadFlag) {
	this->throwState = 0;
	this->catchCount = 0;
	this->pushForProtect = false;
	this->name = name;
	this->queue = std::make_shared<MessageQueue>();
	this->block = std::make_shared<Block>();
	this->classLoaderStack = std::stack<ClassLoaderSPtr>();
	this->listener = [](Thread* t, Object_* e) {};
	this->runtimeID = runtimeID;
	this->threadID = std::this_thread::get_id();
	this->state = ThreadState::RUNNABLE;
	this->isSystemThreadFlag = isSystemThreadFlag;
	this->exception = nullptr;
	naming();
}

void Thread::naming() {
	//��ӂ̃X���b�h�����w�肵�܂��B
	int index = 0;
	std::string baseName = name;
	while (containsName(name)) {
		name = baseName + "-" + std::to_string(index++);
	}
}

bool Thread::containsName(std::string name) {
	for (int i = 0; i < threads.size(); i++) {
		ThreadSPtr th = threads.at(i);
		if (th->getName() == name) {
			return true;
		}
	}
	return false;
}

void Thread::runFile(std::string mainFile) {
	//�S�ẴX���b�h�̗�O�t���O���N���A
	for (auto thr : Thread::threads) {
		thr->clearException();
	}
	//�\�[�X�R�[�h�̉��
	BString source = IO::readText(mainFile);
	ASTNodeSPtr root = Bean::compileplaf(mainFile, source, true);
	if (!root) {
		//��͂Ɏ��s����
		return;
	}
	//�J�n�����̎擾
	UserSystem* uSys = UserSystem::getInstance();
	TimeSpan span = TimeSpan();
	span.start();
	//�N���X���[�h
	ClassLoaderSPtr rootClsLoader = std::make_shared<ClassLoader>(root);
	rootClsLoader->registerClassLoader();
	CodeBlock* cdb = rootClsLoader->getCodeBlock();
	ClassLoader::pushCurrentClassLoader(rootClsLoader);
	//Debug::addFlag(Debug::DBG_BASE_CLASS_LOADING);
	try {
		rootClsLoader->loadDefaults();
	} catch (CodeSyntaxException e) {
		Console::println(e.what());
	} catch (ClassFormatException cfe) {
		Console::println(cfe.what());
	}
	//Debug::removeFlag(Debug::DBG_BASE_CLASS_LOADING);
	//�G���g���|�C���g�̎��s
	ClassLoader::pushCurrentClassLoader(rootClsLoader);
	MessageQueue::getInstance()->push(MessageInfo::createTop());
	cdb->enter(false);
	try {
		//�f�t�H���g�ŃC���N���[�h����閼�O���/�N���X�̓ǂݍ���
		rootClsLoader->loadProperties();
		//Bean�C���^�v���^�̎��s
		ASTPreInterpretVisitor funcVisitor = ASTPreInterpretVisitor(rootClsLoader);
		ASTInterpretVisitor interpretVisitor = ASTInterpretVisitor(rootClsLoader);
		root->visit(&funcVisitor);
		root->visit(&interpretVisitor);
	//�f�t�H���g�C���N���[�h�ɂ��G���[
	} catch(ClassFormatException cfe) {
		Console::println("�ȉ��̌����ɂ�� �C���^�v���^���I�����܂�");
		Console::println(cfe.what());
	//Bean�ŗ�O������������E�o
	} catch(BeanRuntimeException bre) {
	} catch (InterpretExitException iee) {
		Console::println("�ȉ��̌����ɂ�� �C���^�v���^���I�����܂�");
		Console::println(iee.what());
	}
	//�C���^�v���^�̏I��
	cdb->exit(true);
	MessageQueue::getInstance()->pop();
	ClassLoader::popCurrentClassLoader();
	//�o�ߎ��Ԃ̕\��
	span.end();
	if (uSys->value<bool>(UserSystem::PERFORMANCETEST)) {
		span.print("run file:");
	}
	this->state = ThreadState::TERMINATE;
	//�������[�̔j��
	//Heap::getInstance()->dump();
	block->page_clearAll();
	Heap::getInstance()->fullGC();
}

void Thread::checkPush() {
	if (pushForProtect) return;
	std::lock_guard<std::recursive_mutex> lock(Thread::thread_sync);
	for (int i = 0; i < threads.size(); i++) {
		if (threads.at(i).get() == this) {
			return;
		}
	}
	//std::cout << "PUSH " << getName() << std::endl;
	threads.push_back(shared_from_this());
	this->pushForProtect = true;
	if (!isSystemThreadFlag) {
		this->parent = getCurrent();
	}
}
//---private method
