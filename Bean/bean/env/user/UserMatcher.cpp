#include "UserMatcher.h"
#include "UserPattern.h"
#include "../Package.h"
//public method---
UserMatcher::UserMatcher(const std::string& source, UserPattern* pattern)
 : Object_(nullptr) {
	reset();
	this->startPosVec = std::vector<int>();
	this->endPosVec = std::vector<int>();
	this->groupStrVec = std::vector<std::string>();
	this->source = source;
	this->pattern = pattern;
}

UserMatcher::~UserMatcher() {
}

Object_ * UserMatcher::clone() {
	return nullptr;
}

bool UserMatcher::find() {
	int pos = 0;
	if (!endPosVec.empty()) {
		pos = end();
	}
	return find(pos);
}

bool UserMatcher::find(int pos) {
	reset();
	if (pos < 0 || pos >= source.size()) {
		return false;
	}
	std::string sub = source.substr(pos, source.size() - pos);
	bool b = std::regex_search(
		sub,
		this->res,
		*pattern->getRegex()
	);
	if (b) {
		save(sub, pos);
		return true;
	} else reset();
	return b;
}

int UserMatcher::start() {
	return startPosVec.empty() ? -1 : this->startPosVec.at(0);
}

int UserMatcher::start(int groupIndex) {
	return startPosVec.empty() ? -1 : startPosVec.at(groupIndex);
}

int UserMatcher::end() {
	return endPosVec.empty() ? -1 : this->endPosVec.at(0);
}

int UserMatcher::end(int groupIndex) {
	return endPosVec.empty() ? -1 : endPosVec.at(groupIndex);
}

std::string UserMatcher::group() {
	return groupStrVec.empty() ? "" : this->groupStrVec.at(0);
}

std::string UserMatcher::group(int groupIndex) {
	return groupStrVec.empty() ? "" : groupStrVec.at(groupIndex);
}

std::string UserMatcher::replaceFirst(std::string templ) {
	reset();
	return std::regex_replace(
		source, 
		*pattern->getRegex(), 
		templ,
		std::regex_constants::format_first_only
	);
}

std::string UserMatcher::replaceAll(std::string templ) {
	reset();
	return std::regex_replace(
		source,
		*pattern->getRegex(),
		templ
	);
}

bool UserMatcher::all() {
	reset();
	return std::regex_match(source, *pattern->getRegex());
}

void UserMatcher::reset() {
	this->gen = false;
}

void UserMatcher::reset(const std::string source) {
	reset();
	this->source = source;
}

int UserMatcher::groupCount() {
	return res.size();
}

std::vector<Object_*> UserMatcher::getVirtualField() {
	return concatDynamicMembers(std::vector<Object_*> {
		pattern
	});
}

void UserMatcher::save(const std::string range, int prev) {
	startPosVec.clear();
	endPosVec.clear();
	groupStrVec.clear();
	for (int i = 0; i < res.size(); i++) {
		if (!res[i].matched) {
			startPosVec.push_back(-1);
			groupStrVec.push_back("");
			endPosVec.push_back(-1);
			continue;
		}
		int startPos = prev + res.position(i);
		startPosVec.push_back(startPos);
		groupStrVec.push_back(res[i].str());
		endPosVec.push_back(startPos + res[i].length());
	}
}
//---public method

//protected method---
void UserMatcher::lazyLoading() {
	setClass(Package::getClassOrLoad("api.Matcher"));
}
//---protected method