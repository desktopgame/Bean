#pragma once
#ifndef BEAN_AST_ASTNEWSTATEMENT_H
#define BEAN_AST_ASTNEWSTATEMENT_H
#include "ASTFactor.h"
#include "ASTName.h"
//NOTE:	使用されていません。
//		newはメソッド呼び出しと同じになりました
/**
 * new
 */
class ASTNewStatement : public ASTFactor {
public:
	ASTNewStatement();
	~ASTNewStatement();
	/**
	 * 生成されるクラス名を設定します.
	 * @param className
	 */
	void setClassName(std::shared_ptr<ASTName> className);

	/**
	 * 生成されるクラス名を返します.
	 * @return
	 */
	std::shared_ptr<ASTName> getClassName() const;

	/**
	 * コンストラクタ呼び出しに引数を追加します.
	 * @param factor
	 */
	void addArgument(std::shared_ptr<ASTFactor> factor);

	/**
	 * 指定位置の引数を返します.
	 * @param index
	 */
	std::shared_ptr<ASTFactor> getArgumentAt(int index) const;

	/**
	 * 全ての引数の数を返します.
	 * @return
	 */
	int getArgumentCount() const;

	std::string format() const override;
	void accept(ASTVisitor* visitor) override;
	// ASTFactor を介して継承されました
	Object_ * eval() override;
	DECL_MAKE_SHARED_0_H(ASTNewStatement)
protected:
private:
	std::shared_ptr<ASTName> className;
	std::vector<std::shared_ptr<ASTFactor>> arguments;
};
#endif // !BEAN_AST_ASTNEWSTATEMENT_H
