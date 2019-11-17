#pragma once
#include "Int32.h"
#include "String.h"

namespace System {
	class i32::i32Impl {

	public:
		i32Impl() {

		}
		inline static String* ToString(i32 i) {
			/*auto str = u"123";
			return str;*/
			return new String(u"aaa");
			//  shared_ptr<String> return make_shared<String>(new String(u"111"));
		}

		~i32Impl() {

		}

		//auto str = new String(u"111");
	};
}
