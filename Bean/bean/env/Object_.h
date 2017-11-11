#pragma once
#ifndef BEAN_ENV_OBJECT_H_
#define BEAN_ENV_OBJECT_H_
#include <functional>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>
#include "ObjectState.h"
#include "gc/GCProgress.cpp"
//#include "../util/Eventbus.h"
class Class;
class Object_;

class Boolean;
class Character;
class Numeric;
class String;
class UserObject;
class UserDelegate;
class UserArray;
class UserThread;
class UserComponent;
class Thread;

using ThreadSPtr = std::shared_ptr<Thread>;
using ThreadWPtr = std::weak_ptr<Thread>;

using ClassSPtr = std::shared_ptr<Class>;
using ClassWPtr = std::weak_ptr<Class>;
/**
 * Bean����Ŏg�p�\�ȑS�Ẵf�[�^�̊��N���X�ł�.
 */
class Object_ {
public:
	Object_(ClassSPtr classz);
	virtual ~Object_();
	virtual Object_* clone() = 0;

	/**
	 * ���̃I�u�W�F�N�g�Ƃ���I�u�W�F�N�g�̉��Z���`���܂�.
	 * @param right
	 * @return
	 */
	virtual Object_* add(Object_* right);

	/**
	 * ���̃I�u�W�F�N�g�Ƃ���I�u�W�F�N�g�̌��Z���`���܂�.
	 * @param right
	 * @return
	 */
	virtual Object_* sub(Object_* right);

	/**
	 * ���̃I�u�W�F�N�g�Ƃ���I�u�W�F�N�g�̏�Z���`���܂�.
	 * @param right
	 * @return
	 */
	virtual Object_* mul(Object_* right);

	/**
	 * ���̃I�u�W�F�N�g�Ƃ���I�u�W�F�N�g�̏��Z���`���܂�.
	 * @param right
	 * @return
	 */
	virtual Object_* div(Object_* right);

	/**
	 * ���̃I�u�W�F�N�g�Ƃ���I�u�W�F�N�g�̏�]���`���܂�.
	 * @param right
	 * @return
	 */
	virtual Object_* mod(Object_* right);

	/**
	 * ���̃I�u�W�F�N�g�Ƃ���I�u�W�F�N�g�̔�r���Z���`���܂�.
	 * @param right
	 * @return
	 */
	virtual Object_* equals(Object_* right);

	/**
	 * ���̃I�u�W�F�N�g�Ƃ���I�u�W�F�N�g�̔�r���Z���`���܂�.
	 * @param right
	 * @return
	 */
	virtual Object_* biggest(Object_* right);

	/**
	 * ���̃I�u�W�F�N�g�Ƃ���I�u�W�F�N�g�̔�r���Z���`���܂�.
	 * @param right
	 * @return
	 */
	virtual Object_* e_biggest(Object_* right);

	/**
	 * ���̃I�u�W�F�N�g�Ƃ���I�u�W�F�N�g�̔�r���Z���`���܂�.
	 * @param right
	 * @return
	 */
	virtual Object_* smallest(Object_* right);

	/**
	 * ���̃I�u�W�F�N�g�Ƃ���I�u�W�F�N�g�̔�r���Z���`���܂�.
	 * @param right
	 * @return
	 */
	virtual Object_* e_smallest(Object_* right);

	/**
	 * �l�� +1 ���܂�.
	 */
	virtual void increment();

	/**
	 * �l�� -1 ���܂�.
	 */
	virtual void decrement();

	/**
	 * ���̃N���X���V���O���g���Ȃ�true��Ԃ��܂�.
	 * @return
	 */
	bool virtual isSingleton();

	//
	//�C�x���g
	//

	/**
	 * �w��̖��O�̃��\�b�h�����������Ŏ��s���܂�.
	 * @param name
	 */
	Object_* const execute(std::string name);

	/**
	 * �w��̖��O�̃��\�b�h��������Ŏ��s���܂�.
	 * @param name
	 * @param arg1
	 */
	Object_* const execute(std::string name, Object_* arg1);

