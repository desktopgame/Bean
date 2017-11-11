#include "NativeCastException.h"
#include <type_traits>
//public method---
NativeCastException::NativeCastException(std::string msg) 
 : std::logic_error(msg) {
}

NativeCastException::~NativeCastException() {
}
//---public method