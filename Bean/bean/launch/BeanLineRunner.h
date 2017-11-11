#pragma once
#ifndef BEAN_LAUNCH_BEANLINERUNNER_H
#define BEAN_LAUNCH_BEANLINERUNNER_H
#include <memory>
#include <vector>
#include "../env/ClassLoader.h"
#include "../ast/visitor/ASTInterpretVisitor.h"
class ASTInterpretVisitor;
/**
 * Beanプログラムを一行ごとに解釈するクラス.
 */
class BeanLineRunner {
public:
	/**
	 * 現在の状態を表す識別子.
	 */
	enum class State {
		Run,
		Err,
		Exit,
	};

	BeanLineRunner();
	~BeanLineRunner();

	/**
	 * クラスローダを初期化します.
	 */
	void initialize();

	/**
	 * 指定の一行を解釈します.
	 * @param line
	 */
	State eval(BString line);

	/**
	 * 標準入力から一行読みこんで実行します.
	 */
	State eval();

	/**
	 * ユーザがリターンコードを実行するまで入力を実行します.
	 */
	void evalWhile();

	/**
	 * このオブジェクトを破棄します.
	 */
	void exit();
private:
	std::vector<ASTNodeSPtr> nodeList;
	ClassLoaderSPtr placeHolder;
	ClassLoaderSPtr rootClsLoader;
	std::shared_ptr<ASTInterpretVisitor> visitor;
};
#endif // !BEAN_LAUNCH_BEANLINERUNNER_H
