#include "ClassLoader.h"
#include <algorithm>
#include <memory>
#include <sstream>
#include <string>
#include <thread>
#include "ClassFormatException.h"
#include "ConstructorChainType.h"
#include "Constructor_.h"
#include "DelegateConstructor.h"
#include "FunctionManager.h"
#include "IncludeManager.h"
#include "Package.h"
#include "../Debug.h"
#include "user/UserSystem.h"
#include "../ast/ASTConstructorChain.h"
#include "../ast/ASTNode.h"
#include "../ast/CodeSyntaxException.h"
#include "../env/Class.h"
#include "../env/CodeBlock.h"
#include "../env/Constructor_.h"
#include "../env/Enum.h"
#include "../env/Field.h"
#include "../launch/Bean.h"
#include "../env/Package.h"
#include "../util/IO.h"
#include "../threads/Thread.h"
#include "../util/STL.h"
#include "../ast/visitor/ASTClassBuilder.h"
#include "../ast/visitor/ASTEnumBuilder.h"
#include "../ast/visitor/ASTIncludeVisitor.h"

using ClassLoaderSPtr = std::shared_ptr<ClassLoader>;
using ClassLoaderWPtr = std::weak_ptr<ClassLoader>;
std::vector<ClassLoaderSPtr> ClassLoader::entryPointCLLVector = std::vector<ClassLoaderSPtr>();
std::vector<ClassLoaderSPtr> ClassLoader::rootClassLoaderVec = std::vector<ClassLoaderSPtr>();
std::stack<ClassLoaderSPtr> ClassLoader::classLoaderStack = std::stack<ClassLoaderSPtr>();

//public method---
ClassLoader::ClassLoader(ClassLoaderSPtr parent, std::shared_ptr<ASTNode> root, std::string path) 
 : ClassLoader(parent, root, path, false) {
	
}

ClassLoader::ClassLoader(ClassLoaderSPtr parent, std::shared_ptr<ASTNode> root, std::string path, bool delegateCLL) {
	this->path = path;
	this->entryPoint = false;
	this->functionManager = nullptr;
	if (parent != nullptr &&
		!delegateCLL) {
		parent->pkgStack.push_back(path);
	}
	init(parent, root, delegateCLL);
	includeManager->include(path);
}

ClassLoader::ClassLoader(std::shared_ptr<ASTNode> root) {
	this->path = "root";
	this->functionManager = new FunctionManager();
	this->entryPoint = true;
	init(nullptr, root, false);
}

void ClassLoader::setRoot(std::shared_ptr<ASTNode> root) {
	this->root = root;
}

void ClassLoader::dump() {
	std::cout << "loader " << getPath() << " " << "child " << children.size() << std::endl;
}

ClassLoader::~ClassLoader() {
	children.clear();
	//�I�u�W�F�N�g���폜
	delete includeManager;
	delete functionManager;
	//�R�[�h�u���b�N�̍폜
	using MapItr = std::unordered_map<std::thread::id, CodeBlock*>::iterator;
	MapItr itr = codeBlockMap.begin();
	while (itr != codeBlockMap.end()) {
		CodeBlock* elem = itr->second;
		itr = codeBlockMap.erase(itr);
		delete elem;
	}
	delete source;
}

void ClassLoader::registerClassLoader() {
	ClassLoader::entryPointCLLVector.push_back(shared_from_this());
	ClassLoader::rootClassLoaderVec.push_back(shared_from_this());
	//�e�Ɏ�����ǉ�
	if (!this->parent.expired()) {
		parent.lock()->children.push_back(shared_from_this());
	}
}

