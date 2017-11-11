#pragma once
#ifndef BEAN_WXGUI_FRAMEINTERFACE_H
#define BEAN_WXGUI_FRAMEINTERFACE_H
#include <wx/wx.h>
#include "WindowInterface.h"
/**
 * Frameのうち、テンプレートに依存しない実装を提供します.
 */
class FrameInterface {
public:
	FrameInterface();
	virtual ~FrameInterface() = 0;
	/**
	 * ウィンドウが閉じるまで呼び出し側を待機して、
	 * 別のスレッドでこのウィンドウのイベントループを開始します。
	 */
	virtual void mainLoop() = 0;

	/**
	 * ウィンドウサイズを最適化します.
	 */
	virtual void pack() = 0;


	/**
	 * コンポーネントを配置するための領域を返します.
	 * @return
	 */
	virtual wxPanel* getContentPane() const = 0;

	/**
	 * メニューバーを設定します.
	 * @param menubar
	 */
	virtual void setMenuBar(wxMenuBar* menuBar) = 0;

	/**
	 * メニューバーを返します.
	 * @return
	 */
	virtual wxMenuBar* getMenuBar() = 0;

	/**
	 * 指定の数の項目を表示するためのステータスバーを作成します.
	 * @param length
	 */
	virtual void createStatusBar(int length) = 0;

	/**
	 * 指定位置の項目を書き換えます.
	 * @param index
	 * @param text
	 */
	virtual void printStatus(int index, std::string text) = 0;
};
#endif // !BEAN_WXGUI_FRAMEINTERFACE_H
