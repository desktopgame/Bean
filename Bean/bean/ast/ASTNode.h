#pragma once
#ifndef BEAN_AST_ASTNODE_H
#define BEAN_AST_ASTNODE_H
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "visitor/ASTVisitor.h"
//#include "ASTBranch.h"
//std::make_shared<自分の型> make_shared() を自動生成するマクロ---
#define MAKE_SHARED_AUTOGENENABLED
//#undef MAKE_SHARED_AUTOGENENABLED

#define DECL_MAKE_SHARED_0_H(CNAME) static std::shared_ptr<CNAME> make_shared();

#define IMPL_MAKE_SHARED_0_CPP(CNAME) std::shared_ptr<CNAME> CNAME::make_shared() {		\
								return ASTNode::make_shared<CNAME>();					\
								}

#define DECL_MAKE_SHARED_1_H(CNAME, TNAME0) static std::shared_ptr<CNAME> make_shared(TNAME0 t0);

#define IMPL_MAKE_SHARED_1_CPP(CNAME, TNAME0) std::shared_ptr<CNAME> CNAME::make_shared(TNAME0 t0) {		\
								return ASTNode::make_shared<CNAME>(t0);									\
								}

#define DECL_MAKE_SHARED_2_H(CNAME, TNAME0, TNAME1) static std::shared_ptr<CNAME> make_shared(TNAME0 t0, TNAME1 t1);

#define IMPL_MAKE_SHARED_2_CPP(CNAME, TNAME0, TNAME1) std::shared_ptr<CNAME> CNAME::make_shared(TNAME0 t0, TNAME1 t1) {	\
								return ASTNode::make_shared<CNAME>(t0, t1);												\
								}

#define DECL_MAKE_SHARED_3_H(CNAME, TNAME0, TNAME1, TNAME2) static std::shared_ptr<CNAME> make_shared(TNAME0 t0, TNAME1 t1, TNAME2 t2);

#define IMPL_MAKE_SHARED_3_CPP(CNAME, TNAME0, TNAME1, TNAME2) std::shared_ptr<CNAME> CNAME::make_shared(TNAME0 t0, TNAME1 t1, TNAME2 t2) {	\
								return ASTNode::make_shared<CNAME>(t0, t1, t2);																	\
								}

/**
 * std::enabled_shared_from_this<T>#shared_from_this()を、
 * std::shared_ptr<CNAME>型へ変換します。
 */
#define SHARED_FROM_THIS(CNAME) std::dynamic_pointer_cast<CNAME>(shared_from_this())

#ifndef MAKE_SHARED_AUTOGENENABLED
#undef DECL_MAKE_SHARED_0_H(CNAME)
#undef DECL_MAKE_SHARED_1_H(CNAME, TNAME0)
#undef DECL_MAKE_SHARED_2_H(CNAME, TNAME0, TNAME1)
#undef DECL_MAKE_SHARED_3_H(CNAME, TNAME0, TNAME1, TNAME2)

#undef IMPL_MAKE_SHARED_0_CPP(CNAME)
#undef IMPL_MAKE_SHARED_1_CPP(CNAME, TNAME0)
#undef IMPL_MAKE_SHARED_2_CPP(CNAME, TNAME0, TNAME1)
#undef IMPL_MAKE_SHARED_3_CPP(CNAME, TNAME0, TNAME1, TNAME2)
#endif
//---マクロ

class ASTNode;
using ASTNodeSPtr = std::shared_ptr<ASTNode>;
using ASTNodeWPtr = std::weak_ptr<ASTNode>;

/**
 * 抽象構文木を構成する要素です.
 */
class ASTNode : public std::enable_shared_from_this<ASTNode> {
public:
	ASTNode();
	virtual ~ASTNode();

	/**
	 * このノードのソースコード中の開始位置を設定します.
	 * @param startOffset
	 */
	void setStartOffset(int startOffset);

	/**
	 * このノードのソースコード中の開始位置を返します.
	 * @return
	 */
	int getStartOffset() const;

	/**
	* このノードのソースコード中の終了位置を設定します.
	* @param endOffset
	*/
	void setEndOffset(int endOffset);

	/**
	 * このノードのソースコード中の終了位置を返します.
	 * @return
	 */
	int getEndOffset() const;

	/**
	 * 抽象構文木をダンプします.
	 */
	void dump();

	/** 
	 * 例外がスローされているならtrue.
	 * @return
	 */
	bool thrown();

	/**
	 * この要素を起点として全ての要素を訪問します.
	 * @param visit
	 */
	void visit(ASTVisitor* visitor);

	/**
	* この要素の文字列表現を返します.
	*/
	virtual std::string format() const;

	/**
	* 適切なメソッドを呼び出します.
	* @parma visitor
	*/
	virtual void accept(ASTVisitor* visitor);

protected:

	/**
	 * この型を表す std::shared_ptr を返します.
	 * @param args
	 */
	template<typename T, typename... Args>
	static std::shared_ptr<T> make_shared(Args... args) {
		std::shared_ptr<T> ret = std::make_shared<T>(args...);
		return ret;
	}

	/**
	 * 現在のスレッドの Buffer#begin を呼び出します.
	 */
	void buffer_begin();

	/**
	 * 現在のスレッドの Buffer#end を呼び出します.
	　*/ 
	void buffer_end();

	/**
	 * 指定のノードがnullptrでなければacceptします.
	 * @param visitor
	 * @param node
	 */
	void accept_(ASTVisitor* visitor, std::shared_ptr<ASTNode> node);
protected:
	bool isSingleton;
private:
	int startOffset;
	int endOffset;
	void visitImpl(ASTNode* root, ASTVisitor* visitor);
};
#endif
