#include "ASTMethodVisitor.h"
#include <functional>
#include "ASTInterpretVisitor.h"
#include "../ASTAssignOperator.h"
#include "../../Debug.h"
#include "../../env/Boolean.h"
#include "../../env/Exception.h"
#include "../../threads/Thread.h"
#include "../../env/gc/GCLock.h"
#include "../../env/pointer/Pointer.h"
#include "../../env/user/UserDelegate.h"

//public method---
ASTMethodVisitor::ASTMethodVisitor(ExceptionHandle* parent) {
	init(nullptr, parent);
}

ASTMethodVisitor::ASTMethodVisitor(ThreadSPtr t) {
	init(t, nullptr);
}

ASTMethodVisitor::ASTMethodVisitor() {
	init(nullptr, nullptr);
}

ASTMethodVisitor::~ASTMethodVisitor() {
}

ClassLoaderSPtr ASTMethodVisitor::getClassLoader() {
	return classLoader;
}

bool ASTMethodVisitor::isThrown() const {
	return thrown;
}

Object_ * ASTMethodVisitor::getReturnValue() const {
	return returnValue;
}

Object_ * ASTMethodVisitor::getException() const {
	return exception;
}

void ASTMethodVisitor::enter(std::shared_ptr<ASTNode > element) {
	if (isShutdown()) return;
	
}

void ASTMethodVisitor::enter(std::shared_ptr<ASTContinueStatement > element) {
	if (isShutdown()) return;
	this->next = true;
}

void ASTMethodVisitor::enter(std::shared_ptr<ASTBreakStatement > element) {
	if (isShutdown()) return;
	this->aexit = true;
}

void ASTMethodVisitor::enter(std::shared_ptr<ASTReturnStatement > element) {
//	GCLock gcLock = GCLock();
	if (isShutdown()) return;
	this->aexit = true;
//	std::shared_ptr<ASTReturnStatement> retStmt = std::dynamic_pointer_cast<ASTReturnStatement>(element);
	std::shared_ptr<ASTFactor> factor = element->getFactor();
	if (factor != nullptr) {
		this->hasRetVal = true;
		this->returnValue = factor->eval();
	}
}

void ASTMethodVisitor::enter(std::shared_ptr<ASTThrow > element) {
	if (isShutdown()) return;
	std::shared_ptr<ASTFactor> factor = element->getFactor();
	Block::pushCurrent();
	Object_* fEx = factor->eval();
	Block::popCurrent();
	if (fEx == Null::getInstance()) {
		return;
	}
	Thread::getCurrent()->setException(fEx);
	this->aexit = true;
	this->hasException = true;
	this->exception = fEx;
}

void ASTMethodVisitor::enter(std::shared_ptr<ASTDynFieldDeclaration > element) {
	if (isShutdown()) return;
	Block::pushCurrent();
	Object_* inv = element->getInvoker()->eval();
	std::string name = element->getName()->getCString();
	Object_* val = element->getValue()->eval();
	inv->defineDynField(name, val);
	Block::popCurrent();
}

void ASTMethodVisitor::enter(std::shared_ptr<ASTDynMethodDeclaration > element) {
	if (isShutdown()) return;
	Block::pushCurrent();
	Object_* inv = element->getInvoker()->eval();
	std::string name = element->getName()->getCString();
	Object_* val = element->getLambda()->eval();
	inv->defineDynMethod(name, dynamic_cast<UserDelegate*>(val));
	Block::popCurrent();
}

void ASTMethodVisitor::enter(std::shared_ptr<ASTIfStatement > element) {
	int offset = 0;
	std::shared_ptr<ASTIfCauseStatement> tmp = element;
	while (true) {
		Object_* condRef = tmp->getFactor()->eval();
		Object_* obj = condRef;
		Boolean* b = obj->asBoolean();
		//Boolean�^�ł͂Ȃ�����
		if (b == nullptr) {
			Exception::throw_e_zero_args("api.exc.NotBooleanError");
			break;
		}
		//�����𖞂����Ȃ�E�o
		if (b->of()) {
			std::shared_ptr<ASTBody> abody = tmp->getBody();
			abody->visit(this);
			break;
		//����elseif��
		} else if (offset < element->getElseIfCount()) {
			tmp = element->getElseIfAt(offset++);
		//else��
		} else {
			std::shared_ptr<ASTElseStatement> elseStmt = element->getElse();
			if (elseStmt == nullptr) {
				break;
			}
			elseStmt->getBody()->visit(this);
			break;
		}
	}
}

