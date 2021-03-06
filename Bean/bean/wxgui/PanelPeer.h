#pragma once
#ifndef BEAN_WXGUI_PANELPEER_H
#define BEAN_WXGUI_PANELPEER_H
#include <wx/wx.h>
#include "ContainerPeer.h"
#include "PanelInterface.h"
#include "WxPanelEx.h"
/**
 * Panelの低レベルな振る舞いを提供します.
 */
class PanelPeer : public ContainerPeer<WxPanelEx>, public PanelInterface {
public:
	PanelPeer(wxWindow* window);
	~PanelPeer();
};
#endif // !BEAN_WXGUI_PANELPEER_H
