#pragma once
#ifndef BEAN_ENV_PACKAGE_H
#define BEAN_ENV_PACKAGE_H
#include <functional>
#include <memory>
#include <vector>
class Class;
using ClassSPtr = std::shared_ptr<Class>;

class Package;
using PackageSPtr = std::shared_ptr<Package>;
using PackageWPtr = std::weak_ptr<Package>;

/**
 * クラスを格納するコンテナです.
 */
class Package final : public std::enable_shared_from_this<Package> {

	
	using PackageVisitor = std::function<void(PackageSPtr)>;
	using ClassVisitor = std::function<void(ClassSPtr)>;
public:
	Package(PackageSPtr parent, const std::string& name);
	Package(const std::string& name);
	~Package();

	/**
	 * このパッケージにサブパッケージを追加します.
	 * @param name
	 */
	PackageSPtr addPackage(const std::string& name);
	
	/**
	 * このパッケージの配下にクラスを追加します.
	 * @param classz
	 */
	void addClass(ClassSPtr classz);

	/**
	 * 指定位置のパッケージを返します.
	 * @param index
	 * @return
	 */
	PackageSPtr getPackageAt(int index);

	/**
	* 指定位置のクラスを返します.
	* @param index
	* @return
	*/
	ClassSPtr const getClassAt(int index);

	/**
	 * このパッケージとその配下のパッケージを再帰的に訪問します.
	 * @param visitor
	 */
	void visit(PackageVisitor visitor);

	/**
	 * このパッケージ直下のパッケージの数を返します.
	 * @return
	 */
	int getPackageCount();

	/**
	 * このパッケージ直下のクラスの数を返します.
	 * @return index
	 */
	int getClassCount();

	/**
	 * 親パッケージを返します.
	 * ルートではnullptrです。
	 * @return
	 */
	PackageWPtr getParent();

	/**
	 * 親がいるならtrue.
	 * @return
	 */
	bool hasParent();

	/**
	 * このパッケージの名前を返します.
	 * @return
	 */
	std::string getName();

	/**
	 * このパッケージが属するディレクトリを返します.
	 * @return
	 */
	std::string getDirectory();

	/**
	 * このパッケージから下をダンプします.
	 */
	void dump();

	/**
	 * ルートに新しいパッケージを定義します.
	 * @param name
	 */
	static PackageSPtr newPackage(const std::string& name);

	/**
	 * 既に定義されているパッケージを検索します.
	 * 引数はピリオドによって区切られ(先頭と最後はなし)ている必要があります。
	 * @param fqcn
	 * @param make 見つからなかった場合には新規に作成するならtrue.
	 * @return
	 */
	static PackageSPtr getPackage(const std::string& fqcn, bool make);

	/**
	 * getPackage(fqcn, false)と等価です.
	 * @param fqcn
	 * @param make
	 * @return
	 */
	static PackageSPtr getPackage(const std::string& fqcn);

	/**
	 * ルートのパッケージを全て返します.
	 * @return
	 */
	static std::vector<PackageSPtr> getPackages();

	/**
	 * 既に定義されているクラスを検索します.
	 * 見つからない場合はnullptrを返します。
	 * @param fqcn
	 * @param make 存在しないパッケージを作成するならtrue.
	 * @return
	 */
	static ClassSPtr const getClass(const std::string& fqcn, bool make);

	/**
	 * trueで呼び出します.
	 * @param fqcn
	 */
	static ClassSPtr const getClass(const std::string& fqcn);

	/** 
	 * クラスを検索し、見つからなかった場合は現在のクラスローダーでそれのロードを行います.
	 * @param fqcn
	 */
	static ClassSPtr const getClassOrLoad(const std::string& fqcn);

	/**
	 * 指定のクラス名から実際のパスを特定します.
	 * @param fqcn
	 * @return
	 */
	static std::string resolvePath(const std::string& fqcn);

	/**
	 * 指定のクラス名からパッケージ名を特定します.
	 * @param fqcn
	 * @return
	 */
	static std::string resolvePackage(const std::string& fqcn);

	/**
	 * 全てのクラスを訪問します.
	 * @param cv
	 */
	static void visitAllClasses(ClassVisitor cv);

	/**
	 * 全てのパッケージをダンプします.
	 */
	static void dumpAll();

	/**
	 * 全てのパッケージをdeleteします.
	 */
	static void destroy();

	/**
	 * Classクラスのコンストラクタから呼び出されます.
	 * @param classz
	 */
	static void registerClass(ClassSPtr classz);

	const static std::string ENTRY_POINT_PACKAGE;
private:
	static std::vector<PackageSPtr> rootPackages;
	static std::vector<ClassSPtr> rootClasses;
	
	void visitorImpl(PackageSPtr, PackageVisitor fv);
	void dumpImpl(PackageSPtr, int depth);
	PackageWPtr parent;
	std::vector<PackageSPtr> children;
	std::vector<ClassSPtr> classes;
	std::string name;
	bool bHasParent;
};
#endif // !BEAN_ENV_PACKAGE_H


