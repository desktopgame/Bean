#include "ClassLoaderTreeLock.h"
//public method---
ClassLoaderTreeLock::ClassLoaderTreeLock(ClassLoaderSPtr clsSptr) {
	ClassLoader::pushCurrentClassLoader(clsSptr);
}

ClassLoaderTreeLock::~ClassLoaderTreeLock() {
	ClassLoader::popCurrentClassLoader();
}
//---public method