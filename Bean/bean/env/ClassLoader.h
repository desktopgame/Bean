#pragma once
#ifndef BEAN_ENV_CLASSLOADER_H
#define BEAN_ENV_CLASSLOADER_H
#include <list>
#include <memory>
#include <mutex>
#include <stack>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>
class ASTNode;
class Package;
class CodeBlock;
class StackTrace_;
class Thread;
class Class;
class Object_;
class IncludeManager;
class FunctionManager;

class ASTClassDeclaration;
class ASTEnumDeclaration;

class ASTConstructorChain;

class Constructor_;
class ClassLoader;
using ClassLoaderSPtr = std::shared_ptr<ClassLoader>;
using ClassLoaderWPtr = std::weak_ptr<ClassLoader>;

using ClassSPtr = std::shared_ptr<Class>;
using ThreadSPtr = std::shared_ptr<Thread>;
using ThreadWPtr = std::weak_ptr<Thread>;
//using TheadID = std::thread::id;
/**
 * ���ۍ\���؂�Class�I�u�W�F�N�g�ւƕϊ�����N���X�ł�.
 *
 * �N���X���[�_�[�ɂ̓��[�g�̊T�O������܂��B
 * �����ł������[�g�Ƃ�Object�N���X�̂��Ƃł͂Ȃ��A
 * �g�b�v���x���̊֐�����`�����G���g���|�C���g�ɊY������t�@�C���̂��Ƃł��B
 * Bean�ł̓��C�����\�b�h�͕K�v�Ȃ��̂ŁA
 * �N���X�������Ȃ��\���؂��������N���X���[�_�[�����[�g�ɂȂ�܂��B
 */
class ClassLoader final : public std::enable_shared_from_this<ClassLoader> {
public:
	/**
	 * �G���g���|�C���g�Œ�`���ꂽ�N���X���쐬���邽�߂Ɏg�p�o���܂�.
	 * ���̏ꍇ�ł͈ꕔ�̏������G���g���|�C���g��\���N���X���[�_�ɈϏ�����K�v������̂ŁA
	 * ���̃t���O��ON�ɂ��܂��B
	 * @param paretn
	 * @param root
	 * @param path
	 * @param delegateCLL
	 */
	ClassLoader(ClassLoaderSPtr parent, std::shared_ptr<ASTNode> root, std::string path, bool delegateCLL);
	
	/**
	 * �e�N���X���[�_�[���w�肵�ĐV���ȃN���X���[�_�[���\�z���܂�.
	 * @param parent
	 * @param root
	 * @param path
	 */
	ClassLoader(ClassLoaderSPtr parent, std::shared_ptr<ASTNode> root, std::string path);
	
	/**
	 * ���[�g�N���X���[�_�[���쐬���܂�.
	 * @param root
	 */
	ClassLoader(std::shared_ptr<ASTNode> root);
	~ClassLoader();

	/**
	 * ���̃N���X���[�_�[��e�N���X���[�_�[�ɕR�Â��܂�.
	 * std::shared_ptr#shared_from_this �̓R���X�g���N�^����Q�Əo���Ȃ��̂ŁA
	 * �Ăяo�����ł͐���������ɕK�����̃��\�b�h���Ăяo���Ă��������B
	 */
	void registerClassLoader();

	/**
	 * �C���N���[�h��R�[�h�u���b�N�̊K�w��ۂ����܂�
	 * �\���؂��������ւ��܂�.
	 * REPL�Ŏg�p����܂��B
	 * @param root
	 */
	void setRoot(std::shared_ptr<ASTNode> root);

	/**
	 * �w��̃N���X�����[�h���܂�.
	 * @param fqcn
	 * @return
	 */
	ClassSPtr const loadClass(std::string fqcn);

	/**
	 * �w��̃N���X���[�_�[�����̃N���X���[�_�[�̎q�v�f�ɐݒ肵�܂�.
	 * �N���X�̓��I�쐬�Ŏg�p����܂��B
	 * @param child
	 */
	void loadClass(ClassLoaderSPtr child);


	/**
	 * �N���X�錾��ǂݍ���Ńp�b�P�[�W�֒ǉ����܂�.
	 * @param package
	 * @param classDecl
	 * @param parent
	 */
	static void loadClass(const std::string& package, std::shared_ptr<ASTClassDeclaration> classDecl, ClassLoaderSPtr parent);

