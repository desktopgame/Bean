#pragma once
#ifndef BEAN_WXGUI_FRAMEINTERFACE_H
#define BEAN_WXGUI_FRAMEINTERFACE_H
#include <wx/wx.h>
#include "WindowInterface.h"
/**
 * Frame�̂����A�e���v���[�g�Ɉˑ����Ȃ�������񋟂��܂�.
 */
class FrameInterface {
public:
	FrameInterface();
	virtual ~FrameInterface() = 0;
	/**
	 * �E�B���h�E������܂ŌĂяo������ҋ@���āA
	 * �ʂ̃X���b�h�ł��̃E�B���h�E�̃C�x���g���[�v���J�n���܂��B
	 */
	virtual void mainLoop() = 0;

	/**
	 * �E�B���h�E�T�C�Y���œK�����܂�.
	 */
	virtual void pack() = 0;


	/**
	 * �R���|�[�l���g��z�u���邽�߂̗̈��Ԃ��܂�.
	 * @return
	 */
	virtual wxPanel* getContentPane() const = 0;

	/**
	 * ���j���[�o�[��ݒ肵�܂�.
	 * @param menubar
	 */
	virtual void setMenuBar(wxMenuBar* menuBar) = 0;

	/**
	 * ���j���[�o�[��Ԃ��܂�.
	 * @return
	 */
	virtual wxMenuBar* getMenuBar() = 0;

	/**
	 * �w��̐��̍��ڂ�\�����邽�߂̃X�e�[�^�X�o�[���쐬���܂�.
	 * @param length
	 */
	virtual void createStatusBar(int length) = 0;

	/**
	 * �w��ʒu�̍��ڂ����������܂�.
	 * @param index
	 * @param text
	 */
	virtual void printStatus(int index, std::string text) = 0;
};
#endif // !BEAN_WXGUI_FRAMEINTERFACE_H
