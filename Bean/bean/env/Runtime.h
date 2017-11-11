#pragma once
#ifndef BEAN_ENV_RUNTIME_H
#define BEAN_ENV_RUNTIME_H
#include <string>
#include <vector>
#include "../threads/Thread.h"
/**
 * Beanの実行環境.
 */
class Runtime {
public:
	Runtime();
	~Runtime();

	/**
	 * 現在実行中のランタイムを返します.
	 * @return
	 */
	static Runtime* const getCurrent();

	/**
	 * 現在のランタイムに紐づけられるスレッドを返します.
	 * @param name
	 * @return
	 */
	static ThreadSPtr newThread(std::string name);

	/**
	 * 指定のファイルを起動します.
	 * @param mainFile
	 */
	void exec(std::string mainFile);

	/**
	 * このランタイムに割り当てられたIDを返します.
	 * @return
	 */
	int getID() const;
private:
	int id;
	static Runtime* current;
	static int index;
	void execImpl(std::string mainFile);
};
#endif // !BEAN_ENV_RUNTIME_H
