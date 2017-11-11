#include "BeanLineRunner.h"
#include <stdio.h>
#include "../launch/Bean.h"
#include "../ast/BeanRuntimeException.h"
#include "../env/ClassFormatException.h"
#include "../parser/BisonWrapper.h"
#include "../util/Console.h"
#include "../util/IO.h"
#include "../threads/Thread.h"
BeanLineRunner::BeanLineRunner() {
}

BeanLineRunner::~BeanLineRunner() {
}

void BeanLineRunner::initialize() {
	Thread::getSystemThread()->registerThread();
	//�v���[�X�z���_�Ƃ��ċ@�\����N���X���[�_�[
	ClassLoaderSPtr placeHolder = std::make_shared<ClassLoader>(std::make_shared<ASTNode>());
	placeHolder->registerClassLoader();
	try {
		placeHolder->loadDefaults();
		placeHolder->loadProperties();
	} catch (ClassFormatException cfe) {
		Console::println(cfe.what());
		return;
	}
	this->rootClsLoader = nullptr;
	this->visitor = nullptr;
	this->nodeList = std::vector<ASTNodeSPtr>();
}

BeanLineRunner::State BeanLineRunner::eval(BString line) {
	//���s�����̎�O�܂ł����擾�o���Ȃ��̂ŁA
	//���̂܂ܓn���ƃp�[�T�[�����܂������Ȃ�
	if (line == STR("exit")) return BeanLineRunner::State::Exit;
	line.push_back(CH(' '));
	//��s�����ꎞ�t�@�C���֏�������
	//char* tmpfnam = tmpnam(NULL);
	//IO::writeText(tmpfnam, line);
	//���
	std::shared_ptr<ASTNode> root = Bean::compileplaf("console", line, true);
	if(root == nullptr) {
		return BeanLineRunner::State::Err;
	}
	//�ŏ��̎��s�ŃC���^�v���^���쐬����
	if (rootClsLoader == nullptr) {
		rootClsLoader = std::make_shared<ClassLoader>(placeHolder, root, "line");
		rootClsLoader->registerClassLoader();
		rootClsLoader->loadProperties();
		rootClsLoader->getCodeBlock()->enter(false);
		visitor = std::make_shared<ASTInterpretVisitor>(rootClsLoader);
	//��s�ڈȍ~�̎��s�ł�
	//���݂̏�Ԃ������p���N���X���[�_�[�Ŏ��s����
	} else {
		std::shared_ptr<ASTNode> old = rootClsLoader->getRoot();
		rootClsLoader->setRoot(root);
		nodeList.push_back(old);
	}
	//�g�b�v���x���Ŏ��s����
	ClassLoader::pushCurrentClassLoader(rootClsLoader);
	MessageQueue::getInstance()->push(MessageInfo::createTop());
	//���s���ɃG���[�����������Ȃ�I�����܂�
	try {
		root->visit(visitor.get());
	//Bean�ŗ�O������������E�o
	} catch(BeanRuntimeException e) {
	} catch (InterpretExitException iee) {
		Console::println("�ȉ��̌����ɂ�� �C���^�v���^���I�����܂�");
		Console::println(iee.what());
		MessageQueue::getInstance()->pop();
		ClassLoader::popCurrentClassLoader();
		return BeanLineRunner::State::Err;
	}
	MessageQueue::getInstance()->pop();
	ClassLoader::popCurrentClassLoader();
	return BeanLineRunner::State::Run;
}

BeanLineRunner::State BeanLineRunner::eval() {
	return eval(Console::readln());
}

void BeanLineRunner::evalWhile() {
	while (true) {
		State state = eval();
		if (state == State::Exit) break;
	}
}

void BeanLineRunner::exit() {
	this->rootClsLoader->getCodeBlock()->exit(true);
	Heap::getInstance()->fullGC();
	nodeList.clear();
}
