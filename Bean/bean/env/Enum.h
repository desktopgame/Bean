#pragma once
#ifndef BEAN_ENV_ENUM_H
#define BEAN_ENV_ENUM_H
#include "Class.h"
/**
 * �񋓌^.
 */
class Enum : public Class {
public:
	Enum(ClassLoaderSPtr classLoader, ClassSPtr super, std::string name);
	~Enum();
	bool isEnum() const override;

	/**
	 * �w��̖��O�̗񋓎q��Ԃ��܂�.
	 * @param name
	 * @return
	 */
	Object_* findEnumItem(const std::string& name);

	/**
	 * �w��̒l�����񋓎q������Ȃ�true��Ԃ��܂�.
	 * @param obj
	 * @return
	 */
	bool containsEnumItem(Object_* obj);

	/**
	 * ���̗񋓂̐����ԍ���Ԃ��܂�.
	 * �񋓎q�̔�r�̂��߂Ɏg�p����܂��B
	 * @return
	 */
	int getId() const;
protected:
	int id;
	static int enumId;
};
#endif // !BEAN_ENV_ENUM_H
