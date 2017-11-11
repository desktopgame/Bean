#pragma once
#ifndef BEAN_UTIL_BITFLAGS_H
#define BEAN_UTIL_BITFLAGS_H
/**
 * ビット演算でフラグを管理するクラス.
 */
class BitFlags {
public:
	BitFlags();
	~BitFlags();
	/**
	 * 指定のビットでフラグを立てます.
	 * @param flag
	 */
	void setFlag(int flag);

	/**
	 * 現在のビットに加えて引数のビットでも、
	 * #hasFlag でtrueを返すようにビットを変更します.
	 * @param flag
	 */
	void addFlag(int flag);

	/**
	 * フラグを取り除きます.
	 * @param flag
	 */
	void removeFlag(int flag);

	/**
	 * フラグをクリアします.
	 */
	void clearFlag();

	/**
	 * 現在のフラグを返します.
	 * @return
	 */
	int getFlag();

	/**
	 * 指定のフラグが立っているならtrue.
	 * @param flag
	 * @return
	 */
	bool hasFlag(int flag);

	/**
	 * フラグが一致するならtrue.
	 * @param flag
	 * @return
	 */
	bool compFlag(int flag);
	
	/**
	 * 指定の段階のビットを返します.
	 * @param level
	 * @return
	 */
	static int makeBit(int level);
private:
	int flag;
};
#endif // !BEAN_UTIL_BITFLAGS_H
