#pragma once
#ifndef BEAN_WXGUI_FRAME_H
#define BEAN_WXGUI_FRAME_H
#include <functional>
#include <vector>
#include "FrameInterface.h"
#include "FramePeer.h"
#include "Window.h"
enum {
	wxID_TEXT_LABEL
};
/**
 * フレームの最上位レイヤーです.
 * より抽象的な表現は UserFrame クラスで提供されます。
 */
class Frame : public Window<FramePeer>, public FrameInterface {
public:
	Frame(const wxString& title, int width, int height);
	~Frame();
	void mainLoop() override;
	void pack() override;
	wxWindow* getWindow() override;
	wxPanel* getContentPane() const override;
	void setMenuBar(wxMenuBar* menubar) override;
	wxMenuBar* getMenuBar() override;
	void createStatusBar(int length) override;
	void printStatus(int index, std::string text) override;
protected:
};
//#include "FrameImpl.h"
#endif // !BEAN_WXGUI_FRAME_H
