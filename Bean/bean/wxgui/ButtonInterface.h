#pragma once
#ifndef BEAN_WXGUI_BUTTONINTERFACE_H
#define BEAN_WXGUI_BUTTONINTERFACE_H
#include <string>
#include "../wxgui/WxButtonEx.h"
/**
 * Button�̎����̂����e���v���[�g�Ɉˑ����Ȃ�������񋟂��܂�.
 */
class ButtonInterface {
public:
	ButtonInterface();
	virtual ~ButtonInterface() = 0;

	/**
	 * �{�^���������ꂽ�Ƃ��ɏ��������s���郊�X�i�[��ǉ����܂�.
	 * @param listener
	 */
	virtual void addPushListener(PushListener listener) = 0;

	/**
	 * �{�^���������ꂽ�Ƃ��ɏ��������s���郊�X�i�[���폜���܂�.
	 * @param index
	 */
	virtual void removePushListenerAt(int index) = 0;

	/**
	 * �{�^���������ꂽ�Ƃ��ɏ��������s���郊�X�i�[�̐���Ԃ��܂�.
	 * @return
	 */
	virtual int getPushListenerCount() = 0;

	/**
	 * �{�^���ɕ\������镶�����ݒ肵�܂�.
	 * @param text
	 */
	virtual void setText(std::string text) = 0;

	/**
	 * �{�^���ɕ\������镶�����Ԃ��܂�.
	 * @return
	 */
	virtual std::string getText() = 0;
};
#endif // !BEAN_WXGUI_BUTTONINTERFACE_H