	/**
	 * �w��̖��O�̃��\�b�h�����s���܂�.
	 * @param name
	 * @param args
	 */
	Object_* const execute(std::string name, std::vector<Object_*> args);

	/**
	 * ���̃C���X�^���X��delete��v�����܂�.
	 * delete�ł����Ȃ�true��Ԃ��܂��B
	 */
	virtual bool die();

	/**
	 * �N���X��ݒ肵�܂�.
	 * �܂��A�t�B�[���h���m�ۂ��܂��B
	 * @param classz
	 */
	void setClass(ClassSPtr classz);

	/**
	 * ���݂̃I�u�W�F�N�g�̌^������ۓI�Ȃ��̂֕ϊ����܂�.
	 * �R���X�g���N�^���`�F�C���ŌĂяo�����Ƃ��Ɏg�p����܂��B
	 * ���̃��\�b�h�ł̓N���X�K�w���ƂɃt�B�[���h���m�ۂ��܂��B
	 * @param concrete
	 */
	void chainConstruct(ClassSPtr concrete);

	/**
	 * ���̃I�u�W�F�N�g�̌^��Ԃ��܂�.
	 * @return
	 */
	virtual ClassSPtr const getClass();

	/**
	 * GC�p�̏ڍ׏���Ԃ��܂�.
	 * @return
	 */
	virtual ObjectStateSPtr getState();

	/**
	 * ���̃I�u�W�F�N�g�𐶐������X���b�h��Ԃ��܂�.
	 * @return
	 */
	ThreadWPtr getGenThread() const;

	/**
	 * ���̒l���v���~�e�B�u�^�Ȃ�true��Ԃ��܂�.
	 * �v���~�e�B�u�^�ł͎Q�Ƃɒl����������Ƃ��Ƀ|�C���^�ł͂Ȃ�������n���܂��B
	 * @return
	 */
	virtual bool isPrimitive();

	/**
	 * ���̃I�u�W�F�N�g���܂��}�[�N����Ă��Ȃ����
	 * �ċA�I�Ƀ}�[�N���s���܂�.
	 */
	virtual void markTree();

	/**
	 * ���̃I�u�W�F�N�g�̏����o�͂��܂�.
	 */
	virtual void dump();

	/**
	 * ���̃I�u�W�F�N�g���v���~�e�B�u�^�Ȃ畡����Ԃ��܂�.
	 * @return
	 */
	virtual Object_* data();

	/**
	 * �w��̖��O�œ��I�t�B�[���h���`���܂�.
	 * @param name
	 * @param value
	 */
	void defineDynField(const std::string& name, Object_* value);

	/**
	 * �w��̖��O�œ��I�t�B�[���h���`���܂�.
	 * @param name
	 * @param value
	 */
	void defineDynMethod(const std::string& name, UserDelegate* value);

	/**
	 * ���̃C���X�^���X�Ɏw��̖��O�Ńt�B�[���h����`����Ă���Ȃ炻���Ԃ��܂�.
	 * @param name
	 * @return �Ȃ���� nullptr
	 */
	Object_* findDynField(const std::string& name);

	/**
	 * ���̃C���X�^���X�Ɏw��̖��O�Ń��\�b�h����`����Ă���Ȃ炻���Ԃ��܂�.
	 * @param name
	 * @param argc
	 * @return �Ȃ���� nullptr
	 */
	UserDelegate* findDynMethod(const std::string& name, int argc);

	/**
	 * ���I�t�B�[���h�̈ꗗ��Ԃ��܂�.
	 * @return
	 */
	std::unordered_map<std::string, Object_*> getDynFields() const;

	//
	//�L���X�g
	//

	/**
	 * �ϊ��o����Ȃ� Boolean �ɕϊ����ĕԂ��܂�.
	 * @return �ϊ��o���Ȃ������� nullptr
	 */
	virtual Boolean* asBoolean();

