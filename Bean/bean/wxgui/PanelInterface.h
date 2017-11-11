#pragma once
#ifndef BEAN_WXGUI_PANELINTERFACE_H
#define BEAN_WXGUI_PANELINTERFACE_H
/**
 * Panelの実装のうちテンプレートに依存しないものを提供します.
 */
class PanelInterface {
public:
	PanelInterface();
	virtual ~PanelInterface() = 0;
};
#endif // !BEAN_WXGUI_PANELINTERFACE_H
