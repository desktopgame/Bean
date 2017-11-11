#pragma once
#ifndef BEAN_ENV_CODEBLOCK_H
#define BEAN_ENV_CODEBLOCK_H
#include <functional>
#include <map>
#include <mutex>
#include <string>
#include <unordered_map>
#include <vector>
//#define SCOPE_LOCK std::lock_guard<std::recursive_mutex> lock(thread_sync)
//#define SCOPE_LOCK ;
class Object_;
/**
 * �ϐ����Ǘ�����N���X.
 */
class CodeBlock {
public:
	/**
	 * �V���ȃR�[�h�u���b�N���\�z���܂�.
	 * ���̃R���X�g���N�^�͊�{�I�Ƀ��[�g���쐬���邽�߂Ɉ�x�����N���C�A���g�ɂ���ČĂяo����܂��B
	 */
	CodeBlock();

	/**
	 * ���̃R�[�h�u���b�N��j�����܂�.
	 * �R�[�h�u���b�N�̎q�K�w���ɍ폜����ƃA�N�Z�X�ᔽ���������邽�߁A
	 * ���̃f�X�g���N�^���Ăяo�����Ŏ��s�����Ƃ��A���V�[�o�͏�Ƀ��[�g�ł��B
	 */
	~CodeBlock();

	/**
	 * �X�^�b�N��̕ϐ���T���r���Ƃ��ă}�[�N���܂�.
	 */
	static void paintSearchNow();

	/**
	 * �X�^�b�N��̕ϐ����}�[�N���܂�.
	 */
	static void mark_items();

	/**
	 * �X�^�b�N��Ɏw��̕ϐ������݂���Ȃ珜�����܂�.
	 * @param ref
	 */
	static void sweep_item(Object_* ref);

	/**
	 * �S�ẴX�^�b�N��K�₵�܂�.
	 * �������R�[���X�^�b�N�Ƃ��Ă̂݋@�\����u���b�N�͖�������܂��B
	 * @param f
	 */
	static void forEach(std::function<void(CodeBlock*)> f);

	/**
	 * ���̃R�[�h�u���b�N�̕�����Ԃ��܂�.
	 * @param syncData �V���{���e�[�u�������L����Ȃ�true.
	 */
	CodeBlock* clone(bool syncData);

	/**
	 * ���̃R�[�h�u���b�N�ɒ�`���ꂽ�Q�Ƃ��폜���܂�.
	 * @param �폜�����Q�Ƃ̖��O
	 * @return �폜���ꂽ�Q��
	 */
	Object_* removeReference(const std::string& name);

	/**
	 * ���̃R�[�h�u���b�N�ɒ�`���ꂽ�Q�Ƃ̈ꗗ���폜���܂�.
	 */
	void clearReference();

	/**
	 * ���̃R�[�h�u���b�N�ɐV���ȎQ�Ƃ��`���܂�.
	 * ���ɒ�`����Ă���Q�Ƃ͏㏑������܂��B
	 * @param name �ϐ���
	 * @param ref
	 */
	void declReference(const std::string& name, Object_* ref);

	/**
	 * ���̃R�[�h�u���b�N�A
	 * �������͂��̏�̃R�[�h�u���b�N���������āA
	 * ���� name �̒�`����Ă���R�[�h�u���b�N�ŕϐ����㏑�����܂�.
	 * @param name
	 * @param ref
	 */
	void writeReference(const std::string& name, Object_* ref);

	/**
	 * ���̃R�[�h�u���b�N�ɒ�`���ꂽ�Q�Ƃ�Ԃ��܂�.
	 * ���̃R�[�h�u���b�N���猟�����J�n���A������Ȃ���Ώ�ʂւƌ�����i�߂܂�.
	 * @param name �ϐ���
	 * @return
	 */
	Object_* readReference(const std::string& name);

	/**
	 * �e�X�R�[�v�𑖍������A���̃X�R�[�v�̃e�[�u���������������܂�.
	 * @param name
	 * @return
	 */
	Object_* readCurrentScope(const std::string& name);

	/**
	 * �V���ȃR�[�h�u���b�N���J�n���܂�.
	 * �ȍ~�̕ϐ�IO, �R�[�h�u���b�N�̊J�n/�I���͐V���ȃR�[�h�u���b�N�ֈϏ�����܂��B
	 * @param isClosure �N���[�W���Ȃ�true
	 */
	void enter(bool isClosure);

	/**
	 * �R�[�h�u���b�N���I�����A�e�X�R�[�v�֖߂�܂��B
	 * �ȍ~�̕ϐ�IO, �R�[�h�u���b�N�̊J�n/�I���͐e�v�f�ɂ���Ď��s����܂��B
	 * @param isGC ��`���ꂽ�Q�Ƃ��폜����Ȃ�true.
	 */
	void exit(bool isGC);

