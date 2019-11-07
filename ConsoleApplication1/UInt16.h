#pragma once
#include  <memory>
#include <iostream>
using namespace std;

namespace System {

	class String;
	class ui16 {
	private:
		uint16_t m;
		class ui16Impl;  // int32ʵ�����ǰ������
		const  ui16Impl* pimpl;
		//class Impl;
		//std::unique_ptr<Impl> pImpl_;

	public:

		//����ת��
		ui16(uint16_t i);
		explicit  ui16(uint32_t i);
		explicit  ui16(int64_t i);
		explicit  ui16(uint64_t i);
		ui16(const ui16& str);//�������캯��
		ui16 operator =(const ui16 str);//��ֵ����
		//����ת��

		inline ui16 operator+(ui16 s)const noexcept { return m + s.m; }
		inline ui16 operator-(ui16 s)const noexcept { return m - s.m; }
		inline ui16 operator*(ui16 s)const noexcept { return m * s.m; }
		inline ui16 operator/(ui16 s)const noexcept { return m / s.m; }
		inline bool operator>(ui16 r)const noexcept { return m > r.m; }
		inline bool operator>=(ui16 r)const noexcept { return m >= r.m; }
		inline bool operator<(ui16 r)const noexcept { return m < r.m; }
		inline bool operator<=(ui16 r)const noexcept { return m <= r.m; }
		inline ui16 operator>>(ui16 bit)const noexcept { return  m >> bit; }
		inline ui16 operator<<(ui16 bit)const noexcept { return  m << bit; }
		inline constexpr operator int32_t() const noexcept { return m; }
		inline constexpr explicit operator uint32_t() const noexcept { return m; }
		inline constexpr explicit operator uint64_t()  const noexcept { return m; }

		ui16();
		String& ToString();
		~ui16();

	};




}
