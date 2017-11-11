#pragma once
#ifndef BEAN_WXGUI_WINDOWPEER_H
#define BEAN_WXGUI_WINDOWPEER_H
#include <wx/wx.h>
#include "ContainerPeer.h"
/**
 * Windowの低レベルな振る舞いを提供します.
 */
template<typename WxWidgetWindow>
class WindowPeer : public ContainerPeer<WxWidgetWindow> {
public:
	WindowPeer(WxWidgetWindow* window);
	virtual ~WindowPeer();
	/**
	 * このウィンドウをトップレベルに設定します.
	 * @param app
	 */
	void modal(wxApp* app);

	/**
	 * フレームを画面中央に配置します.
	 */
	void centerOfScreen();

	/** 
	 * ウィンドウのタイトルを設定します.
	 * @parma title
	 */
	void setTitle(std::string title);

	/**
	 * ウィンドウのタイトルを返します.
	 * @return
	 */
	std::string getTitle() const;
};
#include "WindowPeerImpl.h"
#endif // !BEAN_WXGUI_WINDOWPEER_H


