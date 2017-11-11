#include "ExceptionHandle.h"
#include "../../env/Class.h"
#include "../../env/Method.h"
#include "../../env/Object_.h"
#include "../../env/Object_.h"
#include "../../env/String.h"
#include "../../threads/Thread.h"
#include "../../env/gc/GCLock.h"

#include "../../util/Console.h"

//public method---
ExceptionHandle::ExceptionHandle() {
	this->children = std::vector<ExceptionHandle*>();
}

ExceptionHandle::~ExceptionHandle() {
	while (!children.empty()) {
		ExceptionHandle* child = children.at(0);
		children.erase(children.begin());
		delete child;
	}
}

void ExceptionHandle::printException(Thread * t, Object_ * e) {
	GCLock gcLock = GCLock();
	//例外情報を取得
	Object_* eVal = e;
	ClassSPtr eClass = eVal->getClass();
	Method* eGetMessageMethod = eClass->findMethod("getMessage", 0, false);
	std::string eMessage = "No Message";
	//例外オブジェクト#getMessageでメッセージを取得
	if (eGetMessageMethod != nullptr) {
		std::string clName = eClass->getName();
		Object_* eMessageRef = eVal->execute("getMessage");
		Object_* eMessageObj = eMessageRef;
		bool b = eMessageRef == nullptr;
		String* eMessageStr = eMessageObj->asString();
		if (eMessageStr != nullptr) {
			eMessage = *eMessageStr->getCString();
		}
	}
	//コールスタックを取得
	std::vector<std::string> lines = Thread::getCurrent()->getQueue()->dumpLines();
	//全ての情報を出力
	Console::println(eClass->getName() + " : " + eMessage);
	Console::println("thread name:" + t->getName());
//	std::cout << eClass->getName() << " : " << eMessage << std::endl;
//	std::cout << "thread name:" << t->getName() << std::endl;
	for (std::string line : lines) {
		Console::println("    at " + line);
//		std::cout << "    at " << line << std::endl;
	}
}
//---public method

//protected method---
void ExceptionHandle::addHandle(ExceptionHandle * handle) {
	this->children.push_back(handle);
}

void ExceptionHandle::removeHandle(ExceptionHandle * handle) {
	for (int i = 0; i < children.size(); i++) {
		ExceptionHandle* ele = children.at(i);
		if (ele == handle) {
			children.erase(children.begin() + i);
			break;
		}
	}
}

void ExceptionHandle::fire(Thread * t, Object_ * e) {
	for (ExceptionHandle* eh : children) {
		eh->onException(t, e);
	}
}
//---protected method
