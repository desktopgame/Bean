#pragma once
#ifndef BEAN_WXGUI_CONTAINERPEER_H
#define BEAN_WXGUI_CONTAINERPEER_H
#include "ComponentPeer.h"
#include "ContainerInterface.h"
/**
 * �R���|�[�l���g�s�A���R���e�i�����Ɋg���������̂ł�.
 */
template<typename WxWidgetContainer>
class ContainerPeer : public ComponentPeer<WxWidgetContainer>, public ContainerInterface {
public:
	ContainerPeer(WxWidgetContainer* container);
	virtual ~ContainerPeer();
	virtual void setLayout(wxSizer* sizer) override;
	virtual wxSizer* getLayout() override;
	virtual wxWindow* getWindow() override;
};
#include "ContainerPeerImpl.h"
#endif // !BEAN_WXGUI_CONTAINERPEER_H
