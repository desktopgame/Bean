#pragma once
#ifndef BEAN_ENV_USER_USERCONTAINER_H
#define BEAN_ENV_USER_USERCONTAINER_H
#include "UserComponent.h"
#include "../../wxgui/ContainerInterface.h"
/**
 * コンテナのラッパー.
 */
class UserContainer : public UserComponent, public ContainerInterface {
public:
	UserContainer(ContainerInterface* containerInterface);
	virtual ~UserContainer();

	void setLayout(wxSizer* sizer) override;
	wxSizer* getLayout();
	virtual wxWindow * getWindow() override;
protected:
	virtual void lazyLoading() override;
private:
	ContainerInterface* containerInterface;
};
#endif // !BEAN_ENV_USER_USERCONTAINER_H
