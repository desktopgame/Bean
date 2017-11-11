#pragma once
#ifndef BEAN_ENV_USER_USERFILEPTR_H
#define BEAN_ENV_USER_USERFILEPTR_H
#include <stdio.h>
#include "../Object_.h"
/** 
 * ファイルポインタのラッパー.
 */
class UserFilePtr : public Object_ {
public:
	UserFilePtr();
	~UserFilePtr();
	/**
	 * 指定のモードでファイルを開きます.
	 * 既に開かれている場合には例外をスローします。
	 * @param mode
	 */
	void open(Numeric* mode);

	/**
	 * 一文字読み込みます.
	 * @return
	 */
	Numeric* read();

	/**
	 * ファイルをクローズします.
	 * まだオープンされていないのにクローズしようとした場合は例外をスローします.
	 */
	void close();

	// Object_ を介して継承されました
	virtual Object_ * clone() override;
private:
	FILE* ptr;

protected:
	void lazyLoading() override;
	int opened;
	int closed;
};
#endif // !BEAN_ENV_USERFILEPTR_H
