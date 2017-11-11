#pragma once
#ifndef BEAN_THREDS_THREAD_H
#define BEAN_THREDS_THREAD_H
#include <functional>
#include <mutex>
#include <stack>
#include <thread>
#include <vector>
#include "ThreadState.cpp"
#include "../env/ClassLoader.h"
#include "../env/CodeBlock.h"
#include "../env/MessageQueue.h"
#include "../env/gc/Block.h"
class UserDelegate;
class UserThread;
class Thread;
using ThreadID = std::thread::id;
using ExceptionListener = std::function<void(Thread*, Object_*)>;
using ThreadSPtr = std::shared_ptr<Thread>;
using ThreadWPtr = std::weak_ptr<Thread>;
/**
 * プログラム処理の単位を表すクラスです.
 * スレッドごとに平行して処理を実行することが出来ます。
 */
class Thread final : public std::enable_shared_from_this<Thread> {
public:
	Thread(std::string name, int runtimeID, bool isSystemThreadFlag);
	Thread(std::string name, int runtimeID);
	~Thread();

	void registerThread();

	/**
	 * 指定の時間スリープします.
	 * @param l
	 */
	static void sleep(long l);

	/**
	 * 全てのスレッドの数を返します.
	 * @return
	 */
	static int getThreadCount();

	/**
	 * 一番最初に起動するスレッドです.
	 * @return
	 */
	static ThreadSPtr getSystemThread();

	/**
	 * 指定位置のスレッドを返します.
	 * @param index
	 * @return
	 */
	static ThreadSPtr getThreadAt(int index);

	/**
	 * 現在のスレッドを返します.
	 * 現在のスレッドは既に開始しているか、開始していないがシステムスレッドのもののみが返されます。
	 * @return
	 */
	static ThreadSPtr getCurrent();

	/**
	 * 現在のスレッドを返します.
	 * 見つからなかったらシステムスレッドを返しますシステムスレッドを返します.
	 * @return
	 */
	static ThreadSPtr getCurrentOrSystem();

	/**
	 * 指定のIDのスレッドを終了します.
	 * @param id
	 */
	static void destroy(int id);

	/**
	 * 全てのスレッドを終了します.
	 */
	static void destroy();

	/**
	 * 指定のファイルをこのスレッドで実行します.
	 * @param fileName
	 */
	void start(std::string fileName);

	/** 
	 * 指定のデリゲートをこのスレッドで実行します.
	 * @param d
	 */
	void start(UserDelegate* d);

	/**
	 * 現在のスレッドが終了するまで呼び出しを待機します.
	 */
	void join();

	/**
	 * スレッドを終了します.
	 * このメソッドが呼び出された後はこのインスタンスにアクセスしないでください。
	 */
	void exit();

	//
	//クラスローダー
	//

	/**
	 * 現在のスレッドのクラスローダーを入れ替えます.
	 * @param classLoader
	 */
	void pushCurrentClassLoader(ClassLoaderSPtr classLoader);

	/**
	 * 現在のクラスローダーを戻します.
	 */
	void popCurrentClassLoader();

	/**
	 * 現在のクラスローダーを返します.
	 * @return
	 */
	ClassLoaderSPtr getCurrentClassLoader();

	//
	//イベント
	//

	/**
	 * このスレッドで発生した例外を捕捉するリスナーを設定します.
	 * @param listener
	 */
	void setExceptionListener(ExceptionListener listener);

	/**
	 * このスレッドで発生した例外を捕捉するリスナーを返します.
	 * @return
	 */
	ExceptionListener getExceptionListener();

	//
	//プロパティ
	//

	/**
	 * このスレッドを操作しているスクリプトのインスタンスを設定します.
	 * @param owner
	 */
	void setOwner(UserThread* owner);

	/**
	 * このスレッドを操作しているスクリプトのインスタンスを返します.
	 * @return
	 */
	UserThread* const getOwner();

	/**
	 * 例外を設定します.
	 * このメソッドを呼び出すと例外フラグが true になります。
	 * @param ex
	 */
	void setException(Object_* ex);

	/**
	 * 例外を返します.
	 * @return
	 */
	Object_* getException() const;

	/**
	 * 例外フラグを返します.
	 * @return
	 */
	bool wasThrownException();

	/**
	 * catch文を実行する間、
	 * 例外フラグが false を返すようにします。
	 */
	void catchExceptionStart();

	/**
	 * フラグをもとに戻します。
	 */
	void catchExceptionEnd();

	/**
	 * 例外フラグをクリアします.
	 */
	void clearException();

	/**
	 * このスレッドの名前を返します.
	 * @return
	 */
	std::string getName() const;

	/**
	 * このスレッドのIDを返します.
	 * @return
	 */
	int getRuntimeID() const;

	/**
	 * このスレッドの状態を返します.
	 * @return
	 */
	ThreadState getState() const;

	/**
	 * このスレッドのIDを返します.
	 * @return
	 */
	ThreadID getThreadID() const;

	/**
	 * メッセージキューを返します.
	 * @return
	 */
	MessageQueueSPtr getQueue();

	/** 
	 * バッファを返します.
	 * @return
	 */
	BlockSPtr getBuffer();

	/**
	 * 現在のスレッドを全て返します.
	 * @return
	 */
	static std::vector<ThreadSPtr> getThreads();

	/**
	 * 最初のスレッドならtrue.
	 * @return
	 */
	bool isSystemThread() const;
private:
	void naming();
	bool containsName(std::string name);
	void runFile(std::string mainFile);
	void checkPush();

	std::string name;
	ThreadState state;
	ThreadID threadID;
	ThreadWPtr parent;
	UserThread* owner;
	Object_* exception;
	BlockSPtr block;
	bool isSystemThreadFlag;
	bool pushForProtect;
	int runtimeID;

	int throwState;
	int catchCount;
	std::thread impl;
	ExceptionListener listener;
	MessageQueueSPtr queue;
	std::stack<ClassLoaderSPtr> classLoaderStack;
	static std::recursive_mutex thread_sync;
	static ThreadSPtr systemThread;
	static std::vector<ThreadSPtr> threads;
};
#endif // !BEAN_THREDS_THREAD_H


