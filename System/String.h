#pragma once
#include "pch.h"
#include "Char.h"
#include "int32.h"
//#include "GC.h"
#include "Encoding.h"
using namespace System::Text;

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
			//TODO:δʵ��
		}

		String(Char* chars) {
			//TODO:δʵ��
		}


		String(const String& str);//�������캯��
		String& operator =(const String& str);//��ֵ����


		static String& FromCString(Char* chars);

		/// <summary>
		/// Ĭ�ϵ�char ��C++�ļ���Ĭ�ϵ��ַ��� �����Ƕ�̬�仯�ģ�ֻ�ܵ��� byte���鴦��
		/// </summary>
		/// <param name="chars"></param>
		/// <param name="encoding"></param>
		/// <returns></returns>
		static String& From_basic_chars(char* chars, Encoding encoding);

		String(const char16_t* chars) {
			//TODO:δʵ��
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
