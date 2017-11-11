#pragma once
#ifndef BEAN_AST_ASTARRAYINITIALIZER_H
#define BEAN_AST_ASTARRAYINITIALIZER_H
#include <vector>
#include "ASTFactor.h"
/**
 * �z������������邽�߂̍\���ł�.
 * var hoge = { aaa, bbb, ccc };
 */
class ASTArrayInitializer : public ASTFactor {
public:
	ASTArrayInitializer();
	~ASTArrayInitializer();
	/**
	 * ���̔z�񏉊����Ɋ܂܂��v�f��ǉ����܂�.
	 * @param factor
	 */
	void addFactor(ASTFactorSPtr factor);

	/**
	 * �w��ʒu�̗v�f��Ԃ��܂�.
	 * @param index
	 * @return
	 */
	ASTFactorSPtr getFactorAt(int index) const;

	/**
	 * �S�Ă̗v�f����Ԃ��܂�.
	 * @return
	 */
	int getFactorCount() const;

	// ASTFactor ����Čp������܂���
	Object_ * eval() override;
	std::string format() const override;

	DECL_MAKE_SHARED_0_H(ASTArrayInitializer)
private:
	std::vector<ASTFactorSPtr> elems;
};
#endif // !BEAN_AST_ASTARRAYINITIALIZER_H


