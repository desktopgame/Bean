#pragma once
#ifndef BEAN_UTIL_PROPERTYCHANGEEVENT_H
#define BEAN_UTIL_PROPERTYCHANGEEVENT_H
#include <string>
class PropertyChangeEvent {
public:
	PropertyChangeEvent(const std::string key, const std::string val);
	~PropertyChangeEvent();

	/**
	 * �L�[��Ԃ��܂�.
	 * @return
	 */
	std::string getKey() const;

	/**
	 * �l��Ԃ��܂�.
	 * @return
	 */
	std::string getValue() const;
private:
	std::string key;
	std::string val;
};
#endif // !BEAN_UTIL_PROPERTYCHANGEEVENT_H
