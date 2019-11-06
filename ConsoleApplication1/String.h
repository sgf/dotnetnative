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
		String(char16_t const (&str)[N]) :length(N - 1), m(str) {
		}
		String(const char16_t* str) :m(str) {
		}
		String(const u16string&& str);
		String(const String& str);//拷贝构造函数

		String& operator =(const String&& str);//赋值函数


		i32 Length() {
			return (i32)m.length();
		}

	};
}
