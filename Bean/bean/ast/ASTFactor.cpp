#include "ASTFactor.h"
#include "../env/Null.h"
#include "../env/Object_.h"
#include "../env/gc/Block.h"

//public method---
ASTFactor::ASTFactor() {
}

Object_ * ASTFactor::add(ASTFactorSPtr right) {
	begin();
	Object_* retRef = evalImpl(evalThrow(), right->evalThrow(), [](Object_* lv, Object_* rv) {
		return lv->add(rv);
	});
	end();
	return retRef;
}

Object_ * ASTFactor::sub(ASTFactorSPtr right) {
	begin();
	Object_* retRef = evalImpl(evalThrow(), right->evalThrow(), [](Object_* lv, Object_* rv) {
		return lv->sub(rv);
	});
	end();
	return retRef;
}

Object_ * ASTFactor::mul(ASTFactorSPtr right) {
	begin();
	Object_* retRef = evalImpl(evalThrow(), right->evalThrow(), [](Object_* lv, Object_* rv) {
		return lv->mul(rv);
	});
	end();
	return retRef;
}

Object_ * ASTFactor::div(ASTFactorSPtr right) {
	begin();
	Object_* retRef = evalImpl(evalThrow(), right->evalThrow(), [](Object_* lv, Object_* rv) {
		return lv->div(rv);
	});
	end();
	return retRef;
}

Object_ * ASTFactor::mod(ASTFactorSPtr right) {
	begin();
	Object_* retRef = evalImpl(evalThrow(), right->evalThrow(), [](Object_* lv, Object_* rv) {
		return lv->mod(rv);
	});
	end();
	return retRef;
}

Object_ * ASTFactor::equals(ASTFactorSPtr right) {
	begin();
	Object_* retRef = evalImpl(evalThrow(), right->evalThrow(), [](Object_* lv, Object_* rv) {
		return lv->equals(rv);
	});
	end();
	return retRef;
}

Object_ * ASTFactor::biggest(ASTFactorSPtr right) {
	begin();
	Object_* retRef = evalImpl(evalThrow(), right->evalThrow(), [](Object_* lv, Object_* rv) {
		return lv->biggest(rv);
	});
	end();
	return retRef;
}

Object_ * ASTFactor::e_biggest(ASTFactorSPtr right) {
	begin();
	Object_* retRef = evalImpl(evalThrow(), right->evalThrow(), [](Object_* lv, Object_* rv) {
		return lv->e_biggest(rv);
	});
	end();
	return retRef;
}

Object_ * ASTFactor::smallest(ASTFactorSPtr right) {
	begin();
	Object_* retRef = evalImpl(evalThrow(), right->evalThrow(), [](Object_* lv, Object_* rv) {
		return lv->smallest(rv);
	});
	end();
	return retRef;
}

Object_ * ASTFactor::e_smallest(ASTFactorSPtr right) {
	begin();
	Object_* retRef = evalImpl(evalThrow(), right->evalThrow(), [](Object_* lv, Object_* rv) {
		return lv->e_smallest(rv);
	});
	end();
	return retRef;
}

ClassSPtr ASTFactor::getBaseLine(ClassSPtr classz) {
	return classz;
}

bool ASTFactor::isStaticReceiver() {
	return false;
}

std::string ASTFactor::getStaticClassName() {
	return std::string();
}

void ASTFactor::accept(ASTVisitor * visitor) {
	visitor->enter(SHARED_FROM_THIS(ASTFactor));
	visitor->exit(SHARED_FROM_THIS(ASTFactor));
}
//---public method

//protected method---
Object_ * ASTFactor::evalThrow() {
	return eval();
}

ASTFactor::~ASTFactor() {
}
//---protected method


//private method---
Object_ * ASTFactor::evalImpl(Object_ * lv, Object_ * rv, std::function<Object_*(Object_*, Object_*)> f) {
	if (lv == nullptr ||
		rv == nullptr ||
		thrown()) {
		return Null::getInstance();
	}
	return f(lv, rv);
}

void ASTFactor::begin() {
	Block::pushCurrent();
}

void ASTFactor::end() {
	Block::popCurrent();
}
//---private method
