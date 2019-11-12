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
	public:
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
}