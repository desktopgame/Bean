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
 * �N���X���i�[����R���e�i�ł�.
 */
class Package final : public std::enable_shared_from_this<Package> {

	
	using PackageVisitor = std::function<void(PackageSPtr)>;
	using ClassVisitor = std::function<void(ClassSPtr)>;
public:
	Package(PackageSPtr parent, const std::string& name);
	Package(const std::string& name);
	~Package();

	/**
	 * ���̃p�b�P�[�W�ɃT�u�p�b�P�[�W��ǉ����܂�.
	 * @param name
	 */
	PackageSPtr addPackage(const std::string& name);
	
	/**
	 * ���̃p�b�P�[�W�̔z���ɃN���X��ǉ����܂�.
	 * @param classz
	 */
	void addClass(ClassSPtr classz);

	/**
	 * �w��ʒu�̃p�b�P�[�W��Ԃ��܂�.
	 * @param index
	 * @return
	 */
	PackageSPtr getPackageAt(int index);

	/**
	* �w��ʒu�̃N���X��Ԃ��܂�.
	* @param index
	* @return
	*/
	ClassSPtr const getClassAt(int index);

	/**
	 * ���̃p�b�P�[�W�Ƃ��̔z���̃p�b�P�[�W���ċA�I�ɖK�₵�܂�.
	 * @param visitor
	 */
	void visit(PackageVisitor visitor);

	/**
	 * ���̃p�b�P�[�W�����̃p�b�P�[�W�̐���Ԃ��܂�.
	 * @return
	 */
	int getPackageCount();

	/**
	 * ���̃p�b�P�[�W�����̃N���X�̐���Ԃ��܂�.
	 * @return index
	 */
	int getClassCount();

	/**
	 * �e�p�b�P�[�W��Ԃ��܂�.
	 * ���[�g�ł�nullptr�ł��B
	 * @return
	 */
	PackageWPtr getParent();

	/**
	 * �e������Ȃ�true.
	 * @return
	 */
	bool hasParent();

	/**
	 * ���̃p�b�P�[�W�̖��O��Ԃ��܂�.
	 * @return
	 */
	std::string getName();

	/**
	 * ���̃p�b�P�[�W��������f�B���N�g����Ԃ��܂�.
	 * @return
	 */
	std::string getDirectory();

	/**
	 * ���̃p�b�P�[�W���牺���_���v���܂�.
	 */
	void dump();

	/**
	 * ���[�g�ɐV�����p�b�P�[�W���`���܂�.
	 * @param name
	 */
	static PackageSPtr newPackage(const std::string& name);

	/**
	 * ���ɒ�`����Ă���p�b�P�[�W���������܂�.
	 * �����̓s���I�h�ɂ���ċ�؂��(�擪�ƍŌ�͂Ȃ�)�Ă���K�v������܂��B
	 * @param fqcn
	 * @param make ������Ȃ������ꍇ�ɂ͐V�K�ɍ쐬����Ȃ�true.
	 * @return
	 */
	static PackageSPtr getPackage(const std::string& fqcn, bool make);

	/**
	 * getPackage(fqcn, false)�Ɠ����ł�.
	 * @param fqcn
	 * @param make
	 * @return
	 */
	static PackageSPtr getPackage(const std::string& fqcn);

	/**
	 * ���[�g�̃p�b�P�[�W��S�ĕԂ��܂�.
	 * @return
	 */
	static std::vector<PackageSPtr> getPackages();

	/**
	 * ���ɒ�`����Ă���N���X���������܂�.
	 * ������Ȃ��ꍇ��nullptr��Ԃ��܂��B
	 * @param fqcn
	 * @param make ���݂��Ȃ��p�b�P�[�W���쐬����Ȃ�true.
	 * @return
	 */
	static ClassSPtr const getClass(const std::string& fqcn, bool make);

	/**
	 * true�ŌĂяo���܂�.
	 * @param fqcn
	 */
	static ClassSPtr const getClass(const std::string& fqcn);

	/** 
	 * �N���X���������A������Ȃ������ꍇ�͌��݂̃N���X���[�_�[�ł���̃��[�h���s���܂�.
	 * @param fqcn
	 */
	static ClassSPtr const getClassOrLoad(const std::string& fqcn);

	/**
	 * �w��̃N���X��������ۂ̃p�X����肵�܂�.
	 * @param fqcn
	 * @return
	 */
	static std::string resolvePath(const std::string& fqcn);

	/**
	 * �w��̃N���X������p�b�P�[�W������肵�܂�.
	 * @param fqcn
	 * @return
	 */
	static std::string resolvePackage(const std::string& fqcn);

	/**
	 * �S�ẴN���X��K�₵�܂�.
	 * @param cv
	 */
	static void visitAllClasses(ClassVisitor cv);

	/**
	 * �S�Ẵp�b�P�[�W���_���v���܂�.
	 */
	static void dumpAll();

	/**
	 * �S�Ẵp�b�P�[�W��delete���܂�.
	 */
	static void destroy();

	/**
	 * Class�N���X�̃R���X�g���N�^����Ăяo����܂�.
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


