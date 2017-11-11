#include "TextFieldPeer.h"

//public method---
TextFieldPeer::TextFieldPeer(wxWindow* window) 
 : ComponentPeer<WxTextFieldEx>(new WxTextFieldEx(window)) {
}

TextFieldPeer::~TextFieldPeer() {
}

void TextFieldPeer::select(int start, int end) {
	getTarget()->SetSelection(start, end);
}

void TextFieldPeer::selectAll() {
	getTarget()->SetSelection(-1, -1);
}

int TextFieldPeer::getSelectionStart() {
	long start;
	long end;
	getTarget()->GetSelection(&start, &end);
	return static_cast<int>(start);
}

int TextFieldPeer::getSelectionEnd() {
	long start;
	long end;
	getTarget()->GetSelection(&start, &end);
	return static_cast<int>(end);
}

void TextFieldPeer::copy() {
	getTarget()->Copy();
}

void TextFieldPeer::cut() {
	getTarget()->Cut();
}

void TextFieldPeer::paste() {
	getTarget()->Paste();
}

bool TextFieldPeer::canUndo() {
	return getTarget()->CanUndo();
}

void TextFieldPeer::undo() {
	if (canUndo()) {
		getTarget()->Undo();
	}
}

bool TextFieldPeer::canRedo() {
	return getTarget()->CanRedo();
}

void TextFieldPeer::redo() {
	getTarget()->Redo();
}

void TextFieldPeer::discardAllEdits() {
	getTarget()->DiscardEdits();
}

void TextFieldPeer::setText(std::string content) {
	getTarget()->SetValue(content);
}

std::string TextFieldPeer::getText() {
	return getTarget()->GetValue();
}

void TextFieldPeer::insert(std::string content, int offset) {
	std::string src = getText();
	src.insert(offset, content);
	setText(src);
}

void TextFieldPeer::remove(int offset, int length) {
	std::string src = getText();
	src.erase(src.begin() + offset, src.begin() + (offset + length));
	setText(src);
}

void TextFieldPeer::setCaretPosition(int position) {
	getTarget()->SetInsertionPoint(position);
}

int TextFieldPeer::getCaretPosition() {
	return getTarget()->GetInsertionPoint();
}
//---public method