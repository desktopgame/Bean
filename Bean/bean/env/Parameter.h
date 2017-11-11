#pragma once
#ifndef BEAN_ENV_PARAMETER_H
#define BEAN_ENV_PARAMETER_H
#include <string>
/**
 * メソッド、コンストラクタの引数をモデル化します.
 */
class Parameter {
public:
	Parameter(const std::string& name);
	~Parameter();
	/**
	 * この引数の名前を返します.
	 * @return
	 */
	std::string getName();

	/**
	 * 複製します.
	 * @return
	 */
	Parameter* clone();
private:
	std::string name;
};
#endif // !BEAN_ENV_PARAMETER_H


