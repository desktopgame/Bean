#include <crtdbg.h>
#include <iostream>
#include <memory>
#include <string>
#include <wx/debug.h>
#include <wx/frame.h>
#include <wx/image.h>
#include <wx/window.h>
#include "ast/ASTNode.h"
#include "launch/Bean.h"
#include "launch/BeanLineRunner.h"
#include "util/Console.h"
#include "wxgui/ApplicationContext.h"
#include "util/IO.h"
#include "wxgui/WxButtonEx.h"
#include "wxgui/WxFrameEx.h"
#include "env/gc/GCLock.h"
#include "env/native/frame/FrameNewExecutor.h"

#define ARGV_HEAD 1

//event
enum {
	wxID_ButtonPush
};
wxBEGIN_EVENT_TABLE(WxFrameEx, wxFrame)
EVT_MENU(wxID_EXIT, WxFrameEx::OnClose)
wxEND_EVENT_TABLE()
//app
IMPLEMENT_APP_NO_MAIN(ApplicationContext);
IMPLEMENT_WX_THEME_SUPPORT;

void bean_run(int argc, char* argv[]) {
	if (argc < 2) {
		std::cout << "ファイル名を指定してください" << std::endl;
		return;
	}
	Bean::begin();
	Bean::run(argv[ARGV_HEAD + 1]);
	Bean::end();
}

void bean_dbg(int argc, char* argv[]) {
#ifdef _DEBUG
	if (!IO::isExists("TestCode")) {
		std::cout << "実行ファイルと同じディレクトリに [TestCode] ディレクトリが必要です" << std::endl;
		return;
	}
	Bean::begin();
	Bean::runAll("TestCode");
	//Bean::run("source.txt");
	Bean::end();
#else
	std::cout << "開発者向けのコマンドです。" << std::endl;
	std::cout << "この実行ファイルはリリースモードでビルドされているのでデバッグを実行出来ません。" << std::endl;
#endif // DEBUG
}

void bean_doc(int argc, char* argv[]) {
	Bean::begin();
	Bean::dumpDocument(argv[ARGV_HEAD + 1]);
	//Bean::dumpDocument("api.wxgui.Frame");
	Bean::end();
}

void bean_dum(int argc, char* argv[]) {
	Bean::begin();
	Bean::dumpASTTree(argv[ARGV_HEAD + 1]);
	Bean::end();
}

void bean_inr(int argc, char* argv[]) {
	Bean::begin();
	BeanLineRunner lineRunner = BeanLineRunner();
	lineRunner.initialize();
	lineRunner.evalWhile();
	lineRunner.exit();
	Bean::end();
}

void wxsetup(int argc, char* argv[]) {
	wxApp::SetInstance(new ApplicationContext());
	//引数を記録
	FrameNewExecutor::argc = argc;
	FrameNewExecutor::argv = argv;
}

int bean_main(int argc, char* argv[]) {
	//WXGUIの準備
	wxsetup(argc, argv);
	//コマンドで処理を分ける
	//プログラムの実行
	if (strcmp(argv[ARGV_HEAD], "bean") == 0) {
		bean_run(argc, argv);
		//bean_dbg(argc, argv);
		//bean_dum(argc, argv);
		//bean_inr(argc, argv);
		//bean_doc(argc, argv);
	//デバッグの実行
	} else if (strcmp(argv[ARGV_HEAD], "debug") == 0) {
		bean_dbg(argc, argv);
	//ドキュメントの表示
	} else if (strcmp(argv[ARGV_HEAD], "doc") == 0) {
		bean_doc(argc, argv);
	//構文木のダンプ
	} else if (strcmp(argv[ARGV_HEAD], "dump") == 0) {
		bean_dum(argc, argv);
	//REPLの起動
	} else if (strcmp(argv[ARGV_HEAD], "repl") == 0) {
		bean_inr(argc, argv);
	}
	wxTheApp->OnExit();
	wxTheApp->CleanUp();
	wxEntryCleanup();
	return 0;
}

/**
* プログラムのエントリポイントです.
*/
int main(int argc, char* argv[]) {
	std::locale("", std::locale::ctype);
	//メモリリークの検出用
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(103280);
	int ret = bean_main(argc, argv);
	return ret;
}
