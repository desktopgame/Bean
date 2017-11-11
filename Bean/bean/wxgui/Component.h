#pragma once
#ifndef BEAN_WXGUI_COMPONENT_H
#define BEAN_WXGUI_COMPONENT_H
#include "ComponentInterface.h"
/**
 * Wxwidget を ラップするコンポーネントです.
 */
template<typename WxWidgetPeer>
class Component : public ComponentInterface {
public:
	Component(WxWidgetPeer* target);
	virtual ~Component();
	
	// ComponentInterface を介して継承されました
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
	/**
	 * ピアインターフェイスを返します.
	 * @return
	 */
	WxWidgetPeer* const getPeer() const;
private:
	WxWidgetPeer* target;

};
#include "ComponentImpl.h"
#endif // !BEAN_WXGUI_COMPONENT_H


