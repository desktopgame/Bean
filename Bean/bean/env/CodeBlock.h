#pragma once
#ifndef BEAN_ENV_CODEBLOCK_H
#define BEAN_ENV_CODEBLOCK_H
#include <functional>
#include <map>
#include <mutex>
#include <string>
#include <unordered_map>
#include <vector>
//#define SCOPE_LOCK std::lock_guard<std::recursive_mutex> lock(thread_sync)
//#define SCOPE_LOCK ;
class Object_;
/**
 * 変数を管理するクラス.
 */
class CodeBlock {
public:
	/**
	 * 新たなコードブロックを構築します.
	 * このコンストラクタは基本的にルートを作成するために一度だけクライアントによって呼び出されます。
	 */
	CodeBlock();

	/**
	 * このコードブロックを破棄します.
	 * コードブロックの子階層を先に削除するとアクセス違反が発生するため、
	 * このデストラクタが呼び出し側で実行されるとき、レシーバは常にルートです。
	 */
	~CodeBlock();

	/**
	 * スタック上の変数を探索途中としてマークします.
	 */
	static void paintSearchNow();

	/**
	 * スタック上の変数をマークします.
	 */
	static void mark_items();

	/**
	 * スタック上に指定の変数が存在するなら除去します.
	 * @param ref
	 */
	static void sweep_item(Object_* ref);

	/**
	 * 全てのスタックを訪問します.
	 * ただしコールスタックとしてのみ機能するブロックは無視されます。
	 * @param f
	 */
	static void forEach(std::function<void(CodeBlock*)> f);

	/**
	 * このコードブロックの複製を返します.
	 * @param syncData シンボルテーブルを共有するならtrue.
	 */
	CodeBlock* clone(bool syncData);

	/**
	 * このコードブロックに定義された参照を削除します.
	 * @param 削除される参照の名前
	 * @return 削除された参照
	 */
	Object_* removeReference(const std::string& name);

	/**
	 * このコードブロックに定義された参照の一覧を削除します.
	 */
	void clearReference();

	/**
	 * このコードブロックに新たな参照を定義します.
	 * 既に定義されている参照は上書きされます。
	 * @param name 変数名
	 * @param ref
	 */
	void declReference(const std::string& name, Object_* ref);

	/**
	 * このコードブロック、
	 * もしくはその上のコードブロックを検索して、
	 * 既に name の定義されているコードブロックで変数を上書きします.
	 * @param name
	 * @param ref
	 */
	void writeReference(const std::string& name, Object_* ref);

	/**
	 * このコードブロックに定義された参照を返します.
	 * このコードブロックから検索を開始し、見つからなければ上位へと検索を進めます.
	 * @param name 変数名
	 * @return
	 */
	Object_* readReference(const std::string& name);

	/**
	 * 親スコープを走査せず、このスコープのテーブルだけを検索します.
	 * @param name
	 * @return
	 */
	Object_* readCurrentScope(const std::string& name);

	/**
	 * 新たなコードブロックを開始します.
	 * 以降の変数IO, コードブロックの開始/終了は新たなコードブロックへ委譲されます。
	 * @param isClosure クロージャならtrue
	 */
	void enter(bool isClosure);

	/**
	 * コードブロックを終了し、親スコープへ戻ります。
	 * 以降の変数IO, コードブロックの開始/終了は親要素によって実行されます。
	 * @param isGC 定義された参照を削除するならtrue.
	 */
	void exit(bool isGC);

	/**
	 * マークアンドスイープによって回収された参照をこのブロックから除去します.
	 * @param ref
	 */
	void remove(Object_* ref);

	/**
	 * このスコープの変数一覧を返します.
	 * @return
	 */
	std::vector<std::string> getVariableName();

	/**
	 * このコードブロックの深さを返します.
	 * ルートでは0です。
	 * @return
	 */
	int getDepth() const;

	/**
	 * このコードブロックの子要素の数を返します.
	 * @return
	 */
	int getCount() const;

	/**
	 * このコードブロックがクロージャならtrue.
	 * @return
	 */
	bool getClosure() const;

	/**
	 * ルート要素を返します.
	 * @return
	 */
	CodeBlock* getRoot();

	/**
	 * 親要素を返します.
	 * @return
	 */
	CodeBlock* getParent() const;

	/**
	 * 現在の委譲先を返します.
	 * @return
	 */
	CodeBlock* getPointer();

	/**
	 * 指定位置の子要素を返します.
	 * @param index
	 * @return
	 */
	CodeBlock* getElementAt(int index) const;

	/**
	 * 参照可能な全ての参照を返します.
	 * @return
	 */
	std::vector<Object_*> getRuntime();

	/** 
	 * コールスタックとして機能するコードブロックでtrueを返します.
	 * 新しいスレッドのコードブロックではメモリ空間を共有しますが、
	 * 呼び出し階層は共有出来ません。
	 * これはマルチスレッドの恩恵を受けるための意図的な仕様です。
	 * @return
	 */
	bool isCallStack() const;

	/**
	 * このコードブロック、またその子要素に定義された参照の一覧を出力します.
	 */
	void dump();

	void pri__map_decl(const std::string& name, Object_* ref);
	void pri__map_decl_impl(const std::string& name, Object_* ref);
	Object_* pri__map_read(const std::string& name);
	void pri__map_clear();
	void pri__map_erase(const std::string& name);
	void pri__map_each(std::function<bool(const std::string&, Object_*)> f);
	bool pri__map_contains(const std::string& name);
	std::string pri__list_at(int index);
	void pri__list_erase(int index);
	int pri__list_size();
private:
	/**
	 * 子要素を作成するために利用されるコンストラクタです.
	 * @param parent
	 * @param depth
	 * @param isClosure
	 */
	CodeBlock(CodeBlock* parent, int depth, bool isClosure);

	/**
	 * フィールドを初期化します.
	 * コンストラクタによって呼び出されます。
	 * @param parent
	 * @param depth
	 * @param isClosure
	 */
	void init(CodeBlock* parent, int depth, bool isClosure);

	/**
	* フィールドを開放します.
	* デストラクタによって呼び出されます。
	*/
	void destroy();

	/**
	 * このインスタンスに定義された参照を返します.
	 * @param name 変数名
	 * @param isClosure
	 * @return
	 */
	Object_* readCurrentReference(const std::string& name, bool isClosure);

	//helper
	void declReference(const std::string& name, Object_* ref, bool isClosure);
	void writeReferenceImpl(const std::string& name, Object_* ref);
	Object_* readReference(const std::string& name, bool isClosure);
	bool hasDelegateTarget();
	CodeBlock* getDelegateTarget();
	void getRuntimeImpl(CodeBlock* root, std::vector<Object_*>* ret);
	void removeImpl(CodeBlock* root, Object_* ref);

	

	CodeBlock* cloneImpl(CodeBlock* srcRoot, CodeBlock* dstRoot, bool syncData);
	//fields
	void dumpImpl(CodeBlock* root, int depth);
	int depth;
	int addres;
	bool isClosure;
	std::unordered_map<std::string, Object_*> map;
	std::vector<std::string> variableVector;
	std::vector <CodeBlock*> childrenVector;
	CodeBlock* parent;
	CodeBlock* source;
	static std::vector<CodeBlock*> rootBlockVec;
};
#endif // !BEAN_ENV_CODEBLOCK_H
