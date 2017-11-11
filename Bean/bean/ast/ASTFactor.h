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
 * �v�Z�Ώ�.
 */
class ASTFactor : public ASTNode {
public:
	ASTFactor();
	/**
	 * ���̃m�[�h���v�Z���܂�.
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
	 * ���̃I�u�W�F�N�g�����\�b�h�����s����Ƃ��ɁA
	 * �ǂ̎��_���烁�\�b�h���������邩���w��ł��܂�.
	 * �Ⴆ�΁Asuper�ł͐e�N���X���猟�����J�n�����ׂ��ł��B
	 * @param classz �f�t�H���g�̌����J�n�ʒu.
	 *				 Object#getClass()�̒l�ł��B
	 * @return
	 */
	virtual ClassSPtr getBaseLine(ClassSPtr classz);

	/**
	 * ���̃t�@�N�^�[��static�t�B�[���h�̍��ӂƂ��ċ@�\�o����Ȃ�true��Ԃ��܂�.
	 * �Ⴆ�΁A���̃m�[�h���ϐ��ւ̎Q�Ƃ⃊�e����(�l)�Ƃ��ċ@�\����ꍇ�ɂ�false�ł����A
	 * ���x���Ȃǂ��ꂪ�ϐ��ł��邩�N���X���ł��邩���ʂ����Ȃ��ꍇ��true��Ԃ��܂��B
	 * @return
	 */
	virtual bool isStaticReceiver();

	/**
	 * ���̃m�[�h��static�t�B�[���h�̍��ӂƂ��ċ@�\����ꍇ�ɁA
	 * �ǂ̃N���X���w���������𖾎����邽�߂ɕ�����ŃN���X��Ԃ��܂��B
	 * @return
	 */
	virtual std::string getStaticClassName();

	virtual void ASTFactor::accept(ASTVisitor* visitor) override;
protected:
	/**
	 * ���̃m�[�h���v�Z���܂�.
	 * �������A�v�Z�o���Ȃ������ꍇ�� nullptr �ł͂Ȃ� Null ��Ԃ��A��O���X���[���܂��B
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
