#include "Int32.private.h"
#include "Int32.h"

using namespace System;

namespace System {


	i32::i32(const i32& str)
	{
	}

	i32::i32(int32_t i) :m(i), pimpl(new i32Impl()) {}
	i32::i32(uint32_t i) : m((int32_t)i), pimpl(new i32Impl()) {}
	i32::i32(int64_t i) : m((int32_t)i), pimpl(new i32Impl()) {}
	i32::i32(uint64_t i) : m((int32_t)i), pimpl(new i32Impl()) {}

	i32 i32::operator=(const i32 org)
	{
		return this->m;
	}

	i32::i32() :pimpl(new i32Impl()) {
	}


	i32::~i32() {

	}

	String& i32::ToString() {
		return pimpl->ToString();
	}


}
