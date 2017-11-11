#pragma once
#ifndef BEAN_ENV_USER_USERBITMAP_H
#define BEAN_ENV_USER_USERBITMAP_H
#include <wx/wx.h>
#include "../Object_.h"
/**
 * �r�b�g�}�b�v�̃��b�p�[.
 */
class UserBitmap : public Object_ {
public:
	UserBitmap(const wxBitmap& bmp);
	~UserBitmap();

	// Object_ ����Čp������܂���
	Object_ * clone() override;

	/**
	 * �w��ʒu�ɂ��̉摜��`�悵�܂�.
	 * @param g
	 * @param x
	 * @param y
	 */
	void draw(wxDC* g, int x, int y);

	/**
	 * �摜�̉�����Ԃ��܂�.
	 * @return
	 */
	int getWidth() const;

	/**
	 * �摜�̏c����Ԃ��܂�.
	 * @return
	 */
	int getHeight() const;

	/**
	 * ��������^�֕ϊ����܂�.
	 * @param name
	 */
	static wxBitmapType fromString(const std::string name);
protected:
	void lazyLoading() override;
private:
	wxBitmap bmp;

};
#endif // !BEAN_ENV_USER_USERBITMAP_H
