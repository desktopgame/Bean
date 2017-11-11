#pragma once
#ifndef BEAN_WXGUI_PAINTBOX_H
#define BEAN_WXGUI_PAINTBOX_H
#include "Component.h"
#include "PaintBoxInterface.h"
#include "PaintBoxPeer.h"
/**
 * �y�C���g�{�b�N�X�̍ŏ�ʃ��C���[�ł�.
 * ��蒊�ۓI�ȕ\���� UserPaintBox �N���X�Œ񋟂���܂��B
 */
class PaintBox : public Component<PaintBoxPeer>, public PaintBoxInterface {
public:
	PaintBox(ContainerInterface* parent);
	~PaintBox();

	// PaintBoxInterface ����Čp������܂���
	void start() override;
	void stop() override;
	void addPaintListener(Paint paint) override;
	void removePaintListenerAt(int index) override;
	int getPaintListenerCount() const override;
};
#endif // !BEAN_WXGUI_PAINTBOX_H
