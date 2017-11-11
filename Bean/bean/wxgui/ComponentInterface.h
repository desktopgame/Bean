#pragma once
#ifndef BEAN_WXGUI_COMPONENTINTERFACE_H
#define BEAN_WXGUI_COMPONENTINTERFACE_H
#include <wx/wx.h>
/**
 * Component�̂����A�e���v���[�g�Ɉˑ����Ȃ�������񋟂��܂�.
 */
class ComponentInterface {
public:
	ComponentInterface();
	virtual ~ComponentInterface() = 0;
	/**
	 * ���̃R���|�[�l���g���ĕ`�悵�܂�.
	 */
	virtual void repaint() = 0;

	/**
	 * X���W��ݒ肵�܂�.
	 * @param x
	 */
	virtual void setX(int x) = 0;

	/**
	 * X���W��Ԃ��܂�.
	 * @return
	 */
	virtual int getX() = 0;

	/**
	 * Y���W��ݒ肵�܂�.
	 * @param y
	 */
	virtual void setY(int y) = 0;

	/**
	 * Y���W��Ԃ��܂�.
	 * @return
	 */
	virtual int getY() = 0;

	/**
	 * ������ݒ肵�܂�.
	 * @param w
	 */
	virtual void setWidth(int w) = 0;

	/**
	 * ������Ԃ��܂�.
	 * @return
	 */
	virtual int getWidth() = 0;

	/**
	 * �c����ݒ肵�܂�.
	 * @param h
	 */
	virtual void setHeight(int h) = 0;

	/** 
	 * �c����Ԃ��܂�.
	 * @return
	 */
	virtual int getHeight() = 0;

	/**
	 * �ŏ��T�C�Y��ݒ肵�܂�.
	 * @param size
	 */
	virtual void setMinSize(wxSize size) = 0;

	/**
	 * �ŏ��T�C�Y��Ԃ��܂�.
	 * @return
	 */
	virtual wxSize getMinSize() = 0;

	/**
	 * �����T�C�Y��ݒ肵�܂�.
	 * @param size
	 */
	virtual void setFitSize(wxSize size) = 0;

	/**
	 * �����T�C�Y��Ԃ��܂�.
	 * @return
	 */
	virtual wxSize getFitSize() = 0;

	/**
	 * �ő�T�C�Y��ݒ肵�܂�.
	 * @param size
	 */
	virtual void setMaxSize(wxSize size) = 0;

	/**
	 * �ő�T�C�Y��Ԃ��܂�.
	 * @return
	 */
	virtual wxSize getMaxSize() = 0;

	/**
	 * �O�i�F��ݒ肵�܂�.
	 * @param foreColor
	 */
	virtual void setForeground(wxColor foreColor) = 0;

	/**
	 * �O�i�F��Ԃ��܂�.
	 * @return
	 */
	virtual wxColor getForeground() = 0;

	/**
	 * �w�i�F��ݒ肵�܂�.
	 * @param backColor
	 */
	virtual void setBackground(wxColor backColor) = 0;

	/**
	 * �w�i�F��Ԃ��܂�.
	 * @return
	 */
	virtual wxColor getBackground() = 0;

	/**
	 * �R���|�[�l���g��Ԃ��܂�.
	 * @return
	 */
	virtual wxWindow* getWX() = 0;
};
#endif // !BEAN_WXGUI_COMPONENTINTERFACE_H
