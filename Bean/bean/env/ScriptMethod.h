#pragma once
#ifndef BEAN_ENV_METHODIMPL_H
#define BEAN_ENV_METHODIMPL_H
#include <memory>
#include "Method.h"
class ClassLoader;
//class ASTMethodDeclaration;
using ClassSPtr = std::shared_ptr<Class>;
#include "ClassLoaderSkeleton.h"
#include "../ast/ASTMethodDeclaration.h"
/**
 * �C���X�^���X���\�b�h.
 */
class ScriptMethod : public Method {
public:
	/**
	 * @param classz ���ꂪnull�̂Ƃ��A�g�b�v���x���̊֐��Ƃ��Ĉ����܂��B
	 * @param methodDecl
	 */
	ScriptMethod(ClassSPtr classz, std::shared_ptr<ASTMethodDeclaration> methodDecl);
	~ScriptMethod();
	Object_ * const execute(Object_ * const invoker, std::vector<Object_*> args, bool currentClassLoader) override;
private:
	std::weak_ptr<ASTMethodDeclaration> methodDecl;
	ClassLoaderSPtr getCll();
};
#endif // !BEAN_ENV_METHODIMPL_H


