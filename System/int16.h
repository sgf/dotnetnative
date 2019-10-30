#pragma once
#include "pch.h"


namespace System {
	struct int16
	{
		int16_t m_val;
	public:
		int16(int16_t src) :m_val(src) {

		}

		~int16();

		int16 operator+(int16 s) { return m_val + s.m_val; }
		int16 operator-(int16 s) { return m_val - s.m_val; }
		int16 operator*(int16 s) { return m_val * s.m_val; }
		int16 operator/(int16 s) { return m_val / s.m_val; }
		constexpr operator int16_t() const noexcept { return m_val; }

		/*	friend String operator+(String s, int16 c) {
				return a + to_string(c.m_value);
			}

		friend string operator+(int16 c, string a) {
			return to_string(c.m_value) + a;
		}*/

	private:




	};


	int16::~int16()
	{
	}
}


