#pragma once
#ifndef BEAN_ENV_GC_GCSTRATEGY_H
#define BEAN_ENV_GC_GCSTRATEGY_H
#include "Heap.h"
/**
 * Heap�ɒ~�ς��ꂽ�������[���ǂ̂悤�ɑ|�����邩���`����C���^�[�t�F�C�X�ł�.
 *
 * ObjectState��GC�̂��߂̃v���p�e�B�����J���܂����A
 * GCStrategy�̎����ɂ���Ă͎g�p����܂���B
 * �Ⴆ��IncrementalGC�ȊO�ł�GCProgress�͎g�p����܂���B
 */
class GCStrategy {
public:
	GCStrategy();
	virtual ~GCStrategy() = 0;
	/**
	 * �V���ȎQ�Ƃ����������ƌĂ΂�܂�.
	 * @param item
	 */
	virtual void handleNew(Object_* const item);

	/**
	 * ���C�g�o���A�ɂ���ăI�u�W�F�N�g���C�������ƌĂ΂�܂�.
	 * @param item
	 */
	virtual void handleWriteBarrier(Object_* const item);

	/**
	 * �K�x�[�W�R���N�V���������s���܂�.
	 * @param heap
	 */
	virtual void miniGC(Heap* const heap) = 0;

	/**
	 * �K�x�[�W�R���N�V���������s���܂�.
	 * @param heap
	 */
	virtual void fullGC(Heap* const heap) = 0;
};
#endif // !BEAN_ENV_GC_GCSTRATEGY_H
