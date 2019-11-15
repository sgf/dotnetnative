#pragma once

namespace System {


#if defined(_MSC_VER)
#define _MSVC
#elif defined(__GNUC__)
#define _GCC
#endif

#ifndef Warning
	//自定义Warning 因为小写估计与windwos内部warning有冲突 因此首字母大写
#define Warning(msg) __pragma(message("custom-msg: "msg))
#elif 
#error 错误 Warning 与内部或者任何引用的库产生了冲突
#endif

}

#include "Interface.h"