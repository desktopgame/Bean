#pragma once
#ifndef BEAN_ENV_USER_USERMATCHER_H
#define BEAN_ENV_USER_USERMATCHER_H
#include <regex>
#include "../Object_.h"
#include "../Reference.h"
class UserPattern;
/**
 * ���K�\���G���W���̃��b�p�[.
 */
class UserMatcher : public Object_  {
public:
	UserMatcher(const std::string& source, UserPattern* pattern);
	~UserMatcher();

	// Object_ ����Čp������܂���
	Object_ * clone() override;
	/**
	 * ���݈ʒu����p�^�[������������
	 * �}�b�`�����Ȃ� true ��Ԃ��܂��B
	 * ���̂Ƃ��̊J�n/�I���ʒu/�O���[�v�͋L������܂��B
	 * @return
	 */
	bool find();

	/**
	 * �ʒu�����Z�b�g���Ă���
	 * �w��ʒu����p�^�[������������
	 * �}�b�`�����Ȃ� true ��Ԃ��܂��B
	 * ���̂Ƃ��̊J�n/�I���ʒu/�O���[�v�͋L������܂��B
	 * @return
	 */
	bool find(int pos);

	/**
	 * �Ō�Ƀ}�b�`�����Ƃ��̊J�n�ʒu��Ԃ��܂�.
	 * @return
	 */
	int start();

	/**
	 * �w��̃O���[�v�̍Ō�Ƀ}�b�`�����Ƃ��̊J�n�ʒu��Ԃ��܂�.
	 * @return
	 */
	int start(int groupIndex);

	/**
	 * �Ō�Ƀ}�b�`�����Ƃ��̏I���ʒu��Ԃ��܂�.
	 * @return
	 */
	int end();

	/**
	 * �w��̃O���[�v�̍Ō�Ƀ}�b�`�����Ƃ��̏I���ʒu��Ԃ��܂�.
	 * @return
	 */
	int end(int groupIndex);

	/**
	 * �Ō�Ƀ}�b�`�����������Ԃ��܂�.
	 * @return
	 */
	std::string group();
	/**
	 * �w��̃O���[�v�̍Ō�Ƀ}�b�`�����Ƃ��̕������Ԃ��܂�.
	 * @return
	 */
	std::string group(int groupIndex);

	/**
	 * �ʒu�����Z�b�g���ă}�b�`���J�n���܂�.
	 * �}�b�`�����Ȃ當����u�������ĕԂ��܂�.
	 * @parma templ
	 * @return
	 */
	std::string replaceFirst(std::string templ);

	/**
	 * �ʒu�����Z�b�g���ă}�b�`���J�n���܂�.
	 * �}�b�`�����S�Ă̕�����u�������ĕԂ��܂�.
	 * @parma templ
	 * @return
	 */
	std::string replaceAll(std::string templ);

	/**
	 * �G���W�������������āA
	 * ��x���� find ���Ăяo���܂��B
	 * @return
	 */
	bool all();

	/**
	 * �G���W���̈ʒu�����������܂�.
	 */
	void reset();

	/**
	 * �G���W���̈ʒu�����������܂�.
	 * @param source
	 */
	void reset(const std::string source);

	/**
	 * ���݂̃G���W���Ŏg�p�o����O���[�v�̐���Ԃ��܂�.
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
