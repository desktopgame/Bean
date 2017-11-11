#pragma once
#ifndef BEAN_WXGUI_SCROLLPANE_H
#define BEAN_WXGUI_SCROLLPANE_H
#include "Container.h"
#include "ScrollPaneInterface.h"
#include "ScrollPanePeer.h"
/**
 * スクロール可能領域の最上位レイヤーです.
 * より抽象的な表現は UserScrollPane で提供されます。
 */
class ScrollPane : public Container<ScrollPanePeer>, public ScrollPaneInterface {
public:
	ScrollPane(ContainerInterface* containerInterface);
	~ScrollPane();
};
#endif // !BEAN_WXGUI_SCROLLPANE_H
