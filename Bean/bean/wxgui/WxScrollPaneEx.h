#pragma once
#ifndef BEAN_WXGUI_WXSCROLLPANEEX_H
#define BEAN_WXGUI_WXSCROLLPANEEX_H
#include <wx/wx.h>
/**
 * ScrolledWindow�̊g���ł�.
 * �s�A�N���X�̈Ϗ���Ƃ��Ďg�p����܂��B
 */
class WxScrollPaneEx : public wxScrolledWindow {
public:
	WxScrollPaneEx(wxWindow* window);
	~WxScrollPaneEx();
};
#endif // !BEAN_WXGUI_WXSCROLLPANEEX_H
