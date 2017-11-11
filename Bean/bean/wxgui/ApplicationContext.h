#pragma once
#ifndef BEAN_WXGUI_APPLICATIONCONTEXT_H
#define BEAN_WXGUI_APPLICATIONCONTEXT_H
#include <wx/wx.h>
#include <wx/wxprec.h>
class Frame;
/**
 * wxwidgets の wxApp をラップしたクラスです.
 */
class ApplicationContext : public wxApp {
public:
	ApplicationContext();
	~ApplicationContext();
	/**
	 * アプリケーション起動時に呼ばれます.
	 * @return
	 */
	bool OnInit();

	/**
	 * 現在起動しているフレームを返します.
	 * @return
	 */
	Frame* getFrame() const;

	/**
	 * 唯一のインスタンスを返します.
	 * @return
	 */
	static ApplicationContext* getInstance();
private:
	Frame* frame;
};
#endif // !BEAN_WXGUI_APPLICATIONCONTEXT_H
