#pragma once
#ifndef BEAN_ENV_USER_USERPATTERN_H
#define BEAN_ENV_USER_USERPATTERN_H
#include <regex>
#include <string>
#include "../Object_.h"
class UserPattern : public Object_ {
public:
	UserPattern();
	~UserPattern();
	// Object_ ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	Object_ * clone() override;

	void compile(const std::string& patternText);

	std::regex* getRegex();
protected:
	void lazyLoading() override;
private:
	std::string patternText;
	std::regex regex;
};
#endif // !BEAN_ENV_USER_USERPATTERN_H
