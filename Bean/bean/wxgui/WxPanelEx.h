#pragma once
#ifndef BEAN_WXGUI_WXPANELEX_H
#define BEAN_WXGUI_WXPANELEX_H
#include <wx/wx.h>
/**
 * Panel�̊g���ł�.
 * �s�A�N���X�̈Ϗ���Ƃ��Ďg�p����܂��B
 */
class WxPanelEx : public wxPanel {
public:
	WxPanelEx(wxWindow* window, wxWindowID id);
	~WxPanelEx();
};
#endif // !BEAN_WXGUI_WXPANELEX_H
