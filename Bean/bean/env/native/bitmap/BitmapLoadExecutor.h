#pragma once
#ifndef BEAN_ENV_NATIVE_BITMAP_BITMAPLOADEXECUTOR_H
#define BEAN_ENV_NATIVE_BITMAP_BITMAPLOADEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class BitmapLoadExecutor : public TypedNativeMethodExecutor {
public:
	BitmapLoadExecutor();
	~BitmapLoadExecutor();

	// TypedNativeMethodExecutor ����Čp������܂���
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_BITMAP_BITMAPLOADEXECUTOR_H
