#pragma once
#ifndef BEAN_AST_ASTERRORNODE_H
#define BEAN_AST_ASTERRORNODE_H
#include <string>
#include "ASTNode.h"
/**
 * AST�̃W�F�l���[�^���G���[��񍐂��Ȃ����͂𑱍s���邽�߂Ɏg�p����܂�.
 */
class ASTErrorNode : public ASTNode {
public:
	ASTErrorNode();
	ASTErrorNode(const std::string& message);
	~ASTErrorNode();
	std::string getMessage() const;
	DECL_MAKE_SHARED_0_H(ASTErrorNode)
	DECL_MAKE_SHARED_1_H(ASTErrorNode, const std::string&)
private:
	std::string message;
};
#endif // !BEAN_AST_ASTERRORNODE_H
