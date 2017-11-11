#pragma once
#ifndef BEAN_WXGUI_MENUBARINTERFACE_H
#define BEAN_WXGUI_MENUBARINTERFACE_H
#include <wx/wx.h>
/**
 * MenuBar の実装のうちテンプレートに依存しないものを提供します.
 */
class MenuBarInterface {
public:
	MenuBarInterface();
	virtual ~MenuBarInterface() = 0;
	/**
	 * メニューを追加します.
	 * @param label
	 * @return
	 */
	virtual wxMenu* addMenu(std::string label) = 0;

	/**
	 * 指定位置のメニューを削除します.
	 * @param index
	 */
	virtual void removeMenuAt(int index) = 0;

	/**
	 * メニューの数を返します.
	 * @return
	 */
	virtual int getMenuCount() = 0;

	/**
	 * WXの型で返します.
	 * @return
	 */
	virtual wxMenuBar* getWXMenuBar() = 0;
};
#endif // !BEAN_WXGUI_MENUBARINTERFACE_H
