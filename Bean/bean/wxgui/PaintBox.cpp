#include "PaintBox.h"


PaintBox::PaintBox(ContainerInterface* parent) 
 : Component<PaintBoxPeer>(new PaintBoxPeer(parent->getWindow())) {
}

PaintBox::~PaintBox() {
}

void PaintBox::start() {
	getPeer()->start();
}

void PaintBox::stop() {
	getPeer()->stop();
}

void PaintBox::addPaintListener(Paint paint) {
	getPeer()->addPaintListener(paint);
}

void PaintBox::removePaintListenerAt(int index) {
	getPeer()->removePaintListenerAt(index);
}

int PaintBox::getPaintListenerCount() const {
	return getPeer()->getPaintListenerCount();
}
