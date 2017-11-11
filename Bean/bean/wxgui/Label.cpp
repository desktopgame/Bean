#include "Label.h"
#include "ContainerInterface.h"
#include "FrameInterface.h"
#include "LabelPeer.h"

//public method---
Label::Label(ContainerInterface* parent)
 : Component<LabelPeer>(new LabelPeer(parent->getWindow())) {
}

Label::~Label() {
}

void Label::setText(std::string text) {
	getPeer()->setText(text);
}

std::string Label::getText() {
	return getPeer()->getText();
}
//---public method
