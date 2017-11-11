#include "MessageQueue.h"
#include "../threads/Thread.h"

//public method---
MessageQueue::MessageQueue() {
	this->msgVec = std::stack<MessageInfo*>();
}

MessageQueue::~MessageQueue() {
	clear();
}

MessageQueueSPtr MessageQueue::getInstance() {
	ThreadSPtr cur = Thread::getCurrent();
	if (cur == NULL) {
		return nullptr;
	}
	return cur->getQueue();
}

void MessageQueue::push(MessageInfo* info) {
	this->msgVec.push(info);
}

void MessageQueue::pop() {
	if (msgVec.empty()) return;
	MessageInfo* top = msgVec.top();
	msgVec.pop();
	delete top;
}

const MessageInfo * MessageQueue::top() {
	return msgVec.top();
}

void MessageQueue::clear() {
	while (!msgVec.empty()) {
		MessageInfo* i = msgVec.top();
		msgVec.pop();
		delete i;
	}
}

std::vector<std::string> MessageQueue::dumpLines() {
	std::vector<std::string> ret = std::vector<std::string>();
	while (!msgVec.empty()) {
		MessageInfo* i = msgVec.top();
		msgVec.pop();
		ret.push_back(i->getLocation());
		delete i;
	}
	return ret;
}

bool MessageQueue::empty() {
	return msgVec.empty();
}
//---public method
