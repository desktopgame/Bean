#pragma once
#ifndef BEAN_ENV_MODIFIER_H
#define BEAN_ENV_MODIFIER_H
#include <string>
/**
 * �����o�[�C���q.
 */
class Modifier {
public:
	static const int PUBLIC;
	static const int PRIVATE;
	static const int PROTECTED;
	static const int STATIC;
	static const int FINAL;
	static const int NATIVE;
	static const int BLANK;

	Modifier(int mask);
	Modifier();
	Modifier(Modifier mod, int mask);
	~Modifier();
	/**
	* �Ή�����ID��Ԃ��܂�.
	* @param text
	* @return
	*/
	static int getId(std::string text);

	/**
	 * public|static ��Ԃ��܂�.
	 * @return
	 */
	static Modifier publicStatic();

	/**
	* ������\���ŕԂ��܂�.
	* @return
	*/
	std::string getString() const;

	/**
	* public�Ȃ�true.
	* @return
	*/
	bool isPublic() const;

	/**
	 * private�Ȃ�true.
	 * @return
	 */
	bool isPrivate() const;

	/**
	* protected�Ȃ�true.
	* @return
	*/
	bool isProtected() const;

	/**
	* static�Ȃ�true.
	* @return
	*/
	bool isStatic() const;

	/**
	* final�Ȃ�true.
	* @return
	*/
	bool isFinal() const;

	/**
	* native�Ȃ�true.
	* @return
	*/
	bool isNative() const;

	/**
	* �����ɒ�`�o���Ȃ��A�N�Z�X�ی샌�x������`����Ă�����true.
	* @return
	*/
	bool isError() const;

	/**
	 * �C���q�̒�`����Ȃ� true.
	 * @return
	 */
	bool isBlank() const;

	/**
	* �w��̏C���q�����Ȃ�true.
	* @param bit
	* @return
	*/
	bool hasFlag(int bit) const;
private:
	int mask;
};
#endif // !BEAN_ENV_MODIFIER