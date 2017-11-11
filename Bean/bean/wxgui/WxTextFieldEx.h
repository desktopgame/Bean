#pragma once
#ifndef BEAN_WXGUI_WXTEXTFIELDEX_H
#define BEAN_WXGUI_WXTEXTFIELDEX_H
#include <wx/wx.h>
/**
 * TextFieldの拡張です.
 * ピアクラスの委譲先として使用されます。
 */
class WxTextFieldEx : public wxTextCtrl {
public:
	WxTextFieldEx(wxWindow* window);
	~WxTextFieldEx();
};
#endif // !BEAN_WXGUI_WXTEXTFIELDEX_H
