#include "ConsoleWriteExecutor.h"
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
#include "../../Null.h"
#include "../../Object_.h"
#include "../../String.h"
#include "../../../util/Console.h"
//public method---
ConsoleWriteExecutor::ConsoleWriteExecutor() {
}

ConsoleWriteExecutor::~ConsoleWriteExecutor() {
}

Object_ * const ConsoleWriteExecutor::execute(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	Object_* argObj0 = args.at(0);
	Object_* retVal = argObj0->execute("toString");
	String* str = retVal->asString();
	print__(str);
	return Null::getInstance();
}
//---public method

//private method---
void ConsoleWriteExecutor::print__(String * str) {
#if defined(BTEXT_MULTI)
	Console::print(*str->getCString());
#elif defined(BTEXT_WIDE)
	Console::print(*str->getCString());
#endif
}
//---private method
