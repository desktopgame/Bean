#pragma once
#ifndef BEAN_ENV_ENUMITEM_H
#define BEAN_ENV_ENUMITEM_H
#include "Class.h"
#include "Reference.h"
/**
 * �񋓎q.
 */
class EnumItem : public Class, public Reference {
public:
	EnumItem(ClassLoaderSPtr classLoader, ClassSPtr super, std::string name, int id, Object_* value);
	~EnumItem();
	/**
	 * ���̗񋓎q�̓Y������Ԃ��܂�.
	 * @return
	 */
	int getId() const;

	/**
	 * ���̗񋓎q�̒l��Ԃ��܂�.
	 * @return
	 */
	Object_* getValue() const;
private:
	int id;
	Object_* value;
};
#endif // !BEAN_ENV_ENUMITEM_H
