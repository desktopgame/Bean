#pragma once
#ifndef BEAN_AST_ASTMETHODINVOCATION_H
#define BEAN_AST_ASTMETHODINVOCATION_H
#include <functional>
#include <string>
#include "ASTFactor.h"
#include "../env/MessageQueue.h"
#include "../threads/Thread.h"
class ASTNode;
class ASTName;
class ClassLoader;
class ASTMethodInvocationByMessage;
class ASTMethodInvocationBySelf;
/**
 * メソッド呼び出し.
 * メソッドチェーンは連結リストによって表されます。
 * ただし、ビジターはトップのメソッドしか訪問出来ません。
 */
class ASTMethodInvocation : public ASTFactor {
public:
	ASTMethodInvocation();
	/**
	 * 呼び出されるメソッドの名前を設定します.
	 * @param name
	 */
	void setName(std::shared_ptr<ASTName> name);

	/**
	 * 呼び出されるメソッドの名前を返します.
	 * @return
	 */
	std::shared_ptr<ASTName> getName() const;

	/**
	 * 呼び出されるメソッドに渡される引数を追加します.
	 * @param factor
	 */
	void addArgument(std::shared_ptr<ASTFactor> factor);

	/**
	 * 指定位置の引数を返します.
	 * @param index
	 * @return
	 */
	std::shared_ptr<ASTFactor> getArgumentAt(int index) const;

	/**
	 * 呼び出されるメソッドに渡される引数の数を返します.
	 * @return
	 */
	int getArgumentCount() const;

	/**
	 * このメソッドが連鎖しているなら連鎖先のオブジェクトを設定します.
	 * @param invocation
	 */
	void setInvocation(std::shared_ptr<ASTMethodInvocation> invocation);

	/**
	 * このメソッドが連鎖しているなら連鎖先のオブジェクトを返します.
	 * @return
	 */
	std::shared_ptr<ASTMethodInvocation> getInvocation() const;

	/**
	 * NoClassErrorを指定のクラスローダーでスローします.
	 * @param cll
	 * @param className
	 */
	static void throwNoClassError(ClassLoaderSPtr cll, std::string className);

	/**
	 * NoMethodErrorを指定のクラスローダーでスローします.
	 * @param cll
	 * @param className
	 * @param methodName
	 * @param argCount
	 */
	static void throwNoMethodError(ClassLoaderSPtr cll, std::string className, std::string methodName, int argCount);

	/**
	 * このインスタンスをASTMethodInvocationByMessageへ変換します.
	 * 変換出来なかった場合はnullptrを返します。
	 * @return
	 */
	virtual std::shared_ptr<ASTMethodInvocationByMessage> asByMessage();

	/**
	 * このインスタンスをASTMethodInvocationBySelfへ変換します.
	 * 変換出来なかった場合はnullptrを返します。
	 * @return
	 */
	virtual std::shared_ptr<ASTMethodInvocationBySelf> asBySelf();

	virtual std::string format() const override;
	virtual void accept(ASTVisitor* visitor) override;

protected:

	/**
	 * 引数を計算して返します.
	 * @param f
	 * @return
	 */
	std::vector<Object_*> getEvalArguments(Function* f);

	/**
	 * 引数を計算して返します.
	 * @param m
	 * @return
	 */
	std::vector<Object_*> getEvalArguments(Method* m);

	std::vector<std::shared_ptr<ASTFactor>> arguments;
	virtual ~ASTMethodInvocation();
private:
	std::vector <Object_*> getEvalArgumentImpl(std::function<void(int)> f);
	std::shared_ptr<ASTName> name;
	std::shared_ptr<ASTMethodInvocation> invocation;

};
#endif // !BEAN_AST_ASTMETHODINVOCATION_H
