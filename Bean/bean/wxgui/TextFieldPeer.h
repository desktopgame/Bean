#pragma once
#ifndef BEAN_WXGUI_TEXTFIELDPEER_H
#define BEAN_WXGUI_TEXTFIELDPEER_H
#include "ComponentPeer.h"
#include "TextFieldInterface.h"
#include "WxTextFieldEx.h"
/**
 * TextField‚Ì’áƒŒƒxƒ‹‚ÈU‚é•‘‚¢‚ğ’ñ‹Ÿ‚µ‚Ü‚·.
 */
class TextFieldPeer : public ComponentPeer<WxTextFieldEx>, public TextFieldInterface {
public:
	TextFieldPeer(wxWindow* window);
	~TextFieldPeer();

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
#endif // !BEAN_WXGUI_TEXTFIELDPEER_H
