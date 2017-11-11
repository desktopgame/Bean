#pragma once
#ifndef BEAN_ENV_CLASSLOADERTREELOCK_H
#define BEAN_ENV_CLASSLOADERTREELOCK_H
#include "ClassLoader.h"
class ClassLoaderTreeLock {
public:
	ClassLoaderTreeLock(ClassLoaderSPtr clsSptr);
	~ClassLoaderTreeLock();
private:
};
#endif // !BEAN_ENV_CLASSLOADERTREELOCK_H
