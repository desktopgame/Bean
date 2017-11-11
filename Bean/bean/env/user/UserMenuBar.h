#pragma once
#ifndef BEAN_ENV_USER_USERMENUBAR_H
#define BEAN_ENV_USER_USERMENUBAR_H
#include "UserContainer.h"
#include "../../wxgui/MenuBarInterface.h"
/**
 * ���j���[�o�[�̃��b�p�[.
 */
class UserMenuBar : public UserContainer, public MenuBarInterface {
public:
	UserMenuBar(MenuBarInterface* menuBarInterface);
	~UserMenuBar();
	// MenuBarInterface ����Čp������܂���
	wxMenu* addMenu(std::string label) override;
	void removeMenuAt(int index) override;
	int getMenuCount() override;
	wxMenuBar * getWXMenuBar() override;
protected:
	void lazyLoading() override;
private:
	MenuBarInterface* menuBarInterface;
};
#endif // !BEAN_ENV_USER_USERMENUBAR_H