ClassSPtr const ClassLoader::loadClass(std::string fqcn) {
	ClassSPtr ret = Package::getClass(fqcn);
	includeManager->include(fqcn);
	if (ret != nullptr || (!pkgStack.empty() && pkgStack.back() == fqcn)) {
		return ret;
	}
	//���̃N���X���[�_�[���Q�Ƃ���N���X���[�_�[��������
	std::string path = Package::resolvePath(fqcn);
	//���݂��Ȃ�
	if (!IO::isExists(path)) {
		if(!pkgStack.empty()) pkgStack.pop_back();
		throw ClassFormatException(path + " �͑��݂��܂���");
	}
	BString source = IO::readText(path);
	ASTNodeSPtr root = Bean::compileplaf(path, source, false);
	if(root != nullptr) {
		//���̃t�@�C���̃C���N���[�h��S�ēǂݍ���
		std::shared_ptr<ClassLoader> child = std::make_shared<ClassLoader>(shared_from_this(), root, fqcn);
		child->registerClassLoader();
		std::string resPkg = Package::resolvePackage(fqcn);
		ASTIncludeVisitor inclVisitor = ASTIncludeVisitor(resPkg, child);
		try {
			root->visit(&inclVisitor);
		} catch (ClassFormatException ein) {
			pkgStack.pop_back();
			throw ClassFormatException(ein.what());
		}
		//�폜
		pkgStack.pop_back();
		ret = Package::getClass(fqcn);
		//FIXME:ClassBuilder������s�����
		//checkClass(ret);
		return ret;
	} else {
		checkThrow("�N���X�����[�h�ł��܂���ł���");
	}
}

void ClassLoader::loadClass(ClassLoaderSPtr child) {
	children.push_back(child);
}

void ClassLoader::loadClass(const std::string & package, std::shared_ptr<ASTClassDeclaration> classDecl, ClassLoaderSPtr parent) {
	std::shared_ptr<ASTName> superNameNode = classDecl->getSuperClass();
	std::string name = classDecl->getName()->getCString();
	std::string fullName = "api.Object";
	//���̃N���X��Object�łȂ��A�e�N���X�����w�肳��Ă��Ȃ��Ƃ�
	//�����I�ɐe�N���X��Object�ɐݒ肷��
	if ((package != "api" || name != "Object") &&
		superNameNode == nullptr) {
		superNameNode = ASTName::make_shared(Text::OBJECT);
		classDecl->setSuperClass(superNameNode);
	} else if (superNameNode != nullptr) {
		fullName = package + "." + superNameNode->getCString();
	}
	//superNameNode���܂�nullptr�Ȃ�Object�N���X����
	ClassSPtr cls = Memory::getSharedNull<Class>();
	if (superNameNode == nullptr) {
		cls = std::make_shared<Class>(parent, classDecl->getName()->getCString());
		cls->registerClass();
		//cls = std::make_shared<Class>(parent, objClass, element->getName()->getCString());
		//�ŏ�����e�N���X���������Ă���
		//���邢�͎�����Object���e�N���X�ɂȂ���
	} else {
		int offset = 0;
		ClassSPtr objClass = Package::getClass(fullName);
		if (objClass == nullptr) {
			objClass = parent->getIncludeManager()->getClass(superNameNode->getCString());
		}
		cls = std::make_shared<Class>(parent, objClass, classDecl->getName()->getCString());
		cls->registerClass();
	}
	//���̎��_�Œǉ�
	PackageSPtr pstr = Package::getPackage(package, true);
	pstr->addClass(cls);
	//�N���X���\�z����
	ASTClassBuilder builder = ASTClassBuilder(package, cls, parent);
	classDecl->visit(&builder);
	//���̃N���X���g�������ŃC���N���[�h
	std::string path = package + "." + cls->getName();
	ClassLoaderWPtr cll = cls->getClassLoader();
	cll.lock()->checkClass(cls);
	cll.lock()->getIncludeManager()->self(path);
}

void ClassLoader::loadEnum(const std::string & package, std::shared_ptr<ASTEnumDeclaration> enumDecl, ClassLoaderSPtr parent) {
	std::shared_ptr<Enum> cls = std::make_shared<Enum>(
		parent,
		Package::getClass("api.Enum"),
		enumDecl->getName()->getCString()
		);
	cls->registerClass();
	//�񋓂��\�z����
	ASTEnumBuilder builder = ASTEnumBuilder(package, cls, parent);
	enumDecl->visit(&builder);
}

void ClassLoader::loadProperties() {
	loadUseDirs();
	loadUseFiles();
}

bool ClassLoader::isEntryPoint() const {
	return entryPoint;
}

ClassLoaderWPtr ClassLoader::getParent()  const {
	return parent;
}

std::shared_ptr<ASTNode> ClassLoader::getRoot() const {
	return this->root;
}

CodeBlock * const ClassLoader::getCodeBlock() {
	ThreadSPtr thread = Thread::getCurrent();
	if (thread == nullptr) {
		thread = Thread::getSystemThread();
	}
	ThreadSPtr srcThreadSptr = sourceThread.lock();
	if (srcThreadSptr == thread) {
		return source;
	}
	std::thread::id tid = thread->getThreadID();
	if (codeBlockMap.count(tid) == 0) {
		CodeBlock* c = source->clone(true);
		codeBlockMap[tid] = c;
	}
	return this->codeBlockMap.at(tid);
}

