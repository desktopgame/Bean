#include "ASTMethodInvocationBySelf.h"
#include "ASTName.h"
#include "ASTNode.h"
#include "../env/Class.h"
#include "../env/ClassLoader.h"
#include "../env/Exception.h"
#include "../env/Function.h"
#include "../env/FunctionManager.h"
#include "../env/Method.h"
#include "../env/Null.h"
#include "../env/Object_.h"
#include "../env/Package.h"
#include "../env/gc/Block.h"

//public method---
ASTMethodInvocationBySelf::ASTMethodInvocationBySelf() {
	this->cacheCompiled = false;
}

ASTMethodInvocationBySelf::~ASTMethodInvocationBySelf() {
}

Object_ * ASTMethodInvocationBySelf::eval() {
	buffer_begin();
	Object_* retRef = evalImpl();
	this->cacheCompiled = true;
	buffer_end();
	return retRef;
}

std::shared_ptr<ASTMethodInvocationBySelf> ASTMethodInvocationBySelf::asBySelf() {
	std::shared_ptr<ASTNode> obj = shared_from_this();
	return std::dynamic_pointer_cast<ASTMethodInvocationBySelf>(obj);
}

std::string ASTMethodInvocationBySelf::format() const {
	return "invoke by-self";
}
IMPL_MAKE_SHARED_0_CPP(ASTMethodInvocationBySelf)
//---public method


//private method---
Object_ * ASTMethodInvocationBySelf::evalImpl() {
	ClassLoaderSPtr cll = ClassLoader::getCurrentClassLoader();
	//トップレベルの関数呼び出し
	if (cll->isEntryPoint()) {
		FunctionManager* fm = cll->getFunctionManager();
		Function* func = findTopLevelFunction(fm, getName()->getCString(), getArgumentCount());
		//関数が見つからない
		if (func == nullptr) {
			Exception::throw_e_simple("api.exc.NoFuncError", "関数が見つかりません。:" + getName()->getCString());
			return nullptr;
		}
		//引数の作成
		std::vector<Object_*> args = getEvalArguments(func);
		//引数を計算しているときに例外が発生した場合
		if (thrown()) {
			return Null::getInstance();
		}
		//このスタックフレームの情報を保存します
		//例外がスローされたときに使用されます
		MessageInfo* info = new MessageInfo(cll, nullptr, func);
		MessageQueue::getInstance()->push(info);
		Object_* retVal = func->call(args);
		MessageQueue::getInstance()->pop();
		return retVal;
	//自クラスのメソッド
	} else {
		ClassSPtr classz = Package::getClass(cll->getClassName());
		Method* m = findSelfMethod(classz, getName()->getCString(), getArgumentCount());
		//メソッドが見つからない
		if (m == nullptr) {
			throwNoMethodError(cll, classz->getName(), getName()->getCString(), getArgumentCount());
			return Null::getInstance();
		}
		ClassLoader::pushCurrentClassLoader(classz->getClassLoader().lock());
		//引数の作成
		std::vector<Object_*> args = getEvalArguments(m);
		//引数を計算しているときに例外が発生した場合
		if (thrown()) {
			return Null::getInstance();
		}
		//現在バインドされているオブジェクトを取得します。
		//あるメソッドを実行するとき、
		//最初の呼び出しにおいては必ず名前付きの呼び出し(hoge.foo())が必要です。
		//その呼び出しにおけるレシーバ(この例ではhoge)を取得します。
		Object_* invR = cll->getLock(true);
		//このスタックフレームの情報を保存します
		//例外がスローされたときに使用されます
		MessageInfo* info = new MessageInfo(cll, classz, m);
		MessageQueue::getInstance()->push(info);
		Object_* retVal = m->execute(invR, args);
		MessageQueue::getInstance()->pop();
		ClassLoader::popCurrentClassLoader();
		//例外をこのメソッドを呼び出したオブジェクトへ伝播
		return retVal;
	}
	return nullptr;
}

Function * ASTMethodInvocationBySelf::findTopLevelFunction(FunctionManager * fm, std::string name, int argc) {
	if (!cacheCompiled) {
		Function* f = fm->findFunction(name, argc);
		this->cacheTopLevelFunction = f;
	}
	return cacheTopLevelFunction;
}

Method * ASTMethodInvocationBySelf::findSelfMethod(ClassSPtr classz, std::string name, int argc) {
	if (!cacheCompiled) {
		Method* method = classz->findMethod(name, argc, false);
		this->cacheSelfMethod = method;
	}
	return cacheSelfMethod;
}
//---private method
