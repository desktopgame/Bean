#pragma once
#ifndef BEAN_WXGUI_WINDOW_H
#define BEAN_WXGUI_WINDOW_H
#include "Container.h"
#include "WindowInterface.h"
/**
 * �ړ�,�k��,�i�[,�W�J,�Ȃǂ̋@�\��������W���I�ȃE�B���h�E�ł�.
 */
template<typename WxWidgetWindowPeer>
class Window : public Container<WxWidgetWindowPeer>, public WindowInterface {
public:
	Window(WxWidgetWindowPeer* window);
	virtual ~Window();
	void modal(wxApp* app);

	// WindowInterface ����Čp������܂���
	void centerOfScreen() override;
	void setTitle(std::string title) override;
	std::string getTitle() const override;
};
#include "WindowImpl.h"
#endif // !BEAN_WXGUI_WINDOW_H
