#pragma once
#ifndef BEAN_WXGUI_BUTTONPEER_H
#define BEAN_WXGUI_BUTTONPEER_H
#include <wx/wx.h>
#include "ButtonInterface.h"
#include "ComponentPeer.h"
#include "WxButtonEx.h"
/**
 * Button‚Ì’áƒŒƒxƒ‹‚ÈU‚é•‘‚¢‚ğ’ñ‹Ÿ‚µ‚Ü‚·.
 */
class ButtonPeer : public ComponentPeer<WxButtonEx>, public ButtonInterface {
public:
	ButtonPeer(wxWindow* window);
	~ButtonPeer();

	void addPushListener(PushListener listener) override;
	void removePushListenerAt(int index) override;
	int getPushListenerCount() override;
	void setText(std::string text) override;
	std::string getText() override;
};
#endif // !BEAN_WXGUI_BUTTONPEER_H
