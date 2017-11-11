#include "Constructor_.h"
#include "Class.h"
#include "Class.h"
#include "ClassLoader.h"
#include "CodeBlock.h"
#include "Exception.h"
#include "Null.h"
#include "Object_.h"
#include "Parameter.h"
#include "gc/Block.h"
#include "gc/GCLock.h"
#include "native/NativeCastException.h"
#include "user/UserObject.h"
#include "../ast/ASTFactor.h"

//public method---
Constructor_::Constructor_(ClassSPtr classz, Modifier modifier, std::string name, Method* proxy)
	: Method(classz, modifier, name) {
	this->proxy = proxy;
	this->deleteProxy = true;
}

Constructor_::~Constructor_() {
	if (deleteProxy) {
		delete proxy;
	}
}

void Constructor_::setChain(std::shared_ptr<ASTConstructorChain> chain) {
	this->chain = chain;
}

std::shared_ptr<ASTConstructorChain> Constructor_::getChain() const {
	return this->chain;
}

void Constructor_::addParameter(Parameter * param) {
	Method::addParameter(param);
	proxy->addParameter(new Parameter(param->getName()));
}

Parameter * const Constructor_::getParameterAt(int index) const {
	return proxy->getParameterAt(index);
}

void Constructor_::removeParameterAt(int index) {
	Method::removeParameterAt(index);
	proxy->removeParameterAt(index);
}

int Constructor_::getParameterCount() const {
	return proxy->getParameterCount();
}

Object_ * const Constructor_::execute(Object_ * const invoker, std::vector<Object_*> args, bool currentClassLoader) {
	GCLock gcLock = GCLock();
	int dep = Block::getInstance()->getDepth();
	Object_* instance = nullptr;
	try {
		//遷移先がない
		if (getChain() == nullptr) {
			instance = getProxy()->newObject(getClass().lock(), this, args);
		//あるならそっちを優先
		} else {
			Block::pushCurrent();
			auto chain = getChain();
			auto target = getChain()->find(this);
			auto newArgs = std::vector<Object_*>();
			auto curClass = getClass().lock();
			curClass = curClass->getSuper().lock();
			auto cll = curClass->getClassLoader().lock();
			//コンストラクタが二つ以上チェインするとき
			//変数が参照出来なくなるのでここで書き込む
			auto cdb = cll->getCodeBlock();
			ClassLoader::pushCurrentClassLoader(cll);
			cdb->enter(false);
			auto proxy = getProxy();
			for (int i = 0; i < args.size(); i++) {
				cdb->writeReference(
					getProxy()->getParameterAt(i)->getName(),
					args.at(i)
				);
			}
			//HogeClass() : super(x, y, z)
			//の x, y, z を計算する
			for (int i = 0; i < chain->getArgumentCount(); i++) {
				newArgs.push_back(chain->getArgumentAt(i)->eval());
			}
			instance = target->execute(invoker, newArgs, currentClassLoader);
			cdb->exit(true);
			ClassLoader::popCurrentClassLoader();
			Block::popCurrent();
			//このままだと委譲先コンストラクタのクラス型になってしまうので修正する
			instance->chainConstruct(getClass().lock());
		}
	} catch (NativeCastException e) {
		Exception::throw_e_wrap("api.exc.TypeCastError", e);
		return Null::getInstance();
	}
	Object_* retVal = instance;
	ClassWPtr cls = getClass();
	ClassSPtr clsSptr = cls.lock();
	ClassLoaderWPtr cll = clsSptr->getClassLoader();
	ClassLoaderSPtr cllSptr = cll.lock();
	//コンストラクタを呼び出すために、
	//生成されたオブジェクトを現在のクラスローダーにバインドします。
	//メソッド内部で名前なしの呼び出し( hoge() )が行われたとき、生成されたオブジェクト自身がこれを実行します。
	cllSptr->lockInstance(retVal);
	Object_* nullRetVal = proxy->execute(retVal, args);
	//バインドを解除します。
	cllSptr->unlockInstance();
	return retVal;
}

Method * const Constructor_::getProxy() const {
	return proxy;
}
//---public method
