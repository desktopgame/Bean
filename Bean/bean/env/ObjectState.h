#pragma once
#ifndef BEAN_ENV_OBJECTSTATE_H
#define BEAN_ENV_OBJECTSTATE_H
#include <memory>
#include <vector>
#include "gc/GCProgress.cpp"
class Object_;
class Reference;
class WeakReference;
class ObjectState;
using ObjectStateSPtr = std::shared_ptr<ObjectState>;
using ObjectStateWPtr = std::weak_ptr<ObjectState>;
/**
 * �K�x�[�W�R���N�V�����̍ۂɕK�v�ɂȂ�����܂Ƃ߂��N���X�ł�.
 * GCStrategy�N���X�ɂ���Ďg�p����܂��B
 */
class ObjectState {
public:
	ObjectState(Object_* parent);
	virtual ~ObjectState();

	/**
	 * ���̃I�u�W�F�N�g���t�B�[���h��ϐ��ł͂Ȃ����@�ő������܂�.
	 * �����I�Ɏg�p�����ϐ���GC�ɂ���č폜����Ȃ����߂Ɏg�p����܂��B
	 * @param ref
	 */
	void addStrongReference(Reference* ref);

	/**
	 * �������������܂�.
	 * @param ref
	 * @param isDelete ���̌Ăяo���ŃJ�E���g�� 0 �ɂȂ����Ƃ��폜����Ȃ� true.
	 */
	void removeStrongReference(Reference* ref, bool isDelete);

	/**
	 * �������������܂�.
	 * isDelete �� true �ŌĂяo���܂��B
	 * @param ref
	 */
	void removeStrongReference(Reference* ref);

	/**
	 * �����̐���Ԃ��܂�.
	 * @return
	 */
	int getStrongReferenceCount() const;

	/**
	 * �I�u�W�F�N�g�̍폜���Ď����郊�X�i�[��ǉ����܂�.
	 * @param wRef
	 */
	void addWeakReference(WeakReference* wRef);

	/**
	 * �I�u�W�F�N�g�̍폜���Ď����郊�X�i�[���폜���܂�.
	 * @param wRef
	 */
	void removeWeakReference(WeakReference* wRef);

	/**
	 * �I�u�W�F�N�g�̍폜���Ď����郊�X�i�[�̐���Ԃ��܂�.
	 * @param wRef
	 */
	int getWeakReferenceCount() const;

	/**
	 * �}�[�N��Ԃ�ݒ肵�܂�.
	 * @param bMarked
	 */
	void setMarked(bool bMarked);

	/**
	 * �}�[�N��Ԃ�Ԃ��܂�.
	 */
	bool isMarked() const;

	/**
	 * ���̃I�u�W�F�N�g�̃����N��ݒ肵�܂�.
	 * (a + b) + c �̂悤�Ȏ������߂���Ƃ��A
	 * (a + b) ���v�Z�����Ƃ��ɂ��̌��ʂ͕ϐ��֊i�[����܂���B
	 *
	 * �ϐ��Ɋi�[���ꂽ�I�u�W�F�N�g�̓��[�g����H�邱�Ƃ��o����̂ň��S�ł����A
	 * ���̏ꍇ�ł� (a + b) �̌��ʂ͊i�[����܂���B
	 * �܂��A�V���ȃI�u�W�F�N�g�����蓖�Ă����GC�������\��������̂ŁA
	 * ���� c �Ƃ̉��Z�ŕs���ȃ|�C���^�փA�N�Z�X����\��������܂��B
	 *
	 * ���̃����N�͂��̂悤�Ȏ��K�w�̒��Ō��݂ǂꂮ�炢�[���Ƃ���ɂ��邩�𔻕ʂ��邽�߂Ɏg�p����܂��B
	 * ���̃����N�� 0 ���傫���ꍇ�AGC�̑Ώۂɂ͂Ȃ�܂���B
	 * @param rank
	 */
	void setRank(int rank);

	/**
	 * ���̃I�u�W�F�N�g�̃����N��Ԃ��܂�.
	 * @return
	 */
	int getRank() const;

	/**
	 * �����ݒ肵�܂�.
	 * @param age
	 */
	void setAge(int age);

	/**
	 * �����Ԃ��܂�.
	 * @return
	 */
	int getAge() const;

	/**
	 * �C���N�������^��GC�Ŏg�p����܂�.
	 * �}�[�N�̐i���󋵂�\���܂�.
	 * @param progress
	 */
	void setProgress(GCProgress progress);

	/**
	 * �C���N�������^��GC�Ŏg�p����܂�.
	 * @return
	 */
	GCProgress getProgress() const;

	/**
	 * �f�o�b�O�p�̃��\�b�h.
	 * @return
	 */
	std::string getProgressStr() const;

	/**
	 * �I�u�W�F�N�g�̍폜�����X�i�[�֒ʒm���܂�.
	 * ���̃��\�b�h�� Object_ ����̂݌Ăяo�����悤�ɂ��Ă��������B
	 * @param obj
	 */
	virtual void onDelete(Object_* obj);
private:
	Object_* parent;
	bool marked;
	bool notify;
	int rank;
	int age;
	int mutator;
	bool bIsField;
	GCProgress progress;
	std::vector<Reference*> strongReferences;
	std::vector<WeakReference*> weakReferences;
};
#endif // !BEAN_ENV_OBJECTSTATE_H
