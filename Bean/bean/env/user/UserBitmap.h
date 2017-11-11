#pragma once
#ifndef BEAN_ENV_USER_USERBITMAP_H
#define BEAN_ENV_USER_USERBITMAP_H
#include <wx/wx.h>
#include "../Object_.h"
/**
 * ビットマップのラッパー.
 */
class UserBitmap : public Object_ {
public:
	UserBitmap(const wxBitmap& bmp);
	~UserBitmap();

	// Object_ を介して継承されました
	Object_ * clone() override;

	/**
	 * 指定位置にこの画像を描画します.
	 * @param g
	 * @param x
	 * @param y
	 */
	void draw(wxDC* g, int x, int y);

	/**
	 * 画像の横幅を返します.
	 * @return
	 */
	int getWidth() const;

	/**
	 * 画像の縦幅を返します.
	 * @return
	 */
	int getHeight() const;

	/**
	 * 文字列を型へ変換します.
	 * @param name
	 */
	static wxBitmapType fromString(const std::string name);
protected:
	void lazyLoading() override;
private:
	wxBitmap bmp;

};
#endif // !BEAN_ENV_USER_USERBITMAP_H
