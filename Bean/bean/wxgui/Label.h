#pragma once
#ifndef BEAN_WXGUI_LABEL_H
#define BEAN_WXGUI_LABEL_H
#include "Component.h"
#include "LabelInterface.h"
#include "LabelPeer.h"
/**
 * ���x���̍ŏ�ʃ��C���[�ł�.
 * ��蒊�ۓI�ȕ\���� UserLabel �N���X�Œ񋟂���܂��B
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
