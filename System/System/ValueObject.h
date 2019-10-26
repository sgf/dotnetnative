#pragma once
#include "../pch.h"

namespace System {

	template<class T>
	struct ValueObject {

	public:
		String& ToString() {
			return static_cast<T*>(this)->ToString();
		}


		static T& Prase(String& s) {
			return new T{};
		}

		static bool  TryPrase(String& s, T& rlt) {
			return true;

		}

	};

}
