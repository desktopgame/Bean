#pragma once
#ifndef BEAN_WXGUI_SCROLLPANEINTERFACE_H
#define BEAN_WXGUI_SCROLLPANEINTERFACE_H
/**
 * ScrollPaneのうちテンプレートに依存しない実装を提供します.
 */
class ScrollPaneInterface {
public:
	ScrollPaneInterface();
	virtual ~ScrollPaneInterface() = 0;
};
#endif // !BEAN_WXGUI_SCROLLPANEINTERFACE_H
