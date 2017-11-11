#include "Bean.h"
#include "../BeanSkeleton.h"
#include "../env/ClassLoader.h"
#include "../parser/BisonWrapper.h"
#include "../env/gc/GCLock.h"
#include "../ast/visitor/ASTInterpretVisitor.h"
#include "../parser/bison/compiler.h"
#include "../parser/bison/yyinterface.h"

BeanPreLaunchListenerList Bean::onPreLaunch = BeanPreLaunchListenerList();
BeanPostLaunchListenerList Bean::onPostLaunch = BeanPostLaunchListenerList();
BeanPreExitListenerList Bean::onPreExit = BeanPreExitListenerList();
BeanPostExitListenerList Bean::onPostExit = BeanPostExitListenerList();

//public method---
void Bean::begin() {
	init_compiler_stack();
	onPreLaunch();
	//エントリポイントでクラスを定義すると
	//暗黙的にここに追加される
	Package::newPackage(Package::ENTRY_POINT_PACKAGE);
	UserSystem::initialize();
	install_native_method();
	onPostLaunch();
}

//
//コンパイル関数一覧
//
//

//
//ファイルを入力としてコンパイルします。
//
ASTNodeSPtr Bean::compile(const std::string filePath, bool entryPoint) {
	BisonWrapper bw = BisonWrapper(entryPoint);
	return bw.compile(filePath);
}

//
//std::string を入力としてコンパイルします。
//
ASTNodeSPtr Bean::compilestr(const std::string filePath, const std::string source, bool entryPoint) {
	BisonWrapper bw = BisonWrapper(entryPoint);
	return bw.compilestr(filePath, _strdup(source.c_str()));
}

ASTNodeSPtr Bean::compilestr(const std::string source, bool entryPoint) {
	return compilestr("null", source, entryPoint);
}

//
//std::wstring を入力としてコンパイルします。
//
ASTNodeSPtr Bean::compilewstr(const std::string filePath, const std::wstring source, bool entryPoint) {
	return compilestr(filePath, Text::wideToMulti(source), entryPoint);
}

ASTNodeSPtr Bean::compilewstr(const std::wstring source, bool entryPoint) {
	return compilewstr("null", source, entryPoint);
}

//
//プラットフォームに合わせた文字コードでコンパイルします。
//
ASTNodeSPtr Bean::compileplaf(const std::string & filePath, const BString & source, bool entryPoint) {
#if defined(BTEXT_MULTI)
	return compilestr(filePath, source, entryPoint);
#elif defined(BTEXT_WIDE)
	return compilewstr(filePath, source, entryPoint);
#endif
}

ASTNodeSPtr Bean::compileplaf(const BString & source, bool entryPoint) {
#if defined(BTEXT_MULTI)
	return compilestr(source, entryPoint);
#elif defined(BTEXT_WIDE)
	return compilewstr(source, entryPoint);
#endif
}

//
//ダンプ
//
void Bean::dumpASTTree(std::string path) {
	if (!IO::isExists(path)) {
		std::cout << path << " は存在しません" << std::endl;
		return;
	}
	GCLock gcLock = GCLock();
	BisonWrapper bw = BisonWrapper(true);
	bw.compile(path)->dump();
}

void Bean::dumpDocument(std::string fqcn) {
	std::string path = Package::resolvePath(fqcn);
	if (!IO::isExists(path)) {
		std::cout << path << " は存在しません" << std::endl;
		return;
	}
	BisonWrapper bw = BisonWrapper(false);
	std::shared_ptr<ASTNode> root = bw.compile(path);
	ClassLoaderSPtr cll = std::make_shared<ClassLoader>(root);
	cll->registerClassLoader();
	ClassSPtr objCls = cll->loadClass("api.Object");
	ClassSPtr cls = cll->loadClass(fqcn);
	//クラス階層の出力
	std::string indent = "    ";
	std::stringstream hierarchy = std::stringstream();
	int depth = 0;
	ClassSPtr tmp = cls;
	do {
		hierarchy << indent << makeIndent(depth++, indent) << tmp->getName() << std::endl;
		tmp = tmp->getSuper().lock();
	} while (tmp != nullptr);
	std::cout << "@class hierarchy" << std::endl;
	std::cout << hierarchy.str() << std::endl;
	//フィールド一覧の出力
	std::cout << "@field list" << std::endl;
	for (Member* mem : cls->getFields()) {
		Modifier mod = mem->getModifier();
		std::cout << indent << mem->getName() << " : " << mod.getString() << std::endl;
	}
	//メソッド一覧の出力
	std::cout << std::endl;
	std::cout << "@method list" << std::endl;
	for (Member* mem : cls->getMethods()) {
		Modifier mod = mem->getModifier();
		std::cout << indent << mem->getName() << " : " << mod.getString() << std::endl;
	}
}

