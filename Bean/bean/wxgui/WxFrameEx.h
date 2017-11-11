#pragma once
#ifndef BEAN_WXGUI_WXFRAMEEX_H
#define BEAN_WXGUI_WXFRAMEEX_H
#include <wx/wx.h>
/**
 * Frameの拡張です.
 * ピアクラスの委譲先として使用されます。
 */
class WxFrameEx : public wxFrame {
public:
	WxFrameEx(const wxString& title, int width, int height);
	~WxFrameEx();

	/**
	 * コンポーネントを配置するための領域を返します.
	 * @return
	 */
	wxPanel* getContentPane() const;

	/**
	 * ウィンドウが閉じられると呼ばれます.
	 * @param e
	 */
	void OnClose(wxCommandEvent& e);

private:
	wxPanel* contentPane;
	wxDECLARE_EVENT_TABLE();
};
#endif // !BEAN_WXGUI_WXFRAMEEX_H

