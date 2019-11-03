#pragma once

#include "pch.h"


namespace System {
	struct uint16
	{
		uint16_t m_val;
	public:
		uint16(uint16_t src) :m_val(src) {

		}

		~uint16();

		uint16 operator+(uint16 s) { return m_val + s.m_val; }
		uint16 operator-(uint16 s) { return m_val - s.m_val; }
		uint16 operator*(uint16 s) { return m_val * s.m_val; }
		uint16 operator/(uint16 s) { return m_val / s.m_val; }
		constexpr operator uint16_t() const noexcept { return m_val; }




		/*	friend String operator+(String s, uint16 c) {
				return a + to_string(c.m_value);
			}

		friend string operator+(uint16 c, string a) {
			return to_string(c.m_value) + a;
		}*/

	private:




	};

	typedef  uint16 ushort;


	uint16::~uint16()
	{
	}
}
