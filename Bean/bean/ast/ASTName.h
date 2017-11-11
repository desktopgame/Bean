#pragma once
#ifndef BEAN_AST_ASTNAME_H
#define BEAN_AST_ASTNAME_H
#include <string>
#include "ASTNode.h"
#include "../util/Text.h"
/**
 * ���[�U�����R�ɒ�`�\�Ȗ��O�ł�.
 * ����͗Ⴆ�΃N���X�錾�⃁�\�b�h�錾�ł�.
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
	 * ������ŕԂ��܂�.
	 * @return
	 */
	BString getBString() const;

	/**
	 * ������ŕԂ��܂�.
	 * @return
	 */
	std::string getCString() const;

	/**
	 * ������ŕԂ��܂�.
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
