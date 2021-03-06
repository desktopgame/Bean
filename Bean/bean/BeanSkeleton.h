#pragma once
//このヘッダーは Bean.h からのみ
//インクルードしてください。
#ifndef BEAN_BEANSKELETON_H
#define BEAN_BEANSKELETON_H
#include <iostream>
#include <sstream>
#include <string>
#include <boost/filesystem.hpp>
#include "env/ClassLoader.h"
#include "env/CodeBlock.h"
#include "env/Field.h"
#include "env/IncludeManager.h"
#include "env/Null.h"
#include "env/Package.h"
#include "env/Runtime.h"
#include "util/IO.h"
#include "env/gc/Block.h"
#include "env/gc/Heap.h"
#include "env/user/UserSystem.h"

#include "util/Memory.h"
#include "env/native/NativeMethodExecutor.h"
#include "env/native/NativeMethodRegistry.h"
#include "env/native/array/ArrayGetExecutor.h"
#include "env/native/array/ArrayLengthExecutor.h"
#include "env/native/array/ArrayNewExecutor.h"
#include "env/native/array/ArraySetExecutor.h"
#include "env/native/bitmap/BitmapGetHeightExecutor.h"
#include "env/native/bitmap/BitmapGetWidthExecutor.h"
#include "env/native/bitmap/BitmapLoadExecutor.h"
#include "env/native/boolean/BooleanToString.h"
#include "env/native/button/ButtonAddPushListenerExecutor.h"
#include "env/native/button/ButtonGetPushListenerCountExecutor.h"
#include "env/native/button/ButtonGetTextExecutor.h"
#include "env/native/button/ButtonNewExecutor.h"
#include "env/native/button/ButtonRemovePushListenerAtExecutor.h"
#include "env/native/button/ButtonSetTextExecutor.h"
#include "env/native/character/CharacterAsInteger.h"
#include "env/native/character/CharacterOpAddExecutor.h"
#include "env/native/character/CharacterToStringExecutor.h"
#include "env/native/checkboxmenuitem/CheckBoxMenuItemIsSelectedExecutor.h"
#include "env/native/checkboxmenuitem/CheckBoxMenuItemSetSelectedExecutor.h"
#include "env/native/color/ColorNewAExecutor.h"
#include "env/native/color/ColorNewExecutor.h"
#include "env/native/component/ComponentGetBackgroundExecutor.h"
#include "env/native/component/ComponentGetFitSizeExecutor.h"
#include "env/native/component/ComponentGetForegroundExecutor.h"
#include "env/native/component/ComponentGetHeightExecutor.h"
#include "env/native/component/ComponentGetMaxSizeExecutor.h"
#include "env/native/component/ComponentGetMinSizeExecutor.h""
#include "env/native/component/ComponentGetWidthExecutor.h"
#include "env/native/component/ComponentGetXExecutor.h"
#include "env/native/component/ComponentGetYExecutor.h"
#include "env/native/component/ComponentRepaintExecutor.h"
#include "env/native/component/ComponentSetBackgroundExecutor.h"
#include "env/native/component/ComponentSetFitSizeExecutor.h"
#include "env/native/component/ComponentSetForegroundExecutor.h"
#include "env/native/component/ComponentSetHeightExecutor.h"
#include "env/native/component/ComponentSetMaxSizeExecutor.h"
#include "env/native/component/ComponentSetMinSizeExecutor.h"
#include "env/native/component/ComponentSetWidthExecutor.h"
#include "env/native/component/ComponentSetXExecutor.h"
#include "env/native/component/ComponentSetYExecutor.h"
#include "env/native/console/ConsoleReadExecutor.h"
#include "env/native/console/ConsoleReadLineExecutor.h"
#include "env/native/console/ConsoleWriteExecutor.h"
#include "env/native/console/ConsoleWriteLineExecutor.h"
#include "env/native/container/ContainerGetLayoutExecutor.h"
#include "env/native/container/ContainerSetLayoutExecutor.h""
#include "env/native/delegate/DelegateCallExecutor.h"
#include "env/native/delegate/DelegateNewInstanceExecutor.h"
#include "env/native/enumitem/EnumItemGetIndexExecutor.h"
#include "env/native/enumitem/EnumItemGetValueExecutor.h"
#include "env/native/enumitem/EnumItemToStringExecutor.h"
#include "env/native/enum/EnumValueOfExecutor.h"
#include "env/native/enum/EnumValuesExecutor.h"
#include "env/native/file/FileCopyExecutor.h"
#include "env/native/file/FileCreateNewFileExecutor.h"
#include "env/native/file/FileDeleteExecutor.h"
#include "env/native/file/FileExistsExecutor.h"
#include "env/native/file/FileGetChildrenExecutor.h"
#include "env/native/file/FileGetCurrentPathExecutor.h"
#include "env/native/file/FileGetNameExecutor.h"
#include "env/native/file/FileGetParentExecutor.h"
#include "env/native/file/FileGetPathSeparatorCharExecutor.h"
#include "env/native/file/FileIsDirectoryExecutor.h"
#include "env/native/file/FileIsFileExecutor.h"
#include "env/native/file/FileMkdirExecutor.h"
#include "env/native/file/FileReadTextExecutor.h"
#include "env/native/fileptr/FilePtrCloseExecutor.h"
#include "env/native/fileptr/FilePtrOpenExecutor.h"
#include "env/native/fileptr/FilePtrReadExecutor.h"
#include "env/native/file/FileWriteTextExecutor.h"
#include "env/native/flowlayout/FlowLayoutNewHorizontalExecutor.h"
#include "env/native/flowlayout/FlowLayoutNewVerticalExecutor.h"
#include "env/native/frame/FrameCreateStatusBarExecutor.h"
#include "env/native/frame/FrameGetMenuBarExecutor.h"
#include "env/native/frame/FrameGetTitleExecutor.h"
#include "env/native/frame/FrameMainLoopExecutor.h"
#include "env/native/frame/FrameNewExecutor.h"
#include "env/native/frame/FramePackExecutor.h"
#include "env/native/frame/FramePrintStatusExecutor.h"
#include "env/native/frame/FrameSetMenuBarExecutor.h"
#include "env/native/frame/FrameSetTitleExecutor.h"
#include "env/native/graphics/GraphicsClearExecutor.h"
#include "env/native/graphics/GraphicsDrawBitmapExecutor.h"
#include "env/native/graphics/GraphicsDrawDotExecutor.h"
#include "env/native/graphics/GraphicsDrawEllipseExecutor.h"
#include "env/native/graphics/GraphicsDrawLineExecutor.h"
#include "env/native/graphics/GraphicsDrawRectExecutor.h"
#include "env/native/graphics/GraphicsDrawStringExecutor.h"
#include "env/native/label/LabelGetTextExecutor.h"
#include "env/native/label/LabelNewExecutor.h"
#include "env/native/label/LabelSetTextExecutor.h"
#include "env/native/layoutmanager/LayoutManagerAddComponentExecutor.h"
#include "env/native/layoutmanager/LayoutManagerAddSpaceExecutor.h"
#include "env/native/layoutmanager/LayoutManagerAddStretchExecutor.h"
#include "env/native/layoutmanager/LayoutManagerDoLayoutExecutor.h"
#include "env/native/layoutmanager/LayoutManagerGetComponentCountExecutor.h"
#include "env/native/layoutmanager/LayoutManagerGetFitSizeExecutor.h"
#include "env/native/layoutmanager/LayoutManagerGetMaxSizeExecutor.h"
#include "env/native/layoutmanager/LayoutManagerGetMinSizeExecutor.h"
#include "env/native/layoutmanager/LayoutManagerRemoveComponentAtExecutor.h"
#include "env/native/layoutmanager/LayoutManagerSetFitSizeExecutor.h"
#include "env/native/layoutmanager/LayoutManagerSetMaxSizeExecutor.h"
#include "env/native/layoutmanager/LayoutManagerSetMinSizeExecutor.h"
#include "env/native/layoutparams/LayoutParamsBorderExecutor.h"
#include "env/native/layoutparams/LayoutParamsBottomExecutor.h"
#include "env/native/layoutparams/LayoutParamsCenterExecutor.h"
#include "env/native/layoutparams/LayoutParamsFillExecutor.h"
#include "env/native/layoutparams/LayoutParamsLeftExecutor.h"
#include "env/native/layoutparams/LayoutParamsNewExecutor.h"
#include "env/native/layoutparams/LayoutParamsRightExecutor.h"
#include "env/native/layoutparams/LayoutParamsTopExecutor.h"
#include "env/native/matcher/MatcherAllExecutor.h"
#include "env/native/matcher/MatcherEnd2Executor.h"
#include "env/native/matcher/MatcherEndExecutor.h"
#include "env/native/matcher/MatcherFind2Executor.h"
#include "env/native/matcher/MatcherFindExecutor.h"
#include "env/native/matcher/MatcherGroup2Executor.h"
#include "env/native/matcher/MatcherGroupCountExecutor.h"
#include "env/native/matcher/MatcherGroupExecutor.h"
#include "env/native/matcher/MatcherReplaceAllExecutor.h"
#include "env/native/matcher/MatcherReplaceFirstExecutor.h"
#include "env/native/matcher/MatcherReset2Executor.h"
#include "env/native/matcher/MatcherResetExecutor.h"
#include "env/native/matcher/MatcherStart2Executor.h"
#include "env/native/matcher/MatcherStartExecutor.h"
#include "env/native/math/MathAbsExecutor.h"
#include "env/native/math/MathCeilExecutor.h"
#include "env/native/math/MathCosExecutor.h"
#include "env/native/math/MathFloorExecutor.h"
#include "env/native/math/MathMaxExecutor.h"
#include "env/native/math/MathMinExecutor.h"
#include "env/native/math/MathPowExecutor.h"
#include "env/native/math/MathRoundExecutor.h"
#include "env/native/math/MathSinExecutor.h"
#include "env/native/math/MathSqrtExecutor.h"
#include "env/native/math/MathTanExecutor.h"
#include "env/native/math/MathToDegreeExecutor.h"
#include "env/native/math/MathToRadianExecutor.h"
#include "env/native/menu/MenuAddCheckBoxMenuItemExecutor.h"
#include "env/native/menu/MenuAddMenuExecutor.h"
#include "env/native/menu/MenuAddMenuItemExecutor.h"
#include "env/native/menu/MenuAddSeparatorExecutor.h"
#include "env/native/menubar/MenuBarAddMenuExecutor.h"
#include "env/native/menubar/MenuBarGetMenuCountExecutor.h"
#include "env/native/menubar/MenuBarNewExecutor.h"
#include "env/native/menubar/MenuBarRemoveMenuAtExecutor.h"
#include "env/native/menu/MenuGetSubElementCountExecutor.h"
#include "env/native/menuitem/MenuItemGetTextExecutor.h"
#include "env/native/menuitem/MenuItemNewExecutor.h"
#include "env/native/menuitem/MenuItemSetTextExecutor.h"
#include "env/native/menu/MenuNewExecutor.h"
#include "env/native/menu/MenuRemoveSubElementAtExecutor.h"
#include "env/native/mutex/MutexLockExecutor.h"
#include "env/native/mutex/MutexNewExecutor.h"
#include "env/native/mutex/MutexUnlockExecutor.h"
#include "env/native/numeric/NumericAsCharacterExecutor.h"
#include "env/native/numeric/NumericAsDoubleExecutor.h"
#include "env/native/numeric/NumericAsFloatExecutor.h"
#include "env/native/numeric/NumericAsIntegerExecutor.h"
#include "env/native/numeric/NumericAsLongExecutor.h"
#include "env/native/numeric/NumericAsShortExecutor.h"
#include "env/native/numeric/NumericOpAddExecutor.h"
#include "env/native/numeric/NumericOpDivExecutor.h"
#include "env/native/numeric/NumericOpEqualsExecutor.h"
#include "env/native/numeric/NumericOpModExecutor.h"
#include "env/native/numeric/NumericOpMulExecutor.h"
#include "env/native/numeric/NumericOpSubExecutor.h"
#include "env/native/numeric/NumericToStringExecutor.h"
#include "env/native/object/ObjectHashCodeExecutor.h"
#include "env/native/object/ObjectOpAddExecutor.h"
#include "env/native/object/ObjectOpDivExecutor.h"
#include "env/native/object/ObjectOpEqualsExecutor.h"
#include "env/native/object/ObjectOpModExecutor.h"
#include "env/native/object/ObjectOpMulExecutor.h"
#include "env/native/object/ObjectOpSubExecutor.h"
#include "env/native/object/ObjectToStringExecutor.h"
#include "env/native/paintbox/PaintBoxAddPaintListenerExecutor.h"
#include "env/native/paintbox/PaintBoxGetPaintListenerCountExecutor.h"
#include "env/native/paintbox/PaintBoxNewExecutor.h"
#include "env/native/paintbox/PaintBoxRemovePaintListenerAtExecutor.h"
#include "env/native/paintbox/PaintBoxStartExecutor.h"
#include "env/native/paintbox/PaintBoxStopExecutor.h"
#include "env/native/panel/PanelNewExecutor.h"
#include "env/native/pattern/PatternCompileExecutor.h"
#include "env/native/pattern/PatternMatcherExecutor.h"
#include "env/native/scrollpane/ScrollPaneNewExecutor.h"
#include "env/native/string/StringEncodeExecutor.h"
#include "env/native/string/StringEndsWithExecutor.h"
#include "env/native/string/StringIndexOf2Executor.h"
#include "env/native/string/StringIndexOfExecutor.h"
#include "env/native/string/StringInsertExecutor.h"
#include "env/native/string/StringLastIndexOf2Executor.h"
#include "env/native/string/StringLastIndexOfExecutor.h"
#include "env/native/string/StringLengthExecutor.h"
#include "env/native/string/StringOpAddExecutor.h"
#include "env/native/string/StringRemoveExecutor.h"
#include "env/native/string/StringStartsWithExecutor.h"
#include "env/native/string/StringSubstringExecutor.h"
#include "env/native/string/StringToStringExecutor.h"
#include "env/native/system/SystemApplyExecutor.h"
#include "env/native/system/SystemDefineDynFieldExecutor.h"
#include "env/native/system/SystemDefineDynMethodExecutor.h"
#include "env/native/system/SystemGetProperty2Executor.h"
#include "env/native/system/SystemGetPropertyExecutor.h"
#include "env/native/system/SystemSetPropertyExecutor.h"
#include "env/native/textfield/TextFieldCanRedoExecutor.h"
#include "env/native/textfield/TextFieldCanUndoExecutor.h"
#include "env/native/textfield/TextFieldCopyExecutor.h"
#include "env/native/textfield/TextFieldCutExecutor.h"
#include "env/native/textfield/TextFieldGetCaretPositionExecutor.h"
#include "env/native/textfield/TextFieldGetTextExecutor.h"
#include "env/native/textfield/TextFieldInsertExecutor.h"
#include "env/native/textfield/TextFieldNewExecutor.h"
#include "env/native/textfield/TextFieldPasteExecutor.h"
#include "env/native/textfield/TextFieldRedoExecutor.h"
#include "env/native/textfield/TextFieldRemoveExecutor.h"
#include "env/native/textfield/TextFieldSelectAllExecutor.h"
#include "env/native/textfield/TextFieldSelectExecutor.h"
#include "env/native/textfield/TextFieldSetCaretPositionExecutor.h"
#include "env/native/textfield/TextFieldSetTextExecutor.h"
#include "env/native/textfield/TextFieldUndoExecutor.h"
#include "env/native/thread/ThreadGetCurrentOwner.h"
#include "env/native/thread/ThreadGetNameExecutor.h"
#include "env/native/thread/ThreadJoinExecutor.h"
#include "env/native/thread/ThreadNewExecutor.h"
#include "env/native/thread/ThreadSleepExecutor.h"
#include "env/native/thread/ThreadStartExecutor.h"
#include "env/native/vector/VectorAddExecutor.h"
#include "env/native/vector/VectorBackExecutor.h"
#include "env/native/vector/VectorGetExecutor.h"
#include "env/native/vector/VectorInsertExecutor.h"
#include "env/native/vector/VectorNewExecutor.h"
#include "env/native/vector/VectorPopExecutor.h"
#include "env/native/vector/VectorPushExecutor.h"
#include "env/native/vector/VectorRemoveAtExecutor.h"
#include "env/native/vector/VectorRemoveExecutor.h"
#include "env/native/vector/VectorSetExecutor.h"
#include "env/native/vector/VectorSizeExecutor.h"
#include "env/native/vector/VectorSortExecutor.h"
#include "env/native/vector/VectorTopExecutor.h"
#include "env/native/wxutilities/WxUtilitiesGetKeyStateExecutor.h"
#include "env/native/wxutilities/WxUtilitiesIsLeftClickExecutor.h"
#include "env/native/wxutilities/WxUtilitiesIsMiddleClickExecutor.h"
#include "env/native/wxutilities/WxUtilitiesIsRightClickExecutor.h"
#endif // !BEAN_BEANSKELETON_H
