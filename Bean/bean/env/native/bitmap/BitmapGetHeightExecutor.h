#pragma once
#ifndef BEAN_ENV_NATIVE_BITMAP_BITMAPGETHEIGHTEXECUTOR_H
#define BEAN_ENV_NATIVE_BITMAP_BITMAPGETHEIGHTEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class BitmapGetHeightExecutor : public TypedNativeMethodExecutor {
public:
	BitmapGetHeightExecutor();
	~BitmapGetHeightExecutor();

	// TypedNativeMethodExecutor ����Čp������܂���
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_BITMAP_BITMAPGETHEIGHTEXECUTOR_H
