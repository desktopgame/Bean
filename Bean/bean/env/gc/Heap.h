#pragma once
#ifndef BEAN_ENV_GC_GCSYSTEM_H
#define BEAN_ENV_GC_GCSYSTEM_H
#include <deque>
#include <functional>
#include <mutex>
#include <thread>
#include <vector>
class GCStrategy;
class CodeBlock;
class Object_;

//class GCSystem;
//typedef GCSystem Heap;
/**
 * Beanで確保されたオブジェクトを開放するクラスです.
 */
class Heap {
public:
	Heap(const Heap&) = delete;
	Heap& operator=(const Heap&) = delete;
	Heap(Heap&&) = delete;
	Heap& operator=(Heap&&) = delete;
	/**
	 * 唯一のインスタンスを返します.
	 * @return
	 */
	static Heap* const getInstance() {
		static Heap inst;
		return &inst;
	}
	/**
	 * ガベージコレクタの管理対象に引数を追加します.
	 * このメソッドはマルチスレッドセーフです。
	 * @param obj
	 */
	void add(Object_* obj);

	/**
	 * ガベージコレクタの管理対象から引数を追加します.
	 * このメソッドはマルチスレッドセーフです。
	 * @param obj
	 */
	void remove(Object_* obj);

	/**
	 * ロック化で安全にヒープを参照します.
	 * ここに渡されるObject_の配列はHeapの持つものへのポインタなので、
	 * これを変更することはヒープを変更することと同じです。
	 */
	void view(std::function<void(std::vector<Object_*>&)> f);

	/**
	 * rightをライトバリアによって保護します.
	 * @param left
	 * @param right
	 */
	void writeBarrier(Object_* left, Object_* right);

	/**
	 * rightをライトバリアによって保護します.
	 */
	void writeBarrier(Object_* right);

	/**
	 * 可能なら指定のオブジェクトをスタック/バッファから削除します.
	 * ヒープからの除去とref自体のdeleteは呼び出し側で行います。
	 * @param obj
	 * @return 成功したならtrue.
	 */
	static bool deleteItem(Object_* obj);

	/**
	 * ガベージコレクタが行われないようにロックします.
	 */
	void lock();

	/**
	* ロックを解除します.
	*/
	void unlock();

	/**
	 * 現在のヒープサイズが閾値を超えているならGCを実行します.
	 */
	void test();

	/**
	 * まだヒープに残っているオブジェクトのダンプを出力します.
	 */
	void dump();

	/**
	 * ガベージコレクタを起動します.
	 * このメソッドはマルチスレッドセーフです。
	 */
	void miniGC();

	/**
	 * ガベージコレクタを起動します.
	 * このメソッドはマルチスレッドセーフです。
	 */
	void fullGC();

	/**
	 * ヒープの最大確保数を返します.
	 * この値より多くのオブジェクトが確保されるとGCが作動します。
	 * @return
	 */
	int getHeapThreshold();

	/**
	 * 現在のオブジェクトの数を返します.
	 * このメソッドはマルチスレッドセーフです。
	 */
	int getCurrentSize();

	/**
	* ガベージコレクションを同期するためのロックを獲得します.
	*/
	void enter();

	/**
	* ガベージコレクションを同期するためのロックを開放します.
	*/
	void exit();

	/**
	 * マークスイープGCならtrue.
	 * @return
	 */
	bool isMarkAndSweepGC() const;

	/**
	 * インクリメンタルGCならtrue.
	 * @return
	 */
	bool isIncrementalGC() const;

	/**
	 * ヒープを破棄します.
	 */
	void destroy();
protected:
	/**
	 * ガベージコレクタを起動します.
	 * @param id
	 */
	void execImpl(int id);

	/**
	 * ロックされているならtrue.
	 */
	bool locked();

private:

	void do_codeblock(std::vector<CodeBlock*> rootBlockVec, std::function<void(CodeBlock*)> f);

	Heap();
	~Heap() { delete strategy; }
	std::vector<Object_*> objects;
	std::recursive_mutex thread_sync;
	GCStrategy* strategy;
	int gcType;
	int locks;
	int heapThreshold;
	int initThr;
	bool gcReport;
	bool gcAlways;
};
#endif // !BEAN_ENV_GC_GCSYSTEM_H
