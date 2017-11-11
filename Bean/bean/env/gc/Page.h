#pragma once
#ifndef BEAN_ENV_GC_PAGE_H
#define BEAN_ENV_GC_PAGE_H
#include <memory>
#include <mutex>
#include <vector>
#include "../Object_.h"
#include "../WeakReference.h"
class Page;
using PageSPtr = std::shared_ptr<Page>;
using PageWPtr = std::weak_ptr<Page>;
/**
 * 式の中の一階層を表します.
 * 階層は Blockクラス のスタックによって表されます。
 */
class Page {
public:
	Page(int rank);
	~Page();
	/**
	 * この階層にオブジェクトを追加します.
	 * @param obj
	 */
	void add(Object_* obj);

	/**
	 * 指定位置のオブジェクトを返します.
	 * @param index
	 * @return
	 */
	Object_* get(int index) const;

	/**
	 * 指定位置のオブジェクトを削除します.
	 * @param index
	 */
	void removeAt(int index);

	/**
	 * 指定のオブジェクトを削除します.
	 * @param obj
	 */
	void remove(Object_* obj);

	/**
	 * 全てのオブジェクトの数を返します.
	 * @return
	 */
	int size() const;

	/**
	 * このページが破棄されるとき、
	 * このページに格納されたオブジェクトのランクを0にします.
	 */
	void fix();

	/**
 	 * このページが破棄されるとき、
	 * このページに格納されたオブジェクトを一つ前のページへ移動します.
	 */
	void fix(PageSPtr prev);

	/**
	 * 全てのオブジェクトをツリーマークします.
	 */
	void obj_markAll();

	/**
	 * 全てのオブジェクトのマーク状態をクリアします.
	 */
	void obj_clearAll();

	/**
	 * 全てのオブジェクトのペイント状態を設定します.
	 * @param progress
	 */
	void obj_paintAll(GCProgress progress);

	/** 
	 * このページのアイテム一覧を返します.
	 * @return
	 */
	std::vector<Object_*> getObjects() const;

private:
	int rank;
	std::vector<Object_*> objects;
	std::recursive_mutex thread_sync;
	void removeImpl(Object_* obj, bool listenerRemove);
};
#endif // !BEAN_ENV_GC_PAGE_H
