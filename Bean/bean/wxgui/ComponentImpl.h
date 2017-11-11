#pragma once
#ifndef BEAN_WXGUI_COMPONENTIMPL_H
#define BEAN_WXGUI_COMPONENTIMPL_H
#include "Component.h"

//public method---
template<typename WxWidgetPeer>
Component<WxWidgetPeer>::Component(WxWidgetPeer* target) {
	this->target = target;
}

template<typename WxWidgetPeer>
Component<WxWidgetPeer>::~Component() {
	delete target;
}

template<typename WxWidgetPeer>
void Component<WxWidgetPeer>::repaint() {
	getPeer()->repaint();
}

template<typename WxWidgetPeer>
void Component<WxWidgetPeer>::setX(int x) {
	target->setX(x);
}

template<typename WxWidgetPeer>
int Component<WxWidgetPeer>::getX() {
	return target->getX();
}

template<typename WxWidgetPeer>
void Component<WxWidgetPeer>::setY(int y) {
	target->setY(y);
}

template<typename WxWidgetPeer>
int Component<WxWidgetPeer>::getY() {
	return target->getY();
}

template<typename WxWidgetPeer>
void Component<WxWidgetPeer>::setWidth(int w) {
	target->setWidth(w);
}

template<typename WxWidgetPeer>
int Component<WxWidgetPeer>::getWidth() {
	return target->getWidth();
}

template<typename WxWidgetPeer>
void Component<WxWidgetPeer>::setHeight(int h) {
	target->setHeight(h);
}

template<typename WxWidgetPeer>
int Component<WxWidgetPeer>::getHeight() {
	return target->getHeight();
}

template<typename WxWidgetPeer>
void Component<WxWidgetPeer>::setMinSize(wxSize size) {
	target->setMinSize(size);
}

template<typename WxWidgetPeer>
wxSize Component<WxWidgetPeer>::getMinSize() {
	return target->getMinSize();
}

template<typename WxWidgetPeer>
void Component<WxWidgetPeer>::setFitSize(wxSize size) {
	target->setFitSize(size);
}

template<typename WxWidgetPeer>
wxSize Component<WxWidgetPeer>::getFitSize() {
	return target->getFitSize();
}

template<typename WxWidgetPeer>
void Component<WxWidgetPeer>::setMaxSize(wxSize size) {
	target->setMaxSize(size);
}

template<typename WxWidgetPeer>
wxSize Component<WxWidgetPeer>::getMaxSize() {
	return target->getMaxSize();
}

template<typename WxWidgetPeer>
void Component<WxWidgetPeer>::setForeground(wxColor foreColor) {
	target->setForeground(foreColor);
}

template<typename WxWidgetPeer>
wxColor Component<WxWidgetPeer>::getForeground() {
	return target->getForeground();
}

template<typename WxWidgetPeer>
void Component<WxWidgetPeer>::setBackground(wxColor backColor) {
	target->setBackground(backColor);
}

template<typename WxWidgetPeer>
wxColor Component<WxWidgetPeer>::getBackground() {
	return target->getBackground();
}

template<typename WxWidgetPeer>
wxWindow * Component<WxWidgetPeer>::getWX() {
	return target->getWX();
}

template<typename WxWidgetPeer>
WxWidgetPeer * const Component<WxWidgetPeer>::getPeer() const {
	return this->target;
}
//---public method
#endif // !BEAN_WXGUI_COMPONENTIMPL_H
