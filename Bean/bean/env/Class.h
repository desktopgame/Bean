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
 * �^�����f�������܂�.
 *
 * ���كN���X
 * ���I�ɍ쐬�����N���X�̂����A
 * ���̃N���X�̐e�Ƃ��ċ@�\����N���X����� delete �����Ɩ��ɂȂ�ꍇ������܂��B
 *
 * �Ⴆ�΁AEnumItem �͓��I�ɍ쐬�����N���X�ł����A
 * ���̎��Ԃ� Enum �N���X�� �ÓI�t�B�[���h�ł��B
 * EnumItem �� Enum�̃t�B�[���h�Ƃ��ēK�؂ɍ폜����邱�Ƃ��ۏ؂���邽�߂ɁA
 * EnumItem �� Package �ɓo�^�����A���كN���X�̃C���X�^���X�ɍ폜�����܂��B
 * ���̂��߂ɃN���C�A���g�R�[�h�ł� singular �� true�ŏ��������邱�Ƃ��o���܂��B
 * ���̃R���X�g���N�^�ł� Package �ւ̓o�^���s���܂���B
 * �܂��AUserObject�̃f�X�g���N�^�ł� Class#isSingular ���m�F���āA
 * delete ���s���悤�Ɏ�������Ă���̂ŁAdelete�̃R�[�h��p�ӂ���K�v�͂���܂���B
 * 
 * ���كN���X�Ƃ��Ďg�p����邽�߂ɂ͉��L�̏����𖞂����K�v������܂��B
 * -�C���X�^���X����ł���
 */
class Class : public std::enable_shared_from_this<Class> {
public:
	Class(ClassLoaderSPtr classLoader, ClassSPtr super, std::string name, bool singular);
	Class(ClassLoaderSPtr classLoader, ClassSPtr super, std::string name);
	Class(ClassLoaderSPtr classLoader, std::string name);
	virtual ~Class();

	/**
	 * ���̃N���X�����X�g�֕R�Â��܂�.
	 * std::shared_ptr#shared_from_this �̓R���X�g���N�^����Q�Əo���Ȃ��̂ŁA
	 * �Ăяo�����ł͐���������ɕK�����̃��\�b�h���Ăяo���Ă��������B
	 */
	void registerClass();

	/**
	 * �R���X�g���N�^��ǉ����܂�.
	 * @param constructor
	 */
	void addConstructor(Constructor_* constructor);

	/**
	 * �w��̃V�O�l�`���̃R���X�g���N�^��Ԃ��܂�.
	 * @param paramCOunt
	 * @param findParents �e�������̂ڂ�Ȃ�true
	 * @return
	 */
	Constructor_* const findConstructor(int paramCount, bool findParents);

	/**
	 * �w��̃V�O�l�`���̃R���X�g���N�^��Ԃ��܂�.
	 * ���̃N���X���g�ɃR���X�g���N�^������Ȃ��Ȃ�e�������̂ڂ�܂��B
	 * @param cll
	 * @param paramCOunt
	 * @param findParents �e�������̂ڂ�Ȃ�true
	 * @return
	 */
	Constructor_* const findConstructor(ClassLoaderSPtr cll, int paramCount, bool findParents);

	/**
	 * �w��ʒu�̃R���X�g���N�^��Ԃ��܂�.
	 * @param index
	 * @return
	 */
	Constructor_* const getConstructorAt(int index);

	/**
	 * ������������Ȃ��R���X�g���N�^���܂܂�Ă��āA
	 * ���ꂪ public �������� protected �Ȃ�true.
	 * @return
	 */
	bool hasDefaultConstructor();

	/**
	 * ���̃N���X�̃R���X�g���N�^�ꗗ��Ԃ��܂�.
	 * @return
	 */
	std::vector<Constructor_*> getConstructors();

	/**
	 * �w��ʒu�̃R���X�g���N�^���폜���܂�.
	 * @param index
	 */
	void removeConstructorAt(int index);

	/**
	 * �S�ẴR���X�g���N�^�̐���Ԃ��܂�.
	 * @return
	 */
	int getConstructorCount();

	/**
	 * �t�B�[���h��ǉ����܂�.
	 * @param field
	 */
	void addField(Field* field);

	/**
	 * �w��ʒu�̃t�B�[���h��Ԃ��܂�.
	 * @param index
	 * @return
	 */
	Field* const getFieldAt(int index);

	/**
	 * ���̃N���X�̃t�B�[���h�ꗗ��Ԃ��܂�.
	 * @return
	 */
	std::vector<Field*> getFields();

	/**
	 * �w��̖��O�̃t�B�[���h��Ԃ��܂�.
	 * �K�v�ɉ����Đe�N���X���T���܂��B
	 * @param name
	 */
	Field* const findField(const std::string& name);

	/**
	 * �w��ʒu�̃t�B�[���h���폜���܂�.
	 * @param index
	 */
	void removeFieldAt(int index);

	/**
	 * �S�Ẵt�B�[���h�̐���Ԃ��܂�.
	 * @return
	 */
	int getFieldCount();

	/**
	 * ���\�b�h��ǉ����܂�.
	 * @param method
	 */
	void addMethod(Method* method);

	/**
	 * �w��ʒu�̃��\�b�h��Ԃ��܂�.
	 * @param index
	 * @return
	 */
	Method* const getMethodAt(int index);

	/**
	 * ���̃N���X�̃��\�b�h�ꗗ��Ԃ��܂�.
	 * @return
	 */
	std::vector<Method*> getMethods();

	/**
	 * �w��̃V�O�l�`���̃t�B�[���h��Ԃ��܂�.
	 * �K�v�ɉ����Đe�N���X���T���܂��B
	 * @param name
	 * @param paramCount
	 * @param findParentsIfConstructor �������Ă��郁�\�b�h��new�̂Ƃ��A�e�N���X����������Ȃ�true.
	 * @param extractProxy �������Ă��郁�\�b�h��new�̂Ƃ��A�㗝�l��Method��Ԃ��Ȃ�true.
	 */
	Method* const findMethod(const std::string& name, int paramCount, bool findParentsIfConstructor, bool extractProxy);

	/**
	 * �R���X�g���N�^�Ƃ��ĕԂ��܂�.
	 * @param name
	 * @param paramCount
	 * @param findParentsIfConstructor �������Ă��郁�\�b�h��new�̂Ƃ��A�e�N���X����������Ȃ�true.
	 * @return
	 */
	Method* const findMethod(const std::string&, int paramCount, bool findParentsIfConstructor);

	/**
	 * �w��ʒu�̃��\�b�h���폜���܂�.
	 * @param index
	 * @return
	 */
	void removeMethodAt(int index);

	/**
	 * �S�Ẵ��\�b�h�̐���Ԃ��܂�.
	 * @return
	 */
	int getMethodCount();

	/**
	 * �e�N���X��Ԃ��܂�.
	 * @return
	 */
	ClassWPtr const getSuper();

	/**
	 * �P���ȃN���X����Ԃ��܂�.
	 * @return
	 */
	std::string getName() const;

	/**
	 * ���̃N���X���w��̃N���X�𒼐ڂ��邢�͎q�K�w�̂ǂꂩ����Čp�����Ă���Ȃ�true.
	 * @param classz
	 * @return
	 */
	bool isSubClass(Class* classz);

	/**
	 * ���̃N���X���w��̃N���X�𒼐ڂ��邢�͎q�K�w�̂ǂꂩ����Čp�����Ă���Ȃ�true.
	 * @param classz
	 * @return
	 */
	bool isSubClass(ClassSPtr classSPtr);

	/**
	 * �񋓂Ȃ�true.
	 * @return
	 */
	virtual bool isEnum() const;

	/**
	 * ���كN���X�Ȃ�true.
	 * @return
	 */
	bool isSingular() const;

	/**
	 * ���̃N���X��ǂݍ��񂾃N���X���[�_�[��Ԃ��܂�.
	 * @return
	 */
	ClassLoaderWPtr getClassLoader() const;

	/**
	 * �w��̃I�u�W�F�N�g�̂��߂̗̈���m�ۂ��܂�.
	 * @param o
	 */
	void allocateField(Object_* o);

	/**
	 * �w��̃I�u�W�F�N�g�̂��߂̗̈���J�����܂�.
	 * @param o
	 */
	void freeField(Object_* o);
	
	/**
	 * ���̃N���X�̃N���X���[�_�[���폜�����Ƃ��ɌĂяo����܂�.
	 * ���̃��\�b�h�̓N���C�A���g�R�[�h�ł͌Ăяo���Ȃ��ł��������B
	 */
	void deleteClassLoader(const ClassLoader* const classLoader);

	/**
	 * �w��̃N���X���܂����[�h����Ă��Ȃ����
	 * ���[�h���ĕԂ��܂��B
	 * @param fqcn
	 * @return
	 */
	static ClassSPtr dynamicLoading(const std::string& fqcn);

	/**
	 * �w��̃N���X��K�v�ɉ����ēǂ݂��݁A�C���X�^���X�𐶐����ĕԂ��܂�.
	 * @param fqcn
	 * @param args
	 * @return
	 */
	static Object_* dynamicNewInstance(const std::string& fqcn, std::vector<Object_*> args);

	/**
	 * ������Ő������܂�.
	 * @param fqcn
	 */
	static Object_* dynamicNewInstance(const std::string& fqcn);

	/**
	 * ����1�Ő������܂�.
	 * @param arg1
	 */
	static Object_* dynamicNewInstance(const std::string& fqcn, Object_* arg1);

	/**
	 * ����2�Ő������܂�.
	 * @param arg1
	 * @param arg2
	 */
	static Object_* dynamicNewInstance(const std::string& fqcn, Object_* arg1, Object_* arg2);

	/**
	 * ����3�Ő������܂�.
	 * @param arg1
	 * @param arg2
	 * @param arg3
	 */
	static Object_* dynamicNewInstance(const std::string& fqcn, Object_* arg1, Object_* arg2, Object_* arg3);

	/**
	 * �w��̃N���X�� static���\�b�h���Ăяo���܂�.
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


