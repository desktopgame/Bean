#pragma once
#ifndef BEAN_WXGUI_WINDOW_H
#define BEAN_WXGUI_WINDOW_H
#include "Container.h"
#include "WindowInterface.h"
/**
 * 移動,縮小,格納,展開,などの機能を備えた標準的なウィンドウです.
 */
template<typename WxWidgetWindowPeer>
class Window : public Container<WxWidgetWindowPeer>, public WindowInterface {
public:
	Window(WxWidgetWindowPeer* window);
	virtual ~Window();
	void modal(wxApp* app);

	// WindowInterface を介して継承されました
	void centerOfScreen() override;
	void setTitle(std::string title) override;
	std::string getTitle() const override;
};
#include "WindowImpl.h"
#endif // !BEAN_WXGUI_WINDOW_H
