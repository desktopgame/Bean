#pragma once
#ifndef BEAN_WXGUI_WXTEXTFIELDEX_H
#define BEAN_WXGUI_WXTEXTFIELDEX_H
#include <wx/wx.h>
/**
 * TextField�̊g���ł�.
 * �s�A�N���X�̈Ϗ���Ƃ��Ďg�p����܂��B
 */
class WxTextFieldEx : public wxTextCtrl {
public:
	WxTextFieldEx(wxWindow* window);
	~WxTextFieldEx();
};
#endif // !BEAN_WXGUI_WXTEXTFIELDEX_H
