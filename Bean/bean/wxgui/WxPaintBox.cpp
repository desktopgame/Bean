#include "WxPaintBox.h"

//public method---
WxPaintBox::WxPaintBox(wxWindow* window, wxWindowID id) 
 : wxPanel(window, id, wxDefaultPosition, wxDefaultSize) {
	this->paintListenerList = std::vector<Paint>();
	this->timer = new wxTimer(this, 1);
	Connect(wxEVT_PAINT, wxPaintEventHandler(WxPaintBox::OnPaint));
	Connect(wxEVT_TIMER, wxCommandEventHandler(WxPaintBox::OnTick));
	SetDoubleBuffered(true);
}

WxPaintBox::~WxPaintBox() {
	delete timer;
}

void WxPaintBox::start() {
	if (!timer->IsRunning()) {
		timer->Start(1, false);
	}
}

void WxPaintBox::stop() {
	if (timer->IsRunning()) {
		timer->Stop();
	}
}

void WxPaintBox::addPaintListener(Paint p) {
	this->paintListenerList.push_back(p);
}

void WxPaintBox::removePaintListenerAt(int index) {
	paintListenerList.erase(paintListenerList.begin() + index);
}

int WxPaintBox::getPaintListenerCount() const {
	return paintListenerList.size();
}

void WxPaintBox::OnPaint(wxPaintEvent & e) {
	wxPaintDC dc(this);
	for (int i = 0; i < paintListenerList.size(); i++) {
		Paint p = paintListenerList.at(i);
		p(this, &dc, e);
	}
}

void WxPaintBox::OnTick(wxCommandEvent & e) {
	Refresh();
}
//---public method