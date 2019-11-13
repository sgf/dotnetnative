﻿#pragma once
#include  <memory>
#include "UnicodeCategory.h"
#include "Int32.h"
#include "Array.h"
using namespace std;


namespace System {


	template<class T>
	int length(T& arr)
	{
		return sizeof(arr) / sizeof(arr[0]);
	}


	/// <summary>
	/// sizeof(Char)=2字节
	/// Char is the CodeUnit(如果CodePoint 大于一个Char那就会用两个Char表示)
	/// </summary>
	class Char {
	private:
		uint16_t m;
		static constexpr Byte IsWhiteSpaceFlag = 0x80;
		static constexpr Byte IsUpperCaseLetterFlag = 0x40;
		static constexpr Byte IsLowerCaseLetterFlag = 0x20;
		static constexpr Byte UnicodeCategoryMask = 0x1F;
		//static constexpr Array<Byte> Latin1CharInfo = {
		//	0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x8E, 0x8E, 0x8E, 0x8E, 0x8E, 0x0E, 0x0E, // U+0000..U+000F
		//	0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, // U+0010..U+001F
		//	0x8B, 0x18, 0x18, 0x18, 0x1A, 0x18, 0x18, 0x18, 0x14, 0x15, 0x18, 0x19, 0x18, 0x13, 0x18, 0x18, // U+0020..U+002F
		//	0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x18, 0x18, 0x19, 0x19, 0x19, 0x18, // U+0030..U+003F
		//	0x18, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, // U+0040..U+004F
		//	0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x14, 0x18, 0x15, 0x1B, 0x12, // U+0050..U+005F
		//	0x1B, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, // U+0060..U+006F
		//	0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x14, 0x19, 0x15, 0x19, 0x0E, // U+0070..U+007F
		//	0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x8E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, // U+0080..U+008F
		//	0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, // U+0090..U+009F
		//	0x8B, 0x18, 0x1A, 0x1A, 0x1A, 0x1A, 0x1C, 0x1C, 0x1B, 0x1C, 0x21, 0x16, 0x19, 0x13, 0x1C, 0x1B, // U+00A0..U+00AF
		//	0x1C, 0x19, 0x0A, 0x0A, 0x1B, 0x21, 0x1C, 0x18, 0x1B, 0x0A, 0x21, 0x17, 0x0A, 0x0A, 0x0A, 0x18, // U+00B0..U+00BF
		//	0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, // U+00C0..U+00CF
		//	0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x19, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x21, // U+00D0..U+00DF
		//	0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, // U+00E0..U+00EF
		//	0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x19, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, // U+00F0..U+00FF
		//};

	public:
		static const Char MaxValue;
		static const Char MinValue;


		Char() :m(0) {}
		Char(char16_t _char) :m(_char) {}
		Char(uint16_t c) :m(c) {}
		explicit  Char(int32_t i) :m((int32_t)i) {}
		explicit  Char(uint32_t i) :m(i) {}
		explicit  Char(int64_t i) :m((uint16_t)i) {}
		explicit  Char(uint64_t i) :m((uint16_t)i) {}

		Char operator+(const Char s)const noexcept { return (Char)(m + s.m); }
		Char operator-(const Char s)const noexcept { return (Char)(m - s.m); }
		Char operator*(const Char s)const noexcept { return (Char)(m * s.m); }
		Char operator/(const Char s)const noexcept { return (Char)(m / s.m); }
		bool operator>(const Char r)const noexcept { return m > r.m; }
		bool operator>=(const Char r)const noexcept { return m >= r.m; }
		bool operator<(const Char r)const noexcept { return m < r.m; }
		bool operator<=(const Char r)const noexcept { return m <= r.m; }
		bool operator!=(const Char r)const noexcept { return m != r.m; }
		bool operator==(const Char r)const noexcept { return m == r.m; }
		Char operator>>(const i32 bit)const noexcept { return  (Char)(m >> bit); }
		Char operator<<(const i32 bit)const noexcept { return  (Char)(m << bit); }
		constexpr operator int32_t() const noexcept { return m; }
		constexpr explicit operator int16_t() const noexcept { return (int16_t)m; }
		constexpr explicit operator uint16_t() const noexcept { return (uint16_t)m; }
		constexpr explicit operator uint32_t() const noexcept { return (uint32_t)m; }
		constexpr explicit operator uint64_t()  const noexcept { return (uint64_t)m; }

		//Char& operator=(const char c)& {
		//	m = c;
		//	return *this;
		//}
		//Char& operator=(const char32_t c)&;
		//Char& operator=(const Char c)&;

		//Tips:
		//void foo()&;//只能左值call
		//void foo()&&;//只能右值call




	};

	const Char Char::MaxValue = (Char)0xFFFF;
	const Char Char::MinValue = (Char)0x00;
}
