#pragma once
#ifndef BEAN_WXGUI_WXLABELEX_H
#define BEAN_WXGUI_WXLABELEX_H
#include <wx/wx.h>
/**
 * Label�̊g���ł�.
 * �s�A�N���X�̈Ϗ���Ƃ��Ďg�p����܂��B
 */
class WxLabelEx : public wxStaticText {
public:
	WxLabelEx(wxWindow* window, wxWindowID id, const wxString& label);
	~WxLabelEx();
};
#endif // !BEAN_WXGUI_WXLABELEX_H
