#pragma once
#ifndef BEAN_WXGUI_PANEL_H
#define BEAN_WXGUI_PANEL_H
#include "Container.h"
#include "PanelInterface.h"
#include "PanelPeer.h"
/**
 * �����ȃR���e�i�Ƃ��ċ@�\����N���X�̍ŏ�ʃ��C���[�ł�.
 * ��蒊�ۓI�ȕ\���� UserPanel �Œ񋟂���܂��B
 */
class Panel : public Container<PanelPeer>, public PanelInterface {
public:
	Panel(ContainerInterface* parent);
	~Panel();
};
#endif // !BEAN_WXGUI_PANEL_H
