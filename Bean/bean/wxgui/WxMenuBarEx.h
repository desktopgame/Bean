#pragma once
#ifndef BEAN_WXGUI_WXMENUBAREX_H
#define BEAN_WXGUI_WXMENUBAREX_H
#include <wx/wx.h>
/**
 * MenuBarの拡張です.
 * ピアクラスの委譲先として使用されます。
 */
class WxMenuBarEx : public wxMenuBar {
public:
	WxMenuBarEx();
	~WxMenuBarEx();
};
#endif // !BEAN_WXGUI_WXMENUBAREX_H
