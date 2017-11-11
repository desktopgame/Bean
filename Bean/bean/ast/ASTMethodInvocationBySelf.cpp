#include "ASTMethodInvocationBySelf.h"
#include "ASTName.h"
#include "ASTNode.h"
#include "../env/Class.h"
#include "../env/ClassLoader.h"
#include "../env/Exception.h"
#include "../env/Function.h"
#include "../env/FunctionManager.h"
#include "../env/Method.h"
#include "../env/Null.h"
#include "../env/Object_.h"
#include "../env/Package.h"
#include "../env/gc/Block.h"

//public method---
ASTMethodInvocationBySelf::ASTMethodInvocationBySelf() {
	this->cacheCompiled = false;
}

ASTMethodInvocationBySelf::~ASTMethodInvocationBySelf() {
}

Object_ * ASTMethodInvocationBySelf::eval() {
	buffer_begin();
	Object_* retRef = evalImpl();
	this->cacheCompiled = true;
	buffer_end();
	return retRef;
}

std::shared_ptr<ASTMethodInvocationBySelf> ASTMethodInvocationBySelf::asBySelf() {
	std::shared_ptr<ASTNode> obj = shared_from_this();
	return std::dynamic_pointer_cast<ASTMethodInvocationBySelf>(obj);
}

std::string ASTMethodInvocationBySelf::format() const {
	return "invoke by-self";
}
IMPL_MAKE_SHARED_0_CPP(ASTMethodInvocationBySelf)
//---public method


//private method---
Object_ * ASTMethodInvocationBySelf::evalImpl() {
	ClassLoaderSPtr cll = ClassLoader::getCurrentClassLoader();
	//�g�b�v���x���̊֐��Ăяo��
	if (cll->isEntryPoint()) {
		FunctionManager* fm = cll->getFunctionManager();
		Function* func = findTopLevelFunction(fm, getName()->getCString(), getArgumentCount());
		//�֐���������Ȃ�
		if (func == nullptr) {
			Exception::throw_e_simple("api.exc.NoFuncError", "�֐���������܂���B:" + getName()->getCString());
			return nullptr;
		}
		//�����̍쐬
		std::vector<Object_*> args = getEvalArguments(func);
		//�������v�Z���Ă���Ƃ��ɗ�O�����������ꍇ
		if (thrown()) {
			return Null::getInstance();
		}
		//���̃X�^�b�N�t���[���̏���ۑ����܂�
		//��O���X���[���ꂽ�Ƃ��Ɏg�p����܂�
		MessageInfo* info = new MessageInfo(cll, nullptr, func);
		MessageQueue::getInstance()->push(info);
		Object_* retVal = func->call(args);
		MessageQueue::getInstance()->pop();
		return retVal;
	//���N���X�̃��\�b�h
	} else {
		ClassSPtr classz = Package::getClass(cll->getClassName());
		Method* m = findSelfMethod(classz, getName()->getCString(), getArgumentCount());
		//���\�b�h��������Ȃ�
		if (m == nullptr) {
			throwNoMethodError(cll, classz->getName(), getName()->getCString(), getArgumentCount());
			return Null::getInstance();
		}
		ClassLoader::pushCurrentClassLoader(classz->getClassLoader().lock());
		//�����̍쐬
		std::vector<Object_*> args = getEvalArguments(m);
		//�������v�Z���Ă���Ƃ��ɗ�O�����������ꍇ
		if (thrown()) {
			return Null::getInstance();
		}
		//���݃o�C���h����Ă���I�u�W�F�N�g���擾���܂��B
		//���郁�\�b�h�����s����Ƃ��A
		//�ŏ��̌Ăяo���ɂ����Ă͕K�����O�t���̌Ăяo��(hoge.foo())���K�v�ł��B
		//���̌Ăяo���ɂ����郌�V�[�o(���̗�ł�hoge)���擾���܂��B
		Object_* invR = cll->getLock(true);
		//���̃X�^�b�N�t���[���̏���ۑ����܂�
		//��O���X���[���ꂽ�Ƃ��Ɏg�p����܂�
		MessageInfo* info = new MessageInfo(cll, classz, m);
		MessageQueue::getInstance()->push(info);
		Object_* retVal = m->execute(invR, args);
		MessageQueue::getInstance()->pop();
		ClassLoader::popCurrentClassLoader();
		//��O�����̃��\�b�h���Ăяo�����I�u�W�F�N�g�֓`�d
		return retVal;
	}
	return nullptr;
}

Function * ASTMethodInvocationBySelf::findTopLevelFunction(FunctionManager * fm, std::string name, int argc) {
	if (!cacheCompiled) {
		Function* f = fm->findFunction(name, argc);
		this->cacheTopLevelFunction = f;
	}
	return cacheTopLevelFunction;
}

Method * ASTMethodInvocationBySelf::findSelfMethod(ClassSPtr classz, std::string name, int argc) {
	if (!cacheCompiled) {
		Method* method = classz->findMethod(name, argc, false);
		this->cacheSelfMethod = method;
	}
	return cacheSelfMethod;
}
//---private method
