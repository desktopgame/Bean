#include "ApplicationContext.h"
#include "Frame.h"
//public method---
ApplicationContext::ApplicationContext() {
	this->frame = nullptr;
}

ApplicationContext::~ApplicationContext() {
	delete frame;
}

bool ApplicationContext::OnInit() {
	this->frame = new Frame(wxT(""), 800, 600);
	wxInitAllImageHandlers();
	return true;
}

Frame * ApplicationContext::getFrame() const {
	return this->frame;
}

ApplicationContext * ApplicationContext::getInstance() {
	return dynamic_cast<ApplicationContext*>(wxApp::GetInstance());
}
//---public method