void Bean::run(std::string fileName) {
	std::string c = fileName.substr(fileName.length() - 1, 1);
	if (c == "~") return;
	std::cout << "----- " << fileName << " -----" << std::endl;
	Runtime* runtime = new Runtime();
	runtime->exec(fileName);
	delete runtime;
	std::cout << "" << std::endl;
	std::cout << "" << std::endl;
}

void Bean::runAll(std::string dirName) {
	//テストコードの検証
	//ファイルを列挙
	//*
	std::string root = IO::getCurrentPath() + "/" + dirName;
	boost::filesystem::path p(root);
	boost::filesystem::directory_iterator end_itr;
	for (boost::filesystem::directory_iterator itr(p); itr != end_itr; ++itr) {
		std::string current_file = itr->path().string();
		if (!is_regular_file(itr->path())) {
			continue;
		}
		run(current_file);
	}
}

std::string Bean::makeIndent(int depth, const std::string& spaces) {
	std::string buff = std::string();
	for (int i = 0; i < depth; i++) {
		buff += spaces;
	}
	return buff;
}

void Bean::end() {
	onPreExit();
	Block::blocks_page_clearAll();
	Field::invalidateStatics();
	Heap::getInstance()->fullGC();
	//Heap::getInstance()->dump();

	ClassLoader::destroy();
	Package::destroy();
	Thread::destroy();
	Heap::getInstance()->destroy();
	onPostExit();
	destroy_compiler_stack();
}
//---public method


