#include "String.h"
#include <utility>

using namespace System;
using namespace std;

//������Copy On Write ����
//�ַ���� �ο�fbstring ��Ϊ ���飬bytes when: small<24  /medium<255 /large>255
//https://www.cnblogs.com/promise6522/archive/2012/06/05/2535530.html

String& String::operator =(const String& str)//��ֵ����
{
	if (this != &str)
		//this->m.copy(String(str).m,



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
