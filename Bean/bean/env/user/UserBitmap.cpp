#include "UserBitmap.h"
#include "../Package.h"

UserBitmap::UserBitmap(const wxBitmap& bmp) 
 : Object_(nullptr) {
	this->bmp = bmp;
}

UserBitmap::~UserBitmap() {
}

Object_ * UserBitmap::clone() {
	return nullptr;
}

void UserBitmap::draw(wxDC * g, int x, int y) {
	g->DrawBitmap(bmp, x, y);
}

int UserBitmap::getWidth() const {
	return bmp.GetWidth();
}

int UserBitmap::getHeight() const {
	return bmp.GetHeight();
}

wxBitmapType UserBitmap::fromString(const std::string name) {
	wxBitmapType type = wxBitmapType::wxBITMAP_TYPE_ANY;
	if (name == "Bmp") type = wxBitmapType::wxBITMAP_TYPE_BMP;
	else if (name == "Png") type = wxBitmapType::wxBITMAP_TYPE_PNG;
	else if (name == "Jpeg") type = wxBitmapType::wxBITMAP_TYPE_JPEG;
	else if (name == "Gif") type = wxBitmapType::wxBITMAP_TYPE_GIF;
	return type;
}

//protected method---
void UserBitmap::lazyLoading() {
	setClass(Package::getClassOrLoad("api.wxgui.Bitmap"));
}
//---protected method