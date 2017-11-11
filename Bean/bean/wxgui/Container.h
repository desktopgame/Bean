#pragma once
#ifndef BEAN_WXGUI_CONTAINER_H
#define BEAN_WXGUI_CONTAINER_H
#include "Component.h"
#include "ContainerInterface.h"
/**
 * コンポーネントを包含可能なコンポーネント.
 */
template<typename WxWidgetContainerPeer>
class Container : public Component<WxWidgetContainerPeer>, public ContainerInterface {
public:
	Container(WxWidgetContainerPeer* container);
	virtual ~Container();
	void setLayout(wxSizer* layout) override;
	wxSizer* getLayout() override;
	virtual wxWindow* getWindow() override;
};
#include "ContainerImpl.h"
#endif // !BEAN_WXGUI_CONTAINER_H
