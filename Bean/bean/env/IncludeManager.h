#pragma once
#ifndef BEAN_ENV_INCLUDEMANAGER_H
#define BEAN_ENV_INCLUDEMANAGER_H
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>
class Class;
using ClassSPtr = std::shared_ptr<Class>;
/**
 * �\�߃N���X�̊��S�C���������X�g�ŕێ����Ă����A
 * �P�����ŃC���X�^���X���v�����ꂽ�ꍇ�Ƀ��X�g�ƏƉ�ēK�؂ȃC���X�^���X�𐶐����܂��B
 */
class IncludeManager {
public:
	IncludeManager();
	~IncludeManager();
	/**
	 * �w��̃N���X���C���N���[�h���܂�.
	 * @param fqcn
	 */
	void include(const std::string& fqcn);

	/**
	 * �N���XA�ɂ����āA���g���ȗ����ŎQ�Ƃ��邽�߂ɃC���N���[�h���܂��B
	 * @param self
	 */
	void self(const std::string& self);

	/**
	 * �w��̃N���X��ʖ��ŃA�N�Z�X�ł���悤�ɂ��܂�.
	 * oldName ����N���X���������Ȃ������ꍇ�͕ʖ���t������ false ��Ԃ��܂��B
	 * @param oldName
	 * @parma newName
	 */
	bool alias(const std::string& oldName, const std::string& newName);

	/**
	 * alias �� �Ăяo���� false �� �Ԃ��ꂽ�ꍇ�A ClassFormatException �� �X���[���܂��B
	 * @param oldName
	 * @param newName
	 */
	void checkAlias(const std::string& oldName, const std::string& newName);

	/**
	 * �w��̖��O�̃N���X��Ԃ��܂�.
	 * �܂��p�b�P�[�W���猟�����A������Ȃ������ꍇ�Ɖ�܂��B
	 * @param name ���S�C����/���邢�͒P����
	 */
	ClassSPtr getClass(const std::string& name);
private:
	std::string selfName;
	std::vector<std::string> nameVec;
	std::unordered_map < std::string, std::string> aliasMap;
};
#endif // !BEAN_ENV_INCLUDEMANAGER_H


