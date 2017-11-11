#pragma once
#ifndef BEAN_WXGUI_WINDOWINTERFACE_H
#define BEAN_WXGUI_WINDOWINTERFACE_H
#include <string>
#include "ContainerInterface.h"
/**
 * Window�̂����A�e���v���[�g�Ɉˑ����Ȃ�������񋟂��܂�.
 */
class WindowInterface {
public:
	WindowInterface();
	virtual ~WindowInterface() = 0;
	/**
	 * �E�B���h�E����ʒ����ɔz�u���܂�.
	 */
	virtual void centerOfScreen() = 0;

	/**
	 * �E�B���h�E�̃^�C�g����ݒ肵�܂�.
	 * @param title
	 */
	virtual void setTitle(std::string title) = 0;
	/**
	 * �E�B���h�E�̃^�C�g����Ԃ��܂�.
	 * @return
	 */
	virtual std::string getTitle() const = 0;
};
#endif // !BEAN_WXGUI_WINDOWINTERFACE_H
