#pragma once
#include  <memory>
#include <iostream>
using namespace std;

namespace System {

	class String;
	class i16 {
	private:
		int16_t m;
		class i16Impl;  // int32实现类的前置声明
		const  i16Impl* pimpl;
		//class Impl;
		//std::unique_ptr<Impl> pImpl_;

	public:

		//向内转换
		i16(int16_t i);
		explicit  i16(uint32_t i);
		explicit  i16(int64_t i);
		explicit  i16(uint64_t i);
		i16(const i16& str);//拷贝构造函数
		i16 operator =(const i16 str);//赋值函数
		//向外转换

		inline i16 operator+(i16 s)const noexcept { return m + s.m; }
		inline i16 operator-(i16 s)const noexcept { return m - s.m; }
		inline i16 operator*(i16 s)const noexcept { return m * s.m; }
		inline i16 operator/(i16 s)const noexcept { return m / s.m; }
		inline bool operator>(i16 r)const noexcept { return m > r.m; }
		inline bool operator>=(i16 r)const noexcept { return m >= r.m; }
		inline bool operator<(i16 r)const noexcept { return m < r.m; }
		inline bool operator<=(i16 r)const noexcept { return m <= r.m; }
		inline i16 operator>>(i16 bit)const noexcept { return  m >> bit; }
		inline i16 operator<<(i16 bit)const noexcept { return  m << bit; }
		inline constexpr operator int32_t() const noexcept { return m; }
		inline constexpr explicit operator uint32_t() const noexcept { return m; }
		inline constexpr explicit operator uint64_t()  const noexcept { return m; }

		i16();
		String& ToString();
		~i16();

	};




}
