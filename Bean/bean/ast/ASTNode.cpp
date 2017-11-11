#include "ASTNode.h"
#include "ASTBranch.h"
#include "../Debug.h"
#include "visitor/ASTPrintVisitor.h"
#include "../threads/Thread.h"
#include "../env/gc/Block.h"
//public method---
ASTNode::ASTNode() {
	this->isSingleton = false;
	this->startOffset = 0;
	this->endOffset = 0;
}

void ASTNode::setStartOffset(int startOffset) {
	this->startOffset = startOffset;
}

int ASTNode::getStartOffset() const {
	return this->startOffset;
}

void ASTNode::setEndOffset(int endOffset) {
	this->endOffset = endOffset;
}

int ASTNode::getEndOffset() const {
	return this->endOffset;
}

void ASTNode::dump() {
	ASTPrintVisitor visitor = ASTPrintVisitor();
	visit(&visitor);
}

bool ASTNode::thrown() {
	auto thr = Thread::getCurrent();
	auto ret = thr->wasThrownException();
	//Debug::break_if(ret);
	return ret;
}

void ASTNode::visit(ASTVisitor * visitor) {
	visitImpl(this, visitor);
}

std::string ASTNode::format() const {
	return "empty";
}

void ASTNode::accept(ASTVisitor * visitor) {
	visitor->enter(shared_from_this());
	visitor->exit(shared_from_this());
}
//---public method


//protected method---
ASTNode::~ASTNode() {
}

void ASTNode::buffer_begin() {
	Block::pushCurrent();
}

void ASTNode::buffer_end() {
	Block::popCurrent();
}

void ASTNode::accept_(ASTVisitor* visitor, std::shared_ptr<ASTNode> node) {
	if (node != nullptr) {
		node->accept(visitor);
	}
}
//---protected method

//private method---
void ASTNode::visitImpl(ASTNode * root, ASTVisitor * visitor) {
	root->accept(visitor);
}
//---private method
