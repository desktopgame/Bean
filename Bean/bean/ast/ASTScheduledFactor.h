#pragma once
#ifndef BEAN_AST_ASTSCHEDULEDFACTOR_H
#define BEAN_AST_ASTSCHEDULEDFACTOR_H
#include "ASTFactor.h"
class ASTScheduledFactor;
using ASTScheduledFactorSPtr = std::shared_ptr<ASTScheduledFactor>;
using ASTScheduledFactorWPtr = std::weak_ptr<ASTScheduledFactor>;

/**
 * インクリメントやデクリメントのような計算のタイミングが規定された演算子を定義します.
 */
class ASTScheduledFactor : public ASTFactor {
public:
	ASTScheduledFactor();

	/**
	* 演算が適用される引数を設定します.
	* @param argument
	*/
	void setArgument(std::shared_ptr<ASTFactor> argument);

	/**
	* 演算が適用される引数を返します.
	* @return
	*/
	std::shared_ptr<ASTFactor> getArgument() const;

	/**
	 * この演算子が最初に適用されるべきならtrue.
	 * @param isPrefix
	 */
	void setPrefix(bool isPrefix);

	/**
	 * この演算子が最初に適用されるべきならtrue.
	 * @return
	 */
	bool isPrefix() const;

	/**
	 * この演算子が最後に適用されるべきならtrue.
	 * @param isSuffix
	 */
	void setSuffix(bool isSuffix);

	/**
	 * この演算子が最後に適用されるべきならtrue.
	 * @return
	 */
	bool isSuffix() const;
	Object_ * eval() override;
	virtual std::string format() const override;
	void accept(ASTVisitor* visitor) override;
protected:
	virtual ~ASTScheduledFactor();
	Object_ * evalImpl();
	/**
	* 後置き演算子として実行されるときに、
	* 一時的に作成されるクローンを返します。
	* @param src
	*/
	virtual Object_* newClone(Object_* src);

	/**
	* 演算子を適用します.
	* @param target
	* @param one
	*/
	virtual Object_* lazy(Object_* target, Object_* one);

	/**
	 * 変更を適用します
	 * @param src
	 */
	virtual void edit(Object_* src);
private:
	std::shared_ptr<ASTFactor> argument;
	bool _isPrefix;
	bool _isSuffix;

};
#endif // !BEAN_AST_ASTSCHEDULEDFACTOR_H
