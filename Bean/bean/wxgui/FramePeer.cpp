#include "FramePeer.h"
#include <wx/wx.h>

//public method---
FramePeer::FramePeer(const wxString& title, int width, int height)
	: WindowPeer<WxFrameEx>(new WxFrameEx(title, width, height)) {
}

FramePeer::~FramePeer() {
}

void FramePeer::mainLoop() {
	//getTarget()->Layout();
	centerOfScreen();
	getTarget()->Show(true);
}

void FramePeer::pack() {
	getTarget()->Layout();
	getContentPane()->Fit();
	getTarget()->Fit();
}

wxPanel * FramePeer::getContentPane() const {
	return getTarget()->getContentPane();
}

void FramePeer::setLayout(wxSizer * sizer) {
	this->getContentPane()->SetSizer(sizer);
}

wxSizer * FramePeer::getLayout() {
	return this->getContentPane()->GetSizer();
}

void FramePeer::setMenuBar(wxMenuBar * menuBar) {
	getTarget()->SetMenuBar(menuBar);
}

wxMenuBar * FramePeer::getMenuBar() {
	return getTarget()->GetMenuBar();
}

void FramePeer::createStatusBar(int length) {
	getTarget()->CreateStatusBar(length);
}

void FramePeer::printStatus(int index, std::string text) {
	getTarget()->SetStatusText(text, index);
}
//---public method