ClassSPtr const ClassLoader::getClass() const {
	if (path == "root") return nullptr;
	return Package::getClass(path);
}

std::string ClassLoader::getPath() const {
	return path;
}

std::string ClassLoader::getClassName() const {
	return path;
}

std::string ClassLoader::getPackageName() const {
	if (path == "root") return "root";
	int pos = path.rfind(".");
	PackageSPtr pkg = nullptr;
	if (pos == std::string::npos) {
		pkg = Package::getPackage(path);
	} else {
		pkg = Package::getPackage(path.substr(0, pos));
	}
	return pkg->getName();
}

FunctionManager * const ClassLoader::getFunctionManager() const {
	return functionManager;
}

IncludeManager * const ClassLoader::getIncludeManager() const {
	if (this->delegateCll) {
		return this->parent.lock()->getIncludeManager();
	}
	return includeManager;
}

void ClassLoader::lockInstance(Object_ * o) {
	std::lock_guard<std::recursive_mutex> lock(this->thread_sync);
	locks.push(o);
	//�e�N���X�����b�N
	ClassSPtr cur = getClass();
	if (!cur) return;
	cur = cur->getSuper().lock();
	while (cur) {
		ClassLoaderSPtr cll = cur->getClassLoader().lock();
		cll->lockInstance(o);
		cur = cur->getSuper().lock();
	}
}

Object_ * const ClassLoader::getLock(bool forSuper)  {
	std::lock_guard<std::recursive_mutex> lock(this->thread_sync);
	if (locks.empty()) {
		return parent.expired() || !forSuper ? 
			nullptr : parent.lock()->getLock();
	}
	return locks.top();
}

Object_ * const ClassLoader::getLock() {
	return getLock(false);
}

void ClassLoader::unlockInstance() {
	std::lock_guard<std::recursive_mutex> lock(this->thread_sync);
	//FIXME:�ʂ̃X���b�h�Őe�N���X�����s�����ꍇ
	if (locks.empty()) {
		return;
	}
	Object_* o = locks.top();
	locks.pop();
	//�e�N���X�����b�N
	ClassSPtr cur = getClass();
	if (!cur) return;
	cur = cur->getSuper().lock();
	while (cur) {
		ClassLoaderSPtr cll = cur->getClassLoader().lock();
		cll->unlockInstance();
		cur = cur->getSuper().lock();
	}
}

ClassLoader * const ClassLoader::getSystemClassLoader() {
	return nullptr;
}

void ClassLoader::pushCurrentClassLoader(ClassLoaderSPtr classLoader) {
	Thread::getCurrent()->pushCurrentClassLoader(classLoader);
}

bool ClassLoader::multicastClassLoader(ClassLoaderSPtr classLoader) {
	ClassLoaderSPtr cll = getCurrentClassLoader();
	if (cll->isEntryPoint()) {
		return true;
	}
	ClassSPtr left = cll->getClass();
	ClassSPtr right = classLoader->getClass();
	return right->isSubClass(left);
}

void ClassLoader::popCurrentClassLoader() {
	Thread::getCurrent()->popCurrentClassLoader();
}

ClassLoaderSPtr ClassLoader::getCurrentClassLoader() {
	ThreadSPtr t = Thread::getCurrent();
	//�J�����g�X���b�h���擾�o���Ȃ�
	Debug::break_if(t == nullptr);
	if (t == nullptr) return NULL;
	return Thread::getCurrent()->getCurrentClassLoader();
}

ClassLoaderSPtr ClassLoader::getContextClassLoader() {
	ThreadSPtr t = Thread::getCurrent();
	if (t == nullptr) {
		t = Thread::getSystemThread();
	}
	if (t == nullptr) return NULL;
	return t->getCurrentClassLoader();
}

void ClassLoader::destroy() {
	while (!ClassLoader::classLoaderStack.empty()) {
		ClassLoader::classLoaderStack.pop();
	}
	ClassLoader::entryPointCLLVector.clear();
	ClassLoader::rootClassLoaderVec.clear();
}

