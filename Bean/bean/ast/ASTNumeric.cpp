#include "ASTNumeric.h"
#include <functional>
#include <boost/lexical_cast.hpp>
#include "../env/Numeric.h"
#include "../env/Object_.h"
#include "../util/Memory.h"
#include "../env/gc/Block.h"
#include "../env/gc/GCLock.h"
#include "../env/gc/Heap.h"

//public method---
ASTNumeric::ASTNumeric(short val) {
	this->u.s_val = val;
	init(NumberType::Short);
}

ASTNumeric::ASTNumeric(int val) {
	this->u.i_val = val;
	init(NumberType::Int);
}

ASTNumeric::ASTNumeric(long val) {
	this->u.l_val = val;
	init(NumberType::Long);
}

ASTNumeric::ASTNumeric(float val) {
	this->u.f_val = val;
	init(NumberType::Float);
}

ASTNumeric::ASTNumeric(double val) {
	this->u.d_val = val;
	init(NumberType::Double);
}

ASTNumeric::~ASTNumeric() {
	if (n != NULL) {
		n->getState()->removeStrongReference(this);
	}
}

BString ASTNumeric::getSource() const {
	return this->source;
}

Object_ * const ASTNumeric::getValue() {
	GCLock gcLock = GCLock();
	//
	//クラスローディングより先にNumericのコンストラクタが呼ばれると、
	//その時点では数値型クラス(Short,Integer...)がロードされていないので、
	//Object_#classzにnullが設定されてしまいます。
	//なので遅延初期化しています。
	if (this->n == nullptr) {
		getValueImpl();
		//ASTNumericがそれ単体で式を成すとき、
		//GCのときに削除されてしまうので、
		//このあとさらにこのインスタンスによって二重開放されるのを避ける
		n->getState()->addStrongReference(this);
	}
	return this->n;
}

Object_ * ASTNumeric::eval() {
	return getValue();
}

std::string ASTNumeric::format() const {
	switch (this->type) {
		case NumberType::Short: 
			return std::to_string(this->u.s_val);
		case NumberType::Int:
			return std::to_string(this->u.i_val);
		case NumberType::Long:
			return std::to_string(this->u.l_val);
		case NumberType::Float:
			return std::to_string(this->u.f_val);
		case NumberType::Double:
			return std::to_string(this->u.d_val);
	}
}
IMPL_MAKE_SHARED_1_CPP(ASTNumeric, short)
IMPL_MAKE_SHARED_1_CPP(ASTNumeric, int)
IMPL_MAKE_SHARED_1_CPP(ASTNumeric, long)
IMPL_MAKE_SHARED_1_CPP(ASTNumeric, float)
IMPL_MAKE_SHARED_1_CPP(ASTNumeric, double)
//---public method


//private method---
void ASTNumeric::init(NumberType nt) {
	this->type = nt;
	this->data_initialized = true;
	this->n = NULL;
}

void ASTNumeric::getValueImpl() {
	//lex
	if (!data_initialized) {
		return;
	}
	switch (type) {
		case NumberType::Short:
			this->n = Numeric::newShort(u.s_val);
			break;
		case NumberType::Int:
			this->n = Numeric::newInteger(u.i_val);
			break;
		case NumberType::Long:
			this->n = Numeric::newLong(u.l_val);
			break;
		case NumberType::Float:
			this->n = Numeric::newFloat(u.f_val);
			break;
		case NumberType::Double:
			this->n = Numeric::newDouble(u.d_val);
			break;
	}
}
//---private method
