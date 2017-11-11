#pragma once
#ifndef BEAN_WXGUI_CONTAINERINTERFACE_H
#define BEAN_WXGUI_CONTAINERINTERFACE_H
#include <wx/wx.h>
#include "ComponentInterface.h"
/**
 * Container�̂����A�e���v���[�g�Ɉˑ����Ȃ�������񋟂��܂�.
 */
class ContainerInterface {
public:
	ContainerInterface();
	virtual ~ContainerInterface() = 0;
	/**
	 * �w��̃��C�A�E�g��K�p���܂�.
	 * @param sizer
	 */
	virtual void setLayout(wxSizer* sizer) = 0;

	/**
	 * ���݂̃��C�A�E�g��Ԃ��܂�.
	 */
	virtual wxSizer* getLayout() = 0;

	/**
	 * �E�B���h�E��Ԃ��܂�.
	 * @return
	 */
	virtual wxWindow* getWindow() = 0;
};
#endif // !BEAN_WXGUI_CONTAINERINTERFACE_H