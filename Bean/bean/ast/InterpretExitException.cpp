#include "InterpretExitException.h"
//public method---
InterpretExitException::InterpretExitException(std::string msg) 
 : std::logic_error(msg) {
}

InterpretExitException::~InterpretExitException() {
}
//---public method