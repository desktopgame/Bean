#include "GCLock.h"
#include "Heap.h"

GCLock::GCLock() {
	Heap::getInstance()->lock();
}

GCLock::~GCLock() {
	Heap::getInstance()->unlock();
}
