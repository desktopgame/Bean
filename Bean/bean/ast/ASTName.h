#pragma once
#ifndef BEAN_AST_ASTNAME_H
#define BEAN_AST_ASTNAME_H
#include <string>
#include "ASTNode.h"
#include "../util/Text.h"
/**
 * ユーザが自由に定義可能な名前です.
 * これは例えばクラス宣言やメソッド宣言です.
 */
class ASTName : public ASTNode {
public:
	ASTName(const BString& string);
#ifdef BTEXT_WIDE
	ASTName(const std::string& str)
	 : ASTName(std::wstring(str.begin(), str.end())) {

	}
#endif // BTEXT_WIDE


	~ASTName();

	/**
	 * 文字列で返します.
	 * @return
	 */
	BString getBString() const;

	/**
	 * 文字列で返します.
	 * @return
	 */
	std::string getCString() const;

	/**
	 * 文字列で返します.
	 * @return
	 */
	std::wstring getCWString() const;

	std::string format() const override;
#ifdef BTEXT_WIDE
	DECL_MAKE_SHARED_1_H(ASTName, std::string)
#endif // BTEXT_WIDE
	DECL_MAKE_SHARED_1_H(ASTName, BString)
protected:
private:
	BString string;
};
#endif // !BEAN_AST_ASTNAME_H
