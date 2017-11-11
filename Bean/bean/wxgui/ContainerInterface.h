#pragma once
#ifndef BEAN_WXGUI_CONTAINERINTERFACE_H
#define BEAN_WXGUI_CONTAINERINTERFACE_H
#include <wx/wx.h>
#include "ComponentInterface.h"
/**
 * Containerのうち、テンプレートに依存しない実装を提供します.
 */
class ContainerInterface {
public:
	ContainerInterface();
	virtual ~ContainerInterface() = 0;
	/**
	 * 指定のレイアウトを適用します.
	 * @param sizer
	 */
	virtual void setLayout(wxSizer* sizer) = 0;

	/**
	 * 現在のレイアウトを返します.
	 */
	virtual wxSizer* getLayout() = 0;

	/**
	 * ウィンドウを返します.
	 * @return
	 */
	virtual wxWindow* getWindow() = 0;
};
#endif // !BEAN_WXGUI_CONTAINERINTERFACE_H