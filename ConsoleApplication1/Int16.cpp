#include "Int16.h"
#include "Int16.private.h"

using namespace System;

namespace System {


	i16::i16(const i16& str)
	{
	}

	i16::i16(int16_t i) :m(i), pimpl(new i16Impl()) {}
	i16::i16(uint32_t i) : m((int32_t)i), pimpl(new i16Impl()) {}
	i16::i16(int64_t i) : m((int32_t)i), pimpl(new i16Impl()) {}
	i16::i16(uint64_t i) : m((int32_t)i), pimpl(new i16Impl()) {}

	i16 i16::operator=(const i16 org)
	{
		return this->m;
	}

	i16::i16() :pimpl(new i16Impl()) {
	}


	i16::~i16() {

	}

	String& i16::ToString() {
		return pimpl->ToString();
	}


}