	/**
	 * �ϊ��o����Ȃ� Numeric �ɕϊ����ĕԂ��܂�.
	 * @return �ϊ��o���Ȃ������� nullptr
	 */
	virtual Numeric* asNumeric();

	/**
	 * �ϊ��o����Ȃ� Character �ɕϊ����ĕԂ��܂�.
	 * @return �ϊ��o���Ȃ������� nullptr
	 */
	virtual Character* asCharacter();

	/**
	 * �ϊ��o����Ȃ� String_ �ɕϊ����ĕԂ��܂�.
	 * @return �ϊ��o���Ȃ������� nullptr
	 */
	virtual String* asString();

	/**
	 * �ϊ��o����Ȃ� UserDelegate �ɕϊ����ĕԂ��܂�.
	 * @return �ϊ��o���Ȃ������� nullptr
	 */
	virtual UserDelegate* asUserDelegate();

	/**
	 * �ϊ��o����Ȃ� UserObject �ɕϊ����ĕԂ��܂�.
	 * @return �ϊ��o���Ȃ������� nullptr
	 */
	virtual UserObject* asUserObject();

	/**
	 * �ϊ��o����Ȃ� UserArray �ɕϊ����ĕԂ��܂�.
	 * @return �ϊ��o���Ȃ������� nullptr
	 */
	virtual UserArray* asUserArray();

	/**
	 * �ϊ��o����Ȃ� UserThread �ɕϊ����ĕԂ��܂�.
	 * @return �ϊ��o���Ȃ������� nullptr
	 */
	virtual UserThread* asUserThread();

	/**
	 * �ϊ��o����Ȃ� UserComponent �ɕϊ����ĕԂ��܂�.
	 * @return �ϊ��o���Ȃ������� nullptr
	 */
	virtual UserComponent* asUserComponent();

	/**
	 * ���z�t�B�[���h��Ԃ��܂�.
	 * ���z�t�B�[���h�́A�z�񒆂̗v�f�̂悤�� Field �Ɋi�[����Ȃ����AGC�̑ΏۂƂȂ�Ȃ��l�̂��Ƃł��B
	 * @return
	 */
	virtual std::vector<Object_*> getVirtualField();

protected:
	/**
	 * �N���X���v�����ꂽ�Ƃ��ɂ܂�nullptr���ƌĂ΂�܂�.
	 */
	virtual void lazyLoading();

	/**
	 * GC�p�̏ڍ׏��𐶐����܂�.
	 * �l�C�e�B�u���\�[�X�̂悤�ȍ폜�����̃I�u�W�F�N�g�ƈقȂ���̂ł́A
	 * ������ ObjectState �̃T�u�N���X�^��Ԃ��܂��B
	 * @return
	 */
	virtual ObjectStateSPtr createState();

	/**
	 * GC�̏ڍ׏����o�͂��ĉ��s���܂�.
	 */
	void dumpAttrLn();

	/**
	 * ���̃I�u�W�F�N�g���폜���܂�.
	 */
	void deleteSelf();

	/**
	 * a �ɑ΂��ē��I�����o�[��A�����ĕԂ��܂�.
	 * @param a
	 * @return
	 */
	std::vector<Object_*> concatDynamicMembers(std::vector<Object_*> a);

	/**
	 * ���̃C���X�^���X�ɒ�`���ꂽ���I�����o�[�̈ꗗ��Ԃ��܂�.
	 * @return
	 */
	std::vector<Object_*> getDynamicMembers();
private:
	ThreadWPtr thread;
	ClassWPtr classz;
	ObjectStateSPtr state;
	std::unordered_map<std::string, Object_*> dynFields;
	std::unordered_map<std::string, std::vector<UserDelegate*>> dynMethods;
	bool notify;
	/**
	* ���̃I�u�W�F�N�g���N�_�Ƃ��ĎQ�Ɖ\�ȑS�ẴI�u�W�F�N�g���}�[�N���܂�.
	*/
	void markTreeImpl();

	Object_* newExecutor();
	void deleteExecutor(Object_* ref);
};
#endif // !BEAN_ENV_OBJECT_H_