void ASTMethodVisitor::enter(std::shared_ptr<ASTWhileStatement > element) {
	if (isShutdown()) return;
	std::shared_ptr<ASTFactor> fNode = element->getFactor();
	Object_* fRef = fNode->eval();
	Object_* fObj = fRef;
	Boolean* fBool = fObj->asBoolean();
	//Boolean�^�ł͂Ȃ�����
	if (fBool == nullptr) {
		Exception::throw_e_zero_args("api.exc.NotBooleanError");
		return;
	}
	std::shared_ptr<ASTBody> body = element->getBody();
	CodeBlock* cdb = ClassLoader::getCurrentClassLoader()->getCodeBlock();
	cdb->enter(false);
	//while�̏����𖞂�������
	while (fBool->of()) {
		ASTMethodVisitor* child = newVisitor();
		body->visit(child);
		if (child->aexit) {
			if (child->hasRetVal) {
				this->aexit = true;
				this->returnValue = child->returnValue;
			}
			break;
		}
		//�]�����X�V����
		Heap::getInstance()->enter();
		Object_* condRef = fNode->eval();
		fObj = condRef;
		fBool = fObj->asBoolean();
		Heap::getInstance()->exit();
		//Boolean�^�ł͂Ȃ�����
		if (fBool == nullptr) {
			Exception::throw_e_zero_args("api.exc.NotBooleanError");
			break;
		}
	}
	cdb->exit(true);
}

void ASTMethodVisitor::enter(std::shared_ptr<ASTForStatement > element) {
	if (isShutdown()) return;
	//������
	CodeBlock* cdb = ClassLoader::getCurrentClassLoader()->getCodeBlock();
	cdb->enter(false);
	Block::pushCurrent();
	element->getInitialize()->visit(this);
	Block::popCurrent();
	//����
	std::shared_ptr<ASTFactor> fNode = element->getFactor();
	Object_* fObj = fNode->eval();
	Boolean* fBool = fObj->asBoolean();
	//Boolean�^�ł͂Ȃ�����
	if (fBool == nullptr) {
		Exception::throw_e_zero_args("api.exc.NotBooleanError");
		return;
	}
	//for�̏����𖞂�������
	while (fBool->of()) {
		ASTMethodVisitor* child = newVisitor();
		element->getBody()->visit(child);
		if (child->aexit) {
			if (child->hasRetVal) {
				this->aexit = true;
				this->returnValue = child->returnValue;
			}
			break;
		}
		//�X�V�������s����
		Block::pushCurrent();
		element->getUpdate()->visit(this);
		Block::popCurrent();
		//�]�����X�V����
		fObj = fNode->eval();
		fBool = fObj->asBoolean();
		//Boolean�^�ł͂Ȃ�����
		if (fBool == nullptr) {
			Exception::throw_e_zero_args("api.exc.NotBooleanError");
			break;
		}
	}
	cdb->exit(true);
	//Heap::getInstance()->test();
}

void ASTMethodVisitor::enter(std::shared_ptr<ASTVariableDeclaration > element) {
	if (isShutdown()) return;
	GCLock gcLock = GCLock();
	std::string name = element->getName()->getCString();
	Object_* ref = element->getFactor()->eval();
	ClassLoaderSPtr cll = ClassLoader::getCurrentClassLoader();
	CodeBlock* cdb = cll->getCodeBlock();
	Object_* assVal = ref;
	if (assVal->isPrimitive()) {
		assVal = assVal->clone();
	}
	cdb->declReference(name, assVal);
}

void ASTMethodVisitor::enter(std::shared_ptr<ASTBinaryOperator > element) {
	if (isShutdown()) return;
	std::shared_ptr<ASTAssignOperator> ass = std::dynamic_pointer_cast<ASTAssignOperator>(element);
	GCLock gcLock = GCLock();
	if (ass != nullptr) {
	//	GCSystem::getInstance()->lock();
		ClassLoaderSPtr cll = ClassLoader::getCurrentClassLoader();
		PointerSPtr pointee = ass->getPointer()->getReference();
		Object_* newVal = ass->eval();
		if (!pointee->isAssignable()) {
			Block::pushCurrent();
			std::vector<Object_*> args = std::vector<Object_*>();
			args.push_back(String::allocString(pointee->getLocation()));
			//��O���X���[���ꂽ�̂ł��̎��s���I��
			Object_* ex = Class::dynamicNewInstance("api.exc.CannotAssignError", args);
			this->exception = ex;
			this->hasException = true;
			this->thrown = true;
			this->aexit = true;
			Thread::getCurrent()->setException(ex);
			Block::popCurrent();
		} else {
		// Field/CodeBlock
		// �ւ̑�����s�����ʃX�[�p�[�N���X���`
			Object_* assVal = newVal;
			if (assVal->isPrimitive()) {
				assVal = assVal->clone();
			}
			Heap::getInstance()->writeBarrier(assVal);
			//Object_* oldVal = pointee->getValue();
			//Block::blocks_page_remove(oldVal);
			pointee->setValue(assVal);
	//		Heap::getInstance()->writeBarrier(newVal, pointee->getValue());
	//		Heap::getInstance()->writeBarrier(ref, newVal);
		}
	//	GCSystem::getInstance()->unlock();
	}
}

