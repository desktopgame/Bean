#pragma once
#ifndef BEAN_WXGUI_COMPONENTINTERFACE_H
#define BEAN_WXGUI_COMPONENTINTERFACE_H
#include <wx/wx.h>
/**
 * Componentのうち、テンプレートに依存しない実装を提供します.
 */
class ComponentInterface {
public:
	ComponentInterface();
	virtual ~ComponentInterface() = 0;
	/**
	 * このコンポーネントを再描画します.
	 */
	virtual void repaint() = 0;

	/**
	 * X座標を設定します.
	 * @param x
	 */
	virtual void setX(int x) = 0;

	/**
	 * X座標を返します.
	 * @return
	 */
	virtual int getX() = 0;

	/**
	 * Y座標を設定します.
	 * @param y
	 */
	virtual void setY(int y) = 0;

	/**
	 * Y座標を返します.
	 * @return
	 */
	virtual int getY() = 0;

	/**
	 * 横幅を設定します.
	 * @param w
	 */
	virtual void setWidth(int w) = 0;

	/**
	 * 横幅を返します.
	 * @return
	 */
	virtual int getWidth() = 0;

	/**
	 * 縦幅を設定します.
	 * @param h
	 */
	virtual void setHeight(int h) = 0;

	/** 
	 * 縦幅を返します.
	 * @return
	 */
	virtual int getHeight() = 0;

	/**
	 * 最小サイズを設定します.
	 * @param size
	 */
	virtual void setMinSize(wxSize size) = 0;

	/**
	 * 最小サイズを返します.
	 * @return
	 */
	virtual wxSize getMinSize() = 0;

	/**
	 * 推奨サイズを設定します.
	 * @param size
	 */
	virtual void setFitSize(wxSize size) = 0;

	/**
	 * 推奨サイズを返します.
	 * @return
	 */
	virtual wxSize getFitSize() = 0;

	/**
	 * 最大サイズを設定します.
	 * @param size
	 */
	virtual void setMaxSize(wxSize size) = 0;

	/**
	 * 最大サイズを返します.
	 * @return
	 */
	virtual wxSize getMaxSize() = 0;

	/**
	 * 前景色を設定します.
	 * @param foreColor
	 */
	virtual void setForeground(wxColor foreColor) = 0;

	/**
	 * 前景色を返します.
	 * @return
	 */
	virtual wxColor getForeground() = 0;

	/**
	 * 背景色を設定します.
	 * @param backColor
	 */
	virtual void setBackground(wxColor backColor) = 0;

	/**
	 * 背景色を返します.
	 * @return
	 */
	virtual wxColor getBackground() = 0;

	/**
	 * コンポーネントを返します.
	 * @return
	 */
	virtual wxWindow* getWX() = 0;
};
#endif // !BEAN_WXGUI_COMPONENTINTERFACE_H
