#pragma once

#include "../pch.h"

namespace System
{
	// Due to the vtable pointer a Byte is much larger than a byte
	class Byte
		: public Object
		, public IComparable<Byte>
		, public IEquatable<Byte>
	{
	private:
		uint8_t m_byte;

	public:
		constexpr Byte() : m_byte(0) {}
		constexpr Byte(const uint8_t byt) : m_byte(byt) {}
		virtual ~Byte() {}

		virtual bool Equals(const Byte& obj) const noexcept override;
		virtual String ToString() override;
		virtual int GetHashCode() const override;

		virtual int CompareTo(const Byte& byt) const noexcept override { return m_byte - byt.m_byte; }

		constexpr operator int8_t() const noexcept { return m_byte; }

		//static int8_t Parse(const String &str);
		//static bool TryParse(const String &str, int8_t &outResult) noexcept;
	};
}
