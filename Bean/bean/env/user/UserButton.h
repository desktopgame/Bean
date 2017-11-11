#pragma once
#ifndef BEAN_ENV_USER_USERBUTTON_H
#define BEAN_ENV_USER_USERBUTTON_H
#include <wx/wx.h>
#include "UserComponent.h"
#include "../../wxgui/ButtonInterface.h"
class UserDelegate;
class WxButtonEx;
/**
 * �{�^���̃��b�p�[.
 */
class UserButton : public UserComponent, public ButtonInterface {
public:
	UserButton(ButtonInterface* buttonInterface);
	~UserButton();
	/**
	 * Bean�ɑ΂��ăf�B�X�p�b�`����郊�X�i�[��ǉ����܂�.
	 * ���ۂɂ̓��X�i�[�͈�����ł����A
	 * ���̃��X�i�[�����̃��\�b�h�Œǉ����ꂽ�S�Ẵf���Q�[�g�֒ʒm���܂��B
	 * @param d
	 */
	void addPushListener(UserDelegate* d);
	void addPushListener(PushListener listener) override;

	/**
	 * Bean�ɑ΂��ăf�B�X�p�b�`����郊�X�i�[���폜���܂�.
	 * @param index
	 */
	void removePushListenerAt(int index) override;
	
	/**
	 * Bean�ɑ΂��ăf�B�X�p�b�`����郊�X�i�[�̐���Ԃ��܂�.
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
