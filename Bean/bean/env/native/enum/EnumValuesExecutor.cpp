#include "EnumValuesExecutor.h"
#include "../../Enum.h"
#include "../../Field.h"
#include "../../MessageInfo.h"
#include "../../MessageQueue.h"
#include "../../user/UserArray.h"

//public method---
EnumValuesExecutor::EnumValuesExecutor() {
}

EnumValuesExecutor::~EnumValuesExecutor() {
}

Object_ * const EnumValuesExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	MessageQueueSPtr queue = MessageQueue::getInstance();
	const MessageInfo* info = queue->top();
	std::shared_ptr<Enum> enumClass = std::dynamic_pointer_cast<Enum>(info->getClass());
//	Enum* enumClass = static_cast<Enum*>(info->getClass());
	std::vector<Field*> fields = enumClass->getFields();
	//Bean‚Ì”z—ñ‚Å•Ô‚·
	UserArray* enumArr = new UserArray();
	enumArr->alloc(fields.size());
	for (int i = 0; i < fields.size(); i++) {
		enumArr->set(i, fields.at(i)->getValue(nullptr));
	}
	return enumArr;
}
//---public method
