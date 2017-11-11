#ifndef BEAN_UTIL_STLIMPL_CPP
#define BEAN_UTIL_STLIMPL_CPP
#include <algorithm>
#include "STL.h"

//public method---
template<typename T>
bool STL::contains(std::vector<T> container, T item) {
	std::vector<T>::iterator itr = std::find(container.begin(), container.end(), item);
	return itr != container.end();
}

template<typename T>
void STL::each_reverse(std::vector<T> container, std::function<bool(T)> preErase, std::function<void(T)> postErase) {
	for (int i = container.size() - 1; i >= 0; i--) {
		T val = container.at(i);
		bool erase = preErase(val);
		if (erase) {
			container.erase(container.begin() + i);
			postErase(val);
		}
	}
}

template<typename T>
void STL::remove(std::vector<T> container, T item, std::function<void(T)> consumer) {
	std::vector<T>::iterator itr = std::remove_if(container.begin(), container.end(), [&item](T elem) { return elem == item; });
	std::vector<T>::iterator offs = itr;
	std::vector<T> copy = std::vector<T>();
	for (; offs != container.end(); offs++) {
		copy.push_back(*offs);
	}
	container.erase(itr, container.end());
	std::for_each(copy.begin(), copy.end(), [&consumer](T elem) { consumer(elem); });
}

template<typename T>
void STL::removeAll(std::vector<T> container, std::function<void(T)> consumer) {
	std::vector<T>::iterator itr = container.begin();
	for (; itr != container.end();) {
		T val = *itr;
		itr = container.erase(itr);
		consumer(val);
	}
}

template<typename K, typename V>
void STL::remove(std::map<K, V> container, V value, std::function<void(K, V)> consumer) {
	std::map<K, V>::iterator itr = std::remove_if(container.begin(), container.end(), [](std::pair<K, V> pair) {
		return pair->second == value;
	});
	std::map<K, V>::iterator offs = itr;
	std::vector<std::pair<K, V>> copy = std::vector<std::pair<K, V>>();
	for (; offs != container.end(); offs++) {
		copy.push_back(std::pair<K, V>(offs->first, offs->second));
	}
	container.erase(itr, container.end());
	std::for_each(copy.begin(), copy.end(), [&consumer](std::pair<K, V> elem) { consumer(elem.first, elem.second); });
}

template<typename K, typename V>
void STL::removeAll(std::map<K, V> container, std::function<void(K, V)> consumer) {
	std::map<K, V>::iterator itr = container.begin();
	for (; itr != container.end();) {
		std::pair<K, V> pair = *itr;
		itr = container.erase(itr);
		consumer(pair.first, pair.second);
	}
}
//---public method
#endif // !BEAN_UTIL_STLIMPL_CPP
