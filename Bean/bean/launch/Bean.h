#pragma once
#ifndef BEAN_LAUNCH_BEAN_H
#define BEAN_LAUNCH_BEAN_H
#include <functional>
#include <memory>
#include <string>
#include <vector>
#include <boost/signals2.hpp>
#include "../Debug.h"
#include "../ast/ASTNode.h"
#include "../util/Text.h"
using BeanPreLaunchListenerList = boost::signals2::signal<void()>;
using BeanPostLaunchListenerList = boost::signals2::signal<void()>;
using BeanPreExitListenerList = boost::signals2::signal<void()>;
using BeanPostExitListenerList = boost::signals2::signal<void()>;
/**
 * Bean言語の起動-終了を扱うクラス.
 */
class Bean {
public:
	/**
	 * プログラムの先頭でこれを呼び出してください.
	 * ここではBeanのネイティブメソッドをロードします。
	 */
	static void begin();

	/**
	 * 指定のファイルを解析します.
	 * @param filePath
	 * @param entryPoint
	 */
	static ASTNodeSPtr compile(const std::string filePath, bool entryPoint);


	/**
	 * 指定のソースを解析します.
	 * 解析に失敗したとき適切なエラーを出す必要があるならこちらを呼び出します。
	 * @param filePath
	 * @param source
	 * @param entryPoint
	 */
	static ASTNodeSPtr compilestr(const std::string filePath, const std::string source, bool entryPoint);

	/**
	 * 指定のソースを解析します.
	 * @param source
	 * @param entryPoint
	 */
	static ASTNodeSPtr compilestr(const std::string source, bool entryPoint);


	/**
	 * 指定のソースを解析します.
	 * 解析に失敗したとき適切なエラーを出す必要があるならこちらを呼び出します。
	 * @param filePath
	 * @param source
	 * @param entryPoint
	 */
	static ASTNodeSPtr compilewstr(const std::string filePath, const std::wstring source, bool entryPoint);

	/**
	 * 指定のソースを解析します.
	 * @param source
	 * @param entryPoint
	 */
	static ASTNodeSPtr compilewstr(const std::wstring source, bool entryPoint);


	/**
	 * 指定のソースを解析します.
	 * 解析に失敗したとき適切なエラーを出す必要があるならこちらを呼び出します。
	 * @param filePath
	 * @param source
	 * @param entryPoint
	 */
	static ASTNodeSPtr compileplaf(const std::string& filePath, const BString& source, bool entryPoint);

	/**
	 * 指定のソースを解析します.
	 * @param source
	 * @param entryPoint
	 */
	static ASTNodeSPtr compileplaf(const BString& source, bool entryPoint);

	/**
	 * 指定のファイルを解析して構文木を出力します.
	 * @param path
	 */
	static void dumpASTTree(std::string path);
	
	/**
	 * 指定のクラスの詳細を出力します.
	 * @param fqcn
	 */
	static void dumpDocument(std::string fqcn);

	/**
	 * 指定のファイルを実行します.
	 * @param fileName
	 */
	static void run(std::string fileName);

	/**
	 * 指定のディレクトリのファイルをすべて実行します.
	 * @parma dirName
	 */
	static void runAll(std::string dirName);

	/**
	 * 指定の深さのインデントを作成します.
	 * @param depth
	 * @parma spaces
	 * @return
	 */
	static std::string makeIndent(int depth, const std::string& spaces);

	/**
	 * プログラムの末尾でこれを呼び出してください.
	 * ここでは全てのクラスと関連するプロパティを全てアンロードします。
	 */
	static void end();

	//
	//イベント
	//
	static BeanPreLaunchListenerList onPreLaunch;
	static BeanPostLaunchListenerList onPostLaunch;
	static BeanPreExitListenerList onPreExit;
	static BeanPostExitListenerList onPostExit;
private:
	static void install_native_method();
	Bean() = default;
	~Bean() = default;
};
#endif // !BEAN_LAUNCH_BEAN_H


