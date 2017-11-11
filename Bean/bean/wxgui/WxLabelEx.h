#pragma once
#ifndef BEAN_WXGUI_WXLABELEX_H
#define BEAN_WXGUI_WXLABELEX_H
#include <wx/wx.h>
/**
 * Labelの拡張です.
 * ピアクラスの委譲先として使用されます。
 */
class WxLabelEx : public wxStaticText {
public:
	WxLabelEx(wxWindow* window, wxWindowID id, const wxString& label);
	~WxLabelEx();
};
#endif // !BEAN_WXGUI_WXLABELEX_H
