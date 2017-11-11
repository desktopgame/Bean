#include "ClassFormatException.h"

//public method---
ClassFormatException::ClassFormatException(std::string msg) 
 : std::logic_error(msg) {
}

ClassFormatException::~ClassFormatException() {
}
//---public method