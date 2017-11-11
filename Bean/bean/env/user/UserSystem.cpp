#include "UserSystem.h"
#include <fstream>
#include <sstream>
#include "../../util/IO.h"

const std::string UserSystem::LIB_PATH_KEY = "bean.lib.path";
const std::string UserSystem::DEFAULT_USE_NAMESPACES = "bean.defaultIncludeNamespaces";
const std::string UserSystem::DEFAULT_USE_CLASSES = "bean.defaultIncludeClasses";
const std::string UserSystem::PERFORMANCETEST = "bean.dev.performanceTest";
const std::string UserSystem::GC_REPORT = "bean.dev.gcReport";
const std::string UserSystem::GC_TYPE = "bean.dev.gcType";
const std::string UserSystem::GC_THRESHOLD = "bean.dev.gcThreshold";
const std::string UserSystem::GC_ALWAYS = "bean.dev.gcAlways";
const std::string UserSystem::GC_INC_MAG_MARKS = "bean.dev.gcIncMagMarks";
const std::string UserSystem::GC_INC_MAG_SWEEPS = "bean.dev.gcIncMagSweeps";
const std::string UserSystem::GC_INC_MIN_MARKS = "bean.dev.gcIncMinMarks";
const std::string UserSystem::GC_INC_MIN_SWEEPS = "bean.dev.gcIncMinSweeps";
const std::string UserSystem::GC_INC_LIMIT_FULL_SWEEPS = "bean.dev.gcIncLimitFullSweeps";
//public method---
UserSystem::UserSystem() {
	this->props = Properties();
}

UserSystem::~UserSystem() {
}

std::string UserSystem::getSysPath() {
	return IO::getCurrentPath() + IO::getDirectorySeparatorChar() + "sys.ini";
}

void UserSystem::put(const std::string& key, const std::string& val) {
	props.put(key, val);
}

void UserSystem::put(const std::string & key, const char * val) {
	props.put(key, val);
}

std::string UserSystem::get(const std::string& key) {
	return props.get(key);
}

std::string UserSystem::str(const std::string & key) {
	return props.str(key);
}

std::string UserSystem::str(const std::string & key, const std::string & val) {
	return props.str(key, val);
}

std::string UserSystem::remove(const std::string & key) {
	return props.remove(key);
}

bool UserSystem::contains(const std::string& key) {
	return props.contains(key);
}

void UserSystem::initialize() {
	std::string sysFile = getSysPath();
	UserSystem* uSys = UserSystem::getInstance();
	if (!IO::isExists(sysFile)) {
		IO::createNewFile(sysFile);
		uSys->defaults();
		uSys->apply(sysFile);
	} else {
		uSys->load(sysFile);
	}
}

void UserSystem::defaults() {
	put(LIB_PATH_KEY, IO::getCurrentPath());
	put(DEFAULT_USE_NAMESPACES, "api");
	put(DEFAULT_USE_CLASSES, "null");
	put(PERFORMANCETEST, false);
	put(GC_REPORT, false);
	put(GC_TYPE, 0);
	put(GC_THRESHOLD, 64);
	put(GC_ALWAYS, true);
	put(GC_INC_MAG_MARKS, 0.3f);
	put(GC_INC_MAG_SWEEPS, 0.3f);
	put(GC_INC_MIN_MARKS, 50);
	put(GC_INC_MIN_SWEEPS, 50);
	put(GC_INC_LIMIT_FULL_SWEEPS, 300);
}

void UserSystem::load(std::string filePath) {
	props.read(filePath);
}

void UserSystem::apply(std::string filePath) {
	props.write(filePath);
}

PropertyChangeListenerList* UserSystem::onPropertyChange() {
	return &props.onPropertyChange;
}
//---public method