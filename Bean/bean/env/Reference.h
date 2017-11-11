#pragma once
#ifndef BEAN_ENV_REFERENCE_H
#define BEAN_ENV_REFERENCE_H
/**
 * ガベージコレクションの対象外となるオブジェクトを監視するクラス.
 */
class Reference {
public:
	Reference();
	virtual ~Reference();
};
#endif // !BEAN_ENV_REFERENCE_H
