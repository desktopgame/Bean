#pragma once
#ifndef BEAN_WXGUI_WXPANELEX_H
#define BEAN_WXGUI_WXPANELEX_H
#include <wx/wx.h>
/**
 * Panelの拡張です.
 * ピアクラスの委譲先として使用されます。
 */
class WxPanelEx : public wxPanel {
public:
	WxPanelEx(wxWindow* window, wxWindowID id);
	~WxPanelEx();
};
#endif // !BEAN_WXGUI_WXPANELEX_H
