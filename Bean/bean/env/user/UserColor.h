#pragma once
#ifndef BEAN_ENV_USER_USERCOLOR_H
#define BEAN_ENV_USER_USERCOLOR_H
#include <wx/wx.h>
#include "../Object_.h"
/**
 * wxColorのラッパー.
 */
class UserColor : public Object_ {
public:
	UserColor(float r, float g, float b, float a);
	UserColor(float r, float g, float b);
	UserColor(wxColor color);
	~UserColor();

	// Object_ を介して継承されました
	virtual Object_ * clone() override;
	virtual Object_ * equals(Object_ * right) override;
	/**
	 * wxwidgetの型で返します.
	 * @return
	 */
	wxColor getWXColor();
protected:
	void lazyLoading() override;
private:
	wxColor color;
};
#endif // !BEAN_ENV_USER_USERCOLOR_H
