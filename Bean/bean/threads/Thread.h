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
 * �v���O���������̒P�ʂ�\���N���X�ł�.
 * �X���b�h���Ƃɕ��s���ď��������s���邱�Ƃ��o���܂��B
 */
class Thread final : public std::enable_shared_from_this<Thread> {
public:
	Thread(std::string name, int runtimeID, bool isSystemThreadFlag);
	Thread(std::string name, int runtimeID);
	~Thread();

	void registerThread();

	/**
	 * �w��̎��ԃX���[�v���܂�.
	 * @param l
	 */
	static void sleep(long l);

	/**
	 * �S�ẴX���b�h�̐���Ԃ��܂�.
	 * @return
	 */
	static int getThreadCount();

	/**
	 * ��ԍŏ��ɋN������X���b�h�ł�.
	 * @return
	 */
	static ThreadSPtr getSystemThread();

	/**
	 * �w��ʒu�̃X���b�h��Ԃ��܂�.
	 * @param index
	 * @return
	 */
	static ThreadSPtr getThreadAt(int index);

	/**
	 * ���݂̃X���b�h��Ԃ��܂�.
	 * ���݂̃X���b�h�͊��ɊJ�n���Ă��邩�A�J�n���Ă��Ȃ����V�X�e���X���b�h�̂��݂̂̂��Ԃ���܂��B
	 * @return
	 */
	static ThreadSPtr getCurrent();

	/**
	 * ���݂̃X���b�h��Ԃ��܂�.
	 * ������Ȃ�������V�X�e���X���b�h��Ԃ��܂��V�X�e���X���b�h��Ԃ��܂�.
	 * @return
	 */
	static ThreadSPtr getCurrentOrSystem();

	/**
	 * �w���ID�̃X���b�h���I�����܂�.
	 * @param id
	 */
	static void destroy(int id);

	/**
	 * �S�ẴX���b�h���I�����܂�.
	 */
	static void destroy();

	/**
	 * �w��̃t�@�C�������̃X���b�h�Ŏ��s���܂�.
	 * @param fileName
	 */
	void start(std::string fileName);

	/** 
	 * �w��̃f���Q�[�g�����̃X���b�h�Ŏ��s���܂�.
	 * @param d
	 */
	void start(UserDelegate* d);

	/**
	 * ���݂̃X���b�h���I������܂ŌĂяo����ҋ@���܂�.
	 */
	void join();

	/**
	 * �X���b�h���I�����܂�.
	 * ���̃��\�b�h���Ăяo���ꂽ��͂��̃C���X�^���X�ɃA�N�Z�X���Ȃ��ł��������B
	 */
	void exit();

	//
	//�N���X���[�_�[
	//

	/**
	 * ���݂̃X���b�h�̃N���X���[�_�[�����ւ��܂�.
	 * @param classLoader
	 */
	void pushCurrentClassLoader(ClassLoaderSPtr classLoader);

	/**
	 * ���݂̃N���X���[�_�[��߂��܂�.
	 */
	void popCurrentClassLoader();

	/**
	 * ���݂̃N���X���[�_�[��Ԃ��܂�.
	 * @return
	 */
	ClassLoaderSPtr getCurrentClassLoader();

	//
	//�C�x���g
	//

	/**
	 * ���̃X���b�h�Ŕ���������O��ߑ����郊�X�i�[��ݒ肵�܂�.
	 * @param listener
	 */
	void setExceptionListener(ExceptionListener listener);

	/**
	 * ���̃X���b�h�Ŕ���������O��ߑ����郊�X�i�[��Ԃ��܂�.
	 * @return
	 */
	ExceptionListener getExceptionListener();

	//
	//�v���p�e�B
	//

	/**
	 * ���̃X���b�h�𑀍삵�Ă���X�N���v�g�̃C���X�^���X��ݒ肵�܂�.
	 * @param owner
	 */
	void setOwner(UserThread* owner);

	/**
	 * ���̃X���b�h�𑀍삵�Ă���X�N���v�g�̃C���X�^���X��Ԃ��܂�.
	 * @return
	 */
	UserThread* const getOwner();

	/**
	 * ��O��ݒ肵�܂�.
	 * ���̃��\�b�h���Ăяo���Ɨ�O�t���O�� true �ɂȂ�܂��B
	 * @param ex
	 */
	void setException(Object_* ex);

	/**
	 * ��O��Ԃ��܂�.
	 * @return
	 */
	Object_* getException() const;

	/**
	 * ��O�t���O��Ԃ��܂�.
	 * @return
	 */
	bool wasThrownException();

	/**
	 * catch�������s����ԁA
	 * ��O�t���O�� false ��Ԃ��悤�ɂ��܂��B
	 */
	void catchExceptionStart();

	/**
	 * �t���O�����Ƃɖ߂��܂��B
	 */
	void catchExceptionEnd();

	/**
	 * ��O�t���O���N���A���܂�.
	 */
	void clearException();

	/**
	 * ���̃X���b�h�̖��O��Ԃ��܂�.
	 * @return
	 */
	std::string getName() const;

	/**
	 * ���̃X���b�h��ID��Ԃ��܂�.
	 * @return
	 */
	int getRuntimeID() const;

	/**
	 * ���̃X���b�h�̏�Ԃ�Ԃ��܂�.
	 * @return
	 */
	ThreadState getState() const;

	/**
	 * ���̃X���b�h��ID��Ԃ��܂�.
	 * @return
	 */
	ThreadID getThreadID() const;

	/**
	 * ���b�Z�[�W�L���[��Ԃ��܂�.
	 * @return
	 */
	MessageQueueSPtr getQueue();

	/** 
	 * �o�b�t�@��Ԃ��܂�.
	 * @return
	 */
	BlockSPtr getBuffer();

	/**
	 * ���݂̃X���b�h��S�ĕԂ��܂�.
	 * @return
	 */
	static std::vector<ThreadSPtr> getThreads();

	/**
	 * �ŏ��̃X���b�h�Ȃ�true.
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


