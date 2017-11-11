#include "ASTMethodInvocationByMessage.h"
#include "ASTName.h"
#include "ASTNode.h"
#include "ASTSuperFactor.h"
#include "ASTVariable.h"
#include "../Debug.h"
#include "../env/Class.h"
#include "../env/ClassLoader.h"
#include "../env/Delegate.h"
#include "../env/DelegateMethod.h"
#include "../env/IncludeManager.h"
#include "../env/Method.h"
#include "../env/Null.h"
#include "../env/Numeric.h"
#include "../env/Parameter.h"
#include "../env/String.h"
#include "../util/TimeSpan.h"
#include "../env/gc/Block.h"
#include "../env/gc/GCLock.h"
#include "../env/user/UserDelegate.h"

//public method---
ASTMethodInvocationByMessage::ASTMethodInvocationByMessage() {
	this->cacheCompiled = false;
	this->cacheMethodStatic = nullptr;
	this->cacheMethodDynamic = nullptr;
}

ASTMethodInvocationByMessage::~ASTMethodInvocationByMessage() {
	delete this->cacheMethodDynamic;
}

void ASTMethodInvocationByMessage::setInvoker(std::shared_ptr<ASTFactor> invoker) {
	this->invoker = invoker;
}

std::shared_ptr<ASTFactor> ASTMethodInvocationByMessage::getInvoker() const {
	return this->invoker;
}

Object_ * ASTMethodInvocationByMessage::eval() {
	buffer_begin();
	Object_* retV = evalImpl();
	buffer_end();
	return retV;
}

std::shared_ptr<ASTMethodInvocationByMessage> ASTMethodInvocationByMessage::asByMessage() {
	std::shared_ptr<ASTNode> obj = shared_from_this();
	return std::dynamic_pointer_cast<ASTMethodInvocationByMessage>(obj);
}

std::string ASTMethodInvocationByMessage::format() const {
	return "invoke by-message";
}

void ASTMethodInvocationByMessage::accept(ASTVisitor * visitor) {
	visitor->enter(SHARED_FROM_THIS(ASTMethodInvocation));
	visitor->exit(SHARED_FROM_THIS(ASTMethodInvocation));
}
IMPL_MAKE_SHARED_0_CPP(ASTMethodInvocationByMessage)
//---public method


