#pragma once
#ifndef BEAN_WXGUI_BUTTON_H
#define BEAN_WXGUI_BUTTON_H
#include "ButtonInterface.h"
#include "ButtonPeer.h"
#include "Component.h"
#include "Frame.h"
/**
 * �������݉\�ȃ{�^���̍ŏ�ʃ��C���[�ł�.
 * ��蒊�ۓI�ȕ\���� UserButton �N���X�Œ񋟂���܂��B
 */
class FrameInterface;
class Button : public Component<ButtonPeer>, public ButtonInterface {
public:
	Button(ContainerInterface* parent);
	~Button();

	// ButtonInterface ����Čp������܂���
	void addPushListener(PushListener listener) override;
	void removePushListenerAt(int index) override;
	int getPushListenerCount() override;

	void setText(std::string text) override;
	std::string getText() override;
};
#endif // !BEAN_WXGUI_BUTTON_H
