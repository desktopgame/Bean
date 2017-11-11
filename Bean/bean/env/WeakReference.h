#pragma once
#ifndef BEAN_ENV_WEAKREFERENCE_H
#define BEAN_ENV_WEAKREFERENCE_H
class Object_;
/**
 * オブジェクトの消失を監視するクラス.
 */
class WeakReference {
public:
	WeakReference();
	virtual ~WeakReference() = 0;
	/**
	 * オブジェクトが削除されるときに呼び出されます.
	 * @parma obj
	 */
	virtual void onDelete(Object_* obj);
};
#endif // !BEAN_ENV_WEAKREFERENCE_H
