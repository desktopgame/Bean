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
	//�z��ł͂Ȃ�null���n���ꂽ��S��null�œn��
	if (arr == nullptr && arg == getNull()) {
		for (int i = 0; i < ud->getDelegate()->requestArgumentCount(); i++) {
			argsArr.push_back(getNull());
		}
	//�z�񂪓n���ꂽ��ʂ̎Q�ƂŃ��b�v����
	} else {
		arr = arg_cast(UserArray, 0, "Array");
		for (int i = 0; i<ud->getDelegate()->requestArgumentCount(); i++) {
			//��葽���v�f�����v������Ă��邪�A
			//�n���ꂽ�z��̒���������Ȃ��̂�null�Ŗ��߂�
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
