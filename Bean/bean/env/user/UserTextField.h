#pragma once
#ifndef BEAN_ENV_USER_USERTEXTFIELD_H
#define BEAN_ENV_USER_USERTEXTFIELD_H
#include "UserComponent.h"
#include "../../wxgui/TextFieldInterface.h"
/**
 * テキストフィールドのラッパー.
 */
class UserTextField : public UserComponent, public TextFieldInterface {
public:
	UserTextField(TextFieldInterface* textFieldInterface);
	~UserTextField();
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
protected:
	void lazyLoading() override;
private:
	TextFieldInterface* textFieldInterface;
};
#endif // !BEAN_ENV_USER_USERTEXTFIELD_H
