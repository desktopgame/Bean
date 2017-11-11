#pragma once
#ifndef BEAN_WXGUI_LAYOUTMANAGER_H
#define BEAN_WXGUI_LAYOUTMANAGER_H
#include <wx/wx.h>
#include "LayoutManagerInterface.h"
/**
 * �e���v���[�g�Ŏ�������� LayoutManager �ł�.
 * ������ wxsizer �ւ̈Ϗ��ł��B
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
