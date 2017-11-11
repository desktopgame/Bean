#pragma once
#ifndef BEAN_WXGUI_WXSCROLLPANEEX_H
#define BEAN_WXGUI_WXSCROLLPANEEX_H
#include <wx/wx.h>
/**
 * ScrolledWindowの拡張です.
 * ピアクラスの委譲先として使用されます。
 */
class WxScrollPaneEx : public wxScrolledWindow {
public:
	WxScrollPaneEx(wxWindow* window);
	~WxScrollPaneEx();
};
#endif // !BEAN_WXGUI_WXSCROLLPANEEX_H
