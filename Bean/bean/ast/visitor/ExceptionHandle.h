#pragma once
#ifndef BEAN_VISITOR_EXCEPTIONHANDLE_H
#define BEAN_VISITOR_EXCEPTIONHANDLE_H
#include <vector>
class Thread;
class Object_;
/**
 * 例外を捕捉するインターフェイス.
 */
class ExceptionHandle {
public:
	ExceptionHandle();
	virtual ~ExceptionHandle();
	/**
	 * 例外が捕捉されると呼び出されます.
	 * このビジターが以降の処理をスキップするようにフラグをONにします.
	 */
	virtual void onException(Thread* t, Object_* e) = 0;

	/**
	 * 例外がキャッチされると、
	 * それをキャッチしたより深い階層のハンドルから呼び出されます。
	 */
	virtual void onCatch() = 0;

	/**
	 * 例外情報を出力します.
	 * @param t
	 * @param e
	 */
	virtual void printException(Thread* t, Object_* e);
protected:
	/**
	 * このハンドルの子要素にさらに通知を受けるハンドルが必要なら追加します.
	 * @param handle
	 */
	void addHandle(ExceptionHandle* handle);

	/**
	 * 指定のハンドルを通知から除外します.
	 * @parma handle
	 */
	void removeHandle(ExceptionHandle* handle);

	/** 
	 * 追加されたハンドルへ通知を行います.
	 * @param t
	 * @param e
	 */
	void fire(Thread* t, Object_* e);
	std::vector<ExceptionHandle*> children;
};
#endif // !BEAN_VISITOR_EXCEPTIONHANDLE_H
