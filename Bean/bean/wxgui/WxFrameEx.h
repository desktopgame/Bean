#pragma once
#ifndef BEAN_WXGUI_WXFRAMEEX_H
#define BEAN_WXGUI_WXFRAMEEX_H
#include <wx/wx.h>
/**
 * Frame�̊g���ł�.
 * �s�A�N���X�̈Ϗ���Ƃ��Ďg�p����܂��B
 */
class WxFrameEx : public wxFrame {
public:
	WxFrameEx(const wxString& title, int width, int height);
	~WxFrameEx();

	/**
	 * �R���|�[�l���g��z�u���邽�߂̗̈��Ԃ��܂�.
	 * @return
	 */
	wxPanel* getContentPane() const;

	/**
	 * �E�B���h�E��������ƌĂ΂�܂�.
	 * @param e
	 */
	void OnClose(wxCommandEvent& e);

private:
	wxPanel* contentPane;
	wxDECLARE_EVENT_TABLE();
};
#endif // !BEAN_WXGUI_WXFRAMEEX_H

