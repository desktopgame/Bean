#pragma once
#ifndef BEAN_ENV_USER_USERLAYOUTPARAMS_H
#define BEAN_ENV_USER_USERLAYOUTPARAMS_H
#include <wx/wx.h>
#include "../Object_.h"
/**
 * レイアウト制約のラッパー.
 */
class UserLayoutParams : public Object_ {
public:
	UserLayoutParams();
	~UserLayoutParams();
	/**
	 * 左寄せに設定します.
	 * @return このインスタンス
	 */
	const UserLayoutParams* left();
	/**
	 * 右寄せに設定します.
	 * @return このインスタンス
	 */
	const UserLayoutParams* right();
	/**
	 * 上寄せに設定します.
	 * @return このインスタンス
	 */
	const UserLayoutParams* top();
	/**
	 * 下寄せに設定します.
	 * @return このインスタンス
	 */
	const UserLayoutParams* bottom();
	/**
	 * 中央寄せに設定します.
	 * @return このインスタンス.
	 */
	const UserLayoutParams* center();
	/**
	 * ボーダーを設定します.
	 * @return このインスタンス
	 */
	const UserLayoutParams* border(int thick);

	/**
	 * コンポーネントが出来るだけ塗りつぶすようにします.
	 * @return
	 */
	const UserLayoutParams* fill();

	/**
	 * wxの型で返します.
	 * @return
	 */
	wxSizerFlags* getValue();

	// Object_ を介して継承されました
	Object_ * clone() override;
protected:
	void lazyLoading() override;
private:
	wxSizerFlags flags;
};
#endif // !BEAN_ENV_USER_USERLAYOUTPARAMS_H