void ASTMethodVisitor::enter(std::shared_ptr<ASTMethodInvocation > element) {
	if (isShutdown()) return;
	element->eval();
}

void ASTMethodVisitor::enter(std::shared_ptr<ASTTryStatement > element) {
	std::shared_ptr<ASTBody> body = element->getBody();
	CodeBlock* cdb = ClassLoader::getCurrentClassLoader()->getCodeBlock();
	//��O�̔��������鏈�������s����
	cdb->enter(false);
	ASTMethodVisitor* child = newVisitor();
	//�L���b�`�u���b�N������Ȃ�
	//���ꂩ�甭�������O�͕K���L���b�`�����
	if (element->getCatchStatement() != nullptr) {
		child->markException();
	}
	body->visit(child);
	cdb->exit(true);
	if (this->exception == nullptr) {
		this->exception = Thread::getCurrent()->getException();
	}
	//��O����������
	if (child->hasException || hasException) {
		//catch�߂����s����
		auto catchStmt = element->getCatchStatement();
		auto exName = catchStmt->getCaptureExceptionName()->getCString();
		auto curThread = Thread::getCurrent();
		cdb->enter(false);
		cdb->declReference(exName, exception);
		//catch���̒��ł̓t���O���N���A
		ASTMethodVisitor* cChild = newVisitor();
		curThread->catchExceptionStart();
		catchStmt->getBody()->visit(cChild);
		curThread->catchExceptionEnd();
		cdb->exit(true);
		//catch�u���b�N�����s������
		//��O�t���O���N���A����
		curThread->clearException();
		//catch�߂ɂ���ė�O���X���[���ꂽ��
		if (cChild->hasException) {
			this->hasException = true;
			this->exception = cChild->exception;
		}
	}
	//finally�߂�����Ȃ���s����
	std::shared_ptr<ASTBody> finallyBlock = element->getFinally();
	if (finallyBlock != nullptr) {
		cdb->enter(false);
		ASTMethodVisitor fbmv = ASTMethodVisitor();
		finallyBlock->visit(&fbmv);
		cdb->exit(true);
	}
}

void ASTMethodVisitor::enter(std::shared_ptr<ASTScheduledFactor > element) {
	element->eval();
}

void ASTMethodVisitor::onException(Thread* t, Object_* e) {
	//try���m�F����Ă���̂�
	//�e�ɕ�
	if (rethrow) {
		parent->onCatch();
		this->rethrow = false;
		return;
	}
	fire(t, e);
	this->aexit = true;
	this->hasException = true;
	if (this->async) {
		printException(t, e);
	//	Thread::getCurrent()->clearException();
	}
}

void ASTMethodVisitor::onCatch() {
	if (parent != nullptr) {
		parent->onCatch();
	}
}
//---public method


//private method---
void ASTMethodVisitor::longJump(Object_ * exception) {
	this->aexit = true;
	this->exception = exception;
	this->hasException = true;
}

ASTMethodVisitor* ASTMethodVisitor::newVisitor() {
	ASTMethodVisitor* v= new ASTMethodVisitor(this);
	addHandle(v);
	return v;
}

void ASTMethodVisitor::init(ThreadSPtr t, ExceptionHandle * parent) {
	this->parent = nullptr;
	if (t != nullptr) {
		t->setExceptionListener([this](Thread* t, Object_* e) { onException(t, e); });
		this->async = true;
	}
	if (parent != nullptr) {
		this->parent = parent;
	}
	this->returnValue = Null::getInstance();
	this->next = false;
	this->hasRetVal = false;
	this->hasException = false;
	this->exception = nullptr;
	this->classLoader = ClassLoader::getCurrentClassLoader();
}

bool ASTMethodVisitor::isShutdown() {
	return next || aexit;
}
//---private method
