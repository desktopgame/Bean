#include "HeapMutexLock.h"
#include "Heap.h"

HeapMutexLock::HeapMutexLock() {
	Heap::getInstance()->enter();
}

HeapMutexLock::~HeapMutexLock() {
	Heap::getInstance()->exit();
}
