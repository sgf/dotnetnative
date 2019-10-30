#pragma once
#include "pch.h"
#include "core.h"
#include "format.h"
#include "format-inl.h"
#include "String.h"

namespace System {

	class Console {

		template<typename... Args>
		static inline void Write(String& format, Args&& ...args) {
			fmt::print(format, args);
		}

		static inline void Write(String& str) {
			fmt::print("Error: ");
		}

		template<typename... Args>
		static inline void WriteLine(String& format, Args&& ...args) {
			fmt::print(format + Enviroment::NewLine, args);
		}



		static inline void WriteLine(String& str) {
			auto ss = (str + Environment::NewLine);
			fmt::print("asssss");
		}
	};




}