#include "PaintBoxPeer.h"

//public method---
PaintBoxPeer::PaintBoxPeer(wxWindow* window) 
 : ComponentPeer<WxPaintBox>(new WxPaintBox(window, wxID_ANY)) {
}

PaintBoxPeer::~PaintBoxPeer() {
}

void PaintBoxPeer::start() {
	getTarget()->start();
}

void PaintBoxPeer::stop() {
	getTarget()->stop();
}

void PaintBoxPeer::addPaintListener(Paint paint) {
	getTarget()->addPaintListener(paint);
}

void PaintBoxPeer::removePaintListenerAt(int index) {
	getTarget()->removePaintListenerAt(index);
}

int PaintBoxPeer::getPaintListenerCount() const {
	return getTarget()->getPaintListenerCount();
}
//---public method