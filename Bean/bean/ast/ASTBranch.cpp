#include "ASTBranch.h"

//public method---
ASTBranch::ASTBranch() {
	this->children = std::vector<ASTNodeSPtr>();
}

ASTBranch::~ASTBranch() {
	children.clear();
}

void ASTBranch::add(ASTNodeSPtr child) {
	if (child == nullptr
		/*	|| dynamic_cast<ASTEmptyBody*>(child) != nullptr */) {
		return;
	}
	this->children.push_back(child);
}

void ASTBranch::insert(ASTNodeSPtr child, int index) {
	if (child == nullptr) {
		return;
	}
	this->children.insert(children.begin() + index, child);
}

void ASTBranch::remove(int index) {
	const ASTNodeSPtr child = children.at(index);
	children.erase(children.begin() + index);
//	child->deleteSelf();
//	delete child;
}

void ASTBranch::clear() {
	this->children.clear();
}

ASTNodeSPtr ASTBranch::getChildrenAt(int index) const {
	return this->children.at(index);
}

int ASTBranch::getChildrenCount() const {
	return this->children.size();
}
IMPL_MAKE_SHARED_0_CPP(ASTBranch)
//---public method

//protected method---
void ASTBranch::accept(ASTVisitor * visitor) {
	visitor->enter(SHARED_FROM_THIS(ASTBranch));
	for (int i = 0; i < getChildrenCount(); i++) {
		getChildrenAt(i)->accept(visitor);
	}
	visitor->exit(SHARED_FROM_THIS(ASTBranch));
}

std::string ASTBranch::format() const {
	return "branch";
}
//---protected method