#include "BeanRuntimeException.h"

BeanRuntimeException::BeanRuntimeException(const std::string& err) 
 : std::logic_error(err) {
}

BeanRuntimeException::BeanRuntimeException() 
 : BeanRuntimeException("empty") {
}

BeanRuntimeException::~BeanRuntimeException() {
}
