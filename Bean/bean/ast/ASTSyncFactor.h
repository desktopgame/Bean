#pragma once
#ifndef BEAN_AST_ASTSYNCFACTOR_H
#define BEAN_AST_ASTSYNCFACTOR_H
#include "ASTFactor.h"
/**
 * ガベージコレクタに対して同期化されたファクタです.
 */
class ASTSyncFactor : public ASTFactor {
public:
	ASTSyncFactor(std::shared_ptr<ASTFactor> factor);
	~ASTSyncFactor();

	// ASTFactor を介して継承されました
	ClassSPtr getBaseLine(ClassSPtr classz) override;
	Object_ * eval() override;
	bool isStaticReceiver() override;
	std::string getStaticClassName() override;
	void accept(ASTVisitor* visitor) override;
	DECL_MAKE_SHARED_1_H(ASTSyncFactor, std::shared_ptr<ASTFactor>)
private:
	std::shared_ptr<ASTFactor> factor;
};
#endif