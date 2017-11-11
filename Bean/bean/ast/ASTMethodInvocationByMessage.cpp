#include "ASTMethodInvocationByMessage.h"
#include "ASTName.h"
#include "ASTNode.h"
#include "ASTSuperFactor.h"
#include "ASTVariable.h"
#include "../Debug.h"
#include "../env/Class.h"
#include "../env/ClassLoader.h"
#include "../env/Delegate.h"
#include "../env/DelegateMethod.h"
#include "../env/IncludeManager.h"
#include "../env/Method.h"
#include "../env/Null.h"
#include "../env/Numeric.h"
#include "../env/Parameter.h"
#include "../env/String.h"
#include "../util/TimeSpan.h"
#include "../env/gc/Block.h"
#include "../env/gc/GCLock.h"
#include "../env/user/UserDelegate.h"

//public method---
ASTMethodInvocationByMessage::ASTMethodInvocationByMessage() {
	this->cacheCompiled = false;
	this->cacheMethodStatic = nullptr;
	this->cacheMethodDynamic = nullptr;
}

ASTMethodInvocationByMessage::~ASTMethodInvocationByMessage() {
	delete this->cacheMethodDynamic;
}

void ASTMethodInvocationByMessage::setInvoker(std::shared_ptr<ASTFactor> invoker) {
	this->invoker = invoker;
}

std::shared_ptr<ASTFactor> ASTMethodInvocationByMessage::getInvoker() const {
	return this->invoker;
}

Object_ * ASTMethodInvocationByMessage::eval() {
	buffer_begin();
	Object_* retV = evalImpl();
	buffer_end();
	return retV;
}

std::shared_ptr<ASTMethodInvocationByMessage> ASTMethodInvocationByMessage::asByMessage() {
	std::shared_ptr<ASTNode> obj = shared_from_this();
	return std::dynamic_pointer_cast<ASTMethodInvocationByMessage>(obj);
}

std::string ASTMethodInvocationByMessage::format() const {
	return "invoke by-message";
}

void ASTMethodInvocationByMessage::accept(ASTVisitor * visitor) {
	visitor->enter(SHARED_FROM_THIS(ASTMethodInvocation));
	visitor->exit(SHARED_FROM_THIS(ASTMethodInvocation));
}
IMPL_MAKE_SHARED_0_CPP(ASTMethodInvocationByMessage)
//---public method


