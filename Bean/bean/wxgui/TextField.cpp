#include "TextField.h"
#include "ContainerInterface.h"

//public method---
TextField::TextField(ContainerInterface* parent) 
 : Component<TextFieldPeer>(new TextFieldPeer(parent->getWindow())) {
}

TextField::~TextField() {
}

void TextField::select(int start, int end) {
	getPeer()->select(start, end);
}

void TextField::selectAll() {
	getPeer()->selectAll();
}

int TextField::getSelectionStart() {
	return getPeer()->getSelectionStart();
}

int TextField::getSelectionEnd() {
	return getPeer()->getSelectionEnd();
}

void TextField::copy() {
	getPeer()->copy();
}

void TextField::cut() {
	getPeer()->cut();
}

void TextField::paste() {
	getPeer()->paste();
}

bool TextField::canUndo() {
	return getPeer()->canUndo();
}

void TextField::undo() {
	getPeer()->undo();
}

bool TextField::canRedo() {
	return getPeer()->canRedo();
}

void TextField::redo() {
	getPeer()->redo();
}

void TextField::discardAllEdits() {
	getPeer()->discardAllEdits();
}

void TextField::setText(std::string content) {
	getPeer()->setText(content);
}

std::string TextField::getText() {
	return getPeer()->getText();
}

void TextField::insert(std::string content, int offset) {
	getPeer()->insert(content, offset);
}

void TextField::remove(int offset, int length) {
	getPeer()->remove(offset, length);
}

void TextField::setCaretPosition(int position) {
	getPeer()->setCaretPosition(position);
}

int TextField::getCaretPosition() {
	return getPeer()->getCaretPosition();
}
//---public method