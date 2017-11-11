#pragma once
#ifndef BEAN_WXGUI_LAYOUTMANAGERINTERFACE_H
#define BEAN_WXGUI_LAYOUTMANAGERINTERFACE_H
#include <wx/wx.h>
/**
 * LayoutManagerのうちテンプレートに依存しない実装を提供します.
 */
class LayoutManagerInterface {
public:
	LayoutManagerInterface();
	virtual ~LayoutManagerInterface() = 0;
	/**
	 * コンポーネントを追加します.
	 * @param c
	 * @param flags
	 */
	virtual void addComponent(wxWindow* c, wxSizerFlags flags) = 0;

	/**
	 * 伸縮しない余白を追加します.
	 * @param size
	 */
	virtual void addSpace(int size) = 0;

	/**
	 * 伸縮する余白を追加します.
	 */
	virtual void addStretch() = 0;

	/**
	 * 指定位置のコンポーネントを削除します.
	 * @param index
	 */
	virtual void removeComponentAt(int index) = 0;

	/**
	 * 全てのコンポーネントの数を返します.
	 * @return
	 */
	virtual int getComponentCount() = 0;

	/**
	 * レイアウトの最小サイズを設定します.
	 * @param size
	 */
	virtual void setMinSize(wxSize size) = 0;
	/**
	 * レイアウトの最小サイズを返します.
	 * @return
	 */
	virtual wxSize getMinSize() = 0;
	/**
	 * レイアウトの推奨サイズを設定します.
	 * @param size
	 */
	virtual void setFitSize(wxSize size) = 0;
	/**
	 * レイアウトの推奨サイズを返します.
	 * @return
	 */
	virtual wxSize getFitSize() = 0;
	/**
	 * レイアウトの最大サイズを設定します.
	 * @param size
	 */
	virtual void setMaxSize(wxSize size) = 0;
	/**
	 * レイアウトの最大サイズを返します.
	 * @return
	 */
	virtual wxSize getMaxSize() = 0;
	/**
	 * 強制的に再レイアウトを実行します.
	 */
	virtual void doLayout() = 0;

	/**
	 * wxwidgetの型で返します.
	 * @return
	 */
	virtual wxSizer* getWX() = 0;
};
#endif // !BEAN_WXGUI_LAYOUTMANAGERINTERFACE_H
