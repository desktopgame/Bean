#pragma once
#ifndef BEAN_AST_ASTSYNCOPERATOR_H
#define BEAN_AST_ASTSYNCOPERATOR_H
#include "ASTOperator.h"
class ASTSyncOperator : public ASTOperator {
public:
	ASTSyncOperator(std::shared_ptr<ASTOperator> op);
	~ASTSyncOperator();

	ClassSPtr getBaseLine(ClassSPtr classz) override;
	Object_ * eval() override;
	bool isStaticReceiver() override;
	std::string getStaticClassName() override;
	void accept(ASTVisitor* visitor) override;

	DECL_MAKE_SHARED_1_H(ASTSyncOperator, std::shared_ptr<ASTOperator>)
private:
	std::shared_ptr<ASTOperator> op;
};
#endif // !BEAN_AST_ASTSYNCOPERATOR_H
