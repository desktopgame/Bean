#pragma once
#ifndef BEAN_ENV_GC_GCSYSTEM_H
#define BEAN_ENV_GC_GCSYSTEM_H
#include <deque>
#include <functional>
#include <mutex>
#include <thread>
#include <vector>
class GCStrategy;
class CodeBlock;
class Object_;

//class GCSystem;
//typedef GCSystem Heap;
/**
 * Bean�Ŋm�ۂ��ꂽ�I�u�W�F�N�g���J������N���X�ł�.
 */
class Heap {
public:
	Heap(const Heap&) = delete;
	Heap& operator=(const Heap&) = delete;
	Heap(Heap&&) = delete;
	Heap& operator=(Heap&&) = delete;
	/**
	 * �B��̃C���X�^���X��Ԃ��܂�.
	 * @return
	 */
	static Heap* const getInstance() {
		static Heap inst;
		return &inst;
	}
	/**
	 * �K�x�[�W�R���N�^�̊Ǘ��ΏۂɈ�����ǉ����܂�.
	 * ���̃��\�b�h�̓}���`�X���b�h�Z�[�t�ł��B
	 * @param obj
	 */
	void add(Object_* obj);

	/**
	 * �K�x�[�W�R���N�^�̊Ǘ��Ώۂ��������ǉ����܂�.
	 * ���̃��\�b�h�̓}���`�X���b�h�Z�[�t�ł��B
	 * @param obj
	 */
	void remove(Object_* obj);

	/**
	 * ���b�N���ň��S�Ƀq�[�v���Q�Ƃ��܂�.
	 * �����ɓn�����Object_�̔z���Heap�̎����̂ւ̃|�C���^�Ȃ̂ŁA
	 * �����ύX���邱�Ƃ̓q�[�v��ύX���邱�ƂƓ����ł��B
	 */
	void view(std::function<void(std::vector<Object_*>&)> f);

	/**
	 * right�����C�g�o���A�ɂ���ĕی삵�܂�.
	 * @param left
	 * @param right
	 */
	void writeBarrier(Object_* left, Object_* right);

	/**
	 * right�����C�g�o���A�ɂ���ĕی삵�܂�.
	 */
	void writeBarrier(Object_* right);

	/**
	 * �\�Ȃ�w��̃I�u�W�F�N�g���X�^�b�N/�o�b�t�@����폜���܂�.
	 * �q�[�v����̏�����ref���̂�delete�͌Ăяo�����ōs���܂��B
	 * @param obj
	 * @return ���������Ȃ�true.
	 */
	static bool deleteItem(Object_* obj);

	/**
	 * �K�x�[�W�R���N�^���s���Ȃ��悤�Ƀ��b�N���܂�.
	 */
	void lock();

	/**
	* ���b�N���������܂�.
	*/
	void unlock();

	/**
	 * ���݂̃q�[�v�T�C�Y��臒l�𒴂��Ă���Ȃ�GC�����s���܂�.
	 */
	void test();

	/**
	 * �܂��q�[�v�Ɏc���Ă���I�u�W�F�N�g�̃_���v���o�͂��܂�.
	 */
	void dump();

	/**
	 * �K�x�[�W�R���N�^���N�����܂�.
	 * ���̃��\�b�h�̓}���`�X���b�h�Z�[�t�ł��B
	 */
	void miniGC();

	/**
	 * �K�x�[�W�R���N�^���N�����܂�.
	 * ���̃��\�b�h�̓}���`�X���b�h�Z�[�t�ł��B
	 */
	void fullGC();

	/**
	 * �q�[�v�̍ő�m�ې���Ԃ��܂�.
	 * ���̒l��葽���̃I�u�W�F�N�g���m�ۂ�����GC���쓮���܂��B
	 * @return
	 */
	int getHeapThreshold();

	/**
	 * ���݂̃I�u�W�F�N�g�̐���Ԃ��܂�.
	 * ���̃��\�b�h�̓}���`�X���b�h�Z�[�t�ł��B
	 */
	int getCurrentSize();

	/**
	* �K�x�[�W�R���N�V�����𓯊����邽�߂̃��b�N���l�����܂�.
	*/
	void enter();

	/**
	* �K�x�[�W�R���N�V�����𓯊����邽�߂̃��b�N���J�����܂�.
	*/
	void exit();

	/**
	 * �}�[�N�X�C�[�vGC�Ȃ�true.
	 * @return
	 */
	bool isMarkAndSweepGC() const;

	/**
	 * �C���N�������^��GC�Ȃ�true.
	 * @return
	 */
	bool isIncrementalGC() const;

	/**
	 * �q�[�v��j�����܂�.
	 */
	void destroy();
protected:
	/**
	 * �K�x�[�W�R���N�^���N�����܂�.
	 * @param id
	 */
	void execImpl(int id);

	/**
	 * ���b�N����Ă���Ȃ�true.
	 */
	bool locked();

private:

	void do_codeblock(std::vector<CodeBlock*> rootBlockVec, std::function<void(CodeBlock*)> f);

	Heap();
	~Heap() { delete strategy; }
	std::vector<Object_*> objects;
	std::recursive_mutex thread_sync;
	GCStrategy* strategy;
	int gcType;
	int locks;
	int heapThreshold;
	int initThr;
	bool gcReport;
	bool gcAlways;
};
#endif // !BEAN_ENV_GC_GCSYSTEM_H
