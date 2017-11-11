#pragma once
#ifndef BEAN_ENV_USER_USERPANEL_H
#define BEAN_ENV_USER_USERPANEL_H
#include "UserContainer.h"
#include "../../wxgui/PanelInterface.h"
/**
 * パネルのラッパー.
 */
class UserPanel : public UserContainer, public PanelInterface {
public:
	UserPanel(PanelInterface* panelInterface);
	~UserPanel();
private:
	PanelInterface* panelInterface;
};
#endif // !BEAN_ENV_USER_USERPANEL_H
