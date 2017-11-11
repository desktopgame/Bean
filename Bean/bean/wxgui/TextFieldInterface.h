#pragma once
#ifndef BEAN_WXGUI_TEXTFIELDINTERFACE_H
#define BEAN_WXGUI_TEXTFIELDINTERFACE_H
#include <string>
/**
 * TextFieldのうちテンプレートに依存しない実装を提供します.
 */
class TextFieldInterface {
public:
	TextFieldInterface();
	virtual ~TextFieldInterface() = 0;
	/**
	 * 指定の領域の文字列を選択状態にします.
	 * @param start
	 * @param end
	 */
	virtual void select(int start, int end) = 0;

	/**
	 * 全ての領域の文字列を選択状態にします.
	 */
	virtual void selectAll() = 0;

	/**
	 * 選択の開始位置を返します.
	 * @return
	 */
	virtual int getSelectionStart() = 0;

	/**
	 * 選択の終了位置を返します.
	 * @return
	 */
	virtual int getSelectionEnd() = 0;

	/**
	 * 現在選択されている文字列をクリップボードへコピーします.
	 */
	virtual void copy() = 0;

	/**
	 * 現在選択されている文字列をクリップボードへコピーし、
	 * 選択されていた領域の文字列を削除します。
	 */
	virtual void cut() = 0;

	/**
	 * 現在クリップボードへコピーされている文字列を貼り付けます.
	 */
	virtual void paste() = 0;

	/**
	 * Undo可能であるならtrueを返します.
	 * @return
	 */
	virtual bool canUndo() = 0;

	/**
	 * Undoを実行します.
	 */
	virtual void undo() = 0;

	/**
	 * Redo可能であるかどうかを返します.
	 */
	virtual bool canRedo() = 0;

	/**
	 * Redoを実行します.
	 */
	virtual void redo() = 0;

	/**
	 * 全ての変更履歴を削除します.
	 */
	virtual void discardAllEdits() = 0;

	/**
	 * 表示されるテキストを設定します.
	 * @param content
	 */
	virtual void setText(std::string content) = 0;

	/**
	 * 表示されているテキストを返します.
	 * @return
	 */
	virtual std::string getText() = 0;

	/**
	 * 文字を挿入します.
	 * @param content
	 * @param offset
	 */
	virtual void insert(std::string content, int offset) = 0;

	/**
	 * 文字を削除します.
	 * @param offset
	 * @param length
	 */
	virtual void remove(int offset, int length) = 0;

	/**
	 * カレット位置を設定します.
	 * @param position
	 */
	virtual void setCaretPosition(int position) = 0;

	/**
	 * カレット位置を返します.
	 * @return
	 */
	virtual int getCaretPosition() = 0;
};
#endif // !BEAN_WXGUI_TEXTFIELDINTERFACE_H
