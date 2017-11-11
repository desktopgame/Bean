#pragma once
#ifndef BEAN_WXGUI_LABELINTERFACE_H
#define BEAN_WXGUI_LABELINTERFACE_H
#include <string>
/** 
 * Label の実装のうちテンプレートに依存しないものを提供します.
 */
class LabelInterface {
public:
	LabelInterface();
	virtual ~LabelInterface() = 0;
	/**
	 * 表示される文字列を設定します.
	 * @param text
	 */
	virtual void setText(std::string text) = 0;
	/**
	 * 表示される文字列を返します.
	 * @return
	 */
	virtual std::string getText() = 0;
};
#endif // !BEAN_WXGUI_LABELINTERFACE_H
