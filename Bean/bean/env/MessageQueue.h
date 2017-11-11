#pragma once
#ifndef BEAN_ENV_MESSAGEQUEUE_H
#define BEAN_ENV_MESSAGEQUEUE_H
#include <memory>
#include <stack>
#include <vector>
#include "MessageInfo.h"
class Thread;

class MessageQueue;
using MessageQueueSPtr = std::shared_ptr<MessageQueue>;
using MessageQueueWPtr = std::weak_ptr<MessageQueue>;
/**
 * ���\�b�h�̌Ăяo���K�w��\���L���[�ł�.
 */
class MessageQueue {
public:
	MessageQueue();
	~MessageQueue();

	/**
	 * ���݂̃X���b�h�Ŏg�p����Ă���C���X�^���X��Ԃ��܂�.
	 * @return
	 */
	static MessageQueueSPtr getInstance();

	/**
	 * �擪�Ƀ��b�Z�[�W��ǉ����܂�.
	 * @param info
	 */
	void push(MessageInfo* info);

	/**
	 * �擪�̃��b�Z�[�W�����o���܂�.
	 * @return
	 */
	void pop();

	/**
	 * �Ō�Ƀv�b�V�����ꂽ���b�Z�[�W��Ԃ��܂�.
	 * @return
	 */
	const MessageInfo* top();

	/**
	 * �S�Ă̗v�f���폜���܂�.
	 */
	void clear();

	/** 
	 * �S�Ẵ��b�Z�[�W���_���v���܂�.
	 * �v�f�͋�ɂȂ�܂��B
	 * @return
	 */
	std::vector<std::string> dumpLines();

	/**
	 * �L���[����Ȃ�true.
	 * @return
	 */
	bool empty();
private:
	std::stack<MessageInfo*> msgVec;
};
#endif // !BEAN_ENV_MESSAGEQUEUE_H


