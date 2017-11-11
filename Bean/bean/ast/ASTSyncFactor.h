#pragma once
#ifndef BEAN_AST_ASTSYNCFACTOR_H
#define BEAN_AST_ASTSYNCFACTOR_H
#include "ASTFactor.h"
/**
 * �K�x�[�W�R���N�^�ɑ΂��ē��������ꂽ�t�@�N�^�ł�.
 */
class ASTSyncFactor : public ASTFactor {
public:
	ASTSyncFactor(std::shared_ptr<ASTFactor> factor);
	~ASTSyncFactor();

	// ASTFactor ����Čp������܂���
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