#pragma once
#ifndef BEAN_ENV_USER_USERSCROLLPANE_H
#define BEAN_ENV_USER_USERSCROLLPANE_H
#include "UserContainer.h"
#include "../../wxgui/ScrollPaneInterface.h"
/**
 * スクロール稼働領域のラッパー.
 */
class UserScrollPane : public UserContainer, public ScrollPaneInterface {
public:
	UserScrollPane(ScrollPaneInterface* scrollPaneInterface);
	~UserScrollPane();
protected:
	void lazyLoading() override;
private:
	ScrollPaneInterface* scrollPaneInterface;
};
#endif // !BEAN_ENV_USER_USERSCROLLPANE_H
