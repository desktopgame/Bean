#pragma once
#ifndef BEAN_ENV_USER_USERLABEL_H
#define BEAN_ENV_USER_USERLABEL_H
#include "UserComponent.h"
#include "../../wxgui/LabelInterface.h"
/**
 * ラベルのラッパー.
 */
class UserLabel : public UserComponent, public LabelInterface {
public:
	UserLabel(LabelInterface* labelInterface);
	~UserLabel();

	void setText(std::string text) override;
	std::string getText() override;
protected:
	void lazyLoading() override;
private:
	LabelInterface* labelInterface;
};
#endif // !BEAN_ENV_USER_USERLABEL_H
