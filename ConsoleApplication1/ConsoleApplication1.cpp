// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "String.h"
#include "Int32.h"
#include "Char.h"
#include "Console.h"
using namespace System;

template<size_t N>
constexpr uint32_t length(char16_t const (&aaaa)[N]) {
	return N - 1;
}

template<size_t N>
String* operator +(char16_t const (&left)[N], Char c) {
	return new String(u"");
}

class Test {
public:
	Test() {
		Console::Write(u"__FUNCTION__");
	}

	~Test() {
		Console::Write(u"释放");
	}
};

auto test1() {
	auto a = Test();
	return a;
}

#ifndef  int
#define string String
#define int i32
#define var auto
#endif

int32_t main()
{
	Console::SetForegroundColor(ConsoleColor::Cyan);
	int i = 32;
	var v = i.ToString();
	Console::Write(v);
	var vvvvvvv = sizeof(Test);
	var vvvv = sizeof(i);
	Console::Write(((i32)vvvv).ToString());
	Console::Write(((i32)sizeof(i32)).ToString());

	auto vvv = test1();


	String  s = u"dddddd";
	Console::Write(s);
	//cu16string_span<> aa = ensure_z(u"dddddd");
	//const char16_t* p = to_string(aa).c_str();
	//WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), p, 6, 0, 0);

	//const Array<Byte> Latin1CharInfo = {
	//	0x0E, 0x0E
	//};

	String str = u"Hello World!\n";
	int32_t i1 = str.Length();
	int64_t i2 = str.Length();
	std::cout << i1 << i2;
	std::cout << str.Length();
	auto SS = u"Hello World!\n";
	//length();
	//String ccc = u"Hello World!\n";

		//std::cout << strlen(ccc);;
		//std::cout << ccc;
	getchar();
}




// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
