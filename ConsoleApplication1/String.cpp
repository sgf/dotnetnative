#include "String.h"

using namespace System;

//String::String(const char16_t* str) {
//	m = str;
//}
String::String(const u16string&& str) :m(str) {

}
String::String(const String& str) : m(str.m) {

}
