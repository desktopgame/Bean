#pragma once
#ifndef BEAN_ENV_USER_USERCOMPONENT_H
#define BEAN_ENV_USER_USERCOMPONENT_H
#include <wx/wx.h>
#include "../Object_.h"
#include "../../wxgui/ComponentInterface.h"
/**
 * コンポーネントのラッパー.
 */
class UserComponent : public Object_, public ComponentInterface {
public:
	UserComponent(ComponentInterface* componentInterface);
	virtual ~UserComponent();

	void repaint() override;
	void setX(int x) override;
	int getX() override;
	void setY(int y) override;
	int getY() override;
	void setWidth(int w) override;
	int getWidth() override;
	void setHeight(int h) override;
	int getHeight() override;
	void setMinSize(wxSize size) override;
	wxSize getMinSize() override;
	void setFitSize(wxSize size) override;
	wxSize getFitSize() override;
	void setMaxSize(wxSize size) override;
	wxSize getMaxSize() override;
	void setForeground(wxColor foreColor) override;
	wxColor getForeground() override;
	void setBackground(wxColor backColor) override;
	wxColor getBackground() override;
	wxWindow* getWX() override;
	// Object_ を介して継承されました
	virtual Object_ * clone() override;
	UserComponent* asUserComponent() override;
protected:
	virtual void lazyLoading() override;
private:
	ComponentInterface* componentInterface;

};
#endif // !BEAN_ENV_USER_USERCOMPONENT_H
