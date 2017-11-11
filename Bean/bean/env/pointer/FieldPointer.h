#pragma once
#ifndef BEAN_ENV_POINTER_FIELDPOINTER_H
#define BEAN_ENV_POINTER_FIELDPOINTER_H
#include "Pointer.h"
#include "../../ast/ASTFieldAccess.h"
class FieldPointer : public Pointer {
public:
	FieldPointer(std::shared_ptr<ASTFieldAccess> fieldAccess);
	~FieldPointer();

	// Pointer ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	void setValue(Object_ * obj) override;
	void setValue(Object_* inv, Object_* obj);
	Object_ * getValue() override;
	Object_* getValue(Object_* inv);
	bool isAssignable() override;
	std::string getLocation() override;

private:
	Object_* getInvoker();
	Field* getField();
	Field* cache;
	std::weak_ptr<ASTFieldAccess> fieldAccess;
};
#endif // !BEAN_ENV_POINTER_FIELDPOINTER_H
