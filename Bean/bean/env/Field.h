#pragma once
#ifndef BEAN_ENV_FIELD_H
#define BEAN_ENV_FIELD_H
#include <functional>
#include <map>
#include <memory>
#include <unordered_map>
#include "Member.h"
class ASTFactor;
class Object_;
class Object_;
/**
 * �l���i�[����t�B�[���h�ł�.
 */
class Field : public Member  {
public:
	Field(ClassSPtr classz, Modifier modifier, const std::string& name);
	~Field();

	/**
	 * �w��̃I�u�W�F�N�g�̃t�B�[���h���i�[���邽�߂̗̈���m�ۂ��܂�.
	 * @param obj
	 */
	void alloc(Object_* obj);

	/**
	 * �w��̃I�u�W�F�N�g�̃t�B�[���h���i�[���邽�߂̗̈���J�����܂�.
	 * @param obj
	 */
	void free(Object_* obj);

	/**
	 * �l���㏑�����܂�.
	 * @param obj
	 * @param value
	 */
	void setValue(Object_* obj, Object_* value);

	/**
	 * �l��Ԃ��܂�.
	 * @param obj
	 * @return
	 */
	Object_* const getValue(Object_* obj);

	/**
	 * ���̃t�B�[���h�̃f�t�H���g�l��ݒ肵�܂�.
	 * @param defaultValue
	 */
	void setDefaultValue(std::shared_ptr<ASTFactor> defaultValue);

	/**
	 * ���̃t�B�[���h�̃f�t�H���g�l��Ԃ��܂�.
	 * @return
	 */
	std::shared_ptr<ASTFactor> getDefaultValue() const;

	/**
	 * ���̃t�B�[���h�� ���� �ɂȂ��Ă���Ȃ� true ��Ԃ��܂�.
	 */
	bool isInvalid() const;

	/**
	 * �S�Ă̒l�ɏ������܂�.
	 * @param f
	 */
	void eachAllValues(std::function<void(Object_*, Object_*)> f);

	std::string getLocation() override;

	/**
	 * �S�Ẵt�B�[���h�ɏ������܂�.
	 * @param f
	 */
	static void eachAllFields(std::function<void(Field*)> f);

	/**
	 * �S�Ă̐ÓI�t�B�[���h���}�[�N���܂�.
	 */
	static void markStatics();

	/**
	 * �S�Ă̐ÓI�t�B�[���h��T���r���Ƃ��ă}�[�N���܂�.
	 */
	static void paintSearchNow();

	/**
	 * �ÓI�t�B�[���h��GC�ɉ�������悤�ɂ��܂�.
	 * ���̃��\�b�h�̉e�����󂯂��t�B�[���h�� ���� ��ԂɂȂ�܂��B
	 */
	static void invalidateStatics();
private:
	void staticInit();
	void invalidate();
	static void eachStatics(std::function<void(Field*)> f);
	static std::vector<Field*> staticFields;
	static std::vector<Field*> allFields;
	std::unordered_map<Object_*, Object_*> map;
	Object_* staticRef;
	std::weak_ptr<ASTFactor> defaultValue;
	bool bInvalid;
};
#endif // !BEAN_ENV_FIELD_H
