#pragma once
#ifndef BEAN_ENV_USER_USERMENU_H
#define BEAN_ENV_USER_USERMENU_H
#include "UserMenuElement.h"
#include "../Object_.h"
/**
 * メニューのラッパー.
 */
class UserMenu : public UserMenuElement {
public:
	UserMenu(wxMenu* menu);
	UserMenu();
	~UserMenu();

	void setText(std::string text) override;
	std::string getText() override;
	wxMenuItem* getWXMenuItem() override;
	wxMenu* getWXMenu() override;
	void setSelected(bool isSelected) override;
	bool isSelected() override;
	wxMenuItem* addMenuItem(std::string label);
	wxMenuItem* addCheckBoxMenuItem(std::string label);
	wxMenu* addMenu(std::string label);
	void addSeparator();
	void removeSubElementAt(int index);
	int getSubElementCount();
	
protected:
	std::string label;
	void lazyLoading() override;
private:
	wxMenu* menuEx;
};
#endif // !BEAN_ENV_USER_USERMENU_H
