#pragma once
#ifndef BEAN_WXGUI_WXPAINTBOX_H
#define BEAN_WXGUI_WXPAINTBOX_H
#include <functional>
#include <vector>
#include <wx/wx.h>
//#include <thread>
//#include <mutex>
class WxPaintBox;
using Paint = std::function<void(WxPaintBox*, wxPaintDC*, wxPaintEvent&)>;
/**
 * Panel�̊g���ł�.
 * �s�A�N���X�̈Ϗ���Ƃ��Ďg�p����܂��B
 */
class WxPaintBox : public wxPanel {
public:
	WxPaintBox(wxWindow* window, wxWindowID id);
	~WxPaintBox();

	/**
	 * �A�j���[�V�������J�n���܂�.
	 */
	void start();

	/**
	 * �A�j���[�V�������ꎞ��~���܂�.
	 */
	void stop();

	/**
	 * �`����Ď����郊�X�i�[��ǉ����܂�.
	 * @param p
	 */
	void addPaintListener(Paint p);

	/**
	 * �`����Ď����郊�X�i�[���폜���܂�.
	 * @param index
	 */
	void removePaintListenerAt(int index);

	/**
	 * �`����Ď����郊�X�i�[�̐���Ԃ��܂�.
	 * @return
	 */
	int getPaintListenerCount() const;

	void OnPaint(wxPaintEvent& e);
	void OnTick(wxCommandEvent& e);
private:
	std::vector<Paint> paintListenerList;
	wxTimer* timer;
};
#endif // !BEAN_WXGUI_WXPAINTBOX_H
