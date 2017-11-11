#pragma once
#ifndef BEAN_WXGUI_FRAMEPEER_H
#define BEAN_WXGUI_FRAMEPEER_H
#include "FrameInterface.h"
#include "WindowPeer.h"
#include "WxFrameEx.h"
/**
 * Frame‚Ì’áƒŒƒxƒ‹‚ÈU‚é•‘‚¢‚ğ’ñ‹Ÿ‚µ‚Ü‚·.
 */
class FramePeer : public WindowPeer<WxFrameEx>, public FrameInterface {
public:
	FramePeer(const wxString& title, int width, int height);
	~FramePeer();
	
	void mainLoop() override;
	void pack() override;
	wxPanel* getContentPane() const override;

	void setLayout(wxSizer* sizer) override;
	wxSizer* getLayout() override;
	void setMenuBar(wxMenuBar* menuBar) override;
	wxMenuBar* getMenuBar() override;
	void createStatusBar(int length) override;
	void printStatus(int index, std::string text) override;
};
//#include "FramePeerImpl.h"
#endif // !BEAN_WXGUI_FRAMEPEER_H


