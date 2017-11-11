#pragma once
#ifndef BEAN_ENV_FIELD_H
#define BEAN_ENV_FIELD_H
#include <functional>
#include <map>
#include <memory>
#include <unordered_map>
#include "Member.h"
class ASTFactor;
class Object_;
class Object_;
/**
 * 値を格納するフィールドです.
 */
class Field : public Member  {
public:
	Field(ClassSPtr classz, Modifier modifier, const std::string& name);
	~Field();

	/**
	 * 指定のオブジェクトのフィールドを格納するための領域を確保します.
	 * @param obj
	 */
	void alloc(Object_* obj);

	/**
	 * 指定のオブジェクトのフィールドを格納するための領域を開放します.
	 * @param obj
	 */
	void free(Object_* obj);

	/**
	 * 値を上書きします.
	 * @param obj
	 * @param value
	 */
	void setValue(Object_* obj, Object_* value);

	/**
	 * 値を返します.
	 * @param obj
	 * @return
	 */
	Object_* const getValue(Object_* obj);

	/**
	 * このフィールドのデフォルト値を設定します.
	 * @param defaultValue
	 */
	void setDefaultValue(std::shared_ptr<ASTFactor> defaultValue);

	/**
	 * このフィールドのデフォルト値を返します.
	 * @return
	 */
	std::shared_ptr<ASTFactor> getDefaultValue() const;

	/**
	 * このフィールドが 無効 になっているなら true を返します.
	 */
	bool isInvalid() const;

	/**
	 * 全ての値に処理します.
	 * @param f
	 */
	void eachAllValues(std::function<void(Object_*, Object_*)> f);

	std::string getLocation() override;

	/**
	 * 全てのフィールドに処理します.
	 * @param f
	 */
	static void eachAllFields(std::function<void(Field*)> f);

	/**
	 * 全ての静的フィールドをマークします.
	 */
	static void markStatics();

	/**
	 * 全ての静的フィールドを探索途中としてマークします.
	 */
	static void paintSearchNow();

	/**
	 * 静的フィールドがGCに回収されるようにします.
	 * このメソッドの影響を受けたフィールドは 無効 状態になります。
	 */
	static void invalidateStatics();
private:
	void staticInit();
	void invalidate();
	static void eachStatics(std::function<void(Field*)> f);
	static std::vector<Field*> staticFields;
	static std::vector<Field*> allFields;
	std::unordered_map<Object_*, Object_*> map;
	Object_* staticRef;
	std::weak_ptr<ASTFactor> defaultValue;
	bool bInvalid;
};
#endif // !BEAN_ENV_FIELD_H
