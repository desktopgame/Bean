#include "TimeSpan.h"
#include <algorithm>
#include <iostream>

//public method---
TimeSpan::TimeSpan() {
}

TimeSpan::~TimeSpan() {
}

void TimeSpan::start() {
	this->startClock = std::chrono::system_clock::now();
}

void TimeSpan::end() {
	this->endClock = std::chrono::system_clock::now();
}

void TimeSpan::print(const std::string& s) {
	double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(endClock - startClock).count();
	std::cout << s << " " << elapsed << std::endl;
}

void TimeSpan::print() {
	print("elapsed:");
}
//---public method
