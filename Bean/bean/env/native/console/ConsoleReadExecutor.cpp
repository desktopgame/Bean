#include "ConsoleReadExecutor.h"

//public method---
ConsoleReadExecutor::ConsoleReadExecutor() {
}

ConsoleReadExecutor::~ConsoleReadExecutor() {
}

Object_ * const ConsoleReadExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	//���݂̕������[�h�ɍ��킹�ĕύX
	if (Text::isMulti()) {
		char c;
		std::cin >> c;
		return getCharacter(c);
	} else {
		wchar_t c;
		std::wcin >> c;
		return getCharacter(c);
	}
}
//---public method