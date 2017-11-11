#pragma once
#ifndef BEAN_ENV_ENUM_H
#define BEAN_ENV_ENUM_H
#include "Class.h"
/**
 * 列挙型.
 */
class Enum : public Class {
public:
	Enum(ClassLoaderSPtr classLoader, ClassSPtr super, std::string name);
	~Enum();
	bool isEnum() const override;

	/**
	 * 指定の名前の列挙子を返します.
	 * @param name
	 * @return
	 */
	Object_* findEnumItem(const std::string& name);

	/**
	 * 指定の値を持つ列挙子があるならtrueを返します.
	 * @param obj
	 * @return
	 */
	bool containsEnumItem(Object_* obj);

	/**
	 * この列挙の生成番号を返します.
	 * 列挙子の比較のために使用されます。
	 * @return
	 */
	int getId() const;
protected:
	int id;
	static int enumId;
};
#endif // !BEAN_ENV_ENUM_H
