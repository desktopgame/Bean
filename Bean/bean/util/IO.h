#pragma once
#ifndef BEAN_UTIL_IO_H
#define BEAN_UTIL_IO_H
#include <string>
#include <vector>
#include <boost/filesystem.hpp>
#include "Text.h"
#define FILE_SYSTEM boost::filesystem
#define COPY_OPTION boost::filesystem::copy_option
/**
 * ファイル入出力のユーティリティクラスです.
 */
class IO {
public:
	/**
	 * 引数のファイルに書き込みます.
	 * @param filePath
	 * @param src
	 */
	static void writeText(std::string filePath, BString src);
	static void writeTextMulti(std::string filePath, std::string content);
	static void writeTextWide(std::string filePath, std::wstring content);

	/**
	 * 引数のファイルを読み込んでUnicodeで返します.
	 * @param filePath
	 */
	static BString readText(std::string filePath);
	static std::string readTextMulti(std::string filePath);
	static std::wstring readTextWide(std::string filePath);

	/**
	 * 実行時ディレクトリを返します.
	 * @return
	 */
	static std::string getCurrentPath();

	/**
	 * 指定のファイルを作成します.
	 * @param fileName
	 */
	static void createNewFile(std::string fileName);

	/**
	 * 親ディレクトリを返します.
	 * @param path
	 * @return
	 */
	static std::string getParent(std::string path);

	/**
	 * 子ファイル一覧を返します.
	 * @param path
	 * @param allSubTree
	 * @return
	 */
	static std::vector<std::string> getChildren(std::string path, bool allSubTree);

	/**
	 * 指定のファイルをコピーします.
	 * @param src
	 * @param dst
	 * @param option
	 */
	static void copy(std::string src, std::string dst, boost::filesystem::copy_option option);

	/**
	 * ディレクトリを作成します.
	 * @param dirName
	 */
	static void mkdir(std::string dirName);
	
	/**
	 * 指定のファイルか空のディレクトリを削除します.
	 * @param fileName
	 */
	static void delete_(std::string fileName);

	/**
	 * 指定のパスがファイルならtrueを返します.
	 * @param path
	 * @return
	 */
	static bool isFile(std::string path);

	/**
	 * 指定のパスがディレクトリならtrueを返します.
	 * @param path
	 * @return
	 */
	static bool isDirectory(std::string path);

	/**
	 * 指定のファイルが存在するならtrueを返します.
	 * @param fileName
	 * @return
	 */
	static bool isExists(std::string fileName);

	/**
	 * パスの区切り文字を返します.
	 * @return
	 */
	static char getDirectorySeparatorChar();

	/**
	 * パスから名前を返します.
	 * @param path
	 */
	static std::string getName(const std::string& path);

	/**
	 * パスから拡張子を取り除きます.
	 * @param path
	 */
	static std::string cutExtension(std::string path);
private:
	IO() = default;
	~IO() = default;	
};
#endif // !BEAN_UTIL_IO_H
