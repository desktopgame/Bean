#pragma once
#ifndef BEAN_AST_ASTCONSTRUCTORCHAIN_H
#define BEAN_AST_ASTCONSTRUCTORCHAIN_H
#include <vector>
#include "ASTNode.h"
#include "../env/ConstructorChainType.h"
class Constructor_;
/** 
 * : super()
 * : this()
 */
class ASTConstructorChain : public ASTNode {
public:
	ASTConstructorChain();
	~ASTConstructorChain();
	/**
	 * �A���̕��@��ݒ肵�܂�.
	 * @param type
	 */
	void setChainType(ConstructorChainType type);

	/**
	 * �A���̕��@��Ԃ��܂�.
	 * @return
	 */
	ConstructorChainType getChainType() const;

	/**
	 * ��������ǉ����܂�.
	 * @param arg
	 */
	void addArgument(std::shared_ptr<ASTFactor> arg);

	/**
	 * �w��ʒu�̈�����Ԃ��܂�.
	 * @param index
	 * @return
	 */
	std::shared_ptr<ASTFactor> getArgumentAt(int index) const;

	/**
	 * �w��ʒu�̈������폜���܂�.
	 * @param index
	 */
	void removeArgumentAt(int index);

	/**
	 * �������̐���Ԃ��܂�.
	 * @return
	 */
	int getArgumentCount() const;

	/**
	 * �J�ڐ�̃R���X�g���N�^��Ԃ��܂�.
	 * @param self �J�ڂ��悤�Ƃ��Ă���R���X�g���N�^
	 */
	Constructor_* find(Constructor_* self);
	DECL_MAKE_SHARED_0_H(ASTConstructorChain)
private:
	ConstructorChainType cct;
	std::vector<std::shared_ptr<ASTFactor>> arguments;
};
#endif // !BEAN_AST_ASTCONSTRUCTORCHAIN_H
