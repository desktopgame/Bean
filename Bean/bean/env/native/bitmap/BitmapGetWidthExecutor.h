#pragma once
#ifndef BEAN_ENV_NATIVE_BITMAP_BITMAPGETWIDTHEXECUTOR_H
#define BEAN_ENV_NATIVE_BITMAP_BITMAPGETWIDTHEXECUTOR_H
#include "../TypedNativeMethodExecutor.h"
class BitmapGetWidthExecutor : public TypedNativeMethodExecutor {
public:
	BitmapGetWidthExecutor();
	~BitmapGetWidthExecutor();

	// TypedNativeMethodExecutor を介して継承されました
	virtual Object_ * const executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) override;
};
#endif // !BEAN_ENV_NATIVE_BITMAP_BITMAPGETWIDTHEXECUTOR_H
