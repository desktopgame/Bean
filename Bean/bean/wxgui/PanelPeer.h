#pragma once
#ifndef BEAN_WXGUI_PANELPEER_H
#define BEAN_WXGUI_PANELPEER_H
#include <wx/wx.h>
#include "ContainerPeer.h"
#include "PanelInterface.h"
#include "WxPanelEx.h"
/**
 * Panel‚Ì’áƒŒƒxƒ‹‚ÈU‚é•‘‚¢‚ğ’ñ‹Ÿ‚µ‚Ü‚·.
 */
class PanelPeer : public ContainerPeer<WxPanelEx>, public PanelInterface {
public:
	PanelPeer(wxWindow* window);
	~PanelPeer();
};
#endif // !BEAN_WXGUI_PANELPEER_H
