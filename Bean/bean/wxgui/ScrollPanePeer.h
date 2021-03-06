#pragma once
#ifndef BEAN_WXGUI_SCROLLPANEPEER_H
#define BEAN_WXGUI_SCROLLPANEPEER_H
#include "ContainerPeer.h"
#include "ScrollPaneInterface.h"
#include "WxScrollPaneEx.h"
/**
 * ScrollPaneの低レベルな振る舞いを提供します.
 */
class ScrollPanePeer : public ContainerPeer<WxScrollPaneEx>, public ScrollPaneInterface {
public:
	ScrollPanePeer(wxWindow* window);
	~ScrollPanePeer();
};
#endif // !BEAN_WXGUI_SCROLLPANEPEER_H
