#pragma once
#ifndef BEAN_UTIL_PROPERTYCHANGEEVENT_H
#define BEAN_UTIL_PROPERTYCHANGEEVENT_H
#include <string>
class PropertyChangeEvent {
public:
	PropertyChangeEvent(const std::string key, const std::string val);
	~PropertyChangeEvent();

	/**
	 * ÉLÅ[Çï‘ÇµÇ‹Ç∑.
	 * @return
	 */
	std::string getKey() const;

	/**
	 * ílÇï‘ÇµÇ‹Ç∑.
	 * @return
	 */
	std::string getValue() const;
private:
	std::string key;
	std::string val;
};
#endif // !BEAN_UTIL_PROPERTYCHANGEEVENT_H
