#pragma once
#ifndef BEAN_ENV_MODIFIER_H
#define BEAN_ENV_MODIFIER_H
#include <string>
/**
 * メンバー修飾子.
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
	* 対応するIDを返します.
	* @param text
	* @return
	*/
	static int getId(std::string text);

	/**
	 * public|static を返します.
	 * @return
	 */
	static Modifier publicStatic();

	/**
	* 文字列表現で返します.
	* @return
	*/
	std::string getString() const;

	/**
	* publicならtrue.
	* @return
	*/
	bool isPublic() const;

	/**
	 * privateならtrue.
	 * @return
	 */
	bool isPrivate() const;

	/**
	* protectedならtrue.
	* @return
	*/
	bool isProtected() const;

	/**
	* staticならtrue.
	* @return
	*/
	bool isStatic() const;

	/**
	* finalならtrue.
	* @return
	*/
	bool isFinal() const;

	/**
	* nativeならtrue.
	* @return
	*/
	bool isNative() const;

	/**
	* 同時に定義出来ないアクセス保護レベルが定義されていたらtrue.
	* @return
	*/
	bool isError() const;

	/**
	 * 修飾子の定義が空なら true.
	 * @return
	 */
	bool isBlank() const;

	/**
	* 指定の修飾子を持つならtrue.
	* @param bit
	* @return
	*/
	bool hasFlag(int bit) const;
private:
	int mask;
};
#endif // !BEAN_ENV_MODIFIER