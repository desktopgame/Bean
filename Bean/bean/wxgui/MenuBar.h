#pragma once
#ifndef BEAN_WXGUI_MENUBAR_H
#define BEAN_WXGUI_MENUBAR_H
#include "Container.h"
#include "MenuBarInterface.h"
#include "MenuBarPeer.h"
/**
 * ���j���[�o�[�̍ŏ�ʃ��C���[�ł�.
 * ��蒊�ۓI�ȕ\���� UserMenuBar �N���X�Œ񋟂���܂��B
 */
class MenuBar : public Container<MenuBarPeer>, public MenuBarInterface {
public:
	MenuBar();
	~MenuBar();

	// MenuBarInterface ����Čp������܂���
	wxMenu* addMenu(std::string label) override;
	void removeMenuAt(int index) override;
	int getMenuCount() override;
	wxMenuBar * getWXMenuBar() override;
};
#endif // !BEAN_WXGUI_MENUBAR_H
