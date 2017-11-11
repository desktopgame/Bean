#pragma once
#ifndef BEAN_WXGUI_WINDOWPEERIMPL_H
#define BEAN_WXGUI_WINDOWPEERIMPL_H
#include <wx/wx.h>
#include "WindowPeer.h"

//public method---
template<typename WxWidgetWindow>
WindowPeer<WxWidgetWindow>::WindowPeer(WxWidgetWindow* window)
	: ContainerPeer<WxWidgetWindow>(window) {
}

template<typename WxWidgetWindow>
WindowPeer<WxWidgetWindow>::~WindowPeer() {
}

template<typename WxWidgetWindow>
void WindowPeer<WxWidgetWindow>::modal(wxApp* app) {
	app->SetTopWindow(getTarget());
}

template<typename WxWidgetWindow>
void WindowPeer<WxWidgetWindow>::centerOfScreen() {
	getTarget()->Centre();
}

template<typename WxWidgetWindow>
void WindowPeer<WxWidgetWindow>::setTitle(std::string title) {
	getTarget()->SetTitle(title);
}

template<typename WxWidgetWindow>
std::string WindowPeer<WxWidgetWindow>::getTitle() const {
	return getTarget()->GetTitle();
}
//---public method
#endif // !BEAN_WXGUI_WINDOWPEERIMPL_H
