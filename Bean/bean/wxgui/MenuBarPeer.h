#pragma once
#ifndef BEAN_WXGUI_MENUBARPEER_H
#define BEAN_WXGUI_MENUBARPEER_H
#include "ContainerPeer.h"
#include "MenuBarInterface.h"
#include "WxMenuBarEx.h"
/**
 * MenuBar�̒჌�x���ȐU�镑����񋟂��܂�.
 */
class MenuBarPeer : public ContainerPeer<WxMenuBarEx>, public MenuBarInterface {
public:
	MenuBarPeer();
	~MenuBarPeer();

	// MenuBarInterface ����Čp������܂���
	wxMenu* addMenu(std::string label) override;
	void removeMenuAt(int index) override;
	int getMenuCount() override;
	wxMenuBar * getWXMenuBar() override;
};
#endif // !BEAN_WXGUI_MENUBARPEER_H
