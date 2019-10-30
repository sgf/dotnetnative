#pragma once
#include "pch.h"
#include "fmt.h"
#include "String.h"


namespace System {

	class int32
	{
	private:
		int32_t m_val;
	public:
		int32(int32_t src) :m_val(src) {}
		~int32();


		int32 operator+(int32 s) { return m_val + s.m_val; }
		int32 operator-(int32 s) { return m_val - s.m_val; }
		int32 operator*(int32 s) { return m_val * s.m_val; }
		int32 operator/(int32 s) { return m_val / s.m_val; }
		constexpr operator int32_t() const noexcept { return m_val; }

		/*String&& ToString() {
			return String(fmt::format(u"", m_val));
		}*/


	};

	int32::~int32()
	{
	}

}
