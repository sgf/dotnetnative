#pragma once
#include "pch.h"
#include "Char.h"
#include "int32.h"
//#include "GC.h"
#include "Encoding.h"
using namespace System::Text;

namespace System {

	struct String {
	private:
		Char* m_chars;

	public:
		String() {}
		String(const u16string&& s) {
			//auto c = gc::make(Char{});
		}

		String(String& s) {
			//TODO:未实现
		}

		String(Char* chars) {
			//TODO:未实现
		}


		String(const String& str);//拷贝构造函数
		String& operator =(const String& str);//赋值函数


		static String& FromCString(Char* chars);

		/// <summary>
		/// 默认的char 即C++文件种默认的字符串 编码是动态变化的，只能当初 byte数组处理
		/// </summary>
		/// <param name="chars"></param>
		/// <param name="encoding"></param>
		/// <returns></returns>
		static String& From_basic_chars(char* chars, Encoding encoding);

		String(const char16_t* chars) {
			//TODO:未实现
		}

		int32 Length() {

		}


		String operator+(const String& value) const { return u""; }

		const u16string u16string() const noexcept {
			return std::u16string((char16_t*)m_chars);
		}

		const std::u16string utf16() const noexcept {
			return std::u16string((char16_t*)m_chars);
		}




	};
}
