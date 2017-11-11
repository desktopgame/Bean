#pragma once
#ifndef BEAN_WXGUI_PAINTBOXPEER_H
#define BEAN_WXGUI_PAINTBOXPEER_H
#include "ComponentPeer.h"
#include "PaintBoxInterface.h"
#include "WxPaintBox.h"
/**
 * PaintBox�̒჌�x���ȐU�镑����񋟂��܂�.
 */
class PaintBoxPeer : public ComponentPeer<WxPaintBox>, public PaintBoxInterface {
public:
	PaintBoxPeer(wxWindow* window);
	~PaintBoxPeer();

	// PaintBoxInterface ����Čp������܂���
	void start() override;
	void stop() override;
	void addPaintListener(Paint paint) override;
	void removePaintListenerAt(int index) override;
	int getPaintListenerCount() const override;
};
#endif // !BEAN_WXGUI_PAINTBOXPEER_H
