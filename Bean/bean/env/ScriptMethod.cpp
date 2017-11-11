#include "ScriptMethod.h"
#include "Class.h"
#include "ClassLoader.h"
#include "CodeBlock.h"
#include "Field.h"
#include "Object_.h"
#include "Parameter.h"
#include "gc/Block.h"
#include "../ast/ASTMethodDeclaration.h"
#include "../env/ClassLoader.h"
#include "../ast/visitor/ASTMethodVisitor.h"

//public method---
ScriptMethod::ScriptMethod(ClassSPtr classz, std::shared_ptr<ASTMethodDeclaration> methodDecl)
 : Method(classz, methodDecl->getModifier()->getValue(), methodDecl->getName()->getCString()) {
	this->methodDecl = std::weak_ptr<ASTMethodDeclaration>(methodDecl);
}

ScriptMethod::~ScriptMethod() {
}

Object_ * const ScriptMethod::execute(Object_ * const invoker, std::vector<Object_*> args, bool currentClassLoader) {
	if (currentClassLoader) {
		ClassLoader::pushCurrentClassLoader(getCll());
	}
	ClassLoaderSPtr cll = ClassLoader::getCurrentClassLoader();
	CodeBlock* cdb = cll->getCodeBlock();
	//フィールドを書き込む
	Object_* obj = invoker == nullptr ? nullptr : invoker;
	ClassWPtr objClass = getClass();
	ClassSPtr objClassSptr = objClass.lock();
	//引数を書き込む
	cdb->enter(false);
	for (int i = 0; i < getParameterCount(); i++) {
		Object_* arg = args.at(i);
		cdb->declReference(
			getParameterAt(i)->getName(),
			arg
		);
	}
	//メソッドを実行
	ASTMethodVisitor mv = ASTMethodVisitor();
	methodDecl.lock()->getBody()->visit(&mv);
	//例外をスロー
	if (mv.isThrown()) {
		Thread::getCurrent()->setException(mv.getException());
	}
	//cdb->exit(true);
	cdb->exit(true);
	if (currentClassLoader) {
		ClassLoader::popCurrentClassLoader();
	}
	Object_* retRef = mv.getReturnValue();
	return retRef;
}
//---public method

//private method---
ClassLoaderSPtr ScriptMethod::getCll() {
	ClassWPtr cls = getClass();
	ClassSPtr clsSptr = cls.lock();
	if (clsSptr) {
		return clsSptr->getClassLoader().lock();
	}
	return ClassLoader::getCurrentClassLoader();
}
//---private method
