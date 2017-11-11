#include "UserTextField.h"
#include "../Package.h"
#include "../../wxgui/ComponentInterface.h"

//public method---
UserTextField::UserTextField(TextFieldInterface* textFieldInterface) 
 : UserComponent(dynamic_cast<ComponentInterface*>(textFieldInterface)) {
}

UserTextField::~UserTextField() {
	delete textFieldInterface;
}

void UserTextField::select(int start, int end) {
	textFieldInterface->select(start, end);
}

void UserTextField::selectAll() {
	textFieldInterface->selectAll();
}

int UserTextField::getSelectionStart() {
	return textFieldInterface->getSelectionStart();
}

int UserTextField::getSelectionEnd() {
	return textFieldInterface->getSelectionEnd();
}

void UserTextField::copy() {
	textFieldInterface->copy();
}

void UserTextField::cut() {
	textFieldInterface->cut();
}

void UserTextField::paste() {
	textFieldInterface->paste();
}

bool UserTextField::canUndo() {
	return textFieldInterface->canUndo();
}

void UserTextField::undo() {
	textFieldInterface->undo();
}

bool UserTextField::canRedo() {
	return textFieldInterface->canRedo();
}

void UserTextField::redo() {
	textFieldInterface->redo();
}

void UserTextField::discardAllEdits() {
	textFieldInterface->discardAllEdits();
}

void UserTextField::setText(std::string content) {
	textFieldInterface->setText(content);
}

std::string UserTextField::getText() {
	return textFieldInterface->getText();
}

void UserTextField::insert(std::string content, int offset) {
	textFieldInterface->insert(content, offset);
}

void UserTextField::remove(int offset, int length) {
	textFieldInterface->remove(offset, length);
}

void UserTextField::setCaretPosition(int position) {
	textFieldInterface->setCaretPosition(position);
}

int UserTextField::getCaretPosition() {
	return textFieldInterface->getCaretPosition();
}
//---public method

//protected method---
void UserTextField::lazyLoading() {
	setClass(Package::getClassOrLoad("api.wxgui.TextField"));
}
//---protected method
