#include"Frame.h"
#include <wx/wx.h>

//public method---
Frame::Frame(const wxString & title, int width, int height)
	: Window<FramePeer>(new FramePeer(title, width, height)) {
}

Frame::~Frame() {
}

void Frame::mainLoop() {
	getPeer()->modal(wxTheApp);
	getPeer()->mainLoop();
	wxTheApp->OnRun();
}

void Frame::pack() {
	getPeer()->pack();
}

wxWindow * Frame::getWindow() {
	return getPeer()->getContentPane();
}

wxPanel * Frame::getContentPane() const {
	return getPeer()->getContentPane();
}

void Frame::setMenuBar(wxMenuBar * menubar) {
	getPeer()->setMenuBar(menubar);
}

wxMenuBar * Frame::getMenuBar() {
	return getPeer()->getMenuBar();
}

void Frame::createStatusBar(int length) {
	getPeer()->createStatusBar(length);
}

void Frame::printStatus(int index, std::string text) {
	getPeer()->printStatus(index, text);
}
//---public method
