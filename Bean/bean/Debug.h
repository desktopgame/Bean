#pragma once
#ifndef BEAN_DEBUG_H
#define BEAN_DEBUG_H
#include "util/BitFlags.h"
/**
 * デバッグ用クラス.
 */
class Debug {
public:
	/**
	 * プログラムをブレークします.
	 */
	static void break_of();

	/**
	 * 条件を満たすならブレークします.
	 * @param b
	 */
	static void break_if(bool b);

	/**
	 * 指定のビットが立っているならブレークします.
	 */
	static void break_has(int flag);

	/**
	 * 指定のビットでフラグを立てます.
	 * @param flag
	 */
	static void setFlag(int flag);

	/**
	 * 現在のビットに加えて引数のビットでも、
	 * #hasFlag でtrueを返すようにビットを変更します.
	 * @param flag
	 */
	static void addFlag(int flag);

	/**
	 * フラグを取り除きます.
	 * @param flag
	 */
	static void removeFlag(int flag);

	/**
	 * フラグをクリアします.
	 */
	static void clearFlag();

	/**
	 * 現在のフラグを返します.
	 * @return
	 */
	static int getFlag();

	/**
	 * 指定のフラグが立っているならtrue.
	 * @param flag
	 * @return
	 */
	static bool hasFlag(int flag);

	/** 
	 * フラグが一致するならtrue.
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
