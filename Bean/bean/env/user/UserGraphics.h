#pragma once
#ifndef BEAN_ENV_USER_USERGRAPHICS_H
#define BEAN_ENV_USER_USERGRAPHICS_H
#include <wx/wx.h>
#include "../Object_.h"
class UserBitmap;
/**
 * グラフィックスのラッパー.
 */
class UserGraphics : public Object_ {
public:
	UserGraphics(wxPaintDC* dc);
	~UserGraphics();

	/**
	 * 現在のブラシで画面をクリアします.
	 */
	void clear();

	/**
	 * 指定の位置に点を描画します.
	 * @param x
	 * @param y
	 */
	void drawDot(wxCoord x, wxCoord y);

	/**
	 * 指定の点から点へ線分を描画します.
	 * @param x1
	 * @param y1
	 * @parma x2
	 * @param y2
	 */
	void drawLine(wxCoord x1, wxCoord y1, wxCoord x2, wxCoord y2);

	/**
	 * 楕円を描画します.
	 * @param x
	 * @param y
	 * @param w
	 * @param h
	 */
	void drawEllipse(wxCoord x, wxCoord y, wxCoord w, wxCoord h);

	/**
	 * 矩形を描画します.
	 * @param x
	 * @param y
	 * @param w
	 * @param h
	 */
	void drawRect(wxCoord x, wxCoord y, wxCoord w, wxCoord h);

	/**
	 * 文字列を描画します.
	 * @param x
	 * @param y
	 */
	void drawString(const wxString& s, wxCoord x, wxCoord y);

	/**
	 * 指定の画像を描画します.
	 * @param bmp
	 * @param x
	 * @param y
	 */
	void drawBitmap(const wxBitmap& bmp, wxCoord x, wxCoord y);

	/**
	 * 指定の画像を描画します.
	 * @param bmp
	 * @param x
	 * @param y
	 */
	void drawBitmap(UserBitmap* ubmp, wxCoord x, wxCoord y);

	// Object_ を介して継承されました
	virtual Object_ * clone() override;
protected:
	void lazyLoading() override;
private:
	wxPaintDC* dc;

};
#endif // !BEAN_ENV_USER_USERGRAPHICS_H
