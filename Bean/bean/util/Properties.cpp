#include "Properties.h"
#include <algorithm>
#include <sstream>
#include <string>
#include "IO.h"

//public method---
Properties::Properties() {
	this->map = std::unordered_map<std::string, std::string>();
	this->onPropertyChange = PropertyChangeListenerList();
}

Properties::~Properties() {
}

void Properties::put(const std::string & key, const std::string & val) {
	map.insert_or_assign(key, val);
	onPropertyChange(PropertyChangeEvent(key, val));
}

void Properties::put(const std::string & key, const char * val) {
	put(key, std::string(val));
}

std::string Properties::get(const std::string & key) {
	return map.at(key);
}

std::string Properties::str(const std::string & key) {
	return value<std::string>(key);
}

std::string Properties::str(const std::string & key, const std::string & val) {
	return value<std::string>(key, val);
}

std::string Properties::remove(const std::string & key) {
	auto itr = map.begin();
	std::string ret = "";
	for (; itr != map.end(); itr++) {
		if (itr->first == key) {
			ret = itr->second;
			map.erase(itr);
			break;
		}
	}
	return ret;
}

bool Properties::contains(const std::string & key) {
	return map.count(key) != 0;
}

void Properties::write(const std::string & fileName) {
	std::string buff = std::string();
	auto keys = std::vector<std::string>();
	auto ss = std::ostringstream();
	//キー一覧の追加
	auto itr = map.begin();
	for (; itr != map.end(); itr++) {
		keys.push_back(itr->first);
	}
	//キー一覧のソート
	std::sort(keys.begin(), keys.end());
	//キー一覧の出力
	for (std::string key : keys) {
		ss << key << '=' << map.at(key) << std::endl;
	}
	buff += ss.str();
	IO::writeTextMulti(fileName, buff);
}

void Properties::read(const std::string & fileName) {
	std::string content = IO::readTextMulti(fileName);
	std::string key = std::string();
	std::string val = std::string();
	bool parseKey = true;
	this->map.clear();
	for (int i = 0; i < content.length(); i++) {
		char ch = content[i];
		//キー解析
		if (parseKey && ch != '=') {
			key.push_back(ch);
		} else if (parseKey && ch == '=') {
			parseKey = false;
			continue;
		}
		//値解析
		if (!parseKey) {
			if (ch != '\n' && ch != '\r\n') {
				val.push_back(ch);
			} else {
				put(key, val);
				parseKey = true;
				key = std::string();
				val = std::string();
			}
		}
	}
}
//---public method
