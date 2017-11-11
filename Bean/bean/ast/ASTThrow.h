#pragma once
#ifndef BEAN_AST_ASTTHROW_H
#define BEAN_AST_ASTTHROW_H
#include "ASTNode.h"
/**
 * throw��.
 */
class ASTThrow : public ASTNode {
public:
	ASTThrow();
	~ASTThrow();
	/**
	 * ���̕����X���[�����O�ւ̎Q�Ƃ�ݒ肵�܂�.
	 * @param factor
	 */
	void setFactor(std::shared_ptr<ASTFactor> factor);

	/**
	 * ���̕����X���[�����O�ւ̎Q�Ƃ�Ԃ��܂�.
	 * @return
	 */
	std::shared_ptr<ASTFactor> getFactor() const;
	void accept(ASTVisitor* visitor) override;
	std::string format() const override;
	DECL_MAKE_SHARED_0_H(ASTThrow)
protected:
private:
	std::shared_ptr<ASTFactor> factor;
};
#endif // !BEAN_AST_ASTTHROW_H


