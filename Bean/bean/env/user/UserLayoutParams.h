#pragma once
#ifndef BEAN_ENV_USER_USERLAYOUTPARAMS_H
#define BEAN_ENV_USER_USERLAYOUTPARAMS_H
#include <wx/wx.h>
#include "../Object_.h"
/**
 * ���C�A�E�g����̃��b�p�[.
 */
class UserLayoutParams : public Object_ {
public:
	UserLayoutParams();
	~UserLayoutParams();
	/**
	 * ���񂹂ɐݒ肵�܂�.
	 * @return ���̃C���X�^���X
	 */
	const UserLayoutParams* left();
	/**
	 * �E�񂹂ɐݒ肵�܂�.
	 * @return ���̃C���X�^���X
	 */
	const UserLayoutParams* right();
	/**
	 * ��񂹂ɐݒ肵�܂�.
	 * @return ���̃C���X�^���X
	 */
	const UserLayoutParams* top();
	/**
	 * ���񂹂ɐݒ肵�܂�.
	 * @return ���̃C���X�^���X
	 */
	const UserLayoutParams* bottom();
	/**
	 * �����񂹂ɐݒ肵�܂�.
	 * @return ���̃C���X�^���X.
	 */
	const UserLayoutParams* center();
	/**
	 * �{�[�_�[��ݒ肵�܂�.
	 * @return ���̃C���X�^���X
	 */
	const UserLayoutParams* border(int thick);

	/**
	 * �R���|�[�l���g���o���邾���h��Ԃ��悤�ɂ��܂�.
	 * @return
	 */
	const UserLayoutParams* fill();

	/**
	 * wx�̌^�ŕԂ��܂�.
	 * @return
	 */
	wxSizerFlags* getValue();

	// Object_ ����Čp������܂���
	Object_ * clone() override;
protected:
	void lazyLoading() override;
private:
	wxSizerFlags flags;
};
#endif // !BEAN_ENV_USER_USERLAYOUTPARAMS_H
