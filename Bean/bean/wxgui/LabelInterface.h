#pragma once
#ifndef BEAN_WXGUI_LABELINTERFACE_H
#define BEAN_WXGUI_LABELINTERFACE_H
#include <string>
/** 
 * Label �̎����̂����e���v���[�g�Ɉˑ����Ȃ����̂�񋟂��܂�.
 */
class LabelInterface {
public:
	LabelInterface();
	virtual ~LabelInterface() = 0;
	/**
	 * �\������镶�����ݒ肵�܂�.
	 * @param text
	 */
	virtual void setText(std::string text) = 0;
	/**
	 * �\������镶�����Ԃ��܂�.
	 * @return
	 */
	virtual std::string getText() = 0;
};
#endif // !BEAN_WXGUI_LABELINTERFACE_H
