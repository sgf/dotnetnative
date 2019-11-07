#pragma once
#include "String.h"

namespace System {
	class i32::i32Impl {

	public:
		i32Impl() {

		}
		static String ToString() {
			auto str = u"123";
			return str;
			//  shared_ptr<String> return make_shared<String>(new String(u"111"));
		}

		~i32Impl() {

		}

		//auto str = new String(u"111");
	};
}
