#pragma once
#ifndef BEAN_AST_ASTARRAYINITIALIZER_H
#define BEAN_AST_ASTARRAYINITIALIZER_H
#include <vector>
#include "ASTFactor.h"
/**
 * 配列を初期化するための構文です.
 * var hoge = { aaa, bbb, ccc };
 */
class ASTArrayInitializer : public ASTFactor {
public:
	ASTArrayInitializer();
	~ASTArrayInitializer();
	/**
	 * この配列初期化に含まれる要素を追加します.
	 * @param factor
	 */
	void addFactor(ASTFactorSPtr factor);

	/**
	 * 指定位置の要素を返します.
	 * @param index
	 * @return
	 */
	ASTFactorSPtr getFactorAt(int index) const;

	/**
	 * 全ての要素数を返します.
	 * @return
	 */
	int getFactorCount() const;

	// ASTFactor を介して継承されました
	Object_ * eval() override;
	std::string format() const override;

	DECL_MAKE_SHARED_0_H(ASTArrayInitializer)
private:
	std::vector<ASTFactorSPtr> elems;
};
#endif // !BEAN_AST_ASTARRAYINITIALIZER_H


