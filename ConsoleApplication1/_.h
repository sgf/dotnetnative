#pragma once

namespace System {


#if defined(_MSC_VER)
#define _MSVC
#elif defined(__GNUC__)
#define _GCC
#endif

#ifndef Warning
	//�Զ���Warning ��ΪСд������windwos�ڲ�warning�г�ͻ �������ĸ��д
#define Warning(msg) __pragma(message("custom-msg: "msg))
#elif 
#error ���� Warning ���ڲ������κ����õĿ�����˳�ͻ
#endif

}

#include "Interface.h"