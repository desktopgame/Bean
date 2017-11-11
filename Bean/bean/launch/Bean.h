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
 * Bean����̋N��-�I���������N���X.
 */
class Bean {
public:
	/**
	 * �v���O�����̐擪�ł�����Ăяo���Ă�������.
	 * �����ł�Bean�̃l�C�e�B�u���\�b�h�����[�h���܂��B
	 */
	static void begin();

	/**
	 * �w��̃t�@�C������͂��܂�.
	 * @param filePath
	 * @param entryPoint
	 */
	static ASTNodeSPtr compile(const std::string filePath, bool entryPoint);


	/**
	 * �w��̃\�[�X����͂��܂�.
	 * ��͂Ɏ��s�����Ƃ��K�؂ȃG���[���o���K�v������Ȃ炱������Ăяo���܂��B
	 * @param filePath
	 * @param source
	 * @param entryPoint
	 */
	static ASTNodeSPtr compilestr(const std::string filePath, const std::string source, bool entryPoint);

	/**
	 * �w��̃\�[�X����͂��܂�.
	 * @param source
	 * @param entryPoint
	 */
	static ASTNodeSPtr compilestr(const std::string source, bool entryPoint);


	/**
	 * �w��̃\�[�X����͂��܂�.
	 * ��͂Ɏ��s�����Ƃ��K�؂ȃG���[���o���K�v������Ȃ炱������Ăяo���܂��B
	 * @param filePath
	 * @param source
	 * @param entryPoint
	 */
	static ASTNodeSPtr compilewstr(const std::string filePath, const std::wstring source, bool entryPoint);

	/**
	 * �w��̃\�[�X����͂��܂�.
	 * @param source
	 * @param entryPoint
	 */
	static ASTNodeSPtr compilewstr(const std::wstring source, bool entryPoint);


	/**
	 * �w��̃\�[�X����͂��܂�.
	 * ��͂Ɏ��s�����Ƃ��K�؂ȃG���[���o���K�v������Ȃ炱������Ăяo���܂��B
	 * @param filePath
	 * @param source
	 * @param entryPoint
	 */
	static ASTNodeSPtr compileplaf(const std::string& filePath, const BString& source, bool entryPoint);

	/**
	 * �w��̃\�[�X����͂��܂�.
	 * @param source
	 * @param entryPoint
	 */
	static ASTNodeSPtr compileplaf(const BString& source, bool entryPoint);

	/**
	 * �w��̃t�@�C������͂��č\���؂��o�͂��܂�.
	 * @param path
	 */
	static void dumpASTTree(std::string path);
	
	/**
	 * �w��̃N���X�̏ڍׂ��o�͂��܂�.
	 * @param fqcn
	 */
	static void dumpDocument(std::string fqcn);

	/**
	 * �w��̃t�@�C�������s���܂�.
	 * @param fileName
	 */
	static void run(std::string fileName);

	/**
	 * �w��̃f�B���N�g���̃t�@�C�������ׂĎ��s���܂�.
	 * @parma dirName
	 */
	static void runAll(std::string dirName);

	/**
	 * �w��̐[���̃C���f���g���쐬���܂�.
	 * @param depth
	 * @parma spaces
	 * @return
	 */
	static std::string makeIndent(int depth, const std::string& spaces);

	/**
	 * �v���O�����̖����ł�����Ăяo���Ă�������.
	 * �����ł͑S�ẴN���X�Ɗ֘A����v���p�e�B��S�ăA�����[�h���܂��B
	 */
	static void end();

	//
	//�C�x���g
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


