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
		const  i32Impl* pimpl;
		//class Impl;
		//std::unique_ptr<Impl> pImpl_;

	public:
		//向内转换
		i32(int32_t i) :m(i) {}
		explicit  i32(uint32_t i) :m((int32_t)i) {}
		explicit  i32(int64_t i) :m((int32_t)i) {}
		explicit  i32(uint64_t i) :m((int32_t)i) {}
		i32(const i32& str);//拷贝构造函数
		i32 operator =(const i32 str);//赋值函数
		//向外转换

		inline i32 operator+(i32 s)const noexcept { return m + s.m; }
		inline i32 operator-(i32 s)const noexcept { return m - s.m; }
		inline i32 operator*(i32 s)const noexcept { return m * s.m; }
		inline i32 operator/(i32 s)const noexcept { return m / s.m; }
		inline bool operator>(i32 r)const noexcept { return m > r.m; }
		inline bool operator>=(i32 r)const noexcept { return m >= r.m; }
		inline bool operator<(i32 r)const noexcept { return m < r.m; }
		inline bool operator<=(i32 r)const noexcept { return m <= r.m; }
		inline i32 operator>>(i32 bit)const noexcept { return  m >> bit; }
		inline i32 operator<<(i32 bit)const noexcept { return  m << bit; }
		inline constexpr operator int32_t() const noexcept { return m; }
		inline constexpr explicit operator uint32_t() const noexcept { return m; }
		inline constexpr explicit operator uint64_t()  const noexcept { return m; }

		i32();
		String& ToString();
		~i32();

	};




}
