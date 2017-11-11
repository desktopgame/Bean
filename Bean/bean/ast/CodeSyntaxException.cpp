#include "CodeSyntaxException.h"

//public method---
CodeSyntaxException::CodeSyntaxException(std::string msg) 
 : std::logic_error(msg) {
}

CodeSyntaxException::~CodeSyntaxException() {
}

void CodeSyntaxException::throw_(std::string msg) {
	throw CodeSyntaxException(msg);
}

void CodeSyntaxException::re_throw(CodeSyntaxException e) {
	throw e;
}
//---public method
