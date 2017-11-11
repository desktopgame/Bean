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
	//プレースホルダとして機能するクラスローダー
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
	//改行文字の手前までしか取得出来ないので、
	//そのまま渡すとパーサーがうまく動かない
	if (line == STR("exit")) return BeanLineRunner::State::Exit;
	line.push_back(CH(' '));
	//一行分を一時ファイルへ書き込む
	//char* tmpfnam = tmpnam(NULL);
	//IO::writeText(tmpfnam, line);
	//解析
	std::shared_ptr<ASTNode> root = Bean::compileplaf("console", line, true);
	if(root == nullptr) {
		return BeanLineRunner::State::Err;
	}
	//最初の実行でインタプリタを作成する
	if (rootClsLoader == nullptr) {
		rootClsLoader = std::make_shared<ClassLoader>(placeHolder, root, "line");
		rootClsLoader->registerClassLoader();
		rootClsLoader->loadProperties();
		rootClsLoader->getCodeBlock()->enter(false);
		visitor = std::make_shared<ASTInterpretVisitor>(rootClsLoader);
	//二行目以降の実行では
	//現在の状態を引き継ぐクラスローダーで実行する
	} else {
		std::shared_ptr<ASTNode> old = rootClsLoader->getRoot();
		rootClsLoader->setRoot(root);
		nodeList.push_back(old);
	}
	//トップレベルで実行する
	ClassLoader::pushCurrentClassLoader(rootClsLoader);
	MessageQueue::getInstance()->push(MessageInfo::createTop());
	//実行中にエラーが発生したなら終了します
	try {
		root->visit(visitor.get());
	//Beanで例外が発生したら脱出
	} catch(BeanRuntimeException e) {
	} catch (InterpretExitException iee) {
		Console::println("以下の原因により インタプリタを終了します");
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
