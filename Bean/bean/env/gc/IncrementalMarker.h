#pragma once
#ifndef BEAN_ENV_GC_INCREMENTALMARKER_H
#define BEAN_ENV_GC_INCREMENTALMARKER_H
#include <memory>
#include <vector>
#include "../Class.h"
class Object_;

class IncrementalMarker;
using IncrementalMarkerSPtr = std::shared_ptr<IncrementalMarker>;
/**
 * �b���I�Ƀ}�[�N��i�߂�N���X�ł�.
 */
class IncrementalMarker : public std::enable_shared_from_this<IncrementalMarker> {
public:
	IncrementalMarker(IncrementalMarkerSPtr parent, Object_* root);
	IncrementalMarker(Object_* root);
	~IncrementalMarker();
	/**
	 * �}�[�N�������Âi�߂܂�.
	 */
	int markTree();

	/**
	 * �ŏ��ɓn���ꂽ�I�u�W�F�N�g���N�_�Ƃ����}�[�N
	 * ��S�Ċ�������� true ��Ԃ��܂��B
	 * @return
	 */
	bool isMarkEnd();
private:
	int markFields();
	int markChildren();
	int limit();
	bool isRecursive(Object_* o);

	bool bIsMarkEnd;
	Object_* root;
	ClassSPtr current;
	std::weak_ptr<IncrementalMarker> parent;
	std::vector<IncrementalMarkerSPtr> children;
};
#endif // !BEAN_ENV_GC_INCREMENTALMARKER_H
