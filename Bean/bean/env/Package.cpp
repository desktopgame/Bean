#include "Package.h"
#include <iostream>
#include <string>
#include "Class.h"
#include "ClassLoader.h"
#include "CodeBlock.h"
#include "../Debug.h"
#include "gc/Heap.h"
#include "user/UserSystem.h"
#include "../util/IO.h"
#include "../util/STL.h"

//using PackageSPtr = std::shared_ptr<Package>;
//using PackageWPtr = std::weak_ptr<Package>;
std::vector<PackageSPtr> Package::rootPackages = std::vector<PackageSPtr>();
std::vector<ClassSPtr> Package::rootClasses = std::vector<ClassSPtr>();
const std::string Package::ENTRY_POINT_PACKAGE = "$entrypoint";
//public method---
Package::Package(PackageSPtr parent, const std::string& name)
 : Package(name) {	
	this->bHasParent = true;
	//this->parent = std::weak_ptr<Package>(parent);
}

Package::Package(const std::string& name) {
	this->name = name;
	this->children = std::vector<PackageSPtr>();
	this->classes = std::vector<ClassSPtr>();
	this->bHasParent = false;
}

Package::~Package() {
	children.clear();
	classes.clear();
}

PackageSPtr Package::addPackage(const std::string& name) {
	PackageSPtr pkg = std::make_shared<Package>(
		shared_from_this(), name
	);
	this->children.push_back(pkg);
	return pkg;
}

void Package::addClass(ClassSPtr classz) {
	classes.push_back(classz);
}

PackageSPtr Package::getPackageAt(int index) {
	return children.at(index);
}

ClassSPtr const Package::getClassAt(int index) {
	return classes.at(index);
}

void Package::visit(PackageVisitor visitor) {
	visitorImpl(shared_from_this(), visitor);
}

int Package::getPackageCount() {
	int x =  children.size();
	return x;
}

int Package::getClassCount() {
	return classes.size();
}

PackageWPtr Package::getParent() {
	return this->parent;
}

bool Package::hasParent() {
	return this->bHasParent;;
}

std::string Package::getName() {
	return this->name;
}

std::string Package::getDirectory() {
	UserSystem* uSys = UserSystem::getInstance();
	std::string libPath = uSys->value(UserSystem::LIB_PATH_KEY, IO::getCurrentPath()) + IO::getDirectorySeparatorChar();
	if (!bHasParent) {
		return libPath + getName() + IO::getDirectorySeparatorChar();
	}
	std::string buff = std::string(); 
//	buff.push_back()
	PackageWPtr root = std::weak_ptr<Package>(shared_from_this());
	do {
		auto holder = root.lock();
		buff.insert(0, holder->getName() + IO::getDirectorySeparatorChar());
		if (holder->hasParent()) {
			root = holder->getParent();
		} else {
			break;
		}
	} while (true);
	buff.insert(0, libPath);
	return buff;
}

void Package::dump() {
	dumpImpl(shared_from_this(), 0);
}
//---public method

//static method---
PackageSPtr Package::newPackage(const std::string& name) {
	PackageSPtr pkg = std::make_shared<Package>(name);
	Package::rootPackages.push_back(pkg);
	return pkg;
}

PackageSPtr Package::getPackage(const std::string& fqcn, bool make) {
	std::vector<PackageSPtr> copy = rootPackages;
	std::string buff = std::string();
	PackageSPtr parent;
	for (int i = 0; i < fqcn.size(); i++) {
		char c = fqcn[i];
		if (c == '.') {
			bool found = false;
			for (int j = 0; j < copy.size(); j++) {
				PackageSPtr current = copy.at(j);
				std::string currentName = current->getName();
				if (buff == currentName) {
					parent = current;
					copy.clear();
					copy = current->children;
					found = true;
					break;
				}
			}
			//見つからなかったが、新規作成するモードなら
			if (!found && make) {
				if (parent != NULL) {
					parent->addPackage(buff);
				} else {
					parent = newPackage(buff);
				}
			}
			buff = std::string();
		} else {
			buff.push_back(c);
		}
	}
	PackageSPtr ret = NULL;
	for (int i = 0; i <copy.size(); i++) {
		PackageSPtr child = copy.at(i);
		std::string childName = child->getName();
		if (childName == buff) {
			ret = child;
			break;
		}
	}
	if (ret == NULL && make) {
		//親がいないので直下に作成
		if (parent == NULL) {
			ret = std::make_shared<Package>(buff);
			Package::rootPackages.push_back(ret);
		//親がいるのでそいつの子要素にする
		} else {
			ret = parent->addPackage(buff);
		}
	//	ret = parent->addPackage(buff);
	}
	copy.clear();
	return ret;
}

