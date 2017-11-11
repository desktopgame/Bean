#include "Window.h"
#pragma once
#ifndef BEAN_WXGUI_WINDOWIMPL_H
#define BEAN_WXGUI_WINDOWIMPL_H
//#include "Window.h"

//public method---
template<typename WxWidgetWindowPeer>
Window<WxWidgetWindowPeer>::Window(WxWidgetWindowPeer* window)
	: Container<WxWidgetWindowPeer>(window) {
}

template<typename WxWidgetWindowPeer>
Window<WxWidgetWindowPeer>::~Window() {
}

template<typename WxWidgetWindowPeer>
void Window<WxWidgetWindowPeer>::modal(wxApp* app) {
	getPeer()->modal(app);
}

template<typename WxWidgetWindowPeer>
void Window<WxWidgetWindowPeer>::centerOfScreen() {
	getPeer()->centerOfScreen();
}

template<typename WxWidgetWindowPeer>
void Window<WxWidgetWindowPeer>::setTitle(std::string title) {
	getPeer()->setTitle(title);
}

template<typename WxWidgetWindowPeer>
std::string Window<WxWidgetWindowPeer>::getTitle() const {
	return getPeer()->getTitle();
}
//---public method
#endif // !BEAN_WXGUI_WINDOWIMPL_H
