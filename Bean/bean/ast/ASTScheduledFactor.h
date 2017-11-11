#pragma once
#ifndef BEAN_AST_ASTSCHEDULEDFACTOR_H
#define BEAN_AST_ASTSCHEDULEDFACTOR_H
#include "ASTFactor.h"
class ASTScheduledFactor;
using ASTScheduledFactorSPtr = std::shared_ptr<ASTScheduledFactor>;
using ASTScheduledFactorWPtr = std::weak_ptr<ASTScheduledFactor>;

/**
 * �C���N�������g��f�N�������g�̂悤�Ȍv�Z�̃^�C�~���O���K�肳�ꂽ���Z�q���`���܂�.
 */
class ASTScheduledFactor : public ASTFactor {
public:
	ASTScheduledFactor();

	/**
	* ���Z���K�p����������ݒ肵�܂�.
	* @param argument
	*/
	void setArgument(std::shared_ptr<ASTFactor> argument);

	/**
	* ���Z���K�p����������Ԃ��܂�.
	* @return
	*/
	std::shared_ptr<ASTFactor> getArgument() const;

	/**
	 * ���̉��Z�q���ŏ��ɓK�p�����ׂ��Ȃ�true.
	 * @param isPrefix
	 */
	void setPrefix(bool isPrefix);

	/**
	 * ���̉��Z�q���ŏ��ɓK�p�����ׂ��Ȃ�true.
	 * @return
	 */
	bool isPrefix() const;

	/**
	 * ���̉��Z�q���Ō�ɓK�p�����ׂ��Ȃ�true.
	 * @param isSuffix
	 */
	void setSuffix(bool isSuffix);

	/**
	 * ���̉��Z�q���Ō�ɓK�p�����ׂ��Ȃ�true.
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
	* ��u�����Z�q�Ƃ��Ď��s�����Ƃ��ɁA
	* �ꎞ�I�ɍ쐬�����N���[����Ԃ��܂��B
	* @param src
	*/
	virtual Object_* newClone(Object_* src);

	/**
	* ���Z�q��K�p���܂�.
	* @param target
	* @param one
	*/
	virtual Object_* lazy(Object_* target, Object_* one);

	/**
	 * �ύX��K�p���܂�
	 * @param src
	 */
	virtual void edit(Object_* src);
private:
	std::shared_ptr<ASTFactor> argument;
	bool _isPrefix;
	bool _isSuffix;

};
#endif // !BEAN_AST_ASTSCHEDULEDFACTOR_H
