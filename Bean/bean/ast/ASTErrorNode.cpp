#include "ASTErrorNode.h"

//public method---
ASTErrorNode::ASTErrorNode() 
 : ASTErrorNode("empty") {
}

ASTErrorNode::ASTErrorNode(const std::string& message) {
	this->message = message;
}

ASTErrorNode::~ASTErrorNode() {
}

std::string ASTErrorNode::getMessage() const {
	return this->message;
}
IMPL_MAKE_SHARED_0_CPP(ASTErrorNode)
IMPL_MAKE_SHARED_1_CPP(ASTErrorNode, const std::string&)
//---public method