	/**
	 * �}�[�N�A���h�X�C�[�v�ɂ���ĉ�����ꂽ�Q�Ƃ����̃u���b�N���珜�����܂�.
	 * @param ref
	 */
	void remove(Object_* ref);

	/**
	 * ���̃X�R�[�v�̕ϐ��ꗗ��Ԃ��܂�.
	 * @return
	 */
	std::vector<std::string> getVariableName();

	/**
	 * ���̃R�[�h�u���b�N�̐[����Ԃ��܂�.
	 * ���[�g�ł�0�ł��B
	 * @return
	 */
	int getDepth() const;

	/**
	 * ���̃R�[�h�u���b�N�̎q�v�f�̐���Ԃ��܂�.
	 * @return
	 */
	int getCount() const;

	/**
	 * ���̃R�[�h�u���b�N���N���[�W���Ȃ�true.
	 * @return
	 */
	bool getClosure() const;

	/**
	 * ���[�g�v�f��Ԃ��܂�.
	 * @return
	 */
	CodeBlock* getRoot();

	/**
	 * �e�v�f��Ԃ��܂�.
	 * @return
	 */
	CodeBlock* getParent() const;

	/**
	 * ���݂̈Ϗ����Ԃ��܂�.
	 * @return
	 */
	CodeBlock* getPointer();

	/**
	 * �w��ʒu�̎q�v�f��Ԃ��܂�.
	 * @param index
	 * @return
	 */
	CodeBlock* getElementAt(int index) const;

	/**
	 * �Q�Ɖ\�ȑS�Ă̎Q�Ƃ�Ԃ��܂�.
	 * @return
	 */
	std::vector<Object_*> getRuntime();

	/** 
	 * �R�[���X�^�b�N�Ƃ��ċ@�\����R�[�h�u���b�N��true��Ԃ��܂�.
	 * �V�����X���b�h�̃R�[�h�u���b�N�ł̓�������Ԃ����L���܂����A
	 * �Ăяo���K�w�͋��L�o���܂���B
	 * ����̓}���`�X���b�h�̉��b���󂯂邽�߂̈Ӑ}�I�Ȏd�l�ł��B
	 * @return
	 */
	bool isCallStack() const;

	/**
	 * ���̃R�[�h�u���b�N�A�܂����̎q�v�f�ɒ�`���ꂽ�Q�Ƃ̈ꗗ���o�͂��܂�.
	 */
	void dump();

	void pri__map_decl(const std::string& name, Object_* ref);
	void pri__map_decl_impl(const std::string& name, Object_* ref);
	Object_* pri__map_read(const std::string& name);
	void pri__map_clear();
	void pri__map_erase(const std::string& name);
	void pri__map_each(std::function<bool(const std::string&, Object_*)> f);
	bool pri__map_contains(const std::string& name);
	std::string pri__list_at(int index);
	void pri__list_erase(int index);
	int pri__list_size();
private:
	/**
	 * �q�v�f���쐬���邽�߂ɗ��p�����R���X�g���N�^�ł�.
	 * @param parent
	 * @param depth
	 * @param isClosure
	 */
	CodeBlock(CodeBlock* parent, int depth, bool isClosure);

	/**
	 * �t�B�[���h�����������܂�.
	 * �R���X�g���N�^�ɂ���ČĂяo����܂��B
	 * @param parent
	 * @param depth
	 * @param isClosure
	 */
	void init(CodeBlock* parent, int depth, bool isClosure);

	/**
	* �t�B�[���h���J�����܂�.
	* �f�X�g���N�^�ɂ���ČĂяo����܂��B
	*/
	void destroy();

	/**
	 * ���̃C���X�^���X�ɒ�`���ꂽ�Q�Ƃ�Ԃ��܂�.
	 * @param name �ϐ���
	 * @param isClosure
	 * @return
	 */
	Object_* readCurrentReference(const std::string& name, bool isClosure);

	//helper
	void declReference(const std::string& name, Object_* ref, bool isClosure);
	void writeReferenceImpl(const std::string& name, Object_* ref);
	Object_* readReference(const std::string& name, bool isClosure);
	bool hasDelegateTarget();
	CodeBlock* getDelegateTarget();
	void getRuntimeImpl(CodeBlock* root, std::vector<Object_*>* ret);
	void removeImpl(CodeBlock* root, Object_* ref);

	

	CodeBlock* cloneImpl(CodeBlock* srcRoot, CodeBlock* dstRoot, bool syncData);
	//fields
	void dumpImpl(CodeBlock* root, int depth);
	int depth;
	int addres;
	bool isClosure;
	std::unordered_map<std::string, Object_*> map;
	std::vector<std::string> variableVector;
	std::vector <CodeBlock*> childrenVector;
	CodeBlock* parent;
	CodeBlock* source;
	static std::vector<CodeBlock*> rootBlockVec;
};
#endif // !BEAN_ENV_CODEBLOCK_H
