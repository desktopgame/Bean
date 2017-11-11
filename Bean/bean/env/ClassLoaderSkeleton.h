#pragma once
#ifndef BEAN_ENV_CLASSLOADERSKELETON_H
#define BEAN_ENV_CLASSLOADERSKELETON_H
#include <memory>

class ClassLoader;
using ClassLoaderSPtr = std::shared_ptr<ClassLoader>;
using ClassLoaderWPtr = std::weak_ptr<ClassLoader>;
#endif // !BEAN_ENV_CLASSLOADERSKELETON_H
