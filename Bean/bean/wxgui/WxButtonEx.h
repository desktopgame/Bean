#pragma once
#ifndef BEAN_WXGUI_WXBUTTONEX_H
#define BEAN_WXGUI_WXBUTTONEX_H
#include <functional>
#include <vector>
#include <wx/wx.h>
/**
 * �{�^���������ꂽ�Ƃ��ɌĂяo�����֐�.
 */
class WxButtonEx;
using PushListener = std::function<void(WxButtonEx*, const wxCommandEvent&)>;
/**
 * Button�̊g���ł�.
 * �s�A�N���X�̈Ϗ���Ƃ��Ďg�p����܂��B
 */
class WxButtonEx : public wxButton {
public:
	WxButtonEx(wxWindow* parent, wxWindowID id, const wxString& label);
	~WxButtonEx();
	//
	//�C�x���g
	//

	/**
	 * �C�x���g���X�i�[��ǉ����܂�.
	 * @param listener
	 */
	void addPushListener(PushListener listener);

	/**
	 * �C�x���g���X�i�[���폜���܂�.
	 * @param index
	 */
	void removePushListenerAt(int index);

	/**
	 * ���X�i�[�̐���Ԃ��܂�.
	 * @return
	 */
	int getPushListenerCount() const;

	/**
	 * �{�^�����������܂��ƌĂ΂�܂�.
	 * @param e
	 */
	void OnPush(wxCommandEvent& e);
protected:
	/**
	 * �v�b�V���C�x���g��ʒm���܂�.
	 * @param sender
	 * @param e
	 */
	void firePushEvent(WxButtonEx* sender, wxCommandEvent& e);
private:
	std::vector<PushListener> pushListenerList;
//	wxDECLARE_EVENT_TABLE();
};
#endif // !BEAN_WXGUI_WXBUTTONEX_H
