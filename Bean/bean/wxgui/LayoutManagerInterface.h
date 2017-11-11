#pragma once
#ifndef BEAN_WXGUI_LAYOUTMANAGERINTERFACE_H
#define BEAN_WXGUI_LAYOUTMANAGERINTERFACE_H
#include <wx/wx.h>
/**
 * LayoutManager�̂����e���v���[�g�Ɉˑ����Ȃ�������񋟂��܂�.
 */
class LayoutManagerInterface {
public:
	LayoutManagerInterface();
	virtual ~LayoutManagerInterface() = 0;
	/**
	 * �R���|�[�l���g��ǉ����܂�.
	 * @param c
	 * @param flags
	 */
	virtual void addComponent(wxWindow* c, wxSizerFlags flags) = 0;

	/**
	 * �L�k���Ȃ��]����ǉ����܂�.
	 * @param size
	 */
	virtual void addSpace(int size) = 0;

	/**
	 * �L�k����]����ǉ����܂�.
	 */
	virtual void addStretch() = 0;

	/**
	 * �w��ʒu�̃R���|�[�l���g���폜���܂�.
	 * @param index
	 */
	virtual void removeComponentAt(int index) = 0;

	/**
	 * �S�ẴR���|�[�l���g�̐���Ԃ��܂�.
	 * @return
	 */
	virtual int getComponentCount() = 0;

	/**
	 * ���C�A�E�g�̍ŏ��T�C�Y��ݒ肵�܂�.
	 * @param size
	 */
	virtual void setMinSize(wxSize size) = 0;
	/**
	 * ���C�A�E�g�̍ŏ��T�C�Y��Ԃ��܂�.
	 * @return
	 */
	virtual wxSize getMinSize() = 0;
	/**
	 * ���C�A�E�g�̐����T�C�Y��ݒ肵�܂�.
	 * @param size
	 */
	virtual void setFitSize(wxSize size) = 0;
	/**
	 * ���C�A�E�g�̐����T�C�Y��Ԃ��܂�.
	 * @return
	 */
	virtual wxSize getFitSize() = 0;
	/**
	 * ���C�A�E�g�̍ő�T�C�Y��ݒ肵�܂�.
	 * @param size
	 */
	virtual void setMaxSize(wxSize size) = 0;
	/**
	 * ���C�A�E�g�̍ő�T�C�Y��Ԃ��܂�.
	 * @return
	 */
	virtual wxSize getMaxSize() = 0;
	/**
	 * �����I�ɍă��C�A�E�g�����s���܂�.
	 */
	virtual void doLayout() = 0;

	/**
	 * wxwidget�̌^�ŕԂ��܂�.
	 * @return
	 */
	virtual wxSizer* getWX() = 0;
};
#endif // !BEAN_WXGUI_LAYOUTMANAGERINTERFACE_H
