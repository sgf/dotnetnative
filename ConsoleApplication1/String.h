#pragma once
#include "Int32.h"
#include <string>
#include <gsl/string_span>

namespace System {
	using namespace std;
	using namespace gsl;

	/// <summary>
	/// 大型字符串
	/// </summary>
	struct smallString {
	private:
		std::byte length;

	public:
		const inline static i32 smallMaxSize = 25;
		const inline static i32 mediumMaxSize = 255;
		const inline static i32 largeMaxSize = 255;



		i32 Lenght() {

		}
		i32 size;

		smallString() {

		}


	};


	template<class T_CHAR_TYPE>
	struct StrP {
	private:
		T_CHAR_TYPE* Ptr;
		i32 Len;
	public:
		StrP(T_CHAR_TYPE* p, i32 len) {
			Ptr = p;
			Len = len;
		}
	};

	class String {
	private:
		cu16string_span<> m;
		//array<char16_t, N> aaa;
		const i32 length;

	public:
		String() :m(ensure_z(u"")) {
		}
		template<size_t N>
		String(const char16_t(&str)[N]) : length(N - 1), m(ensure_z(str)) { }//参数构造函数
		//template<size_t N>
		//String(const char16_t(&& str)[N]) : length(N - 1), m(str) { }//参数构造函数 接收右值
		//String(const char16_t* str) :m(ensure_z(str)) {} //参数构造函数 
		String(const u16string&& str) :m(str) {}//Move构造函数 接受右值
		String(const String& str) :m(str.m) {}//拷贝构造函数
		String& operator =(const String& str);//赋值重载
		String& operator =(String&& str);//右值赋值重载

		//length_bytes/length/size/size_bytes
		const i32 Length() const {
			return (i32)m.length();
		}

		/// <summary>
		/// T_CHAR_TYPE char16_t/char32_t/wchar_t/unsigned short/char/char8_t
		/// </summary>
		template<class T_CHAR_TYPE>
		const StrP<T_CHAR_TYPE> ToPtr() {
			return new StrP<T_CHAR_TYPE>(&this->m.cbegin());
		}

		const char16_t* ToPtr() const {
			return to_string(m).c_str();
		}

		/// <summary>
		/// char16_t/char32_t/wchar_t/unsigned short/char/char8_t
		/// </summary>
		template<class char_T>
		static const i32 Length(const char_T* str) {
			return char_traits<char_T>::length(str);
		}



	};
}
