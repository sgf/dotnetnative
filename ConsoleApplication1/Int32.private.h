#pragma once
#include "String.h"

namespace System {
	class i32::i32Impl {

	public:
		i32Impl() {

		}
		static String& ToString() {
			String str = u"111";
			return str;
		}

		~i32Impl() {

		}

	};
}