PackageSPtr Package::getPackage(const std::string& fqcn) {
	return getPackage(fqcn, false);
}

std::vector<PackageSPtr> Package::getPackages() {
	return rootPackages;
}

ClassSPtr const Package::getClass(const std::string& fqcn, bool make) {
	int offset = fqcn.rfind('.');
	int len = fqcn.length();
	std::string previus = fqcn.substr(0, offset);
	std::string suffix = fqcn.substr(offset+1, len - offset);
	PackageSPtr pkg = getPackage(previus, make);
	if (pkg == NULL) {
		return nullptr;
	}
	for (int i = 0; i < pkg->classes.size(); i++) {
		ClassSPtr classz = pkg->classes.at(i);
		std::string classzName = classz->getName();
		if (suffix == classzName) {
			return classz;
		}
	}
	return NULL;
}

ClassSPtr const Package::getClass(const std::string& fqcn) {
	return getClass(fqcn, true);
}

ClassSPtr const Package::getClassOrLoad(const std::string& fqcn) {
	ClassSPtr classz = getClass(fqcn);
	if (classz == NULL) {
		ClassLoaderSPtr cll = ClassLoader::getContextClassLoader();
		if (cll != NULL) {
			classz = cll->loadClass(fqcn);
		}
	} else {
		return classz;
	}
	return classz;
}

std::string Package::resolvePath(const std::string& fqcn) {
	char separator = IO::getDirectorySeparatorChar();
	UserSystem* uSys = UserSystem::getInstance();
	std::string libPath = uSys->value(UserSystem::LIB_PATH_KEY, IO::getCurrentPath());
	std::string current = IO::getCurrentPath() + separator;
	std::string buff = std::string();
	for (int i = 0; i < fqcn.length(); i++) {
		char fqcnC = fqcn.at(i);
		if (fqcnC == '.') {
			current += buff;
			current += separator;
			buff = std::string();
		} else {
			buff += fqcnC;
		}
	}
	current += buff;
	current += ".bn";
	return current;
}

std::string Package::resolvePackage(const std::string& fqcn) {
	int offs = fqcn.rfind(".");
	return fqcn.substr(0, offs);
}

void Package::visitAllClasses(ClassVisitor cv) {
	for (PackageSPtr root : Package::getPackages()) {
		root->visit([&cv](PackageSPtr p) {
			for (int i = 0; i < p->getClassCount(); i++) {
				ClassSPtr classz = p->getClassAt(i);
				cv(classz);
			}
		});
	}
}

void Package::dumpAll() {
	for (int i = 0; i < rootPackages.size(); i++) {
		PackageSPtr pkg = rootPackages.at(i);
		pkg->dump();
		std::cout << "---" << std::endl;
	}
}

void Package::destroy() {
	Heap::getInstance()->fullGC();
	rootPackages.clear();
	rootClasses.clear();
}

void Package::registerClass(ClassSPtr classz) {
	Package::rootClasses.push_back(classz);
}
//---static method

//private method---
void Package::visitorImpl(PackageSPtr parent, PackageVisitor fv) {
	fv(parent);
	for (PackageSPtr child : parent->children) {
		visitorImpl(child, fv);
	}
}

void Package::dumpImpl(PackageSPtr root, int depth) {
	//字下げの作成
	std::string indent = std::string();
	for (int i = 0; i < depth; i++) {
		indent += "    ";
	}
	std::cout << indent << root->getName() << std::endl;
	for (int i = 0; i < root->getClassCount(); i++) {
		ClassSPtr classz = root->getClassAt(i);
		std::cout << indent << "-" << classz->getName() << std::endl;
	}
	for (int i = 0; i < root->getPackageCount(); i++) {
		dumpImpl(root->getPackageAt(i), depth + 1);
	}
}
//---private method
