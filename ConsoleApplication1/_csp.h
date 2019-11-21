#pragma once

//重写取地址操作符
template<class T>
constexpr T* operator &(T& right) {
	return (T*)__builtin_addressof(right);
}



#ifndef  int
#define string String
#define int i32
#define var auto
#define sizeof(exp) ((i32)sizeof(exp))
#endif
