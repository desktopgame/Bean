#pragma once
#ifndef BEAN_UTIL_BITFLAGS_H
#define BEAN_UTIL_BITFLAGS_H
/**
 * �r�b�g���Z�Ńt���O���Ǘ�����N���X.
 */
class BitFlags {
public:
	BitFlags();
	~BitFlags();
	/**
	 * �w��̃r�b�g�Ńt���O�𗧂Ă܂�.
	 * @param flag
	 */
	void setFlag(int flag);

	/**
	 * ���݂̃r�b�g�ɉ����Ĉ����̃r�b�g�ł��A
	 * #hasFlag ��true��Ԃ��悤�Ƀr�b�g��ύX���܂�.
	 * @param flag
	 */
	void addFlag(int flag);

	/**
	 * �t���O����菜���܂�.
	 * @param flag
	 */
	void removeFlag(int flag);

	/**
	 * �t���O���N���A���܂�.
	 */
	void clearFlag();

	/**
	 * ���݂̃t���O��Ԃ��܂�.
	 * @return
	 */
	int getFlag();

	/**
	 * �w��̃t���O�������Ă���Ȃ�true.
	 * @param flag
	 * @return
	 */
	bool hasFlag(int flag);

	/**
	 * �t���O����v����Ȃ�true.
	 * @param flag
	 * @return
	 */
	bool compFlag(int flag);
	
	/**
	 * �w��̒i�K�̃r�b�g��Ԃ��܂�.
	 * @param level
	 * @return
	 */
	static int makeBit(int level);
private:
	int flag;
};
#endif // !BEAN_UTIL_BITFLAGS_H
