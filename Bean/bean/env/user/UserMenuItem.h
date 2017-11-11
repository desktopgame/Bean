#pragma once
#ifndef BEAN_ENV_USER_USERMENUITEM_H
#define BEAN_ENV_USER_USERMENUITEM_H
#include "UserMenuElement.h"
/**
 * メニューアイテムのラッパー.
 */
class UserMenuItem : public UserMenuElement {
public:
	UserMenuItem(wxMenuItem* item);
	UserMenuItem();
	~UserMenuItem();
	void setText(std::string text) override;
	std::string getText() override;
	wxMenuItem* getWXMenuItem() override;
	wxMenu* getWXMenu() override;
	void setSelected(bool isSelected) override;
	bool isSelected() override;
protected:
	void lazyLoading() override;
private:
	std::string label;
	wxMenuItem* itemEx;
};
#endif // !BEAN_ENV_USER_USERMENUITEM_H
