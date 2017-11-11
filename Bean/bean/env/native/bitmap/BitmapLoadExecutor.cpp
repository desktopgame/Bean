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
	//��v����񋓎q�����邩�ǂ���
	auto imageFormatClass = Package::getClassOrLoad("api.wxgui.ImageFormat");
	auto imageFormatEnum = std::dynamic_pointer_cast<Enum>(imageFormatClass);
	if (!imageFormatEnum->containsEnumItem(imageFormat)) {
		Exception::throw_e_simple("api.exc.ArgumentException", "�t�H�[�}�b�g�𐳂����w�肵�Ă�������");
		return getNull();
	}
	//C�̕������
	std::string fileNameCStr = *fileName->getCString();
	std::string formatCStr = *imageFormat->execute("toString")->asString()->getCString();
	wxBitmapType type = UserBitmap::fromString(formatCStr);
	//���[�h
	wxBitmap bmp = wxBitmap();
	if (!bmp.LoadFile(fileNameCStr, type)) {
		Exception::throw_e_simple("api.exc.IOException", "�ǂݍ��݂Ɏ��s���܂���");
		return getNull();
	}
	return new UserBitmap(bmp);
}
