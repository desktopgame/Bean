#pragma once
#ifndef BEAN_WXGUI_LABEL_H
#define BEAN_WXGUI_LABEL_H
#include "Component.h"
#include "LabelInterface.h"
#include "LabelPeer.h"
/**
 * ラベルの最上位レイヤーです.
 * より抽象的な表現は UserLabel クラスで提供されます。
 */
class ContainerInterface;
class Label : public Component<LabelPeer>, public LabelInterface {
public:
	Label(ContainerInterface* parent);
	~Label();

	void setText(std::string text) override;
	std::string getText() override;
};
#endif // !BEAN_WXGUI_LABEL_H