//private method---
void Bean::install_native_method() {
	NativeMethodRegistry*  reg = NativeMethodRegistry::getInstance();
	//api.Object
	std::string clsName = "api.Object";
	reg->add(clsName + "#op_add(1)", new ObjectOpAddExecutor());
	reg->add(clsName + "#op_sub(1)", new ObjectOpSubExecutor());
	reg->add(clsName + "#op_mul(1)", new ObjectOpMulExecutor());
	reg->add(clsName + "#op_div(1)", new ObjectOpDivExecutor());
	reg->add(clsName + "#op_mod(1)", new ObjectOpModExecutor());
	reg->add(clsName + "#op_equals(1)", new ObjectOpEqualsExecutor());
	reg->add(clsName + "#hashCode(0)", new ObjectHashCodeExecutor());
	reg->add(clsName + "#toString(0)", new ObjectToStringExecutor());
	//api.Numeric
	clsName = "api.Numeric";
	reg->add(clsName + "#op_add(1)", new NumericOpAddExecutor());
	reg->add(clsName + "#op_sub(1)", new NumericOpSubExecutor());
	reg->add(clsName + "#op_mul(1)", new NumericOpMulExecutor());
	reg->add(clsName + "#op_div(1)", new NumericOpDivExecutor());
	reg->add(clsName + "#op_mod(1)", new NumericOpModExecutor());
	reg->add(clsName + "#op_equals(1)", new NumericOpEqualsExecutor());
	reg->add(clsName + "#asShort(1)", new NumericAsShortExecutor());
	reg->add(clsName + "#asInteger(1)", new NumericAsIntegerExecutor());
	reg->add(clsName + "#asLong(1)", new NumericAsLongExecutor());
	reg->add(clsName + "#asFloat(1)", new NumericAsFloatExecutor());
	reg->add(clsName + "#asCharacter(1)", new NumericAsCharacterExecutor());
	reg->add(clsName + "#asDouble(1)", new NumericAsDoubleExecutor());
	reg->add(clsName + "#toString(0)", new NumericToStringExecutor());
	//api.Character
	clsName = "api.Character";
	reg->add(clsName + "#op_add(1)", new CharacterOpAddExecutor());
	reg->add(clsName + "#toString(0)", new CharacterToStringExecutor());
	reg->add(clsName + "#asInteger(1)", new CharacterAsInteger());
	//api.String
	clsName = "api.String";
	reg->add(clsName + "#op_add(1)", new StringOpAddExecutor());
	reg->add(clsName + "#toString(0)", new StringToStringExecutor());
	reg->add(clsName + "#encode(1)", new StringEncodeExecutor());
	reg->add(clsName + "#indexOf(1)", new StringIndexOfExecutor());
	reg->add(clsName + "#indexOf(2)", new StringIndexOf2Executor());
	reg->add(clsName + "#lastIndexOf(1)", new StringLastIndexOfExecutor());
	reg->add(clsName + "#lastIndexOf(2)", new StringLastIndexOf2Executor());
	reg->add(clsName + "#insert(2)", new StringInsertExecutor());
	reg->add(clsName + "#remove(2)", new StringRemoveExecutor());
	reg->add(clsName + "#startsWith(1)", new StringStartsWithExecutor());
	reg->add(clsName + "#endsWith(1)", new StringEndsWithExecutor());
	reg->add(clsName + "#length(0)", new StringLengthExecutor());
	reg->add(clsName + "#substring(2)", new StringSubstringExecutor());
	//api.Boolean
	clsName = "api.Boolean";
	reg->add(clsName + "#toString(0)", new BooleanToString());
	//api.Array
	clsName = "api.Array";
	reg->add(clsName + "#new(1)", new ArrayNewExecutor());
	reg->add(clsName + "#set(2)", new ArraySetExecutor());
	reg->add(clsName + "#get(1)", new ArrayGetExecutor());
	reg->add(clsName + "#length(0)", new ArrayLengthExecutor());
	//api.Console
	clsName = "api.Console";
	reg->add(clsName + "#write(1)", new ConsoleWriteExecutor());
	reg->add(clsName + "#writeLine(1)", new ConsoleWriteLineExecutor());
	reg->add(clsName + "#read(0)", new ConsoleReadExecutor());
	reg->add(clsName + "#readLine(0)", new ConsoleReadLineExecutor());
	//api.Delegate
	clsName = "api.Delegate";
	reg->add(clsName + "#newInstance(4)", new DelegateNewInstanceExecutor());
	reg->add(clsName + "#call(1)", new DelegateCallExecutor());
	//api.File
	clsName = "api.File";
	reg->add(clsName + "#getCurrentPath(0)", new FileGetCurrentPathExecutor());
	reg->add(clsName + "#getPathSeparatorChar(0)", new FileGetPathSeparatorCharExecutor());
	reg->add(clsName + "#exists(1)", new FileExistsExecutor());
	reg->add(clsName + "#readText(1)", new FileReadTextExecutor());
	reg->add(clsName + "#writeText(2)", new FileWriteTextExecutor());
	reg->add(clsName + "#isFile(1)", new FileIsFileExecutor());
	reg->add(clsName + "#isDirectory(1)", new FileIsDirectoryExecutor());
	reg->add(clsName + "#createNewFile(1)", new FileCreateNewFileExecutor());
	reg->add(clsName + "#mkdir(1)", new FileMkdirExecutor());
	reg->add(clsName + "#delete(1)", new FileDeleteExecutor());
	reg->add(clsName + "#copy(3)", new FileCopyExecutor());
	reg->add(clsName + "#getName(1)", new FileGetNameExecutor());
	reg->add(clsName + "#getParent(1)", new FileGetParentExecutor());
	reg->add(clsName + "#getChildren(2)", new FileGetChildrenExecutor());
	//api.Thread
	clsName = "api.Thread";
	reg->add(clsName + "#new(1)", new ThreadNewExecutor());
	reg->add(clsName + "#start(1)", new ThreadStartExecutor());
	reg->add(clsName + "#sleep(1)", new ThreadSleepExecutor());
	reg->add(clsName + "#join(0)", new ThreadJoinExecutor());
	reg->add(clsName + "#getCurrent(0)", new ThreadGetCurrentOwner());
	reg->add(clsName + "#getName(0)", new ThreadGetNameExecutor());
	//api.io.FilePtr;
	clsName = "api.io.FilePtr";
	reg->add(clsName + "#open(2)", new FilePtrOpenExecutor());
	reg->add(clsName + "#read(0)", new FilePtrReadExecutor());
	reg->add(clsName + "#close(0)", new FilePtrCloseExecutor());
	//api.Enum
	clsName = "api.Enum";
	reg->add(clsName + "#values(0)", new EnumValuesExecutor());
	reg->add(clsName + "#valueOf(1)", new EnumValueOfExecutor());
	//api.EnumItem
	clsName = "api.EnumItem";
	reg->add(clsName + "#toString(0)", new EnumItemToStringExecutor("EnumItem"));
	reg->add(clsName + "#getIndex(0)", new EnumItemGetIndexExecutor());
	reg->add(clsName + "#getValue(0)", new EnumItemGetValueExecutor());
	//api.Math
	clsName = "api.Math";
	reg->add(clsName + "#min(2)", new MathMinExecutor());
	reg->add(clsName + "#max(2)", new MathMaxExecutor());
	reg->add(clsName + "#abs(1)", new MathAbsExecutor());
	reg->add(clsName + "#pow(2)", new MathPowExecutor());
	reg->add(clsName + "#floor(1)", new MathFloorExecutor());
	reg->add(clsName + "#ceil(1)", new MathCeilExecutor());
	reg->add(clsName + "#round(1)", new MathRoundExecutor());
	reg->add(clsName + "#sqrt(1)", new MathSqrtExecutor());
	reg->add(clsName + "#sin(1)", new MathSinExecutor());
	reg->add(clsName + "#cos(1)", new MathCosExecutor());
	reg->add(clsName + "#tan(1)", new MathTanExecutor());
	reg->add(clsName + "#toRadian(1)", new MathToRadianExecutor());
	reg->add(clsName + "#toDegree(1)", new MathToDegreeExecutor());
	//api.Mutex
	clsName = "api.Mutex";
	reg->add(clsName + "#new(0)", new MutexNewExecutor());
	reg->add(clsName + "#lock(0)", new MutexLockExecutor());
	reg->add(clsName + "#unlock(0)", new MutexUnlockExecutor());
	//api.wxgui.Component
	clsName = "api.wxgui.Component";
	reg->add(clsName + "#repaint(0)", new ComponentRepaintExecutor());
	reg->add(clsName + "#setX(1)", new ComponentSetXExecutor());
	reg->add(clsName + "#setY(1)", new ComponentSetYExecutor());
	reg->add(clsName + "#setWidth(1)", new ComponentSetWidthExecutor());
	reg->add(clsName + "#setHeight(1)", new ComponentSetHeightExecutor());
	reg->add(clsName + "#getX(0)", new ComponentGetXExecutor());
	reg->add(clsName + "#getY(0)", new ComponentGetYExecutor());
	reg->add(clsName + "#getWidth(0)", new ComponentGetWidthExecutor());
	reg->add(clsName + "#getHeight(0)", new ComponentGetHeightExecutor());
	reg->add(clsName + "#setMinSize(2)", new ComponentSetMinSizeExecutor());
	reg->add(clsName + "#getMinSize(0)", new ComponentGetMinSizeExecutor());
	reg->add(clsName + "#setFitSize(2)", new ComponentSetFitSizeExecutor());
	reg->add(clsName + "#getFitSize(0)", new ComponentGetFitSizeExecutor());
	reg->add(clsName + "#setMaxSize(2)", new ComponentSetMaxSizeExecutor());
	reg->add(clsName + "#getMaxSize(0)", new ComponentGetMaxSizeExecutor());
	reg->add(clsName + "#setForeground(1)", new ComponentSetForegroundExecutor());
	reg->add(clsName + "#getForeground(0)", new ComponentGetForegroundExecutor());
	reg->add(clsName + "#setBackground(1)", new ComponentSetBackgroundExecutor());
	reg->add(clsName + "#getBackground(0)", new ComponentGetBackgroundExecutor());
	//api.wxgui.Container
	clsName = "api.wxgui.Container";
	reg->add(clsName + "#setLayout(1)", new ContainerSetLayoutExecutor());
	reg->add(clsName + "#getLayout(0)", new ContainerGetLayoutExecutor());
	//api.wxgui.Frame
	clsName = "api.wxgui.Frame";
	reg->add(clsName + "#new(3)", new FrameNewExecutor());
	reg->add(clsName + "#mainLoop(0)", new FrameMainLoopExecutor());
	reg->add(clsName + "#setMenuBar(1)", new FrameSetMenuBarExecutor());
	reg->add(clsName + "#getMenuBar(0)", new FrameGetMenuBarExecutor());
	reg->add(clsName + "#createStatusBar(1)", new FrameCreateStatusBarExecutor());
	reg->add(clsName + "#printStatus(2)", new FramePrintStatusExecutor());
	reg->add(clsName + "#pack(0)", new FramePackExecutor());
	reg->add(clsName + "#setTitle(1)", new FrameSetTitleExecutor());
	reg->add(clsName + "#getTitle(0)", new FrameGetTitleExecutor());
	//api.wxgui.Button;
	clsName = "api.wxgui.Button";
	reg->add(clsName + "#new(2)", new ButtonNewExecutor());
	reg->add(clsName + "#setText(1)", new ButtonSetTextExecutor());
	reg->add(clsName + "#getText(0)", new ButtonGetTextExecutor());
	reg->add(clsName + "#addPushListener(1)", new ButtonAddPushListenerExecutor());
	reg->add(clsName + "#removePushListenerAt(1)", new ButtonRemovePushListenerAtExecutor());
	reg->add(clsName + "#getPushListenerCount(0)", new ButtonGetPushListenerCountExecutor());
	//api.wxgui.Label
	clsName = "api.wxgui.Label";
	reg->add(clsName + "#new(2)", new LabelNewExecutor());
	reg->add(clsName + "#setText(1)", new LabelSetTextExecutor());
	reg->add(clsName + "#getText(0)", new LabelGetTextExecutor());
	//api.wxgui.Panel
	clsName = "api.wxgui.Panel";
	reg->add(clsName + "#new(1)", new PanelNewExecutor());
	//api.wxgui.Color;
	clsName = "api.wxgui.Color";
	reg->add(clsName + "#new(3)", new ColorNewExecutor());
	reg->add(clsName + "#new(4)", new ColorNewAExecutor());
	//api.wxgui.TextField;
	clsName = "api.wxgui.TextField";
	reg->add(clsName + "#new(1)", new TextFieldNewExecutor());
	reg->add(clsName + "#setText(1)", new TextFieldSetTextExecutor());
	reg->add(clsName + "#getText(0)", new TextFieldGetTextExecutor());
	reg->add(clsName + "#insert(2)", new TextFieldInsertExecutor());
	reg->add(clsName + "#remove(2)", new TextFieldRemoveExecutor());
	reg->add(clsName + "#undo(0)", new TextFieldUndoExecutor());
	reg->add(clsName + "#redo(0)", new TextFieldRedoExecutor());
	reg->add(clsName + "#canUndo(0)", new TextFieldCanUndoExecutor());
	reg->add(clsName + "#canRedo(0)", new TextFieldCanRedoExecutor());
	reg->add(clsName + "#setCaretPosition(1)", new TextFieldSetCaretPositionExecutor());
	reg->add(clsName + "#getCaretPosition(0)", new TextFieldGetCaretPositionExecutor());
	reg->add(clsName + "#select(2)", new TextFieldSelectExecutor());
	reg->add(clsName + "#selectAll(0)", new TextFieldSelectAllExecutor());
	reg->add(clsName + "#cut(0)", new TextFieldCutExecutor());
	reg->add(clsName + "#copy(0)", new TextFieldCopyExecutor());
	reg->add(clsName + "#paste(0)", new TextFieldPasteExecutor());
	//api.wxgui.ScrollPane
	clsName = "api.wxgui.ScrollPane";
	reg->add(clsName + "#new(1)", new ScrollPaneNewExecutor());
	//api.wxgui.LayoutManager
	clsName = "api.wxgui.LayoutManager";
	reg->add(clsName + "#addComponent(2)", new LayoutManagerAddComponentExecutor());
	reg->add(clsName + "#addSpace(1)", new LayoutManagerAddSpaceExecutor());
	reg->add(clsName + "#addStretch(0)", new LayoutManagerAddStretchExecutor());
	reg->add(clsName + "#removeComponentAt(1)", new LayoutManagerRemoveComponentAtExecutor());
	reg->add(clsName + "#getComponentCount(0)", new LayoutManagerGetComponentCountExecutor());
	reg->add(clsName + "#doLayout(0)", new LayoutManagerDoLayoutExecutor());
	reg->add(clsName + "#setMinSize(1)", new LayoutManagerSetMinSizeExecutor());
	reg->add(clsName + "#getMinSize(0)", new LayoutManagerGetMinSizeExecutor());
	reg->add(clsName + "#setFitSize(1)", new LayoutManagerSetFitSizeExecutor());
	reg->add(clsName + "#getFitSize(0)", new LayoutManagerGetFitSizeExecutor());
	reg->add(clsName + "#setMaxSize(1)", new LayoutManagerSetMaxSizeExecutor());
	reg->add(clsName + "#getMaxSize(0)", new LayoutManagerGetMaxSizeExecutor());
	//api.wxgui.LayoutParams
	clsName = "api.wxgui.LayoutParams";
	reg->add(clsName + "#new(0)", new LayoutParamsNewExecutor());
	reg->add(clsName + "#left(0)", new LayoutParamsLeftExecutor());
	reg->add(clsName + "#right(0)", new LayoutParamsRightExecutor());
	reg->add(clsName + "#top(0)", new LayoutParamsTopExecutor());
	reg->add(clsName + "#bottom(0)", new LayoutParamsBottomExecutor());
	reg->add(clsName + "#center(0)", new LayoutParamsCenterExecutor());
	reg->add(clsName + "#border(0)", new LayoutParamsBorderExecutor());
	reg->add(clsName + "#fill(0)", new LayoutParamsFillExecutor());
	//api.wxgui.FlowLayout
	clsName = "api.wxgui.FlowLayout";
	reg->add(clsName + "#newHorizontal(0)", new FlowLayoutNewHorizontalExecutor());
	reg->add(clsName + "#newVertical(0)", new FlowLayoutNewVerticalExecutor());
	//api.wxgui.MenuBar
	clsName = "api.wxgui.MenuBar";
	reg->add(clsName + "#new(0)", new MenuBarNewExecutor());
	reg->add(clsName + "#addMenu(1)", new MenuBarAddMenuExecutor());
	reg->add(clsName + "#removeMenuAt(1)", new MenuBarRemoveMenuAtExecutor());
	reg->add(clsName + "#getMenuCount(0)", new MenuBarGetMenuCountExecutor());
	//api.wxgui.MenuItem
	clsName = "api.wxgui.MenuItem";
	reg->add(clsName + "#new(1)", new MenuItemNewExecutor());
	reg->add(clsName + "#setText(1)", new MenuItemSetTextExecutor());
	reg->add(clsName + "#getText(0)", new MenuItemGetTextExecutor());
	//api.wxgui.Menu
	clsName = "api.wxgui.Menu";
	reg->add(clsName + "#new(1)", new MenuNewExecutor());
	reg->add(clsName + "#addCheckBoxMenuItem(1)", new MenuAddCheckBoxMenuItemExecutor());
	reg->add(clsName + "#addMenu(1)", new MenuAddMenuExecutor());
	reg->add(clsName + "#addMenuItem(1)", new MenuAddMenuItemExecutor());
	reg->add(clsName + "#addSeparator(0)", new MenuAddSeparatorExecutor());
	reg->add(clsName + "#removeSubElementAt(1)", new MenuRemoveSubElementAtExecutor());
	reg->add(clsName + "#getSubElementCount(0)", new MenuGetSubElementCountExecutor());
	//api.wxgui.CheckBoxMenuItem
	clsName = "api.wxgui.CheckBoxMenuItem";
	reg->add(clsName + "#setSelected(1)", new CheckBoxMenuItemSetSelectedExecutor());
	reg->add(clsName + "#isSelected(0)", new CheckBoxMenuItemIsSelectedExecutor());
	//api.wxgui.PaintBox
	clsName = "api.wxgui.PaintBox";
	reg->add(clsName + "#new(1)", new PaintBoxNewExecutor());
	reg->add(clsName + "#start(0)", new PaintBoxStartExecutor());
	reg->add(clsName + "#stop(0)", new PaintBoxStopExecutor());
	reg->add(clsName + "#addPaintListener(1)", new PaintBoxAddPaintListenerExecutor());
	reg->add(clsName + "#removePaintListenerAt(1)", new PaintBoxRemovePaintListenerAtExecutor());
	reg->add(clsName + "#getPaintListenerCount(0)", new PaintBoxGetPaintListenerCountExecutor());
	//api.wxgui.Graphics
	clsName = "api.wxgui.Graphics";
	reg->add(clsName + "#clear(0)", new GraphicsClearExecutor());
	reg->add(clsName + "#drawDot(2)", new GraphicsDrawDotExecutor());
	reg->add(clsName + "#drawEllipse(4)", new GraphicsDrawEllipseExecutor);
	reg->add(clsName + "#drawLine(4)", new GraphicsDrawLineExecutor);
	reg->add(clsName + "#drawRect(4)", new GraphicsDrawRectExecutor());
	reg->add(clsName + "#drawString(3)", new GraphicsDrawStringExecutor());
	reg->add(clsName + "#drawBitmap(3)", new GraphicsDrawBitmapExecutor());
	//api.wxgui.Bitmap
	clsName = "api.wxgui.Bitmap";
	reg->add(clsName + "#load(2)", new BitmapLoadExecutor());
	reg->add(clsName + "#getWidth(0)", new BitmapGetWidthExecutor());
	reg->add(clsName + "#getHeight(0)", new BitmapGetHeightExecutor());
	//api.wxgui.WxUtilities
	clsName = "api.wxgui.WxUtilities";
	reg->add(clsName + "#getKeyState(1)", new WxUtilitiesGetKeyStateExecutor());
	reg->add(clsName + "#isLeftClick(0)", new WxUtilitiesIsLeftClickExecutor());
	reg->add(clsName + "#isMiddleClick(0)", new WxUtilitiesIsMiddleClickExecutor());
	reg->add(clsName + "#isRightClick(0)", new WxUtilitiesIsRightClickExecutor());
	//api.coll.Vector
	clsName = "api.coll.Vector";
	reg->add(clsName + "#new(0)", new VectorNewExecutor());
	reg->add(clsName + "#add(1)", new VectorAddExecutor());
	reg->add(clsName + "#set(2)", new VectorSetExecutor());
	reg->add(clsName + "#insert(2)", new VectorInsertExecutor());
	reg->add(clsName + "#remove(1)", new VectorRemoveExecutor());
	reg->add(clsName + "#removeAt(1)", new VectorRemoveAtExecutor());
	reg->add(clsName + "#get(1)", new VectorGetExecutor());
	reg->add(clsName + "#push(1)", new VectorPushExecutor());
	reg->add(clsName + "#top(0)", new VectorTopExecutor());
	reg->add(clsName + "#back(0)", new VectorPopExecutor());
	reg->add(clsName + "#sort(1)", new VectorSortExecutor());
	reg->add(clsName + "#size(0)", new VectorSizeExecutor());
	//api.System
	clsName = "api.System";
	reg->add(clsName + "#setProperty(2)", new SystemSetPropertyExecutor());
	reg->add(clsName + "#getProperty(1)", new SystemGetPropertyExecutor());
	reg->add(clsName + "#getProperty(2)", new SystemGetProperty2Executor());
	reg->add(clsName + "#defineDynField(3)", new SystemDefineDynFieldExecutor());
	reg->add(clsName + "#defineDynMethod(3)", new SystemDefineDynMethodExecutor());
	reg->add(clsName + "#apply(0)", new SystemApplyExecutor());
	//api.Pattern
	clsName = "api.Pattern";
	reg->add(clsName + "#compile(1)", new PatternCompileExecutor());
	reg->add(clsName + "#matcher(1)", new PatternMatcherExecutor());
	//api.Matcher
	clsName = "api.Matcher";
	reg->add(clsName + "#all(0)", new MatcherAllExecutor());
	reg->add(clsName + "#end(0)", new MatcherEndExecutor());
	reg->add(clsName + "#end(1)", new MatcherEnd2Executor());
	reg->add(clsName + "#find(0)", new MatcherFindExecutor());
	reg->add(clsName + "#find(1)", new MatcherFind2Executor());
	reg->add(clsName + "#group(0)", new MatcherGroupExecutor());
	reg->add(clsName + "#group(1)", new MatcherGroup2Executor());
	reg->add(clsName + "#groupCount(0)", new MatcherGroupCountExecutor());
	reg->add(clsName + "#replaceAll(1)", new MatcherReplaceAllExecutor());
	reg->add(clsName + "#replaceFirst(1)", new MatcherReplaceFirstExecutor());
	reg->add(clsName + "#reset(1)", new MatcherReset2Executor());
	reg->add(clsName + "#reset(0)", new MatcherResetExecutor());
	reg->add(clsName + "#start(0)", new MatcherStartExecutor());
	reg->add(clsName + "#start(1)", new MatcherStart2Executor());
}
//---private method
