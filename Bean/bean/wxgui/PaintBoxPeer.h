#pragma once
#ifndef BEAN_WXGUI_PAINTBOXPEER_H
#define BEAN_WXGUI_PAINTBOXPEER_H
#include "ComponentPeer.h"
#include "PaintBoxInterface.h"
#include "WxPaintBox.h"
/**
 * PaintBoxの低レベルな振る舞いを提供します.
 */
class PaintBoxPeer : public ComponentPeer<WxPaintBox>, public PaintBoxInterface {
public:
	PaintBoxPeer(wxWindow* window);
	~PaintBoxPeer();

	// PaintBoxInterface を介して継承されました
	void start() override;
	void stop() override;
	void addPaintListener(Paint paint) override;
	void removePaintListenerAt(int index) override;
	int getPaintListenerCount() const override;
};
#endif // !BEAN_WXGUI_PAINTBOXPEER_H
