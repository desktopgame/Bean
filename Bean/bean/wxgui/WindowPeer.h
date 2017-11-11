#pragma once
#ifndef BEAN_WXGUI_WINDOWPEER_H
#define BEAN_WXGUI_WINDOWPEER_H
#include <wx/wx.h>
#include "ContainerPeer.h"
/**
 * Window�̒჌�x���ȐU�镑����񋟂��܂�.
 */
template<typename WxWidgetWindow>
class WindowPeer : public ContainerPeer<WxWidgetWindow> {
public:
	WindowPeer(WxWidgetWindow* window);
	virtual ~WindowPeer();
	/**
	 * ���̃E�B���h�E���g�b�v���x���ɐݒ肵�܂�.
	 * @param app
	 */
	void modal(wxApp* app);

	/**
	 * �t���[������ʒ����ɔz�u���܂�.
	 */
	void centerOfScreen();

	/** 
	 * �E�B���h�E�̃^�C�g����ݒ肵�܂�.
	 * @parma title
	 */
	void setTitle(std::string title);

	/**
	 * �E�B���h�E�̃^�C�g����Ԃ��܂�.
	 * @return
	 */
	std::string getTitle() const;
};
#include "WindowPeerImpl.h"
#endif // !BEAN_WXGUI_WINDOWPEER_H


