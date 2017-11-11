#pragma once
#ifndef BEAN_ENV_GC_BLOCK_H
#define BEAN_ENV_GC_BLOCK_H
#include <functional>
#include <memory>
#include <mutex>
#include <vector>
#include "Page.h"
#include "../Object_.h"
class Block;
using BlockSPtr = std::shared_ptr<Block>;
using BlockWPtr = std::weak_ptr<Block>;
/**
 * ���̒��ňꎞ�I�Ɏg�p�����l��ی삵�܂�.
 */
class Block {
public:
	Block();
	virtual ~Block();

	/**
	 * ���݂̃N���X���[�_�[�ɐݒ肳�ꂽ�u���b�N��Ԃ��܂�.
	 * @return
	 */
	static BlockSPtr getInstance();

	/**
	 * ���݂̃C���X�^���X�� push �����s���܂�.
	 */
	static void pushCurrent();

	/**
	 * ���݂̃C���X�^���X�� pop �����s���܂�.
	 */
	static void popCurrent();

	/**
	 * �w��̃I�u�W�F�N�g���ǉ�����Ă��Ȃ���Βǉ����܂�.
	 * @param obj
	 */
	static void entry(Object_* obj);

	/**
	 * �S�ẴC���X�^���X�őS�Ẵy�[�W���N���A���܂�.
	 */
	static void blocks_page_clearAll();

	/**
	 * �S�ẴC���X�^���X�̑S�Ẵy�[�W�̃y�C���g��Ԃ�ݒ肵�܂�.
	 * @param progress
	 */
	static void blocks_page_paintAll(GCProgress progress);

	/**
	 * �S�ẴC���X�^���X�̑S�Ẵy�[�W�Ń}�[�N�����s���܂�.
	 */
	static void blocks_page_markAll();

	/**
	 * ���݂̃C���X�^���X�Ŏw��̃I�u�W�F�N�g���폜���܂�.
	 * @param obj
	 */
	static void blocks_page_remove(Object_* obj);

	/**
	 * thread/Thread �ŊǗ�����Ȃ��񓯊��u���b�N��Ԃ��܂�.
	 * �ȍ~�̏����� endAsync ���Ă΂��܂ł����ō쐬���ꂽ�u���b�N�ֈϏ�����܂��B
	 */
	static void startAsync();

	/**
	 * �񓯊��u���b�N���I�����܂�.
	 */
	static void endAsync();

	/**
	 * �V���ȃy�[�W��ǉ����܂�.
	 */
	void push();

	/**
	 * �Ō�ɒǉ����ꂽ�y�[�W���폜���܂�.
	 */
	void pop();

	/**
	 * ���Ƀy�[�W�����݂���Ȃ�A
	 * �w��̃I�u�W�F�N�g��GC�̑ΏۂɂȂ�Ȃ��悤�ɂ��܂�.
	 * @parma obj
	 */
	bool recordObject(Object_* obj);

	/**
	 * �y�[�W�̂����ꂩ�� obj ���܂܂��Ȃ�폜���܂�.
	 * @param obj
	 */
	void page_remove(Object_* obj);

	/**
	 * ���̃u���b�N�̎��y�[�W�S�Ă�
	 * obj_clearAll ���Ăяo���܂��B
	 */
	void page_markAll();

	/**
	 * ���̃u���b�N�̎��y�[�W�S�Ă�
	 * obj_clearAll ���Ăяo���܂��B
	 */
	void page_clearAll();

	/**
	 * ���̃u���b�N�̎��y�[�W�S�Ă�
	 * obj_paintAll ���Ăяo���܂��B
	 */
	void page_paintAll(GCProgress progress);

	/**
	 * ���݂̃l�X�g�̐[����Ԃ��܂�.
	 * @return
	 */
	int getDepth() const;
private:
	std::recursive_mutex thread_sync;
	std::vector<PageSPtr> pageStack;

	static std::vector<BlockSPtr> async_blocks;
	static std::recursive_mutex aync_sync;

	static void do_all_blocks(std::function<void(BlockSPtr)> f);
};
#endif // !BEAN_ENV_GC_BLOCK_H
