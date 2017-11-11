#pragma once
#ifndef BEAN_ENV_USER_USERMENUELEMENT_H
#define BEAN_ENV_USER_USERMENUELEMENT_H
#include <wx/wx.h>
#include "../Object_.h"
/**
 * メニューのラッパーの基底クラス.
 */
class UserMenuElement : public Object_ {
public:
	UserMenuElement();
	virtual ~UserMenuElement() = 0;
	/**
	 * メニューの文字列を設定します.
	 * @param text
	 */
	virtual void setText(std::string text) = 0;

	/**
	 * メニューの文字列を返します.
	 * @return
	 */
	virtual std::string getText() = 0;
	/**
	 * WXの型で返します.
	 * @return
	 */
	virtual wxMenuItem* getWXMenuItem() = 0;

	/**
	 * WXの型で返します.
	 * @return
	 */
	virtual wxMenu* getWXMenu() = 0;

	/**
	 * このアイテムを選択状態に設定するなら true.
	 * @param isSelected
	 */
	virtual void setSelected(bool isSelected) = 0;

	/**
	 * このアイテムが選択状態なら true.
	 * @return
	 */
	virtual bool isSelected() = 0;

	// Object_ を介して継承されました
	Object_ * clone() override;
};
#endif // !BEAN_ENV_USER_USERMENUELEMENT_H
