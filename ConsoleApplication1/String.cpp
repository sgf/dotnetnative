#include "String.h"
#include <utility>

using namespace System;
using namespace std;


String& String::operator =(const String& str)//¸³ÖµÖØÔØ
{
	if (this != &str)
		std::swap(String(str).m, this->m);
	return *this;
};

//String::String(const char16_t* str) {
//	m = str;
//}
//String::String(const u16string&& str) :m(str) {
//
//}
//String::String(const String& str) : m(str.m) {
//
//}
