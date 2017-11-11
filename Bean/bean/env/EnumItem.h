#pragma once
#ifndef BEAN_ENV_ENUMITEM_H
#define BEAN_ENV_ENUMITEM_H
#include "Class.h"
#include "Reference.h"
/**
 * 列挙子.
 */
class EnumItem : public Class, public Reference {
public:
	EnumItem(ClassLoaderSPtr classLoader, ClassSPtr super, std::string name, int id, Object_* value);
	~EnumItem();
	/**
	 * この列挙子の添え字を返します.
	 * @return
	 */
	int getId() const;

	/**
	 * この列挙子の値を返します.
	 * @return
	 */
	Object_* getValue() const;
private:
	int id;
	Object_* value;
};
#endif // !BEAN_ENV_ENUMITEM_H
