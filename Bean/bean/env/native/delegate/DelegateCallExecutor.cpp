#include "DelegateCallExecutor.h"
#include "../../../env/ClassLoader.h"
#include "../../../env/Delegate.h"
#include "../../../env/gc/Block.h"
#include "../../../env/user/UserArray.h"
#include "../../../env/user/UserDelegate.h"

//public method---
DelegateCallExecutor::DelegateCallExecutor() {
}

DelegateCallExecutor::~DelegateCallExecutor() {
}

Object_ * const DelegateCallExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	ClassLoaderSPtr cll = ClassLoader::getCurrentClassLoader();
	UserDelegate* ud = invoker->asUserDelegate();
	Object_* arg = args.at(0);
	UserArray* arr = arg->asUserArray();
	std::vector<Object_*> argsArr = std::vector<Object_*>();
	Block::pushCurrent();
	//配列ではなくnullが渡されたら全てnullで渡す
	if (arr == nullptr && arg == getNull()) {
		for (int i = 0; i < ud->getDelegate()->requestArgumentCount(); i++) {
			argsArr.push_back(getNull());
		}
	//配列が渡されたら別の参照でラップする
	} else {
		arr = arg_cast(UserArray, 0, "Array");
		for (int i = 0; i<ud->getDelegate()->requestArgumentCount(); i++) {
			//より多い要素数が要求されているが、
			//渡された配列の長さが足りないのでnullで埋める
			if (i >= arr->getLength()) {
				argsArr.push_back(getNull());
			} else {
				argsArr.push_back(arr->get(i));
			}
		}
	}
	ClassLoader::pushCurrentClassLoader(ud->getCapture());
	Object_* retVal = ud->getDelegate()->call(nullptr, ud->getCapture(), argsArr);
	Block::popCurrent();
	ClassLoader::popCurrentClassLoader();
	return retVal;
}
//---public method
