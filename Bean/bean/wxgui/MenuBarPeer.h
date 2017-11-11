#pragma once
#ifndef BEAN_WXGUI_MENUBARPEER_H
#define BEAN_WXGUI_MENUBARPEER_H
#include "ContainerPeer.h"
#include "MenuBarInterface.h"
#include "WxMenuBarEx.h"
/**
 * MenuBar‚Ì’áƒŒƒxƒ‹‚ÈU‚é•‘‚¢‚ğ’ñ‹Ÿ‚µ‚Ü‚·.
 */
class MenuBarPeer : public ContainerPeer<WxMenuBarEx>, public MenuBarInterface {
public:
	MenuBarPeer();
	~MenuBarPeer();

	// MenuBarInterface ‚ğ‰î‚µ‚ÄŒp³‚³‚ê‚Ü‚µ‚½
	wxMenu* addMenu(std::string label) override;
	void removeMenuAt(int index) override;
	int getMenuCount() override;
	wxMenuBar * getWXMenuBar() override;
};
#endif // !BEAN_WXGUI_MENUBARPEER_H
