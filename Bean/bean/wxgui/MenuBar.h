#pragma once
#ifndef BEAN_WXGUI_MENUBAR_H
#define BEAN_WXGUI_MENUBAR_H
#include "Container.h"
#include "MenuBarInterface.h"
#include "MenuBarPeer.h"
/**
 * メニューバーの最上位レイヤーです.
 * より抽象的な表現は UserMenuBar クラスで提供されます。
 */
class MenuBar : public Container<MenuBarPeer>, public MenuBarInterface {
public:
	MenuBar();
	~MenuBar();

	// MenuBarInterface を介して継承されました
	wxMenu* addMenu(std::string label) override;
	void removeMenuAt(int index) override;
	int getMenuCount() override;
	wxMenuBar * getWXMenuBar() override;
};
#endif // !BEAN_WXGUI_MENUBAR_H
