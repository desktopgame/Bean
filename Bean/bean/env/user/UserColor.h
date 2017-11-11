#pragma once
#ifndef BEAN_ENV_USER_USERCOLOR_H
#define BEAN_ENV_USER_USERCOLOR_H
#include <wx/wx.h>
#include "../Object_.h"
/**
 * wxColor‚Ìƒ‰ƒbƒp[.
 */
class UserColor : public Object_ {
public:
	UserColor(float r, float g, float b, float a);
	UserColor(float r, float g, float b);
	UserColor(wxColor color);
	~UserColor();

	// Object_ ‚ğ‰î‚µ‚ÄŒp³‚³‚ê‚Ü‚µ‚½
	virtual Object_ * clone() override;
	virtual Object_ * equals(Object_ * right) override;
	/**
	 * wxwidget‚ÌŒ^‚Å•Ô‚µ‚Ü‚·.
	 * @return
	 */
	wxColor getWXColor();
protected:
	void lazyLoading() override;
private:
	wxColor color;
};
#endif // !BEAN_ENV_USER_USERCOLOR_H
