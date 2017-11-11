#include "UserGraphics.h"
#include <iostream>
#include "UserBitmap.h"
#include "../Class.h"
#include "../Package.h"

//public method---
UserGraphics::UserGraphics(wxPaintDC* dc) 
 : Object_(nullptr) {
	this->dc = dc;
}

UserGraphics::~UserGraphics() {
}

void UserGraphics::clear() {
	this->dc->Clear();
}

void UserGraphics::drawDot(wxCoord x, wxCoord y) {
	this->dc->DrawPoint(x, y);
}

void UserGraphics::drawLine(wxCoord x1, wxCoord y1, wxCoord x2, wxCoord y2) {
	this->dc->DrawLine(x1, y1, x2, y2);
}

void UserGraphics::drawEllipse(wxCoord x, wxCoord y, wxCoord w, wxCoord h) {
	this->dc->DrawEllipse(x, y, w, h);
}

void UserGraphics::drawRect(wxCoord x, wxCoord y, wxCoord w, wxCoord h) {
	this->dc->DrawRectangle(x, y, w, h);
}

void UserGraphics::drawString(const wxString & s, wxCoord x, wxCoord y) {
	this->dc->DrawText(s, x, y);
}

void UserGraphics::drawBitmap(const wxBitmap & bmp, wxCoord x, wxCoord y) {
	this->dc->DrawBitmap(bmp, x, y);
}

void UserGraphics::drawBitmap(UserBitmap * ubmp, wxCoord x, wxCoord y) {
	ubmp->draw(this->dc, x, y);
}

Object_ * UserGraphics::clone() {
	return nullptr;
}
//---public method

//protected method---
void UserGraphics::lazyLoading() {
	ClassSPtr cls = Package::getClassOrLoad("api.wxgui.Graphics");
//	if (cls == NULL) std::cout << "null" << std::endl;
//	else std::cout << cls->getName() << std::endl;
	//cls->registerClass();
//	std::cout << "count " << cls.use_count() << std::endl;
//	int i = cls.use_count();
	setClass(cls);
}
//---protected method