//private method---
Object_ * ASTMethodInvocationByMessage::evalImpl() {
	int dep = Block::getInstance()->getDepth();
	//���̃��\�b�h�����s����I�u�W�F�N�g���擾����
	//�N���X���݂̂̏ꍇ��static���\�b�h�̌Ăяo��
	Object_* invoker = nullptr;
	std::shared_ptr<ASTFactor> invokerNode = getInvoker();
	if (invokerNode != nullptr) {
		invoker = invokerNode->eval();
		Block::entry(invoker);
	}
	//���̏��������s���Ă���N���X���[�_�[
	//static���\�b�h�ɂ����ẮA
	//���O��Ԃ��������邽�߂ɂ��̃N���X�ŃC���N���[�h����Ă���N���X���ƏƉ��̂Ɏg�p����܂��B
	//��static���\�b�h�ɂ����ẮA
	//���̃��\�b�h�̌Ăяo���Ɋ܂܂�郁�\�b�h�̌Ăяo���ɂ����āA
	//���̃��\�b�h���Ăяo���Ă���I�u�W�F�N�g���g�����V�[�o�Ƃ��Đݒ肵�܂��B
	//�܂�A�ȍ~�� hoge() �̂悤�Ȗ��O�Ȃ��Ăяo���͂��̃��\�b�h�����s���Ă���I�u�W�F�N�g�����s���܂��B
	ClassLoaderSPtr cll = ClassLoader::getCurrentClassLoader();
	Object_* retVal = nullptr;
	std::shared_ptr<ASTSuperFactor> superF = std::dynamic_pointer_cast<ASTSuperFactor>(invokerNode);
	if (superF != nullptr) {
		invoker = cll->getLock();
	}
	//static���\�b�h�̌Ăяo��
	if (invoker == nullptr && superF == nullptr) {
		//���s����郁�\�b�h���������܂�
		std::shared_ptr<ASTVariable> vNameNode = std::dynamic_pointer_cast<ASTVariable>(invokerNode);
		std::string vName = vNameNode->getName()->getCString();
		std::string mName = getName()->getCString();
		ClassSPtr classz = findClassStatic(cll, vName);
		//�w��̃N���X��������Ȃ�
		if (classz == nullptr) {
			throwNoClassError(cll, vName);
			return Null::getInstance();
		}
		Method* method = findMethodStatic(classz, mName, getArgumentCount());
		//���\�b�h��������Ȃ�
		if (method == nullptr) {
			throwNoMethodError(cll, classz->getName(), getName()->getCString(), getArgumentCount());
			return Null::getInstance();
		}
		//�������̍쐬
		std::vector<Object_*> args = getEvalArguments(method);
		//�������v�Z���Ă���Ƃ��ɗ�O�����������ꍇ
		if (thrown()) {
			return Null::getInstance();
		}
		//�����̍쐬
		//������s��Ȃ��ƃR���X�g���N�^�Ăяo���ŕϐ����Q�Əo���Ȃ�
		ClassLoaderSPtr cll = method->getClass().lock()->getClassLoader().lock();
		CodeBlock* cdb = cll->getCodeBlock();
		cdb->enter(false);
		buffer_begin();
		for (int i = 0; i < method->getParameterCount(); i++) {
			cdb->writeReference(
				method->getParameterAt(i)->getName(),
				args.at(i)
			);
		}
		buffer_end();
		//���̃X�^�b�N�t���[���̏���ۑ����܂�
		//��O���X���[���ꂽ�Ƃ��Ɏg�p����܂�
		MessageInfo* info = new MessageInfo(cll, classz, method);
		MessageQueue::getInstance()->push(info);
		//���s
		Object_* retValRef = method->execute(invoker, args);
		MessageQueue::getInstance()->pop();
		cdb->exit(true);
		retVal = retValRef;
		return retVal;
	//�C���X�^���X���\�b�h
	} else {
		//���\�b�h�̌����J�n�ʒu���w��
		ClassSPtr classz = invoker->getClass();
		ClassSPtr s = classz;
		classz = invokerNode->getBaseLine(classz);
		//���ڈȍ~�̓L���b�V����������o��
		Method* method = findMethodDynamic(invoker, classz, getName()->getCString(), getArgumentCount());
		//���\�b�h��������Ȃ�
		if (method == nullptr) {
			throwNoMethodError(cll, classz->getName(), getName()->getCString(), getArgumentCount());
			return Null::getInstance();
		}
		classz = method->getClass().lock();
		//�����̍쐬
		buffer_begin();
		std::vector<Object_*> args = getEvalArguments(method);
		buffer_end();
		//�������v�Z���Ă���Ƃ��ɗ�O�����������ꍇ
		if (thrown()) {
			return Null::getInstance();
		}
		//���̃��\�b�h�����s���Ă���N���X�̃N���X���[�_�[��
		//"���ݏ������Ă���N���X���[�_�[" �ɐݒ肵�܂��B
		auto newCll = classz->getClassLoader().lock();
		ClassLoader::pushCurrentClassLoader(newCll);
		//����̖��O�Ȃ��Ăяo�������̃��\�b�h���Ăяo���Ă���I�u�W�F�N�g���̂�
		//�o�C���h�����悤�Ƀ��b�N���܂��B
		classz->getClassLoader().lock()->lockInstance(invoker);
		//���̃X�^�b�N�t���[���̏���ۑ����܂�
		//��O���X���[���ꂽ�Ƃ��Ɏg�p����܂�
		MessageInfo* info = new MessageInfo(cll, classz, method);
		MessageQueue::getInstance()->push(info);
		//���s
		//super#hoge �̂悤�ȌĂяo���ł��A
		//Method#execute�Ŏ����N���X�̃N���X���[�_�[���ݒ肳��Ă��܂��̂ŁA
		//super�̂Ƃ��N���X���[�_�[��ݒ肵�Ȃ��t���O��ݒ肷��
		Object_* retValRef = method->execute(invoker, args, superF == nullptr);
		MessageQueue::getInstance()->pop();
		retVal = retValRef;
		//buffer_end();
		//���b�N���������܂��B
		classz->getClassLoader().lock()->unlockInstance();
		//"���ݏ������Ă���N���X���[�_�[" �����Ƃɖ߂��܂��B
		ClassLoader::popCurrentClassLoader();
		return retVal;
	}
}

ClassSPtr ASTMethodInvocationByMessage::findClassStatic(ClassLoaderSPtr cll, std::string name) {
	if (!cacheCompiled) {
		ClassSPtr classz = cll->getIncludeManager()->getClass(name);
		this->cacheClassStatic = classz;
	//	this->cacheCompiled = true;
	}
	return cacheClassStatic;
	//return cll->getIncludeManager()->getClass(name);
}

Method * ASTMethodInvocationByMessage::findMethodStatic(ClassSPtr classz, std::string name, int argc) {
	if (!cacheCompiled) {
		Method* method = classz->findMethod(name, argc, false);
		this->cacheMethodStatic = method;
	//	this->cacheCompiled = true;
	}
	return cacheMethodStatic;
}

Method * ASTMethodInvocationByMessage::findMethodDynamic(Object_* obj, ClassSPtr classz, std::string name, int argc) {
	UserDelegate* ud = obj->findDynMethod(name, argc);
	if (ud != nullptr && ud->getDelegate()->requestArgumentCount() == argc) {
		delete this->cacheMethodDynamic;
		this->cacheMethodDynamic = new DelegateMethod(obj, name, ud);
		return cacheMethodDynamic;
	}
	Method* method = classz->findMethod(name, argc, true);
	return method;
}
//---private method
