#pragma once
#ifndef BEAN_WXGUI_APPLICATIONCONTEXT_H
#define BEAN_WXGUI_APPLICATIONCONTEXT_H
#include <wx/wx.h>
#include <wx/wxprec.h>
class Frame;
/**
 * wxwidgets �� wxApp �����b�v�����N���X�ł�.
 */
class ApplicationContext : public wxApp {
public:
	ApplicationContext();
	~ApplicationContext();
	/**
	 * �A�v���P�[�V�����N�����ɌĂ΂�܂�.
	 * @return
	 */
	bool OnInit();

	/**
	 * ���݋N�����Ă���t���[����Ԃ��܂�.
	 * @return
	 */
	Frame* getFrame() const;

	/**
	 * �B��̃C���X�^���X��Ԃ��܂�.
	 * @return
	 */
	static ApplicationContext* getInstance();
private:
	Frame* frame;
};
#endif // !BEAN_WXGUI_APPLICATIONCONTEXT_H
