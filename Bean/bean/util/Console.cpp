#include "Console.h"
#include <iostream>
#include <sstream>
//public method---
void Console::print(const std::string & str) {
#if defined(BTEXT_MULTI)
	printf(str.c_str());
#endif // defined(BTEXT_MULTI)
#if defined(BTEXT_WIDE)
	printf(str.c_str());
#endif // defined(BTEXT_WIDE)
}

void Console::println(const std::string & str) {
	std::stringstream ss;
	ss << str.c_str();
	ss << std::endl;
	printf(ss.str().c_str());
}

BString Console::readln() {
#ifdef BTEXT_MULTI
	std::string line;
	std::getline(std::cin, line);
	return line;
#endif // BTEXT_MULTI
#ifdef BTEXT_WIDE
	std::wstring line;
	std::getline(std::wcin, line);
	//	std::wcin >> line;
	return line;
	//	return std::wstring(line.begin(), line.end());
#endif // BTEXT_WIDE
}
//---public method

//private method---
Console::Console() {
}

Console::~Console() {
}
//---private method
