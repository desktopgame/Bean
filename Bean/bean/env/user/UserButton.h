#pragma once
#ifndef BEAN_ENV_USER_USERBUTTON_H
#define BEAN_ENV_USER_USERBUTTON_H
#include <wx/wx.h>
#include "UserComponent.h"
#include "../../wxgui/ButtonInterface.h"
class UserDelegate;
class WxButtonEx;
/**
 * ボタンのラッパー.
 */
class UserButton : public UserComponent, public ButtonInterface {
public:
	UserButton(ButtonInterface* buttonInterface);
	~UserButton();
	/**
	 * Beanに対してディスパッチされるリスナーを追加します.
	 * 実際にはリスナーは一つだけですが、
	 * そのリスナーがこのメソッドで追加された全てのデリゲートへ通知します。
	 * @param d
	 */
	void addPushListener(UserDelegate* d);
	void addPushListener(PushListener listener) override;

	/**
	 * Beanに対してディスパッチされるリスナーを削除します.
	 * @param index
	 */
	void removePushListenerAt(int index) override;
	
	/**
	 * Beanに対してディスパッチされるリスナーの数を返します.
	 * @return
	 */
	int getPushListenerCount() override;

	void setText(std::string text) override;
	std::string getText() override;

	std::vector<Object_*> getVirtualField() override;
	void filterEvent(WxButtonEx* sender, const wxCommandEvent& e);
protected:
	void lazyLoading() override;
private:
	ButtonInterface* buttonInterface;
	std::vector<UserDelegate*> pushDelegateVector;
};
#endif // !BEAN_ENV_USER_USERBUTTON_H
