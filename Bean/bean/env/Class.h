#pragma once
#ifndef BEAN_ENV_CLASS_H
#define BEAN_ENV_CLASS_H
#include <iostream>
#include <memory>
#include <string>
#include <vector>
class ClassLoader;
class Constructor_;
class Member;
class Field;
class Method;
class Object_;

class Class;
using ClassSPtr = std::shared_ptr<Class>;
using ClassWPtr = std::weak_ptr<Class>;
#include "ClassLoaderSkeleton.h"
/**
 * 型をモデル化します.
 *
 * 特異クラス
 * 動的に作成されるクラスのうち、
 * そのクラスの親として機能するクラスより先に delete されると問題になる場合があります。
 *
 * 例えば、EnumItem は動的に作成されるクラスですが、
 * その実態は Enum クラスの 静的フィールドです。
 * EnumItem が Enumのフィールドとして適切に削除されることが保証されるために、
 * EnumItem を Package に登録せず、特異クラスのインスタンスに削除させます。
 * このためにクライアントコードでは singular を trueで初期化することが出来ます。
 * このコンストラクタでは Package への登録が行われません。
 * また、UserObjectのデストラクタでは Class#isSingular を確認して、
 * delete を行うように実装されているので、deleteのコードを用意する必要はありません。
 * 
 * 特異クラスとして使用されるためには下記の条件を満たす必要があります。
 * -インスタンスが一つである
 */
class Class : public std::enable_shared_from_this<Class> {
public:
	Class(ClassLoaderSPtr classLoader, ClassSPtr super, std::string name, bool singular);
	Class(ClassLoaderSPtr classLoader, ClassSPtr super, std::string name);
	Class(ClassLoaderSPtr classLoader, std::string name);
	virtual ~Class();

	/**
	 * このクラスをリストへ紐づけます.
	 * std::shared_ptr#shared_from_this はコンストラクタから参照出来ないので、
	 * 呼び出し側では生成した後に必ずこのメソッドを呼び出してください。
	 */
	void registerClass();

	/**
	 * コンストラクタを追加します.
	 * @param constructor
	 */
	void addConstructor(Constructor_* constructor);

	/**
	 * 指定のシグネチャのコンストラクタを返します.
	 * @param paramCOunt
	 * @param findParents 親もさかのぼるならtrue
	 * @return
	 */
	Constructor_* const findConstructor(int paramCount, bool findParents);

	/**
	 * 指定のシグネチャのコンストラクタを返します.
	 * このクラス自身にコンストラクタが一つもないなら親をさかのぼります。
	 * @param cll
	 * @param paramCOunt
	 * @param findParents 親もさかのぼるならtrue
	 * @return
	 */
	Constructor_* const findConstructor(ClassLoaderSPtr cll, int paramCount, bool findParents);

	/**
	 * 指定位置のコンストラクタを返します.
	 * @param index
	 * @return
	 */
	Constructor_* const getConstructorAt(int index);

	/**
	 * 引数を一つも取らないコンストラクタが含まれていて、
	 * それが public もしくは protected ならtrue.
	 * @return
	 */
	bool hasDefaultConstructor();

	/**
	 * このクラスのコンストラクタ一覧を返します.
	 * @return
	 */
	std::vector<Constructor_*> getConstructors();

	/**
	 * 指定位置のコンストラクタを削除します.
	 * @param index
	 */
	void removeConstructorAt(int index);

	/**
	 * 全てのコンストラクタの数を返します.
	 * @return
	 */
	int getConstructorCount();

	/**
	 * フィールドを追加します.
	 * @param field
	 */
	void addField(Field* field);

	/**
	 * 指定位置のフィールドを返します.
	 * @param index
	 * @return
	 */
	Field* const getFieldAt(int index);

	/**
	 * このクラスのフィールド一覧を返します.
	 * @return
	 */
	std::vector<Field*> getFields();

	/**
	 * 指定の名前のフィールドを返します.
	 * 必要に応じて親クラスも探します。
	 * @param name
	 */
	Field* const findField(const std::string& name);

	/**
	 * 指定位置のフィールドを削除します.
	 * @param index
	 */
	void removeFieldAt(int index);

	/**
	 * 全てのフィールドの数を返します.
	 * @return
	 */
	int getFieldCount();

	/**
	 * メソッドを追加します.
	 * @param method
	 */
	void addMethod(Method* method);

	/**
	 * 指定位置のメソッドを返します.
	 * @param index
	 * @return
	 */
	Method* const getMethodAt(int index);

	/**
	 * このクラスのメソッド一覧を返します.
	 * @return
	 */
	std::vector<Method*> getMethods();

