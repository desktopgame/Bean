#include "PropertyChangeEvent.h"
//public method---
PropertyChangeEvent::PropertyChangeEvent(const std::string key, const std::string val) {
	this->key = key;
	this->val = val;
}

PropertyChangeEvent::~PropertyChangeEvent() {
}

std::string PropertyChangeEvent::getKey() const {
	return this->key;
}

std::string PropertyChangeEvent::getValue() const {
	return this->val;
}
//---public method