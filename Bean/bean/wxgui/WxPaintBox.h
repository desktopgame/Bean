#pragma once
#ifndef BEAN_WXGUI_WXPAINTBOX_H
#define BEAN_WXGUI_WXPAINTBOX_H
#include <functional>
#include <vector>
#include <wx/wx.h>
//#include <thread>
//#include <mutex>
class WxPaintBox;
using Paint = std::function<void(WxPaintBox*, wxPaintDC*, wxPaintEvent&)>;
/**
 * Panelの拡張です.
 * ピアクラスの委譲先として使用されます。
 */
class WxPaintBox : public wxPanel {
public:
	WxPaintBox(wxWindow* window, wxWindowID id);
	~WxPaintBox();

	/**
	 * アニメーションを開始します.
	 */
	void start();

	/**
	 * アニメーションを一時停止します.
	 */
	void stop();

	/**
	 * 描画を監視するリスナーを追加します.
	 * @param p
	 */
	void addPaintListener(Paint p);

	/**
	 * 描画を監視するリスナーを削除します.
	 * @param index
	 */
	void removePaintListenerAt(int index);

	/**
	 * 描画を監視するリスナーの数を返します.
	 * @return
	 */
	int getPaintListenerCount() const;

	void OnPaint(wxPaintEvent& e);
	void OnTick(wxCommandEvent& e);
private:
	std::vector<Paint> paintListenerList;
	wxTimer* timer;
};
#endif // !BEAN_WXGUI_WXPAINTBOX_H
