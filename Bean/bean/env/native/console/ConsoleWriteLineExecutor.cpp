#include "ConsoleWriteLineExecutor.h"
#include <codecvt>
#include <iostream>
#include <sstream>
#include <string>
#include "../../Class.h"
#include "../../Null.h"
#include "../../Object_.h"
#include "../../String.h"
#include "../../gc/Heap.h"
#include "../../../util/Console.h"
#include "../../../util/Memory.h"

//public method---
ConsoleWriteLineExecutor::ConsoleWriteLineExecutor() {
}

ConsoleWriteLineExecutor::~ConsoleWriteLineExecutor() {
}

Object_ * const ConsoleWriteLineExecutor::execute(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	Object_* argObj0 = args.at(0);
	Object_* retVal = argObj0->execute("toString");
	String* str = retVal->asString();
	println__(str);
	return Null::getInstance();
}
//---public method

//private method---
void ConsoleWriteLineExecutor::println__(String * str) {
#if defined(BTEXT_WIDE)
	std::string s = *str->getCString();
	Console::println(s);
#elif defined(BTEXT_MULTI)
	std::string s = *str->getCString();
	Console::println(s);
#endif
}
//---private method
