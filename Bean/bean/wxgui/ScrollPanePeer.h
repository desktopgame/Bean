#pragma once
#ifndef BEAN_WXGUI_SCROLLPANEPEER_H
#define BEAN_WXGUI_SCROLLPANEPEER_H
#include "ContainerPeer.h"
#include "ScrollPaneInterface.h"
#include "WxScrollPaneEx.h"
/**
 * ScrollPane�̒჌�x���ȐU�镑����񋟂��܂�.
 */
class ScrollPanePeer : public ContainerPeer<WxScrollPaneEx>, public ScrollPaneInterface {
public:
	ScrollPanePeer(wxWindow* window);
	~ScrollPanePeer();
};
#endif // !BEAN_WXGUI_SCROLLPANEPEER_H
