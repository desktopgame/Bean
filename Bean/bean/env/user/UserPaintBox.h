#pragma once
#ifndef BEAN_ENV_USER_USERPAINTBOX_H
#define BEAN_ENV_USER_USERPAINTBOX_H
#include "UserComponent.h"
#include "../../wxgui/PaintBoxInterface.h"
class UserDelegate;
/**
 * �y�C���g�{�b�N�X�̃��b�p�[.
 */
class UserPaintBox : public UserComponent, public PaintBoxInterface {
public:
	UserPaintBox(PaintBoxInterface* paintBoxInterface);
	~UserPaintBox();

	// PaintBoxInterface ����Čp������܂���
	void start() override;
	void stop() override;

	void addPaintListener(Paint paint) override;
	void addPaintListener(UserDelegate* ud);

	void removePaintListenerAt(int index) override;
	int getPaintListenerCount() const override;
	std::vector<Object_*> getVirtualField() override;

	void filterEvent(WxPaintBox* sender, wxPaintDC* dc, wxPaintEvent& e);
protected:
	void lazyLoading() override;
private:
	PaintBoxInterface* paintBoxInterface;
	std::vector<UserDelegate*> paintDelegateVector;
};
#endif // !BEAN_ENV_USER_USERPAINTBOX_H
