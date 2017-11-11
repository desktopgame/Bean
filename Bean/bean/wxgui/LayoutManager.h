#pragma once
#ifndef BEAN_WXGUI_LAYOUTMANAGER_H
#define BEAN_WXGUI_LAYOUTMANAGER_H
#include <wx/wx.h>
#include "LayoutManagerInterface.h"
/**
 * テンプレートで実装される LayoutManager です.
 * 実装は wxsizer への委譲です。
 */
template<typename WxSizer>
class LayoutManager : public LayoutManagerInterface {
public:
	LayoutManager(WxSizer* sizer);
	~LayoutManager();

	void addComponent(wxWindow* c, wxSizerFlags flags) override;
	void addSpace(int size) override;
	void addStretch() override;
	void removeComponentAt(int index) override;
	int getComponentCount() override;
	void setMinSize(wxSize size) override;
	wxSize getMinSize() override;
	void setFitSize(wxSize size) override;
	wxSize getFitSize() override;
	void setMaxSize(wxSize size) override;
	wxSize getMaxSize() override;
	void doLayout() override;
	wxSizer* getWX() override;
private:
	WxSizer* impl;
};
#include "LayoutManagerImpl.h"
#endif // !BEAN_WXGUI_LAYOUTMANAGER_H
