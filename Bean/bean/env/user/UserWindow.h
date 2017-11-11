#pragma once
#ifndef BEAN_ENV_USER_USERWINDOW_H
#define BEAN_ENV_USER_USERWINDOW_H
#include "UserContainer.h"
class WindowInterface;
/**
 * フレーム/ダイアログの基底クラス.
 */
class UserWindow : public UserContainer {
public:
	UserWindow(WindowInterface* windowInterface);
	virtual ~UserWindow();
	/** 
	 * タイトルを設定します.
	 * @param title
	 */
	void setTitle(std::string title);
	/**
	 * タイトルを返します.
	 * @return
	 */
	std::string getTitle() const;
protected:
	virtual void lazyLoading() override;
private:
	WindowInterface* windowInterface;
};
#endif // !BEAN_ENV_USER_USERWINDOW_H
