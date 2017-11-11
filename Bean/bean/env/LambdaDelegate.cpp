#include "LambdaDelegate.h"
#include "../ast/ASTLambdaDeclaration.h"
#include "../env/ClassLoader.h"
#include "../env/CodeBlock.h"
#include "../env/Object_.h"
#include "../util/TimeSpan.h"
#include "../env/gc/Heap.h"
#include "../ast/visitor/ASTInterpretVisitor.h"
#include "../ast/visitor/ASTMethodVisitor.h"
#include "../env/user/UserDelegate.h"
#include "../env/user/UserThread.h"
using MapIterator = std::unordered_map<std::string, Object_*>::iterator;


//public method---
LambdaDelegate::LambdaDelegate(ASTLambdaDeclaration* lambdaDecl) {
	this->lambdaDecl = lambdaDecl;
	this->outerObject_s = std::vector<std::string>();
}

LambdaDelegate::~LambdaDelegate() {
}

void LambdaDelegate::addOutsideReference(std::string name) {
	this->outerObject_s.push_back(name);
}

Object_ * LambdaDelegate::call(ThreadSPtr t, ClassLoaderSPtr cll, std::vector<Object_*> args) {
	ClassLoaderSPtr clld = ClassLoader::getCurrentClassLoader();
	//ここで動的に外側のコードブロックからオブジェクトを取得
	CodeBlock* cdb = cll->getCodeBlock();
	cdb->enter(true);
	for (int i = 0; i < lambdaDecl->getParameterCount(); i++) {
		//引数の作成
		//ここで新たな参照を作成しないと、C#でいうところのrefになってしまう
		cdb->declReference(
			lambdaDecl->getParameterAt(i)->getName()->getCString(),
			args.at(i)
		);
	}
	ASTMethodVisitor mv = ASTMethodVisitor(t);
	ClassLoader::pushCurrentClassLoader(cll);
	//動的メソッドでthisを参照可能に
	if (isDynamicMethod()) {
		cll->lockInstance(clld->getLock());
	}
	lambdaDecl->getBody()->visit(&mv);
	if (isDynamicMethod()) {
		cll->unlockInstance();
	}
	ClassLoader::popCurrentClassLoader();
	cdb->exit(true);
	return mv.getReturnValue();
}

Object_ * LambdaDelegate::call(ClassLoaderSPtr cll, std::vector<Object_*> args) {
	return call(nullptr, cll, args);
}

int LambdaDelegate::requestArgumentCount() {
	return lambdaDecl->getParameterCount();
}

std::vector<Object_*> LambdaDelegate::getVirtualField(ClassLoaderSPtr cll) {
	auto ret = std::vector<Object_*>();
	CodeBlock* cdb = cll->getCodeBlock();
	for (std::string name : this->outerObject_s) {
		Object_* obj = cdb->readReference(name);
		if (obj == nullptr) {
			continue;
		}
		ret.push_back(obj);
	}
	return ret;
}
//---public method
