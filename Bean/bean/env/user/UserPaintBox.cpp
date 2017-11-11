#include "UserPaintBox.h"
#include "UserDelegate.h"
#include "UserGraphics.h"
#include "../ClassLoader.h"
#include "../Delegate.h"
#include "../Object_.h"
#include "../Package.h"
#include "../gc/Block.h"
#include "../gc/Heap.h"
#include "../../wxgui/EventSystem.h"
#include "../../threads/Thread.h"

//public method---
UserPaintBox::UserPaintBox(PaintBoxInterface* paintBoxInterface) 
 : UserComponent(dynamic_cast<ComponentInterface*>(paintBoxInterface)) {
	this->paintBoxInterface = paintBoxInterface;
	this->paintDelegateVector = std::vector<UserDelegate*>();
	paintBoxInterface->addPaintListener([&](WxPaintBox* sender, wxPaintDC* dc, wxPaintEvent& e) { filterEvent(sender, dc, e); });
}

UserPaintBox::~UserPaintBox() {
	delete paintBoxInterface;
}

void UserPaintBox::start() {
	paintBoxInterface->start();
}

void UserPaintBox::stop() {
	paintBoxInterface->stop();
}

void UserPaintBox::addPaintListener(Paint paint) {
	paintBoxInterface->addPaintListener(paint);
}

void UserPaintBox::addPaintListener(UserDelegate * ud) {
	paintDelegateVector.push_back(ud);
}

void UserPaintBox::removePaintListenerAt(int index) {
	paintBoxInterface->removePaintListenerAt(index);
}

int UserPaintBox::getPaintListenerCount() const {
	return paintBoxInterface->getPaintListenerCount();
}

std::vector<Object_*> UserPaintBox::getVirtualField() {
	auto r = std::vector<Object_*>(paintDelegateVector.begin(), paintDelegateVector.end());
	return concatDynamicMembers(r);
}

void UserPaintBox::filterEvent(WxPaintBox * sender, wxPaintDC * dc, wxPaintEvent & e) {
	Block::startAsync();
	std::vector<Object_*> args = std::vector<Object_*>();
	args.push_back(this);
	args.push_back(new UserGraphics(dc));
	EventSystem::postEvent(paintDelegateVector, args);
	Block::endAsync();
}
//---public method

//proteced method---
void UserPaintBox::lazyLoading() {
	setClass(Package::getClassOrLoad("api.wxgui.PaintBox"));
}
//---protected method
