#pragma once
#ifndef BEAN_WXGUI_WINDOWINTERFACE_H
#define BEAN_WXGUI_WINDOWINTERFACE_H
#include <string>
#include "ContainerInterface.h"
/**
 * Windowのうち、テンプレートに依存しない実装を提供します.
 */
class WindowInterface {
public:
	WindowInterface();
	virtual ~WindowInterface() = 0;
	/**
	 * ウィンドウを画面中央に配置します.
	 */
	virtual void centerOfScreen() = 0;

	/**
	 * ウィンドウのタイトルを設定します.
	 * @param title
	 */
	virtual void setTitle(std::string title) = 0;
	/**
	 * ウィンドウのタイトルを返します.
	 * @return
	 */
	virtual std::string getTitle() const = 0;
};
#endif // !BEAN_WXGUI_WINDOWINTERFACE_H
