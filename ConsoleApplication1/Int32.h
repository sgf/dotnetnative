#pragma once
#include  <memory>
#include <iostream>
using namespace std;

namespace System {

	class String;
	class i32 {
	private:
		int32_t m;
		class i32Impl;  // int32实现类的前置声明
		//const  i32Impl* pimpl;
		//class Impl;
		//std::unique_ptr<Impl> pImpl_;

	public:


		//向内转换
		i32(int32_t i);
		explicit  i32(uint32_t i);
		explicit  i32(int64_t i);
		explicit  i32(uint64_t i);
		i32(const i32& org);//拷贝构造函数
		i32& operator =(const i32 str);//赋值函数
	   //向外转换

		i32 operator+(i32 s)const noexcept { return m + s.m; }
		i32 operator-(i32 s)const noexcept { return m - s.m; }
		i32 operator*(i32 s)const noexcept { return m * s.m; }
		i32 operator/(i32 s)const noexcept { return m / s.m; }
		bool operator>(i32 r)const noexcept { return m > r.m; }
		bool operator>=(i32 r)const noexcept { return m >= r.m; }
		bool operator<(i32 r)const noexcept { return m < r.m; }
		bool operator<=(i32 r)const noexcept { return m <= r.m; }
		bool operator!=(i32 r)const noexcept { return m != r.m; }
		bool operator==(i32 r)const noexcept { return m == r.m; }
		i32 operator>>(i32 bit)const noexcept { return  m >> bit; }
		i32 operator<<(i32 bit)const noexcept { return  m << bit; }
		constexpr operator int32_t() const noexcept { return m; }
		constexpr explicit operator int16_t() const noexcept { return (int16_t)m; }
		constexpr explicit operator uint16_t() const noexcept { return (uint16_t)m; }
		constexpr explicit operator uint32_t() const noexcept { return (uint32_t)m; }
		constexpr explicit operator uint64_t()  const noexcept { return (uint64_t)m; }

		i32();
		String&& ToString();
		~i32();

	};




}