	/**
	 * �񋓐錾��ǂݍ���Ńp�b�P�[�W�֒ǉ����܂�.
	 * @param package
	 * @param classDecl
	 * @param parent
	 */
	static void loadEnum(const std::string& package, std::shared_ptr<ASTEnumDeclaration> enumDecl, ClassLoaderSPtr parent);

	/**
	 * Bean�ŗL�v���p�e�B��ǂݍ����
	 * ���̃N���X���[�_�[�ɓK�p���܂�.
	 */
	void loadProperties();

	/**
	 * ���̃N���X���[�_�[���G���g���|�C���g�ɒ�`����Ă���Ȃ�true.
	 * @return
	 */
	bool isEntryPoint() const;

	/**
	 * ���̃N���X���[�_�[���Ϗ�����ΏۂƂȂ�e���[�_�[��Ԃ��܂�.
	 * @return
	 */
	ClassLoaderWPtr getParent() const;

	/**
	 * �w��̃N���X���\������\���؂�Ԃ��܂�.
	 * @return
	 */
	std::shared_ptr<ASTNode> getRoot() const;

	/**
	 * ���̃N���X���[�_�[�̃X�^�b�N�g���[�X��Ԃ��܂�.
	 * @return
	 */
	CodeBlock* const getCodeBlock();

	/**
	 * �ǂ݂��񂾃N���X��Ԃ��܂�.
	 * ���[�g�ł�nullptr��Ԃ��܂��B
	 * @return
	 */
	ClassSPtr const getClass() const;

	/**
	 * �p�X��Ԃ��܂�.
	 * @return
	 */
	std::string getPath() const;

	/**
	 * �ǂ݂��񂾃N���X����Ԃ��܂�.
	 * @return
	 */
	std::string getClassName() const;

	/**
	* �ǂ݂��񂾃p�b�P�[�W����Ԃ��܂�.
	* @return
	*/
	std::string getPackageName() const;

	/**
	 * �֐��ꗗ��Ԃ��܂�.
	 * �g�b�v���x���̃N���X���[�_�[�ł̂ݎg�p�\�ł��B
	 * @return
	 */
	FunctionManager* const getFunctionManager() const;

	/**
	 * ���̃N���X���[�_�[���Q�Ƃ���N���X�ꗗ��Ԃ��܂�.
	 * @return
	 */
	IncludeManager* const getIncludeManager() const;

	/**
	 * �w��̃C���X�^���X�ł��̃N���X���[�_�[�𑩔����܂�.
	 * ���\�b�h�����s����Ƃ��A������ǂ̃C���X�^���X�����s����ׂ����Ƃ������͍\���؂���m�邱�Ƃ��o���܂���B
	 *
	 * �������A����͖��O�t���Ŏ��s����ꍇ(hoge.piyo()�̂悤�ȏꍇ)�͕ʂŁA
	 * �R�[�h�u���b�N����ϐ����Ō�������΂ǂ̃C���X�^���X�����s����ׂ����͖��炩�ł��B
	 * �N���X�����g�̃��\�b�h�����s����ꍇ�͓��ɖ��ŁA�ϐ��������݂��܂���B(hoge���g�� piyo() ����ꍇ)
	 * �ł����A�N���X�����g�̃��\�b�h�����s����ꍇ�ł��ŏ��̈��͕K�����O�t���ŌĂяo���K�v������܂��B
	 * 
	 * ���̃��\�b�h�͂��̍ŏ��̈��ŌĂяo�����K�v������܂��B
	 * �������A���\�b�h�Ăяo���͊K�w�I�ɍs�����Ƃ��o����̂ŁA
	 * ���O�����̌Ăяo���̒��Ŗ��O�t���̌Ăяo�����s��ꂽ�Ȃ�A�Ăт��̃��\�b�h���Ăяo���K�v������܂��B
	 *
	 * �K�w���畜�A���邽�߂ɁA���̌Ăяo���̈����̓X�^�b�N�֋L������܂��B
	 * �X�^�b�N���K�w�𐳂����\�����邽�߂ɁA���O�t���Ăяo�����I�������ɂ�unlockInstance���Ăяo���܂��B
	 * @param o
	 */
	void lockInstance(Object_* o);

