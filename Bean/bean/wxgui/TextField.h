#pragma once
#ifndef BEAN_WXGUI_TEXTFIELD_H
#define BEAN_WXGUI_TEXTFIELD_H
#include "Component.h"
#include "TextFieldInterface.h"
#include "TextFieldPeer.h"
/**
 * 文字入力領域の最上位レイヤーです.
 * より抽象的な表現は UserTextField で提供されます。
 */
class TextField : public Component<TextFieldPeer>, public TextFieldInterface {
public:
	TextField(ContainerInterface* parent);
	~TextField();

	void select(int start, int end) override;
	void selectAll() override;
	int getSelectionStart() override;
	int getSelectionEnd() override;
	void copy() override;
	void cut() override;
	void paste() override;
	bool canUndo() override;
	void undo() override;
	bool canRedo() override;
	void redo() override;
	void discardAllEdits() override;
	void setText(std::string content) override;
	std::string getText() override;
	void insert(std::string content, int offset) override;
	void remove(int offset, int length) override;
	void setCaretPosition(int position) override;
	int getCaretPosition() override;
};
#endif // !BEAN_WXGUI_TEXTFIELD_H
