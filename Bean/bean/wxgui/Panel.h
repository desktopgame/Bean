#pragma once
#ifndef BEAN_WXGUI_PANEL_H
#define BEAN_WXGUI_PANEL_H
#include "Container.h"
#include "PanelInterface.h"
#include "PanelPeer.h"
/**
 * 純粋なコンテナとして機能するクラスの最上位レイヤーです.
 * より抽象的な表現は UserPanel で提供されます。
 */
class Panel : public Container<PanelPeer>, public PanelInterface {
public:
	Panel(ContainerInterface* parent);
	~Panel();
};
#endif // !BEAN_WXGUI_PANEL_H
