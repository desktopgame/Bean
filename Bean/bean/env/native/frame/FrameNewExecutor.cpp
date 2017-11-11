#include "FrameNewExecutor.h"
#include <wx/debug.h>
#include <wx/frame.h>
#include <wx/window.h>
#include <wx/wx.h>
#include "../../Numeric.h"
#include "../../String.h"
#include "../../../Debug.h"
#include "../../user/UserFrame.h"
#include "../../../wxgui/ApplicationContext.h"
#include "../../../wxgui/Frame.h"

int FrameNewExecutor::argc = 0;
char** FrameNewExecutor::argv = nullptr;

//public method---
FrameNewExecutor::FrameNewExecutor() {
}

FrameNewExecutor::~FrameNewExecutor() {
}

Object_ * FrameNewExecutor::newObject(ClassSPtr classz, Constructor_ * cons, std::vector<Object_*> args) {
	String* title = arg_cast(String, 0, "String");
	Numeric* width = arg_cast(Numeric, 1, "Numeric");
	Numeric* height = arg_cast(Numeric, 2, "Numeric");
	//フレームを初期化
	wxEntryStart(argc, argv);
	wxTheApp->OnInit();
	ApplicationContext* inst = dynamic_cast<ApplicationContext*>(wxTheApp);
	Frame* frame = inst->getFrame();
	Debug::break_if(frame == NULL || frame == nullptr);
	UserFrame* uframe = new UserFrame(frame);
	uframe->setTitle(*title->getCString());
	uframe->setWidth(width->getCInt());
	uframe->setHeight(height->getCInt());
	//メインループを開始
	//wxTheApp->OnRun();
	return uframe;
}

Object_ * const FrameNewExecutor::executeImpl(Method * const proxy, Object_ * const invoker, std::vector<Object_*> args) {
	return nullptr;
}
//---public method
