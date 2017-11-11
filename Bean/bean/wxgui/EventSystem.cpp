#include "EventSystem.h"
#include "../env/ClassLoader.h"
#include "../env/Delegate.h"
#include "../threads/Thread.h"
#include "../env/gc/Block.h"
#include "../env/gc/Heap.h"
#include "../env/user/UserDelegate.h"

//public method---
EventSystem::EventSystem() {
}

EventSystem::~EventSystem() {
}

void EventSystem::markRef(ListenerRList rlist, ListenerVList vlist) {
	for (UserDelegate* ud : vlist) {
		ud->markTree();
	}
	for (Object_* obj : rlist) {
		ObjectStateSPtr state = obj->getState();
		state->setMarked(true);
		state->setProgress(GCProgress::Pending);
	//	Heap::getInstance()->writeBarrier(obj);
	}
}

void EventSystem::postEvent(ListenerVList vlist, std::vector<Object_*> args) {
	if (vlist.empty()) {
		return;
	}
//	Heap::getInstance()->lock();
	for (int i = 0; i < vlist.size(); i++) {
		UserDelegate* ud = vlist.at(i);
		ClassLoaderSPtr cls = ud->getCapture();
		ClassLoader::pushCurrentClassLoader(cls);
		Block::pushCurrent();
		Delegate* dd = ud->getDelegate();
		dd->call(Thread::getCurrent(), cls, args);
		Block::popCurrent();
		ClassLoader::popCurrentClassLoader();
	}
//	Heap::getInstance()->miniGC();
//	Heap::getInstance()->unlock();
}
//---public method
