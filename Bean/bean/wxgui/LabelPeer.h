#pragma once
#ifndef BEAN_WXGUI_LABELPEER_H
#define BEAN_WXGUI_LABELPEER_H
#include <wx/wx.h>
#include "ComponentPeer.h"
#include "LabelInterface.h"
#include "WxLabelEx.h"
/**
 * Label‚Ì’áƒŒƒxƒ‹‚ÈU‚é•‘‚¢‚ğ’ñ‹Ÿ‚µ‚Ü‚·.
 */
class LabelPeer : public ComponentPeer<WxLabelEx>, public LabelInterface {
public:
	LabelPeer(wxWindow* window);
	~LabelPeer();

	void setText(std::string text) override;
	std::string getText() override;
};
#endif // !BEAN_WXGUI_LABELPEER_H
