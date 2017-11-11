#include "NativeMethodRegistry.h"
#include "NativeMethodTryExecutor.h"

//public method---
void NativeMethodRegistry::add(const std::string& name, NativeMethodExecutor * nme) {
	map.insert_or_assign(
		name, 
		new NativeMethodTryExecutor(
			nme
		)
	);
}

NativeMethodExecutor * const NativeMethodRegistry::get(const std::string& name) {
	if (map.count(name) == 0) {
		return nullptr;
	}
	return map.at(name);
}

bool NativeMethodRegistry::contains(const std::string& name) {
	return map.count(name) == 0;
}

void NativeMethodRegistry::remove(const std::string& name) {
	map.erase(name);
}

void NativeMethodRegistry::clear() {
	using Iterator = std::unordered_map<std::string, NativeMethodExecutor*>::iterator;
	std::vector<std::string> keyVec = std::vector<std::string>();
	for (Iterator it = map.begin(); it != map.end(); it++) {
		keyVec.push_back(it->first);
	}
	for (int i = 0; i < keyVec.size(); i++) {
		std::string key = keyVec.at(i);
		NativeMethodExecutor* nme = map.at(key);
		map.erase(key);
		delete nme;
	}
}
//---public method