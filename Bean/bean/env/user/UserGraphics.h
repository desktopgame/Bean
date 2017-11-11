#pragma once
#ifndef BEAN_ENV_USER_USERGRAPHICS_H
#define BEAN_ENV_USER_USERGRAPHICS_H
#include <wx/wx.h>
#include "../Object_.h"
class UserBitmap;
/**
 * �O���t�B�b�N�X�̃��b�p�[.
 */
class UserGraphics : public Object_ {
public:
	UserGraphics(wxPaintDC* dc);
	~UserGraphics();

	/**
	 * ���݂̃u���V�ŉ�ʂ��N���A���܂�.
	 */
	void clear();

	/**
	 * �w��̈ʒu�ɓ_��`�悵�܂�.
	 * @param x
	 * @param y
	 */
	void drawDot(wxCoord x, wxCoord y);

	/**
	 * �w��̓_����_�֐�����`�悵�܂�.
	 * @param x1
	 * @param y1
	 * @parma x2
	 * @param y2
	 */
	void drawLine(wxCoord x1, wxCoord y1, wxCoord x2, wxCoord y2);

	/**
	 * �ȉ~��`�悵�܂�.
	 * @param x
	 * @param y
	 * @param w
	 * @param h
	 */
	void drawEllipse(wxCoord x, wxCoord y, wxCoord w, wxCoord h);

	/**
	 * ��`��`�悵�܂�.
	 * @param x
	 * @param y
	 * @param w
	 * @param h
	 */
	void drawRect(wxCoord x, wxCoord y, wxCoord w, wxCoord h);

	/**
	 * �������`�悵�܂�.
	 * @param x
	 * @param y
	 */
	void drawString(const wxString& s, wxCoord x, wxCoord y);

	/**
	 * �w��̉摜��`�悵�܂�.
	 * @param bmp
	 * @param x
	 * @param y
	 */
	void drawBitmap(const wxBitmap& bmp, wxCoord x, wxCoord y);

	/**
	 * �w��̉摜��`�悵�܂�.
	 * @param bmp
	 * @param x
	 * @param y
	 */
	void drawBitmap(UserBitmap* ubmp, wxCoord x, wxCoord y);

	// Object_ ����Čp������܂���
	virtual Object_ * clone() override;
protected:
	void lazyLoading() override;
private:
	wxPaintDC* dc;

};
#endif // !BEAN_ENV_USER_USERGRAPHICS_H
