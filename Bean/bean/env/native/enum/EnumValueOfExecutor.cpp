#include "EnumValueOfExecutor.h"
#include "../../Enum.h"
#include "../../Field.h"
#include "../../MessageInfo.h"
#include "../../MessageQueue.h"
#include "../../String.h"

//public method---
EnumValueOfExecutor::EnumValueOfExecutor() {
}

EnumValueOfExecutor::~EnumValueOfExecutor() {
}

Object_ * const EnumValueOfExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	String* name = arg_cast(String, 0, "String");

	MessageQueueSPtr queue = MessageQueue::getInstance();
	const MessageInfo* info = queue->top();
	std::shared_ptr<Enum> enumClass = std::dynamic_pointer_cast<Enum>(info->getClass());
//	Enum* enumClass = static_cast<Enum*>(info->getClass());
	Field* enumField = enumClass->findField(*name->getCString());
	if (enumField == nullptr) {
		return getNull();
	}
	//—ñ‹“Žq‚ÍÄ‘ã“ü•s‰Â‚È‚Ì‚Å•¡»‚µ‚Ä•Ô‚·
	return enumField->getValue(nullptr);
}
//---public method
