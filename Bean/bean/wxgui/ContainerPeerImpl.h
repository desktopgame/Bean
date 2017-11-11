#pragma once
#ifndef BEAN_WXGUI_CONTAINERPEERIMPL_H
#define BEAN_WXGUI_CONTAINERPEERIMPL_H
#include "ContainerInterface.h"
#include "ContainerPeer.h"

//public method---
template<typename WxWidgetContainer>
ContainerPeer<WxWidgetContainer>::ContainerPeer(WxWidgetContainer* container)
	: ComponentPeer<WxWidgetContainer>(container) {
}

template<typename WxWidgetContainer>
ContainerPeer<WxWidgetContainer>::~ContainerPeer() {
}
template<typename WxWidgetContainer>
void ContainerPeer<WxWidgetContainer>::setLayout(wxSizer * sizer) {
	getTarget()->SetSizer(sizer);
}

template<typename WxWidgetContainer>
wxSizer* ContainerPeer<WxWidgetContainer>::getLayout() {
	return getTarget()->GetSizer();
}

template<typename WxWidgetContainer>
wxWindow * ContainerPeer<WxWidgetContainer>::getWindow() {
	return getTarget();
}
//---public method
#endif // !BEAN_WXGUI_CONTAINERPEERIMPL_H
