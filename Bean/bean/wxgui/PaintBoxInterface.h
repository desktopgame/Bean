#pragma once
#ifndef BEAN_WXGUI_PAINTBOXINTERFACE_H
#define BEAN_WXGUI_PAINTBOXINTERFACE_H
#include "WxPaintBox.h"
/**
 * PaintBoxの実装のうちテンプレートに依存しないものを提供します.
 */
class PaintBoxInterface {
public:
	PaintBoxInterface();
	virtual ~PaintBoxInterface() = 0;

	/**
	 * アニメーションを開始します.
	 */
	virtual void start() = 0;

	/**
	 * アニメーションを一時停止します.
	 */
	virtual void stop() = 0;

	/**
	 * 描画を監視するイベントリスナーを追加します.
	 * @param paint
	 */
	virtual void addPaintListener(Paint paint) = 0;

	/**
	 * 描画を監視するイベントリスナーを削除します.
	 * @param index
	 */
	virtual void removePaintListenerAt(int index) = 0;

	/**
	 * 描画を監視するイベントリスナーの数を返します.
	 * @return
	 */
	virtual int getPaintListenerCount() const = 0;
};
#endif // !BEAN_WXGUI_PAINTBOXINTERFACE_H
