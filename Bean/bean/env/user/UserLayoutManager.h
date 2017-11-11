#pragma once
#ifndef BEAN_ENV_USER_USERLAYOUTMANAGER_H
#define BEAN_ENV_USER_USERLAYOUTMANAGER_H
#include "../Object_.h"
#include "../../wxgui/LayoutManagerInterface.h"
/**
 * ���C�A�E�g�}�l�[�W���̃��b�p�[.
 */
class UserLayoutManager : public Object_, public LayoutManagerInterface {
public:
	UserLayoutManager(LayoutManagerInterface* layoutManagerInterface);
	~UserLayoutManager();
	// LayoutManagerInterface ����Čp������܂���
	void addComponent(wxWindow * c, wxSizerFlags flags) override;
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

	// Object_ ����Čp������܂���
	Object_ * clone() override;
protected:
	void lazyLoading() override;
private:
	LayoutManagerInterface* layoutManagerInterface;
};
#endif // !BEAN_ENV_USER_USERLAYOUTMANAGER_H
