#pragma once
#include "pch.h"


namespace System {


	class i32
	{
	private:
		int32_t m_val;
	public:
		i32(int32_t src) :m_val(src) {}
		~i32();

		i32 operator+(i32 s) { return m_val + s.m_val; }
		i32 operator-(i32 s) { return m_val - s.m_val; }
		i32 operator*(i32 s) { return m_val * s.m_val; }
		i32 operator/(i32 s) { return m_val / s.m_val; }
		i32 operator>(i32 s) { return m_val > s.m_val; }
		i32 operator<(i32 s) { return m_val < s.m_val; }
		constexpr operator int32_t() const noexcept { return m_val; }

		/*String&& ToString() {
			return String(fmt::format(u"", m_val));
		}*/


	};

	i32::~i32()
	{
	}

}
