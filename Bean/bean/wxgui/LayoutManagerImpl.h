#pragma once
#ifndef BEAN_WXGUI_LAYOUTMANAGERIMPL_H
#define BEAN_WXGUI_LAYOUTMANAGERIMPL_H
#include "LayoutManager.h"

//public method---
template<typename WxSizer>
LayoutManager<WxSizer>::LayoutManager(WxSizer* sizer) {
	this->impl = sizer;
}

template<typename WxSizer>
LayoutManager<WxSizer>::~LayoutManager() {
}

template<typename WxSizer>
void LayoutManager<WxSizer>::addComponent(wxWindow * c, wxSizerFlags flags) {
	impl->Add(c, flags);
}

template<typename WxSizer>
void LayoutManager<WxSizer>::addSpace(int size) {
	impl->AddSpacer(size);
}

template<typename WxSizer>
void LayoutManager<WxSizer>::addStretch() {
	impl->AddStretchSpacer();
}

template<typename WxSizer>
void LayoutManager<WxSizer>::removeComponentAt(int index) {
	impl->Remove(index);
}

template<typename WxSizer>
int LayoutManager<WxSizer>::getComponentCount() {
	return impl->GetItemCount();
}

template<typename WxSizer>
void LayoutManager<WxSizer>::setMinSize(wxSize size) {
	impl->SetMinSize(size);
}

template<typename WxSizer>
wxSize LayoutManager<WxSizer>::getMinSize() {
	return impl->GetMinSize();
}

template<typename WxSizer>
void LayoutManager<WxSizer>::setFitSize(wxSize size) {
//	impl->SetVirtualSize(size);
}

template<typename WxSizer>
wxSize LayoutManager<WxSizer>::getFitSize() {
//	return impl->GetVirtualSize();
	return wxSize();
}

template<typename WxSizer>
void LayoutManager<WxSizer>::setMaxSize(wxSize size) {
//	impl->SetMaxSize(size);
}

template<typename WxSizer>
wxSize LayoutManager<WxSizer>::getMaxSize() {
//	return impl->GetMaxSize();
	return wxSize();
}

template<typename WxSizer>
void LayoutManager<WxSizer>::doLayout() {
	impl->Layout();
}

template<typename WxSizer>
wxSizer * LayoutManager<WxSizer>::getWX() {
	return this->impl;
}
//---public method
#endif // !BEAN_WXGUI_LAYOUTMANAGERIMPL_H
