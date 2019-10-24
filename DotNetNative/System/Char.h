#ifndef _DOTNETNATIVE_SYSTEM_CHAR_H_
#define _DOTNETNATIVE_SYSTEM_CHAR_H_

#include "../GlobalDefs.h"
#include "IEquatable.h"
#include "IComparable.h"
#include "UnicodeCategory.h"
#include "Object.h"


namespace System
{
	class Char
		: public Object
		, public IComparable<Char>
		, public IEquatable<Char>
	{
	public:
		static constexpr uint16_t MaxValue = 0xFFFF;
		static constexpr uint16_t MinValue = 0x00;
		static constexpr int UNICODE_PLANE00_END = 0x00ffff;

		// The starting codepoint for Unicode plane 1.  Plane 1 contains 0x010000 ~ 0x01ffff.
		static constexpr int UNICODE_PLANE01_START = 0x10000;

		// The end codepoint for Unicode plane 16.  This is the maximum code point value allowed for Unicode.
		// Plane 16 contains 0x100000 ~ 0x10ffff.
		static constexpr int UNICODE_PLANE16_END = 0x10ffff;

	private:
		const uint16_t m_char;

	public:
		constexpr Char() : m_char(0) {}
		constexpr Char(const uint16_t chr) : m_char(chr) {}
		constexpr Char(const char chr) : m_char(chr) {}
		virtual ~Char() {}

		virtual bool Equals(const Char& obj) const noexcept override;
		virtual String ToString() override;
		virtual int GetHashCode() const override;

		virtual int CompareTo(const Char& chr) const noexcept override { return m_char - chr.m_char; }
		constexpr int CompareTo(const uint16_t chr) const noexcept { return m_char - chr; }
		constexpr operator uint16_t() const noexcept { return m_char; }

		static uint16_t Parse(const String& str);
		static bool TryParse(const String& str, uint16_t& outResult) noexcept;
		static bool IsDigit(const uint16_t c) noexcept;
		static bool IsLetter(uint16_t c) noexcept;
		static bool IsWhiteSpace(const uint16_t c) noexcept;
		static bool IsUpper(const uint16_t c) noexcept;
		static bool IsLower(const uint16_t c) noexcept;
		static bool IsPunctuation(const uint16_t c) noexcept;
		static bool IsLetterOrDigit(const uint16_t c) noexcept;
		static bool IsControl(const uint16_t c) noexcept;
		static bool IsNumber(const uint16_t c) noexcept;
		static bool IsSeparator(const uint16_t c) noexcept;
		static bool IsSurrogate(const uint16_t c) noexcept;
		static bool IsSymbol(const uint16_t c) noexcept;
		static UnicodeCategory GetUnicodeCategory(const uint16_t c) noexcept;
		static double GetNumericValue(const uint16_t c) noexcept;
		static bool IsHighSurrogate(const uint16_t c) noexcept;
		static bool IsLowSurrogate(const uint16_t c) noexcept;
		static bool IsSurrogatePair(const uint16_t highSurrogate, const uint16_t lowSurrogate) noexcept;
		static int ConvertToUtf32(const uint16_t highSurrogate, const uint16_t lowSurrogate) noexcept;

		// ToUpper()
		// ToUpperInvariant()
		// ToLower()
		// ToLowerInvariant()
	};
}


#endif
