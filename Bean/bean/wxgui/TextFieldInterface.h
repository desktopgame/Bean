#pragma once
#ifndef BEAN_WXGUI_TEXTFIELDINTERFACE_H
#define BEAN_WXGUI_TEXTFIELDINTERFACE_H
#include <string>
/**
 * TextField�̂����e���v���[�g�Ɉˑ����Ȃ�������񋟂��܂�.
 */
class TextFieldInterface {
public:
	TextFieldInterface();
	virtual ~TextFieldInterface() = 0;
	/**
	 * �w��̗̈�̕������I����Ԃɂ��܂�.
	 * @param start
	 * @param end
	 */
	virtual void select(int start, int end) = 0;

	/**
	 * �S�Ă̗̈�̕������I����Ԃɂ��܂�.
	 */
	virtual void selectAll() = 0;

	/**
	 * �I���̊J�n�ʒu��Ԃ��܂�.
	 * @return
	 */
	virtual int getSelectionStart() = 0;

	/**
	 * �I���̏I���ʒu��Ԃ��܂�.
	 * @return
	 */
	virtual int getSelectionEnd() = 0;

	/**
	 * ���ݑI������Ă��镶������N���b�v�{�[�h�փR�s�[���܂�.
	 */
	virtual void copy() = 0;

	/**
	 * ���ݑI������Ă��镶������N���b�v�{�[�h�փR�s�[���A
	 * �I������Ă����̈�̕�������폜���܂��B
	 */
	virtual void cut() = 0;

	/**
	 * ���݃N���b�v�{�[�h�փR�s�[����Ă��镶�����\��t���܂�.
	 */
	virtual void paste() = 0;

	/**
	 * Undo�\�ł���Ȃ�true��Ԃ��܂�.
	 * @return
	 */
	virtual bool canUndo() = 0;

	/**
	 * Undo�����s���܂�.
	 */
	virtual void undo() = 0;

	/**
	 * Redo�\�ł��邩�ǂ�����Ԃ��܂�.
	 */
	virtual bool canRedo() = 0;

	/**
	 * Redo�����s���܂�.
	 */
	virtual void redo() = 0;

	/**
	 * �S�Ă̕ύX�������폜���܂�.
	 */
	virtual void discardAllEdits() = 0;

	/**
	 * �\�������e�L�X�g��ݒ肵�܂�.
	 * @param content
	 */
	virtual void setText(std::string content) = 0;

	/**
	 * �\������Ă���e�L�X�g��Ԃ��܂�.
	 * @return
	 */
	virtual std::string getText() = 0;

	/**
	 * ������}�����܂�.
	 * @param content
	 * @param offset
	 */
	virtual void insert(std::string content, int offset) = 0;

	/**
	 * �������폜���܂�.
	 * @param offset
	 * @param length
	 */
	virtual void remove(int offset, int length) = 0;

	/**
	 * �J���b�g�ʒu��ݒ肵�܂�.
	 * @param position
	 */
	virtual void setCaretPosition(int position) = 0;

	/**
	 * �J���b�g�ʒu��Ԃ��܂�.
	 * @return
	 */
	virtual int getCaretPosition() = 0;
};
#endif // !BEAN_WXGUI_TEXTFIELDINTERFACE_H
