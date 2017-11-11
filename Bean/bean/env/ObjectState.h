#pragma once
#ifndef BEAN_ENV_OBJECTSTATE_H
#define BEAN_ENV_OBJECTSTATE_H
#include <memory>
#include <vector>
#include "gc/GCProgress.cpp"
class Object_;
class Reference;
class WeakReference;
class ObjectState;
using ObjectStateSPtr = std::shared_ptr<ObjectState>;
using ObjectStateWPtr = std::weak_ptr<ObjectState>;
/**
 * ガベージコレクションの際に必要になる情報をまとめたクラスです.
 * GCStrategyクラスによって使用されます。
 */
class ObjectState {
public:
	ObjectState(Object_* parent);
	virtual ~ObjectState();

	/**
	 * このオブジェクトをフィールドや変数ではない方法で束縛します.
	 * 内部的に使用される変数がGCによって削除されないために使用されます。
	 * @param ref
	 */
	void addStrongReference(Reference* ref);

	/**
	 * 束縛を解除します.
	 * @param ref
	 * @param isDelete この呼び出しでカウントが 0 になったとき削除するなら true.
	 */
	void removeStrongReference(Reference* ref, bool isDelete);

	/**
	 * 束縛を解除します.
	 * isDelete を true で呼び出します。
	 * @param ref
	 */
	void removeStrongReference(Reference* ref);

	/**
	 * 束縛の数を返します.
	 * @return
	 */
	int getStrongReferenceCount() const;

	/**
	 * オブジェクトの削除を監視するリスナーを追加します.
	 * @param wRef
	 */
	void addWeakReference(WeakReference* wRef);

	/**
	 * オブジェクトの削除を監視するリスナーを削除します.
	 * @param wRef
	 */
	void removeWeakReference(WeakReference* wRef);

	/**
	 * オブジェクトの削除を監視するリスナーの数を返します.
	 * @param wRef
	 */
	int getWeakReferenceCount() const;

	/**
	 * マーク状態を設定します.
	 * @param bMarked
	 */
	void setMarked(bool bMarked);

	/**
	 * マーク状態を返します.
	 */
	bool isMarked() const;

	/**
	 * このオブジェクトのランクを設定します.
	 * (a + b) + c のような式を解釈するとき、
	 * (a + b) を計算したときにその結果は変数へ格納されません。
	 *
	 * 変数に格納されたオブジェクトはルートから辿ることが出来るので安全ですが、
	 * この場合では (a + b) の結果は格納されません。
	 * また、新たなオブジェクトが割り当てられるとGCが動く可能性があるので、
	 * 次の c との演算で不正なポインタへアクセスする可能性があります。
	 *
	 * このランクはそのような式階層の中で現在どれぐらい深いところにいるかを判別するために使用されます。
	 * このランクが 0 より大きい場合、GCの対象にはなりません。
	 * @param rank
	 */
	void setRank(int rank);

	/**
	 * このオブジェクトのランクを返します.
	 * @return
	 */
	int getRank() const;

	/**
	 * 世代を設定します.
	 * @param age
	 */
	void setAge(int age);

	/**
	 * 世代を返します.
	 * @return
	 */
	int getAge() const;

	/**
	 * インクリメンタルGCで使用されます.
	 * マークの進捗状況を表します.
	 * @param progress
	 */
	void setProgress(GCProgress progress);

	/**
	 * インクリメンタルGCで使用されます.
	 * @return
	 */
	GCProgress getProgress() const;

	/**
	 * デバッグ用のメソッド.
	 * @return
	 */
	std::string getProgressStr() const;

	/**
	 * オブジェクトの削除をリスナーへ通知します.
	 * このメソッドは Object_ からのみ呼び出されるようにしてください。
	 * @param obj
	 */
	virtual void onDelete(Object_* obj);
private:
	Object_* parent;
	bool marked;
	bool notify;
	int rank;
	int age;
	int mutator;
	bool bIsField;
	GCProgress progress;
	std::vector<Reference*> strongReferences;
	std::vector<WeakReference*> weakReferences;
};
#endif // !BEAN_ENV_OBJECTSTATE_H
