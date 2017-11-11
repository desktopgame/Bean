#pragma once
#ifndef BEAN_WXGUI_BUTTONINTERFACE_H
#define BEAN_WXGUI_BUTTONINTERFACE_H
#include <string>
#include "../wxgui/WxButtonEx.h"
/**
 * Buttonの実装のうちテンプレートに依存しない実装を提供します.
 */
class ButtonInterface {
public:
	ButtonInterface();
	virtual ~ButtonInterface() = 0;

	/**
	 * ボタンが押されたときに処理を実行するリスナーを追加します.
	 * @param listener
	 */
	virtual void addPushListener(PushListener listener) = 0;

	/**
	 * ボタンが押されたときに処理を実行するリスナーを削除します.
	 * @param index
	 */
	virtual void removePushListenerAt(int index) = 0;

	/**
	 * ボタンが押されたときに処理を実行するリスナーの数を返します.
	 * @return
	 */
	virtual int getPushListenerCount() = 0;

	/**
	 * ボタンに表示される文字列を設定します.
	 * @param text
	 */
	virtual void setText(std::string text) = 0;

	/**
	 * ボタンに表示される文字列を返します.
	 * @return
	 */
	virtual std::string getText() = 0;
};
#endif // !BEAN_WXGUI_BUTTONINTERFACE_H
