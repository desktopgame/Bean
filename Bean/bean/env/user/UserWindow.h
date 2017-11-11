#pragma once
#ifndef BEAN_ENV_USER_USERWINDOW_H
#define BEAN_ENV_USER_USERWINDOW_H
#include "UserContainer.h"
class WindowInterface;
/**
 * �t���[��/�_�C�A���O�̊��N���X.
 */
class UserWindow : public UserContainer {
public:
	UserWindow(WindowInterface* windowInterface);
	virtual ~UserWindow();
	/** 
	 * �^�C�g����ݒ肵�܂�.
	 * @param title
	 */
	void setTitle(std::string title);
	/**
	 * �^�C�g����Ԃ��܂�.
	 * @return
	 */
	std::string getTitle() const;
protected:
	virtual void lazyLoading() override;
private:
	WindowInterface* windowInterface;
};
#endif // !BEAN_ENV_USER_USERWINDOW_H
