#pragma once
#ifndef BEAN_ENV_CLASSLOADER_H
#define BEAN_ENV_CLASSLOADER_H
#include <list>
#include <memory>
#include <mutex>
#include <stack>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>
class ASTNode;
class Package;
class CodeBlock;
class StackTrace_;
class Thread;
class Class;
class Object_;
class IncludeManager;
class FunctionManager;

class ASTClassDeclaration;
class ASTEnumDeclaration;

class ASTConstructorChain;

class Constructor_;
class ClassLoader;
using ClassLoaderSPtr = std::shared_ptr<ClassLoader>;
using ClassLoaderWPtr = std::weak_ptr<ClassLoader>;

using ClassSPtr = std::shared_ptr<Class>;
using ThreadSPtr = std::shared_ptr<Thread>;
using ThreadWPtr = std::weak_ptr<Thread>;
//using TheadID = std::thread::id;
/**
 * 抽象構文木をClassオブジェクトへと変換するクラスです.
 *
 * クラスローダーにはルートの概念があります。
 * ここでいうルートとはObjectクラスのことではなく、
 * トップレベルの関数が定義されるエントリポイントに該当するファイルのことです。
 * Beanではメインメソッドは必要ないので、
 * クラスを持たない構文木だけを持つクラスローダーがルートになります。
 */
class ClassLoader final : public std::enable_shared_from_this<ClassLoader> {
public:
	/**
	 * エントリポイントで定義されたクラスを作成するために使用出来ます.
	 * この場合では一部の処理をエントリポイントを表すクラスローダに委譲する必要があるので、
	 * そのフラグをONにします。
	 * @param paretn
	 * @param root
	 * @param path
	 * @param delegateCLL
	 */
	ClassLoader(ClassLoaderSPtr parent, std::shared_ptr<ASTNode> root, std::string path, bool delegateCLL);
	
	/**
	 * 親クラスローダーを指定して新たなクラスローダーを構築します.
	 * @param parent
	 * @param root
	 * @param path
	 */
	ClassLoader(ClassLoaderSPtr parent, std::shared_ptr<ASTNode> root, std::string path);
	
	/**
	 * ルートクラスローダーを作成します.
	 * @param root
	 */
	ClassLoader(std::shared_ptr<ASTNode> root);
	~ClassLoader();

	/**
	 * このクラスローダーを親クラスローダーに紐づけます.
	 * std::shared_ptr#shared_from_this はコンストラクタから参照出来ないので、
	 * 呼び出し側では生成した後に必ずこのメソッドを呼び出してください。
	 */
	void registerClassLoader();

	/**
	 * インクルードやコードブロックの階層を保ったまま
	 * 構文木だけを入れ替えます.
	 * REPLで使用されます。
	 * @param root
	 */
	void setRoot(std::shared_ptr<ASTNode> root);

	/**
	 * 指定のクラスをロードします.
	 * @param fqcn
	 * @return
	 */
	ClassSPtr const loadClass(std::string fqcn);

	/**
	 * 指定のクラスローダーをこのクラスローダーの子要素に設定します.
	 * クラスの動的作成で使用されます。
	 * @param child
	 */
	void loadClass(ClassLoaderSPtr child);


	/**
	 * クラス宣言を読み込んでパッケージへ追加します.
	 * @param package
	 * @param classDecl
	 * @param parent
	 */
	static void loadClass(const std::string& package, std::shared_ptr<ASTClassDeclaration> classDecl, ClassLoaderSPtr parent);

	/**
	 * 列挙宣言を読み込んでパッケージへ追加します.
	 * @param package
	 * @param classDecl
	 * @param parent
	 */
	static void loadEnum(const std::string& package, std::shared_ptr<ASTEnumDeclaration> enumDecl, ClassLoaderSPtr parent);

	/**
	 * Bean固有プロパティを読み込んで
	 * このクラスローダーに適用します.
	 */
	void loadProperties();

	/**
	 * このクラスローダーがエントリポイントに定義されているならtrue.
	 * @return
	 */
	bool isEntryPoint() const;

	/**
	 * このクラスローダーが委譲する対象となる親ローダーを返します.
	 * @return
	 */
	ClassLoaderWPtr getParent() const;

	/**
	 * 指定のクラスを構成する構文木を返します.
	 * @return
	 */
	std::shared_ptr<ASTNode> getRoot() const;

	/**
	 * このクラスローダーのスタックトレースを返します.
	 * @return
	 */
	CodeBlock* const getCodeBlock();

	/**
	 * 読みこんだクラスを返します.
	 * ルートではnullptrを返します。
	 * @return
	 */
	ClassSPtr const getClass() const;

	/**
	 * パスを返します.
	 * @return
	 */
	std::string getPath() const;

	/**
	 * 読みこんだクラス名を返します.
	 * @return
	 */
	std::string getClassName() const;

	/**
	* 読みこんだパッケージ名を返します.
	* @return
	*/
	std::string getPackageName() const;

