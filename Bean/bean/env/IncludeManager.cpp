#include "IncludeManager.h"
#include "ClassFormatException.h"
#include "Package.h"
#include "../util/Text.h"

//public method---
IncludeManager::IncludeManager() {
	this->nameVec = std::vector<std::string>();
	this->aliasMap = std::unordered_map<std::string, std::string>();
}

IncludeManager::~IncludeManager() {
	nameVec.clear();
}

void IncludeManager::include(const std::string& fqcn) {
	nameVec.push_back(fqcn);
}

void IncludeManager::self(const std::string& self) {
	include(self);
}

bool IncludeManager::alias(const std::string& oldName, const std::string& newName) {
	ClassSPtr cls = getClass(oldName);
	if (cls == nullptr) {
		return false;
	}
	aliasMap.insert_or_assign(newName, oldName);
	return true;
}

void IncludeManager::checkAlias(const std::string& oldName, const std::string& newName) {
	if (!alias(oldName, newName)) {
		throw ClassFormatException(oldName + " Ç… ï ñº " + newName + " ÇïtÇØÇÁÇÍÇ‹ÇπÇÒÇ≈ÇµÇΩÅB");
	}
}

ClassSPtr IncludeManager::getClass(const std::string& name) {
	ClassSPtr ret = Package::getClass(name, false);
	if (ret == NULL) {
		for (int i = 0; i < nameVec.size(); i++) {
			std::string fqcn = nameVec.at(i);
			int startOffset = fqcn.size() - name.size();
			if (startOffset < 0) {
				continue;
			}
			int pos = fqcn.rfind(".");
			if (pos == std::string::npos) {
				pos = 0;
			} else pos++;
			std::string lastName = fqcn.substr(pos, fqcn.size());
			//std::string ending = fqcn.substr(startOffset, name.size());
			if (lastName == name) {
				ret = Package::getClass(fqcn);
				break;
			}
		}
	}
	if (ret == NULL && aliasMap.count(name) != 0) {
		ret = getClass(aliasMap.at(name));
	}
	return ret;
}
//---public method
