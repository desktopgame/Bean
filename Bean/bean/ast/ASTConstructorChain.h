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
	 * 連鎖の方法を設定します.
	 * @param type
	 */
	void setChainType(ConstructorChainType type);

	/**
	 * 連鎖の方法を返します.
	 * @return
	 */
	ConstructorChainType getChainType() const;

	/**
	 * 実引数を追加します.
	 * @param arg
	 */
	void addArgument(std::shared_ptr<ASTFactor> arg);

	/**
	 * 指定位置の引数を返します.
	 * @param index
	 * @return
	 */
	std::shared_ptr<ASTFactor> getArgumentAt(int index) const;

	/**
	 * 指定位置の引数を削除します.
	 * @param index
	 */
	void removeArgumentAt(int index);

	/**
	 * 実引数の数を返します.
	 * @return
	 */
	int getArgumentCount() const;

	/**
	 * 遷移先のコンストラクタを返します.
	 * @param self 遷移しようとしているコンストラクタ
	 */
	Constructor_* find(Constructor_* self);
	DECL_MAKE_SHARED_0_H(ASTConstructorChain)
private:
	ConstructorChainType cct;
	std::vector<std::shared_ptr<ASTFactor>> arguments;
};
#endif // !BEAN_AST_ASTCONSTRUCTORCHAIN_H
