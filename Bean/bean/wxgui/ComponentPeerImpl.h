#pragma once
#ifndef BEAN_WXGUI_COMPONENTPEERIMPL_H
#define BEAN_WXGUI_COMPONENTPEERIMPL_H
#include "ComponentPeer.h"
#include "ContainerInterface.h"

//public method---
template<typename WxWidget>
ComponentPeer<WxWidget>::ComponentPeer(WxWidget* target) {
	this->target = target;
}

template<typename WxWidget>
ComponentPeer<WxWidget>::~ComponentPeer() {
}

template<typename WxWidget>
WxWidget * const ComponentPeer<WxWidget>::getTarget() const {
	return this->target;
}

template<typename WxWidget>
void ComponentPeer<WxWidget>::repaint() {
	getTarget()->Refresh();
}

template<typename WxWidget>
void ComponentPeer<WxWidget>::setX(int x) {
	wxPoint p = getPosition();
	setPosition(wxPoint(x, p.y));
}

template<typename WxWidget>
int ComponentPeer<WxWidget>::getX() {
	return getPosition().x;
}

template<typename WxWidget>
void ComponentPeer<WxWidget>::setY(int y) {
	wxPoint p = getPosition();
	setPosition(wxPoint(p.x, y));
}

template<typename WxWidget>
int ComponentPeer<WxWidget>::getY() {
	return getPosition().y;
}


template<typename WxWidget>
void ComponentPeer<WxWidget>::setWidth(int w) {
	wxSize s = getSize();
	setSize(wxSize(w, s.y));
}

template<typename WxWidget>
int ComponentPeer<WxWidget>::getWidth() {
	return getSize().x;
}

template<typename WxWidget>
void ComponentPeer<WxWidget>::setHeight(int h) {
	wxSize s = getSize();
	setSize(wxSize(s.x, h));
}

template<typename WxWidget>
int ComponentPeer<WxWidget>::getHeight() {
	return getSize().y;
}

template<typename WxWidget>
void ComponentPeer<WxWidget>::setMinSize(wxSize size) {
	getTarget()->SetMinSize(size);
}

template<typename WxWidget>
wxSize ComponentPeer<WxWidget>::getMinSize() {
	return getTarget()->GetMinSize();
}

template<typename WxWidget>
void ComponentPeer<WxWidget>::setFitSize(wxSize size) {
	getTarget()->SetVirtualSize(size);
}

template<typename WxWidget>
wxSize ComponentPeer<WxWidget>::getFitSize() {
	return getTarget()->GetVirtualSize();
}

template<typename WxWidget>
void ComponentPeer<WxWidget>::setMaxSize(wxSize size) {
	getTarget()->SetMaxSize(size);
}

template<typename WxWidget>
wxSize ComponentPeer<WxWidget>::getMaxSize() {
	return getTarget()->GetMaxSize();
}

template<typename WxWidget>
void ComponentPeer<WxWidget>::setForeground(wxColor foreColor) {
	getTarget()->SetForegroundColour(foreColor);
}

template<typename WxWidget>
wxColor ComponentPeer<WxWidget>::getForeground() {
	return getTarget()->GetForegroundColour();
}

template<typename WxWidget>
void ComponentPeer<WxWidget>::setBackground(wxColor backColor) {
	getTarget()->SetBackgroundColour(backColor);
}

template<typename WxWidget>
wxColor ComponentPeer<WxWidget>::getBackground() {
	return getTarget()->GetBackgroundColour();
}

template<typename WxWidget>
wxWindow * ComponentPeer<WxWidget>::getWX() {
	return getTarget();
}

template<typename WxWidget>
void ComponentPeer<WxWidget>::setParent(ContainerInterface * container) {
	getTarget()->SetParent(container);
}

template<typename WxWidget>
ContainerInterface * ComponentPeer<WxWidget>::getParent() const {
	return NULL;
}
//---public method

//private method---
template<typename WxWidget>
void ComponentPeer<WxWidget>::setPosition(wxPoint point) {
	getTarget()->SetPosition(point);
}

template<typename WxWidget>
wxPoint ComponentPeer<WxWidget>::getPosition() {
	return getTarget()->GetPosition();
}

template<typename WxWidget>
void ComponentPeer<WxWidget>::setSize(wxSize size) {
	getTarget()->SetSize(size);
}

template<typename WxWidget>
wxSize ComponentPeer<WxWidget>::getSize() {
	return getTarget()->GetSize();
}
//---private method
#endif // !BEAN_WXGUI_COMPONENTPEERIMPL_H
