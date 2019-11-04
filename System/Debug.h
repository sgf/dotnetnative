#pragma once
#include <cassert>

namespace System {
	class Debug {
	public:
		static inline void Assert(bool b) {
			assert(b);
		}
	};


}
