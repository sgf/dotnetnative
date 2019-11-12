#pragma once
#include  <memory>
#include "Int32.h"
using namespace std;


namespace System {


	/// <summary>
	/// sizeof(Char)=2字节
	/// Char is the CodeUnit(如果CodePoint 大于一个Char那就会用两个Char表示)
	/// </summary>
	class Char {
	private:
		uint16_t m;
		static constexpr byte IsWhiteSpaceFlag = (byte)0x80;
		static constexpr byte IsUpperCaseLetterFlag = (byte)0x40;
		static constexpr byte IsLowerCaseLetterFlag = (byte)0x20;
		static constexpr byte UnicodeCategoryMask = (byte)0x1F;
		static constexpr byte Latin1CharInfo[] = {
				(byte)0x0E, (byte)0x0E, (byte)0x0E, (byte)0x0E, (byte)0x0E, (byte)0x0E, (byte)0x0E, (byte)0x0E, (byte)0x0E, (byte)0x8E, (byte)0x8E, (byte)0x8E, (byte)0x8E, (byte)0x8E, (byte)0x0E, (byte)0x0E, // U+0000..U+000F
				(byte)0x0E, (byte)0x0E, (byte)0x0E, (byte)0x0E, (byte)0x0E, (byte)0x0E, (byte)0x0E, (byte)0x0E, (byte)0x0E, (byte)0x0E, (byte)0x0E, (byte)0x0E, (byte)0x0E, (byte)0x0E, (byte)0x0E, (byte)0x0E, // U+0010..U+001F
				(byte)0x8B, (byte)0x18, (byte)0x18, (byte)0x18, (byte)0x1A, (byte)0x18, (byte)0x18, (byte)0x18, (byte)0x14, (byte)0x15, (byte)0x18, (byte)0x19, (byte)0x18, (byte)0x13, (byte)0x18, (byte)0x18, // U+0020..U+002F
				(byte)0x08, (byte)0x08, (byte)0x08, (byte)0x08, (byte)0x08, (byte)0x08, (byte)0x08, (byte)0x08, (byte)0x08, (byte)0x08, (byte)0x18, (byte)0x18, (byte)0x19, (byte)0x19, (byte)0x19, (byte)0x18, // U+0030..U+003F
				(byte)0x18, (byte)0x40, (byte)0x40, (byte)0x40, (byte)0x40, (byte)0x40, (byte)0x40, (byte)0x40, (byte)0x40, (byte)0x40, (byte)0x40, (byte)0x40, (byte)0x40, (byte)0x40, (byte)0x40, (byte)0x40, // U+0040..U+004F
				(byte)0x40, (byte)0x40, (byte)0x40, (byte)0x40, (byte)0x40, (byte)0x40, (byte)0x40, (byte)0x40, (byte)0x40, (byte)0x40, (byte)0x40, (byte)0x14, (byte)0x18, (byte)0x15, (byte)0x1B, (byte)0x12, // U+0050..U+005F
				(byte)0x1B, (byte)0x21, (byte)0x21, (byte)0x21, (byte)0x21, (byte)0x21, (byte)0x21, (byte)0x21, (byte)0x21, (byte)0x21, (byte)0x21, (byte)0x21, (byte)0x21, (byte)0x21, (byte)0x21, (byte)0x21, // U+0060..U+006F
				(byte)0x21, (byte)0x21, (byte)0x21, (byte)0x21, (byte)0x21, (byte)0x21, (byte)0x21, (byte)0x21, (byte)0x21, (byte)0x21, (byte)0x21, (byte)0x14, (byte)0x19, (byte)0x15, (byte)0x19, (byte)0x0E, // U+0070..U+007F
				(byte)0x0E, (byte)0x0E, (byte)0x0E, (byte)0x0E, (byte)0x0E, (byte)0x8E, (byte)0x0E, (byte)0x0E, (byte)0x0E, (byte)0x0E, (byte)0x0E, (byte)0x0E, (byte)0x0E, (byte)0x0E, (byte)0x0E, (byte)0x0E, // U+0080..U+008F
				(byte)0x0E, (byte)0x0E, (byte)0x0E, (byte)0x0E, (byte)0x0E, (byte)0x0E, (byte)0x0E, (byte)0x0E, (byte)0x0E, (byte)0x0E, (byte)0x0E, (byte)0x0E, (byte)0x0E, (byte)0x0E, (byte)0x0E, (byte)0x0E, // U+0090..U+009F
				(byte)0x8B, (byte)0x18, (byte)0x1A, (byte)0x1A, (byte)0x1A, (byte)0x1A, (byte)0x1C, (byte)0x1C, (byte)0x1B, (byte)0x1C, (byte)0x21, (byte)0x16, (byte)0x19, (byte)0x13, (byte)0x1C, (byte)0x1B, // U+00A0..U+00AF
				(byte)0x1C, (byte)0x19, (byte)0x0A, (byte)0x0A, (byte)0x1B, (byte)0x21, (byte)0x1C, (byte)0x18, (byte)0x1B, (byte)0x0A, (byte)0x21, (byte)0x17, (byte)0x0A, (byte)0x0A, (byte)0x0A, (byte)0x18, // U+00B0..U+00BF
				(byte)0x40, (byte)0x40, (byte)0x40, (byte)0x40, (byte)0x40, (byte)0x40, (byte)0x40, (byte)0x40, (byte)0x40, (byte)0x40, (byte)0x40, (byte)0x40, (byte)0x40, (byte)0x40, (byte)0x40, (byte)0x40, // U+00C0..U+00CF
				(byte)0x40, (byte)0x40, (byte)0x40, (byte)0x40, (byte)0x40, (byte)0x40, (byte)0x40, (byte)0x19, (byte)0x40, (byte)0x40, (byte)0x40, (byte)0x40, (byte)0x40, (byte)0x40, (byte)0x40, (byte)0x21, // U+00D0..U+00DF
				(byte)0x21, (byte)0x21, (byte)0x21, (byte)0x21, (byte)0x21, (byte)0x21, (byte)0x21, (byte)0x21, (byte)0x21, (byte)0x21, (byte)0x21, (byte)0x21, (byte)0x21, (byte)0x21, (byte)0x21, (byte)0x21, // U+00E0..U+00EF
				(byte)0x21, (byte)0x21, (byte)0x21, (byte)0x21, (byte)0x21, (byte)0x21, (byte)0x21, (byte)0x19, (byte)0x21, (byte)0x21, (byte)0x21, (byte)0x21, (byte)0x21, (byte)0x21, (byte)0x21, (byte)0x21, // U+00F0..U+00FF
		};

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