	/**
	 * 関数一覧を返します.
	 * トップレベルのクラスローダーでのみ使用可能です。
	 * @return
	 */
	FunctionManager* const getFunctionManager() const;

	/**
	 * このクラスローダーが参照するクラス一覧を返します.
	 * @return
	 */
	IncludeManager* const getIncludeManager() const;

	/**
	 * 指定のインスタンスでこのクラスローダーを束縛します.
	 * メソッドを実行するとき、それをどのインスタンスが実行するべきかという情報は構文木から知ることが出来ません。
	 *
	 * ただし、これは名前付きで実行する場合(hoge.piyo()のような場合)は別で、
	 * コードブロックから変数名で検索すればどのインスタンスが実行するべきかは明らかです。
	 * クラスが自身のメソッドを実行する場合は特に問題で、変数名が存在しません。(hoge自身が piyo() する場合)
	 * ですが、クラスが自身のメソッドを実行する場合でも最初の一回は必ず名前付きで呼び出す必要があります。
	 * 
	 * このメソッドはその最初の一回で呼び出される必要があります。
	 * もちろん、メソッド呼び出しは階層的に行うことが出来るので、
	 * 名前無しの呼び出しの中で名前付きの呼び出しが行われたなら、再びこのメソッドを呼び出す必要があります。
	 *
	 * 階層から復帰するために、この呼び出しの引数はスタックへ記憶されます。
	 * スタックが階層を正しく表現するために、名前付き呼び出しが終わった後にはunlockInstanceを呼び出します。
	 * @param o
	 */
	void lockInstance(Object_* o);

	/**
	 * 最後にクラスローダーを束縛したインスタンスを返します.
	 * @param forSuper このクラスローダーで束縛されていない場合に親クラスを探索するならtrue
	 * @return
	 */
	Object_* const getLock(bool forSuper);

	/**
	 * 最後にクラスローダーを束縛したインスタンスを返します.
	 * @return
	 */
	Object_* const getLock();

	/**
	 * 束縛を解除します.
	 */
	void unlockInstance();

	/**
	 * Beanを起動するために最初に作成されるクラスローダーを返します.
	 * @return
	 */
	static ClassLoader* const getSystemClassLoader();

	/**
	 * 現在のクラスローダーを入れ替えます.
	 * @param classLoader;
	 */
	static void pushCurrentClassLoader(ClassLoaderSPtr classLoader);

	//NOTE:使用されてません。
	/**
	 * 現在のクラスローダー型に対して引数のクラスローダ型を代入出来るならtrueを返します。
	 * 例えば Base とそのサブクラス Sub が存在し、
	 * 現在のクラスローダが Base で引数が Sub のときは true を返します。
	 * 現在のクラスローダが エントリポイント なら常に true を返します。
	 * @param classLoader
	 * @return
	 */
	static bool multicastClassLoader(ClassLoaderSPtr classLoader);

	/**
	 * 現在のクラスローダーを戻します.
	 */
	static void popCurrentClassLoader();

	/**
	 * 現在使用されているルートのクラスローダーを返します.
	 * @return
	 */
	static ClassLoaderSPtr getCurrentClassLoader();

	/**
	 * 現在のスレッドのクラスローダーを返します.
	 * 見つからなければシステムクラスローダを返します。
	 */
	static ClassLoaderSPtr getContextClassLoader();

	/**
	 * 全てのクラスローダーを順序良く削除します.
	 */
	static void destroy();

	/**
	 * プログラムの起動に必要な最低限のクラスをロードします.
	 */
	void loadDefaults();

	/** 
	 * このクラスローダーに関連する情報をダンプします.
	 */
	void dump();
protected:

private:
	void init(ClassLoaderSPtr parent, std::shared_ptr<ASTNode> root, bool delegateCll);
	
	void loadUseDirs();
	void loadUseFiles();

	void checkClass(ClassSPtr classz);
	void checkConstructor(ClassSPtr classz);
	void checkMatchChainConstructor(ClassSPtr classz, Constructor_* body, std::shared_ptr<ASTConstructorChain> chain);
	void checkNative(ClassSPtr classz);
	void checkThrow(const std::string mes);
	void checkOverride(ClassSPtr classz);

	ClassLoaderWPtr parent;
	std::shared_ptr<ASTNode> root;
	CodeBlock* source;
	FunctionManager* functionManager;
	IncludeManager* includeManager;
	Object_* lock;
	ThreadWPtr sourceThread;
	std::string path;
	std::recursive_mutex thread_sync;
	std::list<std::string> pkgStack;
	std::stack<Object_*> locks;
	std::vector <ClassLoaderSPtr> children;
	std::unordered_map<std::thread::id, CodeBlock*> codeBlockMap;
	bool entryPoint;
	bool delegateCll;
//	int classCount;
	static std::vector<ClassLoaderSPtr> entryPointCLLVector;
	static std::vector<ClassLoaderSPtr> rootClassLoaderVec;
	static std::stack<ClassLoaderSPtr> classLoaderStack;
};
#endif // !BEAN_ENV_CLASSLOADER_H

