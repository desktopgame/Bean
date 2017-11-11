#pragma once
#ifndef BEAN_ENV_GC_BLOCK_H
#define BEAN_ENV_GC_BLOCK_H
#include <functional>
#include <memory>
#include <mutex>
#include <vector>
#include "Page.h"
#include "../Object_.h"
class Block;
using BlockSPtr = std::shared_ptr<Block>;
using BlockWPtr = std::weak_ptr<Block>;
/**
 * 式の中で一時的に使用される値を保護します.
 */
class Block {
public:
	Block();
	virtual ~Block();

	/**
	 * 現在のクラスローダーに設定されたブロックを返します.
	 * @return
	 */
	static BlockSPtr getInstance();

	/**
	 * 現在のインスタンスで push を実行します.
	 */
	static void pushCurrent();

	/**
	 * 現在のインスタンスで pop を実行します.
	 */
	static void popCurrent();

	/**
	 * 指定のオブジェクトが追加されていなければ追加します.
	 * @param obj
	 */
	static void entry(Object_* obj);

	/**
	 * 全てのインスタンスで全てのページをクリアします.
	 */
	static void blocks_page_clearAll();

	/**
	 * 全てのインスタンスの全てのページのペイント状態を設定します.
	 * @param progress
	 */
	static void blocks_page_paintAll(GCProgress progress);

	/**
	 * 全てのインスタンスの全てのページでマークを実行します.
	 */
	static void blocks_page_markAll();

	/**
	 * 現在のインスタンスで指定のオブジェクトを削除します.
	 * @param obj
	 */
	static void blocks_page_remove(Object_* obj);

	/**
	 * thread/Thread で管理されない非同期ブロックを返します.
	 * 以降の処理は endAsync が呼ばれるまでここで作成されたブロックへ委譲されます。
	 */
	static void startAsync();

	/**
	 * 非同期ブロックを終了します.
	 */
	static void endAsync();

	/**
	 * 新たなページを追加します.
	 */
	void push();

	/**
	 * 最後に追加されたページを削除します.
	 */
	void pop();

	/**
	 * 既にページが存在するなら、
	 * 指定のオブジェクトをGCの対象にならないようにします.
	 * @parma obj
	 */
	bool recordObject(Object_* obj);

	/**
	 * ページのいずれかに obj が含まれるなら削除します.
	 * @param obj
	 */
	void page_remove(Object_* obj);

	/**
	 * このブロックの持つページ全てで
	 * obj_clearAll を呼び出します。
	 */
	void page_markAll();

	/**
	 * このブロックの持つページ全てで
	 * obj_clearAll を呼び出します。
	 */
	void page_clearAll();

	/**
	 * このブロックの持つページ全てで
	 * obj_paintAll を呼び出します。
	 */
	void page_paintAll(GCProgress progress);

	/**
	 * 現在のネストの深さを返します.
	 * @return
	 */
	int getDepth() const;
private:
	std::recursive_mutex thread_sync;
	std::vector<PageSPtr> pageStack;

	static std::vector<BlockSPtr> async_blocks;
	static std::recursive_mutex aync_sync;

	static void do_all_blocks(std::function<void(BlockSPtr)> f);
};
#endif // !BEAN_ENV_GC_BLOCK_H
