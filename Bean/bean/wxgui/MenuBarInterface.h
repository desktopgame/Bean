#pragma once
#ifndef BEAN_WXGUI_MENUBARINTERFACE_H
#define BEAN_WXGUI_MENUBARINTERFACE_H
#include <wx/wx.h>
/**
 * MenuBar �̎����̂����e���v���[�g�Ɉˑ����Ȃ����̂�񋟂��܂�.
 */
class MenuBarInterface {
public:
	MenuBarInterface();
	virtual ~MenuBarInterface() = 0;
	/**
	 * ���j���[��ǉ����܂�.
	 * @param label
	 * @return
	 */
	virtual wxMenu* addMenu(std::string label) = 0;

	/**
	 * �w��ʒu�̃��j���[���폜���܂�.
	 * @param index
	 */
	virtual void removeMenuAt(int index) = 0;

	/**
	 * ���j���[�̐���Ԃ��܂�.
	 * @return
	 */
	virtual int getMenuCount() = 0;

	/**
	 * WX�̌^�ŕԂ��܂�.
	 * @return
	 */
	virtual wxMenuBar* getWXMenuBar() = 0;
};
#endif // !BEAN_WXGUI_MENUBARINTERFACE_H
