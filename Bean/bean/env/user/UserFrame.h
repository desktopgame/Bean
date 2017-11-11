#pragma once
#ifndef BEAN_ENV_USER_USERFRAME_H
#define BEAN_ENV_USER_USERFRAME_H
#include <wx/wx.h>
#include "UserWindow.h"
#include "../../wxgui/FrameInterface.h"
class FrameInterface;
/**
 * �t���[���̃��b�p�[.
 */
class UserFrame : public UserWindow, public FrameInterface {
public:
	UserFrame(FrameInterface* frameInterface);
	~UserFrame();

	// FrameInterface ����Čp������܂���
	void mainLoop() override;
	void pack() override;
	wxPanel * getContentPane() const override;
	void setMenuBar(wxMenuBar * menuBar) override;
	wxMenuBar * getMenuBar() override;
	void createStatusBar(int length) override;
	void printStatus(int index, std::string text) override;
protected:
	virtual void lazyLoading() override;
private:
	FrameInterface* frameInterface;
};
#endif // !BEAN_ENV_USER_USERFRAME_H