	/**
	 * 指定のシグネチャのフィールドを返します.
	 * 必要に応じて親クラスも探します。
	 * @param name
	 * @param paramCount
	 * @param findParentsIfConstructor 検索しているメソッドがnewのとき、親クラスも検索するならtrue.
	 * @param extractProxy 検索しているメソッドがnewのとき、代理人のMethodを返すならtrue.
	 */
	Method* const findMethod(const std::string& name, int paramCount, bool findParentsIfConstructor, bool extractProxy);

	/**
	 * コンストラクタとして返します.
	 * @param name
	 * @param paramCount
	 * @param findParentsIfConstructor 検索しているメソッドがnewのとき、親クラスも検索するならtrue.
	 * @return
	 */
	Method* const findMethod(const std::string&, int paramCount, bool findParentsIfConstructor);

	/**
	 * 指定位置のメソッドを削除します.
	 * @param index
	 * @return
	 */
	void removeMethodAt(int index);

	/**
	 * 全てのメソッドの数を返します.
	 * @return
	 */
	int getMethodCount();

	/**
	 * 親クラスを返します.
	 * @return
	 */
	ClassWPtr const getSuper();

	/**
	 * 単純なクラス名を返します.
	 * @return
	 */
	std::string getName() const;

	/**
	 * このクラスが指定のクラスを直接あるいは子階層のどれかを介して継承しているならtrue.
	 * @param classz
	 * @return
	 */
	bool isSubClass(Class* classz);

	/**
	 * このクラスが指定のクラスを直接あるいは子階層のどれかを介して継承しているならtrue.
	 * @param classz
	 * @return
	 */
	bool isSubClass(ClassSPtr classSPtr);

	/**
	 * 列挙ならtrue.
	 * @return
	 */
	virtual bool isEnum() const;

	/**
	 * 特異クラスならtrue.
	 * @return
	 */
	bool isSingular() const;

	/**
	 * このクラスを読み込んだクラスローダーを返します.
	 * @return
	 */
	ClassLoaderWPtr getClassLoader() const;

	/**
	 * 指定のオブジェクトのための領域を確保します.
	 * @param o
	 */
	void allocateField(Object_* o);

	/**
	 * 指定のオブジェクトのための領域を開放します.
	 * @param o
	 */
	void freeField(Object_* o);
	
	/**
	 * このクラスのクラスローダーが削除されるときに呼び出されます.
	 * このメソッドはクライアントコードでは呼び出さないでください。
	 */
	void deleteClassLoader(const ClassLoader* const classLoader);

	/**
	 * 指定のクラスがまだロードされていなければ
	 * ロードして返します。
	 * @param fqcn
	 * @return
	 */
	static ClassSPtr dynamicLoading(const std::string& fqcn);

	/**
	 * 指定のクラスを必要に応じて読みこみ、インスタンスを生成して返します.
	 * @param fqcn
	 * @param args
	 * @return
	 */
	static Object_* dynamicNewInstance(const std::string& fqcn, std::vector<Object_*> args);

	/**
	 * 空引数で生成します.
	 * @param fqcn
	 */
	static Object_* dynamicNewInstance(const std::string& fqcn);

	/**
	 * 引数1で生成します.
	 * @param arg1
	 */
	static Object_* dynamicNewInstance(const std::string& fqcn, Object_* arg1);

	/**
	 * 引数2で生成します.
	 * @param arg1
	 * @param arg2
	 */
	static Object_* dynamicNewInstance(const std::string& fqcn, Object_* arg1, Object_* arg2);

	/**
	 * 引数3で生成します.
	 * @param arg1
	 * @param arg2
	 * @param arg3
	 */
	static Object_* dynamicNewInstance(const std::string& fqcn, Object_* arg1, Object_* arg2, Object_* arg3);

	/**
	 * 指定のクラスの staticメソッドを呼び出します.
	 * @param fqcn
	 * @param methodName
	 * @parma args
	 */
	static Object_* dynamicStaticCall(const std::string& fqcn, std::string methodName, std::vector<Object_*> args);

protected:
private:
	void init(ClassLoaderSPtr classLoader, ClassSPtr super, std::string name, bool singular);
	void init(ClassLoaderSPtr classLoader, std::string name);
	ClassLoaderWPtr classLoader;
	ClassWPtr super;
	std::string name;
	std::vector<Constructor_*> constructors;
	std::vector<Field*> fields;
	std::vector<Method*> methods;
	bool nullOfClassLoader;
	bool singular;
};
#endif // !BEAN_ENV_CLASS_H


