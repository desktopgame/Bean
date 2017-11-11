#pragma once
#ifndef BEAN_POINTER_VARIABLEPOINTER_H
#define BEAN_POINTER_VARIABLEPOINTER_H
#include "Pointer.h"
#include "../../ast/ASTVariable.h"
class VariablePointer : public Pointer {
public:
	VariablePointer(std::shared_ptr<ASTVariable> variable);
	~VariablePointer();

	// Pointer ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	void setValue(Object_ * obj) override;
	Object_ * getValue() override;
	bool isAssignable() override;
	std::string getLocation() override;

private:
	Field* getField();
	Field* cache;
	std::weak_ptr<ASTVariable> variable;
};
#endif // !BEAN_POINTER_VARIABLEPOINTER_H
