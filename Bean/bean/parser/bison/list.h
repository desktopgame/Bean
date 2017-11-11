#pragma once
/**
 * @file list.h
 * @brief ���X�g�B
 */
#ifndef BEAN_PARSER_BISON_LIST_H
#define BEAN_PARSER_BISON_LIST_H
#ifdef __cplusplus
extern "C" {
#endif
	/**
	 * ���X�g�Ɋi�[����f�[�^�^�ł��B
	 * �ėp�R���e�i�Ƃ��邽�߂� void* ���g�p���܂��B
	 */
	typedef void* list_item;
	/**
	 * �ϒ��z��Ƃ��ċ@�\����\���̂ł�.
	 */
	typedef struct list {
		list_item value;
		int* size;
		struct list* prev;
		struct list* next;
	} list;
	/**
	 * ���X�g�̃f���[�^�֐��ł�.
	 * @param item
	 */
	typedef void(*list_element_deleter)(list_item item);
	/**
	 * ���X�g���쐬���܂��B
	 * ���̃��\�b�h�ō쐬�������X�g�� delete �ō폜���Ă��������B
	 * @return
	 */
	list* list_new();

	/**
	 * �����֗v�f��ǉ����܂��B
	 * @param val
	 * @param item
	 */
	void list_add(list* val, list_item item);

	/**
	 * �����֗v�f��ǉ����܂��B
	 * @param dst �ǉ���
	 * @param sec �ǉ���
	 */
	void list_add_all(list* dst, list* src);

	/**
	 * �w��ʒu�̗v�f���폜���܂��B
	 * ���g�͍폜����܂���B
	 * @param val
	 * @param index
	 * @return
	 */
	list_item list_remove(list* val, int index);

	/**
	 * �w��ʒu�̗v�f��Ԃ��܂��B
	 * @param val
	 * @param index
	 * @return
	 */
	list_item list_getAt(list* val, int index);

	/**
	 * ���X�g����ł��邩�ǂ�����Ԃ��܂��B
	 * @param val
	 * @return
	 */
	int list_empty(list* val);

	/**
	 * ���X�g�̗v�f����Ԃ��܂��B
	 * @param val
	 * @return
	 */
	int list_size(list* val);

	/**
	 * ���X�g�ƃA�C�e�����폜���܂��B
	 * @param val
	 * @param deleter
	 */
	void list_delete_with_item(list* val, list_element_deleter deleter);

	/**
	 * ���X�g���폜���܂��B
	 * ���g�͍폜����܂���B
	 * @param val
	 */
	void list_delete(list* val);

	/**
	 * �f���[�g���s��Ȃ��f���[�^�ł��B
	 * @param item
	 */
	void list_deleter_non_delete(list_item item);

	/**
	 * free�ɂ���č폜����f���[�^�ł��B
	 * @param item
	 */
	void list_deleter_free(list_item item);
#ifdef __cplusplus
};
#endif
#endif // !BEAN_PARSER_BISON_LIST_H
