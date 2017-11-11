#pragma once
#ifndef BEAN_WXGUI_SCROLLPANE_H
#define BEAN_WXGUI_SCROLLPANE_H
#include "Container.h"
#include "ScrollPaneInterface.h"
#include "ScrollPanePeer.h"
/**
 * �X�N���[���\�̈�̍ŏ�ʃ��C���[�ł�.
 * ��蒊�ۓI�ȕ\���� UserScrollPane �Œ񋟂���܂��B
 */
class ScrollPane : public Container<ScrollPanePeer>, public ScrollPaneInterface {
public:
	ScrollPane(ContainerInterface* containerInterface);
	~ScrollPane();
};
#endif // !BEAN_WXGUI_SCROLLPANE_H
