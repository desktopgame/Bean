#include "ConsoleReadLineExecutor.h"
#include "../../String.h"

//public method---
ConsoleReadLineExecutor::ConsoleReadLineExecutor() {
}

ConsoleReadLineExecutor::~ConsoleReadLineExecutor() {
}

Object_ * const ConsoleReadLineExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	if (Text::isMulti()) {
		std::string line;
		std::cin >> line;
		return String::allocString(line);
	} else {
		std::wstring line;
		std::wcin >> line;
		std::string fixedLine = std::string(line.begin(), line.end());
		return String::allocString(fixedLine);
	}
}
//---public method