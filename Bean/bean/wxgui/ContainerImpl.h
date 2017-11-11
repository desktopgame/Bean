#pragma once
#ifndef BEAN_WXGUI_CONTAINERIMPL_H
#define BEAN_WXGUI_CONTAINERIMPL_H
#include "Container.h"

//public method---
template<typename WxWidgetContainerPeer>
Container<WxWidgetContainerPeer>::Container(WxWidgetContainerPeer* container)
	: Component<WxWidgetContainerPeer>(container) {
}

template<typename WxWidgetContainerPeer>
Container<WxWidgetContainerPeer>::~Container() {
}

template<typename WxWidgetContainerPeer>
void Container<WxWidgetContainerPeer>::setLayout(wxSizer * layout) {
	getPeer()->setLayout(layout);
}

template<typename WxWidgetContainerPeer>
wxSizer * Container<WxWidgetContainerPeer>::getLayout() {
	return getPeer()->getLayout();
}

template<typename WxWidgetContainerPeer>
wxWindow * Container<WxWidgetContainerPeer>::getWindow() {
	return getPeer()->getWindow();
}
//---public method
#endif // !BEAN_WXGUI_CONTAINERIMPL_H
