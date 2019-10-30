#pragma once
#include "pch.h"
#include "Char.h"
#include "int32.h"


namespace System {

	struct String {


	private:

		Char* m_chars;

	public:
		String(const u16string&& s) {

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

		String&& operator+(String& s) { return u""; }


		constexpr u16string& u16string() const noexcept {
			constexpr std::u16string u16s = (char16_t*)m_chars;
			return u16s;
		}

		//code units :


	};
}
