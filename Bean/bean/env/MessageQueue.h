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
 * メソッドの呼び出し階層を表すキューです.
 */
class MessageQueue {
public:
	MessageQueue();
	~MessageQueue();

	/**
	 * 現在のスレッドで使用されているインスタンスを返します.
	 * @return
	 */
	static MessageQueueSPtr getInstance();

	/**
	 * 先頭にメッセージを追加します.
	 * @param info
	 */
	void push(MessageInfo* info);

	/**
	 * 先頭のメッセージを取り出します.
	 * @return
	 */
	void pop();

	/**
	 * 最後にプッシュされたメッセージを返します.
	 * @return
	 */
	const MessageInfo* top();

	/**
	 * 全ての要素を削除します.
	 */
	void clear();

	/** 
	 * 全てのメッセージをダンプします.
	 * 要素は空になります。
	 * @return
	 */
	std::vector<std::string> dumpLines();

	/**
	 * キューが空ならtrue.
	 * @return
	 */
	bool empty();
private:
	std::stack<MessageInfo*> msgVec;
};
#endif // !BEAN_ENV_MESSAGEQUEUE_H


