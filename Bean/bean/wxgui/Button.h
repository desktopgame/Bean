#pragma once
#ifndef BEAN_WXGUI_BUTTON_H
#define BEAN_WXGUI_BUTTON_H
#include "ButtonInterface.h"
#include "ButtonPeer.h"
#include "Component.h"
#include "Frame.h"
/**
 * 押し込み可能なボタンの最上位レイヤーです.
 * より抽象的な表現は UserButton クラスで提供されます。
 */
class FrameInterface;
class Button : public Component<ButtonPeer>, public ButtonInterface {
public:
	Button(ContainerInterface* parent);
	~Button();

	// ButtonInterface を介して継承されました
	void addPushListener(PushListener listener) override;
	void removePushListenerAt(int index) override;
	int getPushListenerCount() override;

	void setText(std::string text) override;
	std::string getText() override;
};
#endif // !BEAN_WXGUI_BUTTON_H
