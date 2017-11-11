#pragma once
#ifndef BEAN_WXGUI_SCROLLPANEPEER_H
#define BEAN_WXGUI_SCROLLPANEPEER_H
#include "ContainerPeer.h"
#include "ScrollPaneInterface.h"
#include "WxScrollPaneEx.h"
/**
 * ScrollPane‚Ì’áƒŒƒxƒ‹‚ÈU‚é•‘‚¢‚ğ’ñ‹Ÿ‚µ‚Ü‚·.
 */
class ScrollPanePeer : public ContainerPeer<WxScrollPaneEx>, public ScrollPaneInterface {
public:
	ScrollPanePeer(wxWindow* window);
	~ScrollPanePeer();
};
#endif // !BEAN_WXGUI_SCROLLPANEPEER_H
