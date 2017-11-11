#pragma once
#ifndef BEAN_ENV_USER_USERMENUELEMENT_H
#define BEAN_ENV_USER_USERMENUELEMENT_H
#include <wx/wx.h>
#include "../Object_.h"
/**
 * ���j���[�̃��b�p�[�̊��N���X.
 */
class UserMenuElement : public Object_ {
public:
	UserMenuElement();
	virtual ~UserMenuElement() = 0;
	/**
	 * ���j���[�̕������ݒ肵�܂�.
	 * @param text
	 */
	virtual void setText(std::string text) = 0;

	/**
	 * ���j���[�̕������Ԃ��܂�.
	 * @return
	 */
	virtual std::string getText() = 0;
	/**
	 * WX�̌^�ŕԂ��܂�.
	 * @return
	 */
	virtual wxMenuItem* getWXMenuItem() = 0;

	/**
	 * WX�̌^�ŕԂ��܂�.
	 * @return
	 */
	virtual wxMenu* getWXMenu() = 0;

	/**
	 * ���̃A�C�e����I����Ԃɐݒ肷��Ȃ� true.
	 * @param isSelected
	 */
	virtual void setSelected(bool isSelected) = 0;

	/**
	 * ���̃A�C�e�����I����ԂȂ� true.
	 * @return
	 */
	virtual bool isSelected() = 0;

	// Object_ ����Čp������܂���
	Object_ * clone() override;
};
#endif // !BEAN_ENV_USER_USERMENUELEMENT_H
