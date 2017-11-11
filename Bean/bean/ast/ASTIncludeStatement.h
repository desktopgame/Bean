#pragma once
#ifndef BEAN_AST_ASTINCLUDESTATEMENT_H
#define BEAN_AST_ASTINCLUDESTATEMENT_H
#include "ASTName.h"
#include "ASTNode.h"
/**
 * 別のファイルの機能をインクルードする要素です.
 */
class ASTIncludeStatement : public ASTNode {
public:
	ASTIncludeStatement();
	~ASTIncludeStatement();
	/**
	 * この要素がインクルードする対象へのFQCNを設定します.
	 * @param path
	 */
	void setPath(std::shared_ptr<ASTName> path);

	/**
	 * この要素がインクルードする対象へのFQCNを返します.
	 * @return
	 */
	std::shared_ptr<ASTName> getPath() const;

	std::string format() const override;
	void accept(ASTVisitor* visitor);
	DECL_MAKE_SHARED_0_H(ASTIncludeStatement)
private:
	std::shared_ptr<ASTName> path;
};
#endif // !BEAN_AST_ASTINCLUDESTATEMENT_H
