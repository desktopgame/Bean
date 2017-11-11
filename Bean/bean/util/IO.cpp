#include "IO.h"
#include <codecvt>
#include <fstream>
#include <io.h>
#include <iostream>
#include <sstream>
//#include <boost/detail/utf8_codecvt_facet.hpp>
//#include <libs/detail/utf8_codecvt_facet.cpp>
#include <boost/foreach.hpp>
#include <unicode/unistr.h>

//---public method
void IO::writeText(std::string filePath, BString src) {
#ifdef BTEXT_MULTI
	writeTextMulti(filePath, src);
#endif // BTEXT_MULTI
#ifdef BTEXT_WIDE
	writeTextWide(filePath, src);
#endif // BTEXT_WIDE
}

BString IO::readText(std::string filePath) {
#ifdef BTEXT_MULTI
	return readTextMulti(filePath);
#endif // BTEXT_MULTI
#ifdef BTEXT_WIDE
	return readTextWide(filePath);
#endif // BTEXT_WIDE
}

std::string IO::getCurrentPath() {
	const boost::filesystem::path full_path(boost::filesystem::current_path());
	return full_path.string();
}

void IO::createNewFile(std::string fileName) {
	std::ofstream ofs = std::ofstream(fileName);
}

std::string IO::getParent(std::string path) {
	const FILE_SYSTEM::path bPath(path);
	return bPath.parent_path().string();
	//return std::string();
}

std::vector<std::string> IO::getChildren(std::string path, bool allSubTree) {
	std::vector<std::string> list = std::vector<std::string>();
	if (isFile(path)) {
		return list;
	}
	if (allSubTree) {
		BOOST_FOREACH(const boost::filesystem::path& p, std::make_pair(boost::filesystem::recursive_directory_iterator(path),
																	   boost::filesystem::recursive_directory_iterator())) {
			list.push_back(p.filename().string());
		}
	} else {
		BOOST_FOREACH(const boost::filesystem::path& p, std::make_pair(boost::filesystem::directory_iterator(path),
																	   boost::filesystem::directory_iterator())) {
			list.push_back(p.filename().string());
		}
	}
	return list;
}

void IO::copy(std::string src, std::string dst, boost::filesystem::copy_option option) {
	const FILE_SYSTEM::path path(src);
	const FILE_SYSTEM::path dest(dst);
	FILE_SYSTEM::copy_file(path, dest, option);
	//boost::filesystem::filesystem_error&
}

void IO::mkdir(std::string dirName) {
	boost::filesystem::path dir(dirName);
	if (!boost::filesystem::create_directory(dir)) {
//		throw boost::filesystem::filesystem_error("", 0);
	}
}

void IO::delete_(std::string fileName) {
	boost::filesystem::path src(fileName);
	if (!boost::filesystem::remove(src)) {
//		throw BeanIOException(fileName + " の削除に失敗しました");
	}
}

bool IO::isFile(std::string path) {
	if (!isExists(path)) return false;
	boost::filesystem::path fpath(path);
	return boost::filesystem::is_regular_file(fpath);
}

bool IO::isDirectory(std::string path) {
	if (!isExists(path)) return false;
	boost::filesystem::path fpath(path);
	return boost::filesystem::is_directory(fpath);
}

bool IO::isExists(std::string fileName) {
	boost::filesystem::path fpath(fileName);
	return boost::filesystem::exists(fpath);
}

char IO::getDirectorySeparatorChar() {
	return boost::filesystem::path::preferred_separator;
}

std::string IO::getName(const std::string & path) {
	boost::filesystem::path pathr(path);
	return pathr.filename().string();
}

std::string IO::cutExtension(std::string path) {
	size_t pos = path.rfind(".");
	if (pos == std::string::npos) {
		return path;
	}
	return path.substr(0, static_cast<int>(pos));
}

void IO::writeTextMulti(std::string filePath, std::string content) {
	std::ofstream outputStream(filePath);
	if (outputStream.fail()) {
//		throw BeanIOException(filePath + " を開けませんでした");
	}
	outputStream << content << std::endl;
	outputStream.close();
}

void IO::writeTextWide(std::string filePath, std::wstring content) {
	std::wofstream outputStream(filePath);
	if (outputStream.fail()) {
//		throw BeanIOException(filePath + " を開けませんでした");
	}
	outputStream << content << std::endl;
	outputStream.close();
}

std::string IO::readTextMulti(std::string filePath) {
	std::ifstream inputStream(filePath);
	std::string line;
	std::stringstream buff;
	if (inputStream.fail()) {
//		throw BeanIOException(filePath + " を開けませんでした");
	}
	while (std::getline(inputStream, line)) {
		buff << line;
		buff << std::endl;
	}
	line.clear();
	inputStream.close();
	std::string src = buff.str().c_str();
	return src;
}

std::wstring IO::readTextWide(std::string filePath) {
	std::wifstream inputStream(filePath);
	std::wstring line;
	std::wstringstream buff;
	if (inputStream.fail()) {
//		throw BeanIOException(filePath + " を開けませんでした");
	}
	inputStream.imbue(std::locale(inputStream.getloc(), new std::codecvt_utf8<wchar_t>()));
	while (std::getline(inputStream, line)) {
		buff << line;
		buff << std::endl;
	}
	line.clear();
	inputStream.close();
	std::wstring src = buff.str().c_str();
	return src;
}
//public method---
