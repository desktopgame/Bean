#pragma once
#ifndef BEAN_DEBUG_H
#define BEAN_DEBUG_H
#include "util/BitFlags.h"
/**
 * �f�o�b�O�p�N���X.
 */
class Debug {
public:
	/**
	 * �v���O�������u���[�N���܂�.
	 */
	static void break_of();

	/**
	 * �����𖞂����Ȃ�u���[�N���܂�.
	 * @param b
	 */
	static void break_if(bool b);

	/**
	 * �w��̃r�b�g�������Ă���Ȃ�u���[�N���܂�.
	 */
	static void break_has(int flag);

	/**
	 * �w��̃r�b�g�Ńt���O�𗧂Ă܂�.
	 * @param flag
	 */
	static void setFlag(int flag);

	/**
	 * ���݂̃r�b�g�ɉ����Ĉ����̃r�b�g�ł��A
	 * #hasFlag ��true��Ԃ��悤�Ƀr�b�g��ύX���܂�.
	 * @param flag
	 */
	static void addFlag(int flag);

	/**
	 * �t���O����菜���܂�.
	 * @param flag
	 */
	static void removeFlag(int flag);

	/**
	 * �t���O���N���A���܂�.
	 */
	static void clearFlag();

	/**
	 * ���݂̃t���O��Ԃ��܂�.
	 * @return
	 */
	static int getFlag();

	/**
	 * �w��̃t���O�������Ă���Ȃ�true.
	 * @param flag
	 * @return
	 */
	static bool hasFlag(int flag);

	/** 
	 * �t���O����v����Ȃ�true.
	 * @param flag
	 * @return
	 */
	static bool compFlag(int flag);

private:
	Debug();
	~Debug();
	static BitFlags bits;
};
#endif // !BEAN_DEBUG_H
