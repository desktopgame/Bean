#pragma once
#ifndef BEAN_WXGUI_PAINTBOXINTERFACE_H
#define BEAN_WXGUI_PAINTBOXINTERFACE_H
#include "WxPaintBox.h"
/**
 * PaintBox�̎����̂����e���v���[�g�Ɉˑ����Ȃ����̂�񋟂��܂�.
 */
class PaintBoxInterface {
public:
	PaintBoxInterface();
	virtual ~PaintBoxInterface() = 0;

	/**
	 * �A�j���[�V�������J�n���܂�.
	 */
	virtual void start() = 0;

	/**
	 * �A�j���[�V�������ꎞ��~���܂�.
	 */
	virtual void stop() = 0;

	/**
	 * �`����Ď�����C�x���g���X�i�[��ǉ����܂�.
	 * @param paint
	 */
	virtual void addPaintListener(Paint paint) = 0;

	/**
	 * �`����Ď�����C�x���g���X�i�[���폜���܂�.
	 * @param index
	 */
	virtual void removePaintListenerAt(int index) = 0;

	/**
	 * �`����Ď�����C�x���g���X�i�[�̐���Ԃ��܂�.
	 * @return
	 */
	virtual int getPaintListenerCount() const = 0;
};
#endif // !BEAN_WXGUI_PAINTBOXINTERFACE_H
