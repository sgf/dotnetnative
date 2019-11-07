#pragma once
#include "Int32.h"
#include <string>
using namespace std;

namespace System {
	class String {
	private:
		const u16string_view& m;
		const i32 length;

	public:
		template<size_t N>
		String(char16_t const (&str)[N]) :length(N - 1), m(str) { }//参数构造函数
		template<size_t N>
		String(char16_t const (&& str)[N]) : length(N - 1), m(str) { }//参数构造函数 接收右值
		String(const char16_t* str) :m(str) { }//参数构造函数 
		String(const u16string&& str) :m(str) {}//Move构造函数 接受右值
		String(const String& str) :m(str.m) {}//拷贝构造函数
		String& operator =(const String& str);//赋值重载
		String& operator =(String&& str);//右值赋值重载


		i32 Length() {
			return (i32)m.length();
		}

	};
}