void ClassLoader::loadDefaults() {
	this->loadClass("api.Object");
	this->loadClass("api.Numeric");
	this->loadClass("api.Short");
	this->loadClass("api.Integer");
	this->loadClass("api.Long");
	this->loadClass("api.Float");
	this->loadClass("api.Double");
	this->loadClass("api.Boolean");
	this->loadClass("api.Character");
	this->loadClass("api.String");
	this->loadClass("api.Array");
	this->loadClass("api.Delegate");
	this->loadClass("api.Null");
	this->loadClass("api.Enum");
	this->loadClass("api.EnumItem");
}
//---public method

//private method---
void ClassLoader::init(ClassLoaderSPtr parent, std::shared_ptr<ASTNode> root, bool delegateCll) {
	this->delegateCll = delegateCll;
	this->parent = std::weak_ptr<ClassLoader>(parent);
	this->root = root;
	this->includeManager = new IncludeManager();
	this->pkgStack = std::list<std::string>();
	this->locks = std::stack<Object_*>();
	this->children = std::vector<ClassLoaderSPtr>();
	this->source = new CodeBlock();
	this->sourceThread = Thread::getCurrent();
	this->codeBlockMap = std::unordered_map<std::thread::id, CodeBlock*>();
	//�e�N���X���[�_�[���ǂݍ��ݓr���̗v�f�������Ă���Ȃ�p������
	using LIterator = std::list<std::string>::iterator;
	if (parent != NULL && !parent->pkgStack.empty()) {
		for (LIterator lit = parent->pkgStack.begin(); lit != parent->pkgStack.end(); lit++) {
			pkgStack.push_front(*lit);
		}
	}
}

void ClassLoader::loadUseDirs() {
	UserSystem* uSys = UserSystem::getInstance();
	std::string current = IO::getCurrentPath();
	std::string src = uSys->str(UserSystem::DEFAULT_USE_NAMESPACES, "null");
	if (src == "null") {
		return;
	}
	std::vector<std::string> defaultUseNamespaces = Text::split(src, ',');
	char pathSeparator = IO::getDirectorySeparatorChar();
	//�S�ẴC���N���[�h�f�B���N�g����
	for (std::string elem : defaultUseNamespaces) {
		//���O��ԂɑΉ�����f�B���N�g���������邩����
		std::string p = current + pathSeparator + Text::replace(elem, '.', IO::getDirectorySeparatorChar());
		if (!IO::isExists(p)) {
			throw ClassFormatException("�w��̃f�B���N�g���͑��݂��܂���: " + p);
		}
		//�C���N���[�h�f�B���N�g���Ɋ܂܂��t�@�C���ꗗ��
		std::vector <std::string> children = IO::getChildren(p, false);
		for (std::string child : children) {
			std::string dir = elem;
			std::string fName = IO::cutExtension(child);
			std::string fullPath = current + pathSeparator + dir + pathSeparator + child;
			//�f�B���N�g�� or jEdit�̃L���b�V�� �Ȃ疳��
			if (IO::isDirectory(fullPath) ||
				!Text::isFQCN(child)) {
				continue;
			}
			std::string beanFQCN = elem + "." + fName;
			try {
				this->loadClass(beanFQCN);
			} catch (CodeSyntaxException e) {
				throw e;
			} catch (ClassFormatException e) {
				throw e;
			}
			this->getIncludeManager()->include(beanFQCN);
		}
	}
}

void ClassLoader::loadUseFiles() {
	UserSystem* uSys = UserSystem::getInstance();
	std::string current = IO::getCurrentPath();
	std::string src = uSys->str(UserSystem::DEFAULT_USE_CLASSES, "null");
	if (src == "null") {
		return;
	}
	std::vector<std::string> defaultUseNamespaces = Text::split(src, ',');
	for (std::string elem : defaultUseNamespaces) {
		std::string beanFQCN = elem;
		try {
			this->loadClass(beanFQCN);
		} catch (CodeSyntaxException e) {
			throw e;
		} catch (ClassFormatException e) {
			throw e;
		}
		this->getIncludeManager()->include(beanFQCN);
	}
}

void ClassLoader::checkClass(ClassSPtr classz) {
	if (!classz) {
		return;
	}
	checkConstructor(classz);
	checkNative(classz);
	checkOverride(classz);
}

