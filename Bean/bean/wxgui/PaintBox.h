#pragma once
#ifndef BEAN_WXGUI_PAINTBOX_H
#define BEAN_WXGUI_PAINTBOX_H
#include "Component.h"
#include "PaintBoxInterface.h"
#include "PaintBoxPeer.h"
/**
 * ペイントボックスの最上位レイヤーです.
 * より抽象的な表現は UserPaintBox クラスで提供されます。
 */
class PaintBox : public Component<PaintBoxPeer>, public PaintBoxInterface {
public:
	PaintBox(ContainerInterface* parent);
	~PaintBox();

	// PaintBoxInterface を介して継承されました
	void start() override;
	void stop() override;
	void addPaintListener(Paint paint) override;
	void removePaintListenerAt(int index) override;
	int getPaintListenerCount() const override;
};
#endif // !BEAN_WXGUI_PAINTBOX_H
