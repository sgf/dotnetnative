#pragma once
#include "Int32.h"
#include "String.h"
#define FMT_STRING_ALIAS 1
#include <fmt/include/fmt/format.h>

namespace System {
	//using namespace fmt;

	class i32::i32Impl {

	public:
		i32Impl() {


		}



		inline static String* ToString(i32 i) {/*
			static_assert(is_integral_v<_Ty>, "_Ty must be integral");
			using _UTy = make_unsigned_t<_Ty>;
			const auto _UVal = static_cast<_UTy>(_Val);
			if (_Val < 0) {
				_RNext = _UIntegral_to_buff(_RNext, 0 - _UVal);
				*--_RNext = '-';
			}
			else {
				_RNext = _UIntegral_to_buff(_RNext, _UVal);
			}

			std::to_wstring()*/
			return new String(u"ddd");
			//return new String(format(fmt(u"{2}"), (int32_t)i));
			//  shared_ptr<String> return make_shared<String>(new String(u"111"));
		}

		~i32Impl() {

		}

		//auto str = new String(u"111");
	};
}
