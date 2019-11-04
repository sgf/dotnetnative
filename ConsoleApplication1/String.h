#pragma once
#include "Int32.h"

namespace System {
	class String {
	public:
		String() {

		}

		String(const String& str);//拷贝构造函数
		String& operator =(const String& str);//赋值函数

		String(char* src) {

		}

		int32& Length() {
			int32 i32;
			return i32;
		}

	};
}
