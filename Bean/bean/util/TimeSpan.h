#pragma once
#ifndef BEAN_UTIL_TIMESPAN_H
#define BEAN_UTIL_TIMESPAN_H
#include <chrono>
#include <string>
using Clock = std::chrono::system_clock::time_point;
/**
 * �������Ԃ��v�����邽�߂̃N���X.
 */
class TimeSpan {
public:
	TimeSpan();
	~TimeSpan();
	/**
	 * �J�n���Ԃ��L�^���܂�.
	 */
	void start();

	/**
	 * �I�����Ԃ��L�^���܂�.
	 */
	void end();

	/**
	 * �o�ߎ��Ԃ��o�͂��܂�.
	 * @param s
	 */
	void print(const std::string& s);

	/**
	 * �o�ߎ��Ԃ��o�͂��܂�.
	 */
	void print();
private:
	Clock startClock;
	Clock endClock;
};
#endif // !BEAN_UTIL_TIMESPAN_H
