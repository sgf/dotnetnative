#pragma once
#include "pch.h"
#include "Char.h"
#include "int32.h"
//#include "GC.h"


namespace System {

	struct String {
	private:
		Char* m_chars;

	public:
		String() {}
		String(const u16string&& s) {
			//auto c = gc::make(Char{});
		}

		String(String& s) {
			//TODO:未实现
		}

		String(Char* chars) {
			//TODO:未实现
		}

		String(const char16_t* chars) {
			//TODO:未实现
		}

		int32 Length() {

		}


		String operator+(const String& value) const { return u""; }

		const u16string u16string() const noexcept {
			return std::u16string((char16_t*)m_chars);
		}

		const std::u16string utf16() const noexcept {
			return std::u16string((char16_t*)m_chars);
		}




	};
}
