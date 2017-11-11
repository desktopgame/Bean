#pragma once
#ifndef BEAN_ENV_GC_PAGE_H
#define BEAN_ENV_GC_PAGE_H
#include <memory>
#include <mutex>
#include <vector>
#include "../Object_.h"
#include "../WeakReference.h"
class Page;
using PageSPtr = std::shared_ptr<Page>;
using PageWPtr = std::weak_ptr<Page>;
/**
 * ���̒��̈�K�w��\���܂�.
 * �K�w�� Block�N���X �̃X�^�b�N�ɂ���ĕ\����܂��B
 */
class Page {
public:
	Page(int rank);
	~Page();
	/**
	 * ���̊K�w�ɃI�u�W�F�N�g��ǉ����܂�.
	 * @param obj
	 */
	void add(Object_* obj);

	/**
	 * �w��ʒu�̃I�u�W�F�N�g��Ԃ��܂�.
	 * @param index
	 * @return
	 */
	Object_* get(int index) const;

	/**
	 * �w��ʒu�̃I�u�W�F�N�g���폜���܂�.
	 * @param index
	 */
	void removeAt(int index);

	/**
	 * �w��̃I�u�W�F�N�g���폜���܂�.
	 * @param obj
	 */
	void remove(Object_* obj);

	/**
	 * �S�ẴI�u�W�F�N�g�̐���Ԃ��܂�.
	 * @return
	 */
	int size() const;

	/**
	 * ���̃y�[�W���j�������Ƃ��A
	 * ���̃y�[�W�Ɋi�[���ꂽ�I�u�W�F�N�g�̃����N��0�ɂ��܂�.
	 */
	void fix();

	/**
 	 * ���̃y�[�W���j�������Ƃ��A
	 * ���̃y�[�W�Ɋi�[���ꂽ�I�u�W�F�N�g����O�̃y�[�W�ֈړ����܂�.
	 */
	void fix(PageSPtr prev);

	/**
	 * �S�ẴI�u�W�F�N�g���c���[�}�[�N���܂�.
	 */
	void obj_markAll();

	/**
	 * �S�ẴI�u�W�F�N�g�̃}�[�N��Ԃ��N���A���܂�.
	 */
	void obj_clearAll();

	/**
	 * �S�ẴI�u�W�F�N�g�̃y�C���g��Ԃ�ݒ肵�܂�.
	 * @param progress
	 */
	void obj_paintAll(GCProgress progress);

	/** 
	 * ���̃y�[�W�̃A�C�e���ꗗ��Ԃ��܂�.
	 * @return
	 */
	std::vector<Object_*> getObjects() const;

private:
	int rank;
	std::vector<Object_*> objects;
	std::recursive_mutex thread_sync;
	void removeImpl(Object_* obj, bool listenerRemove);
};
#endif // !BEAN_ENV_GC_PAGE_H
