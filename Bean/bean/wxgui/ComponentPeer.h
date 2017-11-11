#pragma once
#ifndef BEAN_WXGUI_COMPONENTPEER_H
#define BEAN_WXGUI_COMPONENTPEER_H
#include <wx/wx.h>
#include "ComponentInterface.h"
class ContainerInterface;
/**
 * �R���|�[�l���g�̃s�A�C���^�[�t�F�C�X�ł�.
 * ���ʂ���჌�x���ȐU�镑���͂����Œ��ۉ�����A
 * �e�R���|�[�l���g�Œ񋟂���܂��B
 */
template<typename WxWidget>
class ComponentPeer : public ComponentInterface {
public:
	ComponentPeer(WxWidget* target);
	~ComponentPeer();
	/**
	 * �Ϗ���̃R���|�[�l���g��Ԃ��܂�.
	 * @return
	 */
	WxWidget* const getTarget() const;

	void repaint() override;
	void setX(int x) override;
	int getX() override;
	void setY(int y) override;
	int getY() override;
	void setWidth(int w) override;
	int getWidth() override;
	void setHeight(int h) override;
	int getHeight() override;
	void setMinSize(wxSize size) override;
	wxSize getMinSize() override;
	void setFitSize(wxSize size) override;
	wxSize getFitSize() override;
	void setMaxSize(wxSize size) override;
	wxSize getMaxSize() override;
	void setForeground(wxColor foreColor) override;
	wxColor getForeground() override;
	void setBackground(wxColor backColor) override;
	wxColor getBackground() override;
	wxWindow* getWX() override;
	void setParent(ContainerInterface* container);
	ContainerInterface* getParent() const;
private:

	void setPosition(wxPoint point);
	wxPoint getPosition();

	void setSize(wxSize size);
	wxSize getSize();

	WxWidget* target;
	ContainerInterface* parent;
};
#include "ComponentPeerImpl.h"
#endif // !BEAN_WXGUI_COMPONENTPEER_H
