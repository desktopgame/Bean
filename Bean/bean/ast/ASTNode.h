#pragma once
#ifndef BEAN_AST_ASTNODE_H
#define BEAN_AST_ASTNODE_H
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "visitor/ASTVisitor.h"
//#include "ASTBranch.h"
//std::make_shared<�����̌^> make_shared() ��������������}�N��---
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
 * std::enabled_shared_from_this<T>#shared_from_this()���A
 * std::shared_ptr<CNAME>�^�֕ϊ����܂��B
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
//---�}�N��

class ASTNode;
using ASTNodeSPtr = std::shared_ptr<ASTNode>;
using ASTNodeWPtr = std::weak_ptr<ASTNode>;

/**
 * ���ۍ\���؂��\������v�f�ł�.
 */
class ASTNode : public std::enable_shared_from_this<ASTNode> {
public:
	ASTNode();
	virtual ~ASTNode();

	/**
	 * ���̃m�[�h�̃\�[�X�R�[�h���̊J�n�ʒu��ݒ肵�܂�.
	 * @param startOffset
	 */
	void setStartOffset(int startOffset);

	/**
	 * ���̃m�[�h�̃\�[�X�R�[�h���̊J�n�ʒu��Ԃ��܂�.
	 * @return
	 */
	int getStartOffset() const;

	/**
	* ���̃m�[�h�̃\�[�X�R�[�h���̏I���ʒu��ݒ肵�܂�.
	* @param endOffset
	*/
	void setEndOffset(int endOffset);

	/**
	 * ���̃m�[�h�̃\�[�X�R�[�h���̏I���ʒu��Ԃ��܂�.
	 * @return
	 */
	int getEndOffset() const;

	/**
	 * ���ۍ\���؂��_���v���܂�.
	 */
	void dump();

	/** 
	 * ��O���X���[����Ă���Ȃ�true.
	 * @return
	 */
	bool thrown();

	/**
	 * ���̗v�f���N�_�Ƃ��đS�Ă̗v�f��K�₵�܂�.
	 * @param visit
	 */
	void visit(ASTVisitor* visitor);

	/**
	* ���̗v�f�̕�����\����Ԃ��܂�.
	*/
	virtual std::string format() const;

	/**
	* �K�؂ȃ��\�b�h���Ăяo���܂�.
	* @parma visitor
	*/
	virtual void accept(ASTVisitor* visitor);

protected:

	/**
	 * ���̌^��\�� std::shared_ptr ��Ԃ��܂�.
	 * @param args
	 */
	template<typename T, typename... Args>
	static std::shared_ptr<T> make_shared(Args... args) {
		std::shared_ptr<T> ret = std::make_shared<T>(args...);
		return ret;
	}

	/**
	 * ���݂̃X���b�h�� Buffer#begin ���Ăяo���܂�.
	 */
	void buffer_begin();

	/**
	 * ���݂̃X���b�h�� Buffer#end ���Ăяo���܂�.
	�@*/ 
	void buffer_end();

	/**
	 * �w��̃m�[�h��nullptr�łȂ����accept���܂�.
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
