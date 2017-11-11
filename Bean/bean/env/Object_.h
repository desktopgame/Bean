#pragma once
#ifndef BEAN_ENV_OBJECT_H_
#define BEAN_ENV_OBJECT_H_
#include <functional>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>
#include "ObjectState.h"
#include "gc/GCProgress.cpp"
//#include "../util/Eventbus.h"
class Class;
class Object_;

class Boolean;
class Character;
class Numeric;
class String;
class UserObject;
class UserDelegate;
class UserArray;
class UserThread;
class UserComponent;
class Thread;

using ThreadSPtr = std::shared_ptr<Thread>;
using ThreadWPtr = std::weak_ptr<Thread>;

using ClassSPtr = std::shared_ptr<Class>;
using ClassWPtr = std::weak_ptr<Class>;
/**
 * Bean言語で使用可能な全てのデータの基底クラスです.
 */
class Object_ {
public:
	Object_(ClassSPtr classz);
	virtual ~Object_();
	virtual Object_* clone() = 0;

	/**
	 * このオブジェクトとあるオブジェクトの加算を定義します.
	 * @param right
	 * @return
	 */
	virtual Object_* add(Object_* right);

	/**
	 * このオブジェクトとあるオブジェクトの減算を定義します.
	 * @param right
	 * @return
	 */
	virtual Object_* sub(Object_* right);

	/**
	 * このオブジェクトとあるオブジェクトの乗算を定義します.
	 * @param right
	 * @return
	 */
	virtual Object_* mul(Object_* right);

	/**
	 * このオブジェクトとあるオブジェクトの除算を定義します.
	 * @param right
	 * @return
	 */
	virtual Object_* div(Object_* right);

	/**
	 * このオブジェクトとあるオブジェクトの剰余を定義します.
	 * @param right
	 * @return
	 */
	virtual Object_* mod(Object_* right);

	/**
	 * このオブジェクトとあるオブジェクトの比較演算を定義します.
	 * @param right
	 * @return
	 */
	virtual Object_* equals(Object_* right);

	/**
	 * このオブジェクトとあるオブジェクトの比較演算を定義します.
	 * @param right
	 * @return
	 */
	virtual Object_* biggest(Object_* right);

	/**
	 * このオブジェクトとあるオブジェクトの比較演算を定義します.
	 * @param right
	 * @return
	 */
	virtual Object_* e_biggest(Object_* right);

	/**
	 * このオブジェクトとあるオブジェクトの比較演算を定義します.
	 * @param right
	 * @return
	 */
	virtual Object_* smallest(Object_* right);

	/**
	 * このオブジェクトとあるオブジェクトの比較演算を定義します.
	 * @param right
	 * @return
	 */
	virtual Object_* e_smallest(Object_* right);

	/**
	 * 値を +1 します.
	 */
	virtual void increment();

	/**
	 * 値を -1 します.
	 */
	virtual void decrement();

	/**
	 * このクラスがシングルトンならtrueを返します.
	 * @return
	 */
	bool virtual isSingleton();

	//
	//イベント
	//

	/**
	 * 指定の名前のメソッドを引数無しで実行します.
	 * @param name
	 */
	Object_* const execute(std::string name);

	/**
	 * 指定の名前のメソッドを引数一つで実行します.
	 * @param name
	 * @param arg1
	 */
	Object_* const execute(std::string name, Object_* arg1);

	/**
	 * 指定の名前のメソッドを実行します.
	 * @param name
	 * @param args
	 */
	Object_* const execute(std::string name, std::vector<Object_*> args);

	/**
	 * このインスタンスのdeleteを要求します.
	 * deleteできたならtrueを返します。
	 */
	virtual bool die();

	/**
	 * クラスを設定します.
	 * また、フィールドを確保します。
	 * @param classz
	 */
	void setClass(ClassSPtr classz);

	/**
	 * 現在のオブジェクトの型をより具象的なものへ変換します.
	 * コンストラクタがチェインで呼び出されるときに使用されます。
	 * このメソッドではクラス階層ごとにフィールドを確保します。
	 * @param concrete
	 */
	void chainConstruct(ClassSPtr concrete);

	/**
	 * このオブジェクトの型を返します.
	 * @return
	 */
	virtual ClassSPtr const getClass();

	/**
	 * GC用の詳細情報を返します.
	 * @return
	 */
	virtual ObjectStateSPtr getState();

	/**
	 * このオブジェクトを生成したスレッドを返します.
	 * @return
	 */
	ThreadWPtr getGenThread() const;

	/**
	 * この値がプリミティブ型ならtrueを返します.
	 * プリミティブ型では参照に値を持たせるときにポインタではなく複製を渡します。
	 * @return
	 */
	virtual bool isPrimitive();

