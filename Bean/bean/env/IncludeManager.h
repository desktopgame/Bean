#pragma once
#ifndef BEAN_ENV_INCLUDEMANAGER_H
#define BEAN_ENV_INCLUDEMANAGER_H
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>
class Class;
using ClassSPtr = std::shared_ptr<Class>;
/**
 * 予めクラスの完全修飾名をリストで保持しておき、
 * 単純名でインスタンスが要求された場合にリストと照会して適切なインスタンスを生成します。
 */
class IncludeManager {
public:
	IncludeManager();
	~IncludeManager();
	/**
	 * 指定のクラスをインクルードします.
	 * @param fqcn
	 */
	void include(const std::string& fqcn);

	/**
	 * クラスAにおいて、自身を省略名で参照するためにインクルードします。
	 * @param self
	 */
	void self(const std::string& self);

	/**
	 * 指定のクラスを別名でアクセスできるようにします.
	 * oldName からクラスを見つけられなかった場合は別名を付けずに false を返します。
	 * @param oldName
	 * @parma newName
	 */
	bool alias(const std::string& oldName, const std::string& newName);

	/**
	 * alias を 呼び出して false が 返された場合、 ClassFormatException を スローします。
	 * @param oldName
	 * @param newName
	 */
	void checkAlias(const std::string& oldName, const std::string& newName);

	/**
	 * 指定の名前のクラスを返します.
	 * まずパッケージから検索し、見つからなかった場合照会します。
	 * @param name 完全修飾名/あるいは単純名
	 */
	ClassSPtr getClass(const std::string& name);
private:
	std::string selfName;
	std::vector<std::string> nameVec;
	std::unordered_map < std::string, std::string> aliasMap;
};
#endif // !BEAN_ENV_INCLUDEMANAGER_H


