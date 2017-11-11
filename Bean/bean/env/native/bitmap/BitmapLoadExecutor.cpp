#include "BitmapLoadExecutor.h"
#include <wx/wx.h>
#include "../../Enum.h"
#include "../../Field.h"
#include "../../Package.h"
#include "../../user/UserBitmap.h"

BitmapLoadExecutor::BitmapLoadExecutor() {
}

BitmapLoadExecutor::~BitmapLoadExecutor() {
}

Object_ * const BitmapLoadExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	String* fileName = arg_cast(String, 0, "String");
	Object_* imageFormat = args.at(1);
	//一致する列挙子があるかどうか
	auto imageFormatClass = Package::getClassOrLoad("api.wxgui.ImageFormat");
	auto imageFormatEnum = std::dynamic_pointer_cast<Enum>(imageFormatClass);
	if (!imageFormatEnum->containsEnumItem(imageFormat)) {
		Exception::throw_e_simple("api.exc.ArgumentException", "フォーマットを正しく指定してください");
		return getNull();
	}
	//Cの文字列へ
	std::string fileNameCStr = *fileName->getCString();
	std::string formatCStr = *imageFormat->execute("toString")->asString()->getCString();
	wxBitmapType type = UserBitmap::fromString(formatCStr);
	//ロード
	wxBitmap bmp = wxBitmap();
	if (!bmp.LoadFile(fileNameCStr, type)) {
		Exception::throw_e_simple("api.exc.IOException", "読み込みに失敗しました");
		return getNull();
	}
	return new UserBitmap(bmp);
}
