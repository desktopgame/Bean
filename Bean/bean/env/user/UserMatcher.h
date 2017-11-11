#pragma once
#ifndef BEAN_ENV_USER_USERMATCHER_H
#define BEAN_ENV_USER_USERMATCHER_H
#include <regex>
#include "../Object_.h"
#include "../Reference.h"
class UserPattern;
/**
 * 正規表現エンジンのラッパー.
 */
class UserMatcher : public Object_  {
public:
	UserMatcher(const std::string& source, UserPattern* pattern);
	~UserMatcher();

	// Object_ を介して継承されました
	Object_ * clone() override;
	/**
	 * 現在位置からパターンを検索して
	 * マッチしたなら true を返します。
	 * このときの開始/終了位置/グループは記憶されます。
	 * @return
	 */
	bool find();

	/**
	 * 位置をリセットしてから
	 * 指定位置からパターンを検索して
	 * マッチしたなら true を返します。
	 * このときの開始/終了位置/グループは記憶されます。
	 * @return
	 */
	bool find(int pos);

	/**
	 * 最後にマッチしたときの開始位置を返します.
	 * @return
	 */
	int start();

	/**
	 * 指定のグループの最後にマッチしたときの開始位置を返します.
	 * @return
	 */
	int start(int groupIndex);

	/**
	 * 最後にマッチしたときの終了位置を返します.
	 * @return
	 */
	int end();

	/**
	 * 指定のグループの最後にマッチしたときの終了位置を返します.
	 * @return
	 */
	int end(int groupIndex);

	/**
	 * 最後にマッチした文字列を返します.
	 * @return
	 */
	std::string group();
	/**
	 * 指定のグループの最後にマッチしたときの文字列を返します.
	 * @return
	 */
	std::string group(int groupIndex);

	/**
	 * 位置をリセットしてマッチを開始します.
	 * マッチしたなら文字を置き換えて返します.
	 * @parma templ
	 * @return
	 */
	std::string replaceFirst(std::string templ);

	/**
	 * 位置をリセットしてマッチを開始します.
	 * マッチした全ての文字を置き換えて返します.
	 * @parma templ
	 * @return
	 */
	std::string replaceAll(std::string templ);

	/**
	 * エンジンを初期化して、
	 * 一度だけ find を呼び出します。
	 * @return
	 */
	bool all();

	/**
	 * エンジンの位置を初期化します.
	 */
	void reset();

	/**
	 * エンジンの位置を初期化します.
	 * @param source
	 */
	void reset(const std::string source);

	/**
	 * 現在のエンジンで使用出来るグループの数を返します.
	 * @return
	 */
	int groupCount();

	std::vector<Object_*> getVirtualField() override;
protected:
	void lazyLoading() override;
private:
	void save(const std::string range, int prev);
	UserPattern* pattern;
	std::vector<int> startPosVec;
	std::vector<int> endPosVec;
	std::vector<std::string> groupStrVec;
	std::string source;
	std::smatch res;
	bool gen;
};
#endif // !BEAN_ENV_USER_USERMATCHER_H
