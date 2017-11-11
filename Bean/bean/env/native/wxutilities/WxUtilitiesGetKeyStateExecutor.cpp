#include "WxUtilitiesGetKeyStateExecutor.h"
#include <wx/wx.h>
#include "../../Enum.h"
#include "../../EnumItem.h"
#include "../../Numeric.h"
#include "../../Package.h"

WxUtilitiesGetKeyStateExecutor::WxUtilitiesGetKeyStateExecutor() {
}

WxUtilitiesGetKeyStateExecutor::~WxUtilitiesGetKeyStateExecutor() {
}

Object_ * const WxUtilitiesGetKeyStateExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	Object_* keycode = args.at(0);
	//一致するキーコードがあるか
	auto keycodeClass = Package::getClassOrLoad("api.wxgui.KeyCode");
	auto keycodeEnum = std::dynamic_pointer_cast<Enum>(keycodeClass);
	if (!keycodeEnum->containsEnumItem(keycode)) {
		Exception::new_e_simple("api.exc.ArgumentException", "キーコードを正しく設定してください");
		return getNull();
	}
	//キーコードの整数値を調べる
	auto keycodeEItem = std::dynamic_pointer_cast<EnumItem>(keycode->getClass());
	Object_* obj  = keycodeEItem->getValue();
	Numeric* keycodeNumeric = dynamic_cast<Numeric*>(obj);
	int keycodeInt = keycodeNumeric->getCInt();
	//押されているか
	bool pressed = false;
//Winodwsなら GetAsyncKeyState
#ifdef __WIN32__
	pressed = GetAsyncKeyState(toWinKeycode(keycodeInt));
//それ以外なら wxGetKeyState
#else
	wxKeyCode type = toKeycode(keycodeInt);
	pressed = wxGetKeyState(type);
#endif // WIN32_
	return getBoolean(pressed);
}

wxKeyCode WxUtilitiesGetKeyStateExecutor::toKeycode(int i) {
	switch (i) {
		case 0: return wxKeyCode::WXK_CONTROL_A;
		case 1: return wxKeyCode::WXK_CONTROL_B;
		case 2: return wxKeyCode::WXK_CONTROL_C;
		case 3: return wxKeyCode::WXK_CONTROL_D;
		case 4: return wxKeyCode::WXK_CONTROL_E;
		case 5: return wxKeyCode::WXK_CONTROL_F;
		case 6: return wxKeyCode::WXK_CONTROL_G;
		case 7: return wxKeyCode::WXK_CONTROL_H;
		case 8: return wxKeyCode::WXK_CONTROL_I;
		case 9: return wxKeyCode::WXK_CONTROL_J;
		case 10: return wxKeyCode::WXK_CONTROL_K;
		case 11: return wxKeyCode::WXK_CONTROL_L;
		case 12: return wxKeyCode::WXK_CONTROL_M;
		case 13: return wxKeyCode::WXK_CONTROL_N;
		case 14: return wxKeyCode::WXK_CONTROL_O;
		case 15: return wxKeyCode::WXK_CONTROL_P;
		case 16: return wxKeyCode::WXK_CONTROL_Q;
		case 17: return wxKeyCode::WXK_CONTROL_R;
		case 18: return wxKeyCode::WXK_CONTROL_S;
		case 19: return wxKeyCode::WXK_CONTROL_T;
		case 20: return wxKeyCode::WXK_CONTROL_U;
		case 21: return wxKeyCode::WXK_CONTROL_V;
		case 22: return wxKeyCode::WXK_CONTROL_W;
		case 23: return wxKeyCode::WXK_CONTROL_X;
		case 24: return wxKeyCode::WXK_CONTROL_Y;
		case 25: return wxKeyCode::WXK_CONTROL_Z;
		case 26: return wxKeyCode::WXK_LEFT;
		case 27: return wxKeyCode::WXK_RIGHT;
		case 28: return wxKeyCode::WXK_UP;
		case 29: return wxKeyCode::WXK_DOWN;
		case 30: return wxKeyCode::WXK_SPACE;
	}
	return wxKeyCode();
}

int WxUtilitiesGetKeyStateExecutor::toWinKeycode(int i) {
	switch (i) {
		case 0: return 'A';
		case 1: return 'B';
		case 2: return 'C';
		case 3: return 'D';
		case 4: return 'E';
		case 5: return 'F';
		case 6: return 'G';
		case 7: return 'H';
		case 8: return 'I';
		case 9: return 'J';
		case 10: return 'K';
		case 11: return 'L';
		case 12: return 'M';
		case 13: return 'N';
		case 14: return 'O';
		case 15: return 'P';
		case 16: return 'Q';
		case 17: return 'R';
		case 18: return 'S';
		case 19: return 'Y';
		case 20: return 'U';
		case 21: return 'V';
		case 22: return 'W';
		case 23: return 'X';
		case 24: return 'Y';
		case 25: return 'Z';
		case 26: return VK_LEFT;
		case 27: return VK_RIGHT;
		case 28: return VK_UP;
		case 29: return VK_DOWN;
		case 30: return VK_SPACE;
	}
	return wxKeyCode();
}