//private method---
Object_ * ASTMethodInvocationByMessage::evalImpl() {
	int dep = Block::getInstance()->getDepth();
	//このメソッドを実行するオブジェクトを取得する
	//クラス名のみの場合はstaticメソッドの呼び出し
	Object_* invoker = nullptr;
	std::shared_ptr<ASTFactor> invokerNode = getInvoker();
	if (invokerNode != nullptr) {
		invoker = invokerNode->eval();
		Block::entry(invoker);
	}
	//この処理を実行しているクラスローダー
	//staticメソッドにおいては、
	//名前空間を解決するためにそのクラスでインクルードされているクラス名と照会するのに使用されます。
	//非staticメソッドにおいては、
	//このメソッドの呼び出しに含まれるメソッドの呼び出しにおいて、
	//このメソッドを呼び出しているオブジェクト自身をレシーバとして設定します。
	//つまり、以降の hoge() のような名前なし呼び出しはこのメソッドを実行しているオブジェクトが実行します。
	ClassLoaderSPtr cll = ClassLoader::getCurrentClassLoader();
	Object_* retVal = nullptr;
	std::shared_ptr<ASTSuperFactor> superF = std::dynamic_pointer_cast<ASTSuperFactor>(invokerNode);
	if (superF != nullptr) {
		invoker = cll->getLock();
	}
	//staticメソッドの呼び出し
	if (invoker == nullptr && superF == nullptr) {
		//実行されるメソッドを検索します
		std::shared_ptr<ASTVariable> vNameNode = std::dynamic_pointer_cast<ASTVariable>(invokerNode);
		std::string vName = vNameNode->getName()->getCString();
		std::string mName = getName()->getCString();
		ClassSPtr classz = findClassStatic(cll, vName);
		//指定のクラスが見つからない
		if (classz == nullptr) {
			throwNoClassError(cll, vName);
			return Null::getInstance();
		}
		Method* method = findMethodStatic(classz, mName, getArgumentCount());
		//メソッドが見つからない
		if (method == nullptr) {
			throwNoMethodError(cll, classz->getName(), getName()->getCString(), getArgumentCount());
			return Null::getInstance();
		}
		//実引数の作成
		std::vector<Object_*> args = getEvalArguments(method);
		//引数を計算しているときに例外が発生した場合
		if (thrown()) {
			return Null::getInstance();
		}
		//引数の作成
		//これを行わないとコンストラクタ呼び出しで変数を参照出来ない
		ClassLoaderSPtr cll = method->getClass().lock()->getClassLoader().lock();
		CodeBlock* cdb = cll->getCodeBlock();
		cdb->enter(false);
		buffer_begin();
		for (int i = 0; i < method->getParameterCount(); i++) {
			cdb->writeReference(
				method->getParameterAt(i)->getName(),
				args.at(i)
			);
		}
		buffer_end();
		//このスタックフレームの情報を保存します
		//例外がスローされたときに使用されます
		MessageInfo* info = new MessageInfo(cll, classz, method);
		MessageQueue::getInstance()->push(info);
		//実行
		Object_* retValRef = method->execute(invoker, args);
		MessageQueue::getInstance()->pop();
		cdb->exit(true);
		retVal = retValRef;
		return retVal;
	//インスタンスメソッド
	} else {
		//メソッドの検索開始位置を指定
		ClassSPtr classz = invoker->getClass();
		ClassSPtr s = classz;
		classz = invokerNode->getBaseLine(classz);
		//二回目以降はキャッシュから引き出す
		Method* method = findMethodDynamic(invoker, classz, getName()->getCString(), getArgumentCount());
		//メソッドが見つからない
		if (method == nullptr) {
			throwNoMethodError(cll, classz->getName(), getName()->getCString(), getArgumentCount());
			return Null::getInstance();
		}
		classz = method->getClass().lock();
		//引数の作成
		buffer_begin();
		std::vector<Object_*> args = getEvalArguments(method);
		buffer_end();
		//引数を計算しているときに例外が発生した場合
		if (thrown()) {
			return Null::getInstance();
		}
		//このメソッドを実行しているクラスのクラスローダーを
		//"現在処理しているクラスローダー" に設定します。
		auto newCll = classz->getClassLoader().lock();
		ClassLoader::pushCurrentClassLoader(newCll);
		//今後の名前なし呼び出しがこのメソッドを呼び出しているオブジェクト自体に
		//バインドされるようにロックします。
		classz->getClassLoader().lock()->lockInstance(invoker);
		//このスタックフレームの情報を保存します
		//例外がスローされたときに使用されます
		MessageInfo* info = new MessageInfo(cll, classz, method);
		MessageQueue::getInstance()->push(info);
		//実行
		//super#hoge のような呼び出しでも、
		//Method#executeで実装クラスのクラスローダーが設定されてしまうので、
		//superのときクラスローダーを設定しないフラグを設定する
		Object_* retValRef = method->execute(invoker, args, superF == nullptr);
		MessageQueue::getInstance()->pop();
		retVal = retValRef;
		//buffer_end();
		//ロックを解除します。
		classz->getClassLoader().lock()->unlockInstance();
		//"現在処理しているクラスローダー" をもとに戻します。
		ClassLoader::popCurrentClassLoader();
		return retVal;
	}
}

ClassSPtr ASTMethodInvocationByMessage::findClassStatic(ClassLoaderSPtr cll, std::string name) {
	if (!cacheCompiled) {
		ClassSPtr classz = cll->getIncludeManager()->getClass(name);
		this->cacheClassStatic = classz;
	//	this->cacheCompiled = true;
	}
	return cacheClassStatic;
	//return cll->getIncludeManager()->getClass(name);
}

Method * ASTMethodInvocationByMessage::findMethodStatic(ClassSPtr classz, std::string name, int argc) {
	if (!cacheCompiled) {
		Method* method = classz->findMethod(name, argc, false);
		this->cacheMethodStatic = method;
	//	this->cacheCompiled = true;
	}
	return cacheMethodStatic;
}

Method * ASTMethodInvocationByMessage::findMethodDynamic(Object_* obj, ClassSPtr classz, std::string name, int argc) {
	UserDelegate* ud = obj->findDynMethod(name, argc);
	if (ud != nullptr && ud->getDelegate()->requestArgumentCount() == argc) {
		delete this->cacheMethodDynamic;
		this->cacheMethodDynamic = new DelegateMethod(obj, name, ud);
		return cacheMethodDynamic;
	}
	Method* method = classz->findMethod(name, argc, true);
	return method;
}
//---private method
