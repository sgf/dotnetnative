#include "Int32.private.h"
using namespace System;

namespace System {



	i32::i32(int32_t i) : m(i) {}
	i32::i32(uint32_t i) : m((int32_t)i) {}
	i32::i32(int64_t i) : m((int32_t)i) {}
	i32::i32(uint64_t i) : m((int32_t)i) {}
	i32::i32(const i32& org) : m(org) {}//拷贝构造函数
	inline i32& i32::operator=(const i32 org) //赋值函数
	{
		m = org.m;
		return *this;
	}

	i32::i32() {
	}


	i32::~i32() {

	}

	String&& i32::ToString() {
		return std::move(*i32Impl::ToString(*this));
	}


}
