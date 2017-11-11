#pragma once
#ifndef BEAN_WXGUI_WXBUTTONEX_H
#define BEAN_WXGUI_WXBUTTONEX_H
#include <functional>
#include <vector>
#include <wx/wx.h>
/**
 * ボタンが押されたときに呼び出される関数.
 */
class WxButtonEx;
using PushListener = std::function<void(WxButtonEx*, const wxCommandEvent&)>;
/**
 * Buttonの拡張です.
 * ピアクラスの委譲先として使用されます。
 */
class WxButtonEx : public wxButton {
public:
	WxButtonEx(wxWindow* parent, wxWindowID id, const wxString& label);
	~WxButtonEx();
	//
	//イベント
	//

	/**
	 * イベントリスナーを追加します.
	 * @param listener
	 */
	void addPushListener(PushListener listener);

	/**
	 * イベントリスナーを削除します.
	 * @param index
	 */
	void removePushListenerAt(int index);

	/**
	 * リスナーの数を返します.
	 * @return
	 */
	int getPushListenerCount() const;

	/**
	 * ボタンが押し込まれると呼ばれます.
	 * @param e
	 */
	void OnPush(wxCommandEvent& e);
protected:
	/**
	 * プッシュイベントを通知します.
	 * @param sender
	 * @param e
	 */
	void firePushEvent(WxButtonEx* sender, wxCommandEvent& e);
private:
	std::vector<PushListener> pushListenerList;
//	wxDECLARE_EVENT_TABLE();
};
#endif // !BEAN_WXGUI_WXBUTTONEX_H
