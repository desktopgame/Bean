#include "NotImplException.h"

//public method---
NotImplException::NotImplException() 
 : std::logic_error("not implemented of this function") {
}

NotImplException::~NotImplException() {
}
//---public method