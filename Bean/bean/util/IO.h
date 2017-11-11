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
 * �t�@�C�����o�͂̃��[�e�B���e�B�N���X�ł�.
 */
class IO {
public:
	/**
	 * �����̃t�@�C���ɏ������݂܂�.
	 * @param filePath
	 * @param src
	 */
	static void writeText(std::string filePath, BString src);
	static void writeTextMulti(std::string filePath, std::string content);
	static void writeTextWide(std::string filePath, std::wstring content);

	/**
	 * �����̃t�@�C����ǂݍ����Unicode�ŕԂ��܂�.
	 * @param filePath
	 */
	static BString readText(std::string filePath);
	static std::string readTextMulti(std::string filePath);
	static std::wstring readTextWide(std::string filePath);

	/**
	 * ���s���f�B���N�g����Ԃ��܂�.
	 * @return
	 */
	static std::string getCurrentPath();

	/**
	 * �w��̃t�@�C�����쐬���܂�.
	 * @param fileName
	 */
	static void createNewFile(std::string fileName);

	/**
	 * �e�f�B���N�g����Ԃ��܂�.
	 * @param path
	 * @return
	 */
	static std::string getParent(std::string path);

	/**
	 * �q�t�@�C���ꗗ��Ԃ��܂�.
	 * @param path
	 * @param allSubTree
	 * @return
	 */
	static std::vector<std::string> getChildren(std::string path, bool allSubTree);

	/**
	 * �w��̃t�@�C�����R�s�[���܂�.
	 * @param src
	 * @param dst
	 * @param option
	 */
	static void copy(std::string src, std::string dst, boost::filesystem::copy_option option);

	/**
	 * �f�B���N�g�����쐬���܂�.
	 * @param dirName
	 */
	static void mkdir(std::string dirName);
	
	/**
	 * �w��̃t�@�C������̃f�B���N�g�����폜���܂�.
	 * @param fileName
	 */
	static void delete_(std::string fileName);

	/**
	 * �w��̃p�X���t�@�C���Ȃ�true��Ԃ��܂�.
	 * @param path
	 * @return
	 */
	static bool isFile(std::string path);

	/**
	 * �w��̃p�X���f�B���N�g���Ȃ�true��Ԃ��܂�.
	 * @param path
	 * @return
	 */
	static bool isDirectory(std::string path);

	/**
	 * �w��̃t�@�C�������݂���Ȃ�true��Ԃ��܂�.
	 * @param fileName
	 * @return
	 */
	static bool isExists(std::string fileName);

	/**
	 * �p�X�̋�؂蕶����Ԃ��܂�.
	 * @return
	 */
	static char getDirectorySeparatorChar();

	/**
	 * �p�X���疼�O��Ԃ��܂�.
	 * @param path
	 */
	static std::string getName(const std::string& path);

	/**
	 * �p�X����g���q����菜���܂�.
	 * @param path
	 */
	static std::string cutExtension(std::string path);
private:
	IO() = default;
	~IO() = default;	
};
#endif // !BEAN_UTIL_IO_H
