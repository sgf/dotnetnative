#pragma once
#include "pch.h"
#include "core.h"
#include "format.h"
#include "format-inl.h"
#include "String.h"

namespace System {

	class Console {

		//template<typename... Args>
		//static inline void Write(String& format, Args&& ...args) {
		//	fmt::print(format, args);
		//}

		//static inline void Write(String& str) {
		//	fmt::print("Error: ");
		//}

		//template<typename... Args>
		//static inline void WriteLine(String& format, Args&& ...args) {
		//	fmt::print(format + Enviroment::NewLine, args);
		//}

		inline static void WriteLine(const String& str) {
			//const auto& nl = Environment::NewLine;
			//auto ss = (str + nl);//care
			//String ss = u"123{0}";
			return;
		}
	};




}