	/**
	 * このオブジェクトがまだマークされていなければ
	 * 再帰的にマークを行います.
	 */
	virtual void markTree();

	/**
	 * このオブジェクトの情報を出力します.
	 */
	virtual void dump();

	/**
	 * このオブジェクトがプリミティブ型なら複製を返します.
	 * @return
	 */
	virtual Object_* data();

	/**
	 * 指定の名前で動的フィールドを定義します.
	 * @param name
	 * @param value
	 */
	void defineDynField(const std::string& name, Object_* value);

	/**
	 * 指定の名前で動的フィールドを定義します.
	 * @param name
	 * @param value
	 */
	void defineDynMethod(const std::string& name, UserDelegate* value);

	/**
	 * このインスタンスに指定の名前でフィールドが定義されているならそれを返します.
	 * @param name
	 * @return なければ nullptr
	 */
	Object_* findDynField(const std::string& name);

	/**
	 * このインスタンスに指定の名前でメソッドが定義されているならそれを返します.
	 * @param name
	 * @param argc
	 * @return なければ nullptr
	 */
	UserDelegate* findDynMethod(const std::string& name, int argc);

	/**
	 * 動的フィールドの一覧を返します.
	 * @return
	 */
	std::unordered_map<std::string, Object_*> getDynFields() const;

	//
	//キャスト
	//

	/**
	 * 変換出来るなら Boolean に変換して返します.
	 * @return 変換出来なかったら nullptr
	 */
	virtual Boolean* asBoolean();

	/**
	 * 変換出来るなら Numeric に変換して返します.
	 * @return 変換出来なかったら nullptr
	 */
	virtual Numeric* asNumeric();

	/**
	 * 変換出来るなら Character に変換して返します.
	 * @return 変換出来なかったら nullptr
	 */
	virtual Character* asCharacter();

	/**
	 * 変換出来るなら String_ に変換して返します.
	 * @return 変換出来なかったら nullptr
	 */
	virtual String* asString();

	/**
	 * 変換出来るなら UserDelegate に変換して返します.
	 * @return 変換出来なかったら nullptr
	 */
	virtual UserDelegate* asUserDelegate();

	/**
	 * 変換出来るなら UserObject に変換して返します.
	 * @return 変換出来なかったら nullptr
	 */
	virtual UserObject* asUserObject();

	/**
	 * 変換出来るなら UserArray に変換して返します.
	 * @return 変換出来なかったら nullptr
	 */
	virtual UserArray* asUserArray();

	/**
	 * 変換出来るなら UserThread に変換して返します.
	 * @return 変換出来なかったら nullptr
	 */
	virtual UserThread* asUserThread();

	/**
	 * 変換出来るなら UserComponent に変換して返します.
	 * @return 変換出来なかったら nullptr
	 */
	virtual UserComponent* asUserComponent();

	/**
	 * 仮想フィールドを返します.
	 * 仮想フィールドは、配列中の要素のような Field に格納されないが、GCの対象とならない値のことです。
	 * @return
	 */
	virtual std::vector<Object_*> getVirtualField();

protected:
	/**
	 * クラスが要求されたときにまだnullptrだと呼ばれます.
	 */
	virtual void lazyLoading();

	/**
	 * GC用の詳細情報を生成します.
	 * ネイティブリソースのような削除が他のオブジェクトと異なるものでは、
	 * ここで ObjectState のサブクラス型を返します。
	 * @return
	 */
	virtual ObjectStateSPtr createState();

	/**
	 * GCの詳細情報を出力して改行します.
	 */
	void dumpAttrLn();

	/**
	 * このオブジェクトを削除します.
	 */
	void deleteSelf();

	/**
	 * a に対して動的メンバーを連結して返します.
	 * @param a
	 * @return
	 */
	std::vector<Object_*> concatDynamicMembers(std::vector<Object_*> a);

	/**
	 * このインスタンスに定義された動的メンバーの一覧を返します.
	 * @return
	 */
	std::vector<Object_*> getDynamicMembers();
private:
	ThreadWPtr thread;
	ClassWPtr classz;
	ObjectStateSPtr state;
	std::unordered_map<std::string, Object_*> dynFields;
	std::unordered_map<std::string, std::vector<UserDelegate*>> dynMethods;
	bool notify;
	/**
	* このオブジェクトを起点として参照可能な全てのオブジェクトをマークします.
	*/
	void markTreeImpl();

	Object_* newExecutor();
	void deleteExecutor(Object_* ref);
};
#endif // !BEAN_ENV_OBJECT_H_