void ClassLoader::checkConstructor(ClassSPtr classz) {
	ClassSPtr super = classz->getSuper().lock();
	if (!super) {
		return;
	}
	//�f�t�H���g�R���X�g���N�^���Ȃ�
	for (Constructor_* cons : classz->getConstructors()) {
		auto chain = cons->getChain();
		//�`�F�C���R���X�g���N�^���Ȃ�
		if (chain != nullptr) {
			checkMatchChainConstructor(classz, cons, chain);
			continue;
		}
		//�l�C�e�B�u�R���X�g���N�^�ł�
		//�p���֌W�𖳎����ăI�u�W�F�N�g�𐶐�����
		if (cons->getModifier().isNative()) {
			continue;
		}
		//�e�ɋ�R���X�g���N�^������Ȃ�
		if (super->hasDefaultConstructor()) {
			auto fixedChainTarget = ASTConstructorChain::make_shared();
			fixedChainTarget->setChainType(ConstructorChainType::cct_Super);
			cons->setChain(fixedChainTarget);
		//�Ȃ�
		} else {
			auto ss = std::stringstream();
			ss << "�e�N���X�Ƀf�t�H���g�R���X�g���N�^�����݂��Ȃ������J����Ă��܂���" << std::endl;
			ss << "���J���ꂽ�e�N���X�̃R���X�g���N�^�𖾎��I�Ɏw�肵�Ă��������B" << std::endl;
			ss << "�F" << cons->getLocation() << std::endl;
			checkThrow(ss.str());
		}
	}
	if (classz->getConstructorCount() == 0) {
		for (Constructor_ * superCons : super->getConstructors()) {
			classz->addConstructor(new DelegateConstructor(classz, superCons));
		}
	}
}

void ClassLoader::checkMatchChainConstructor(ClassSPtr classz, Constructor_* body, std::shared_ptr<ASTConstructorChain> chain) {
	int argCount = chain->getArgumentCount();
	ClassSPtr super = classz->getSuper().lock();
	//�e�N���X�̃R���X�g���N�^�ꗗ���`�F�b�N���āA
	//�`�F�C�����ɓn���ꂽ�����ƈ�v���邩�m�F
	for (Constructor_* cons : super->getConstructors()) {
		if (cons->getParameterCount() == argCount) {
			return;
		}
	}
	auto ss = std::stringstream();
	ss << "�w�肳�ꂽ�`�F�C���R���X�g���N�^�ɑ΂��āA" << std::endl;
	ss << "�e�N���X�ɂ͑Ή�����R���X�g���N�^������܂���B" << std::endl;
	ss << "�F" << body->getLocation() << std::endl;
	checkThrow(ss.str());
}

void ClassLoader::checkNative(ClassSPtr classz) {
	//�S�Ẵt�B�[���h���擾
	for (Field* field : classz->getFields()) {
		Modifier mod = field->getModifier();
		if (mod.isNative()) {
			checkThrow("�t�B�[���h�̓l�C�e�B�u�ɏo���܂���B: " + field->getLocation());
		}
	}
	for (Constructor_* cons : classz->getConstructors()) {
		Modifier mod = cons->getModifier();
		if (mod.isNative() &&
			cons->getChain() != nullptr) {
			checkThrow("native�R���X�g���N�^�� �`�F�C���o���܂���F" + cons->getLocation());
		}
	}
}

void ClassLoader::checkThrow(const std::string mes) {
	if (!pkgStack.empty()) {
		pkgStack.pop_back();
	}
	throw ClassFormatException(mes);
}

void ClassLoader::checkOverride(ClassSPtr classz) {
	ClassSPtr super = classz->getSuper().lock();
	if (!super) {
		return;
	}
	//���݂̃N���X�̃��\�b�h�ꗗ���擾
	for (auto curMethod : classz->getMethods()) {
		auto curMName = curMethod->getName();
		auto curMArgs = curMethod->getParameterCount();
		if (curMName == "new") {
			continue;
		}
		//�e�N���X�̓������\�b�h������
		for (auto superMethod : super->getMethods()) {
			Modifier modi = superMethod->getModifier();
			if (!modi.isFinal()) {
				continue;
			}
			//final���\�b�h�̍Ē�`
			if (superMethod->getName() == curMName &&
				superMethod->getParameterCount() == curMArgs) {
				throw ClassFormatException("final���\�b�h���Ē�`����Ă��܂��B:" + curMethod->getLocation());
			}
		}
	}
}
//---private method