	/**
	 * �Ō�ɃN���X���[�_�[�𑩔������C���X�^���X��Ԃ��܂�.
	 * @param forSuper ���̃N���X���[�_�[�ő�������Ă��Ȃ��ꍇ�ɐe�N���X��T������Ȃ�true
	 * @return
	 */
	Object_* const getLock(bool forSuper);

	/**
	 * �Ō�ɃN���X���[�_�[�𑩔������C���X�^���X��Ԃ��܂�.
	 * @return
	 */
	Object_* const getLock();

	/**
	 * �������������܂�.
	 */
	void unlockInstance();

	/**
	 * Bean���N�����邽�߂ɍŏ��ɍ쐬�����N���X���[�_�[��Ԃ��܂�.
	 * @return
	 */
	static ClassLoader* const getSystemClassLoader();

	/**
	 * ���݂̃N���X���[�_�[�����ւ��܂�.
	 * @param classLoader;
	 */
	static void pushCurrentClassLoader(ClassLoaderSPtr classLoader);

	//NOTE:�g�p����Ă܂���B
	/**
	 * ���݂̃N���X���[�_�[�^�ɑ΂��Ĉ����̃N���X���[�_�^�����o����Ȃ�true��Ԃ��܂��B
	 * �Ⴆ�� Base �Ƃ��̃T�u�N���X Sub �����݂��A
	 * ���݂̃N���X���[�_�� Base �ň����� Sub �̂Ƃ��� true ��Ԃ��܂��B
	 * ���݂̃N���X���[�_�� �G���g���|�C���g �Ȃ��� true ��Ԃ��܂��B
	 * @param classLoader
	 * @return
	 */
	static bool multicastClassLoader(ClassLoaderSPtr classLoader);

	/**
	 * ���݂̃N���X���[�_�[��߂��܂�.
	 */
	static void popCurrentClassLoader();

	/**
	 * ���ݎg�p����Ă��郋�[�g�̃N���X���[�_�[��Ԃ��܂�.
	 * @return
	 */
	static ClassLoaderSPtr getCurrentClassLoader();

	/**
	 * ���݂̃X���b�h�̃N���X���[�_�[��Ԃ��܂�.
	 * ������Ȃ���΃V�X�e���N���X���[�_��Ԃ��܂��B
	 */
	static ClassLoaderSPtr getContextClassLoader();

	/**
	 * �S�ẴN���X���[�_�[�������ǂ��폜���܂�.
	 */
	static void destroy();

	/**
	 * �v���O�����̋N���ɕK�v�ȍŒ���̃N���X�����[�h���܂�.
	 */
	void loadDefaults();

	/** 
	 * ���̃N���X���[�_�[�Ɋ֘A��������_���v���܂�.
	 */
	void dump();
protected:

private:
	void init(ClassLoaderSPtr parent, std::shared_ptr<ASTNode> root, bool delegateCll);
	
	void loadUseDirs();
	void loadUseFiles();

	void checkClass(ClassSPtr classz);
	void checkConstructor(ClassSPtr classz);
	void checkMatchChainConstructor(ClassSPtr classz, Constructor_* body, std::shared_ptr<ASTConstructorChain> chain);
	void checkNative(ClassSPtr classz);
	void checkThrow(const std::string mes);
	void checkOverride(ClassSPtr classz);

	ClassLoaderWPtr parent;
	std::shared_ptr<ASTNode> root;
	CodeBlock* source;
	FunctionManager* functionManager;
	IncludeManager* includeManager;
	Object_* lock;
	ThreadWPtr sourceThread;
	std::string path;
	std::recursive_mutex thread_sync;
	std::list<std::string> pkgStack;
	std::stack<Object_*> locks;
	std::vector <ClassLoaderSPtr> children;
	std::unordered_map<std::thread::id, CodeBlock*> codeBlockMap;
	bool entryPoint;
	bool delegateCll;
//	int classCount;
	static std::vector<ClassLoaderSPtr> entryPointCLLVector;
	static std::vector<ClassLoaderSPtr> rootClassLoaderVec;
	static std::stack<ClassLoaderSPtr> classLoaderStack;
};
#endif // !BEAN_ENV_CLASSLOADER_H

