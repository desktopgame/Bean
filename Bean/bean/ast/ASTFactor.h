#pragma once
#ifndef BEAN_AST_ASTFACTOR_H
#define BEAN_AST_ASTFACTOR_H
#include <functional>
#include "ASTNode.h"
#include "../env/Class.h"
class Object_;

class ASTFactor;
using ASTFactorSPtr = std::shared_ptr<ASTFactor>;
using ASTFactorWPtr = std::weak_ptr<ASTFactor>;
/**
 * 計算対象.
 */
class ASTFactor : public ASTNode {
public:
	ASTFactor();
	/**
	 * このノードを計算します.
	 * @return
	 */
	virtual Object_* eval() = 0;

	virtual Object_* add(ASTFactorSPtr right);
	virtual Object_* sub(ASTFactorSPtr right);
	virtual Object_* mul(ASTFactorSPtr right);
	virtual Object_* div(ASTFactorSPtr right);
	virtual Object_* mod(ASTFactorSPtr right);

	virtual Object_* equals(ASTFactorSPtr right);
	virtual Object_* biggest(ASTFactorSPtr right);
	virtual Object_* e_biggest(ASTFactorSPtr right);
	virtual Object_* smallest(ASTFactorSPtr right);
	virtual Object_* e_smallest(ASTFactorSPtr right);
	/**
	 * このオブジェクトがメソッドを実行するときに、
	 * どの時点からメソッドを検索するかを指定できます.
	 * 例えば、superでは親クラスから検索が開始されるべきです。
	 * @param classz デフォルトの検索開始位置.
	 *				 Object#getClass()の値です。
	 * @return
	 */
	virtual ClassSPtr getBaseLine(ClassSPtr classz);

	/**
	 * このファクターがstaticフィールドの左辺として機能出来るならtrueを返します.
	 * 例えば、このノードが変数への参照やリテラル(値)として機能する場合にはfalseですが、
	 * ラベルなどそれが変数であるかクラス名であるか判別がつかない場合にtrueを返します。
	 * @return
	 */
	virtual bool isStaticReceiver();

	/**
	 * このノードがstaticフィールドの左辺として機能する場合に、
	 * どのクラスを指し示すかを明示するために文字列でクラスを返します。
	 * @return
	 */
	virtual std::string getStaticClassName();

	virtual void ASTFactor::accept(ASTVisitor* visitor) override;
protected:
	/**
	 * このノードを計算します.
	 * ただし、計算出来なかった場合に nullptr ではなく Null を返し、例外をスローします。
	 * @return
	 */
	virtual Object_* evalThrow();
	virtual ~ASTFactor() = 0;
private:
	Object_* evalImpl(Object_* lv, Object_* rv, std::function<Object_*(Object_*, Object_*)> f);
	void begin();
	void end();
};
#endif // !BEAN_AST_ASTFACTOR_H
