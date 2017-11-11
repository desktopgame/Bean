#pragma once
#ifndef BEAN_UTIL_TIMESPAN_H
#define BEAN_UTIL_TIMESPAN_H
#include <chrono>
#include <string>
using Clock = std::chrono::system_clock::time_point;
/**
 * 処理時間を計測するためのクラス.
 */
class TimeSpan {
public:
	TimeSpan();
	~TimeSpan();
	/**
	 * 開始時間を記録します.
	 */
	void start();

	/**
	 * 終了時間を記録します.
	 */
	void end();

	/**
	 * 経過時間を出力します.
	 * @param s
	 */
	void print(const std::string& s);

	/**
	 * 経過時間を出力します.
	 */
	void print();
private:
	Clock startClock;
	Clock endClock;
};
#endif // !BEAN_UTIL_TIMESPAN_H
