#ifndef _DOTNETNATIVE_SYSTEM_VALUEOBJECT_H
#define _DOTNETNATIVE_SYSTEM_VALUEOBJECT_H

//#pragma once

namespace System {

	class String;

	template<class T>
	struct ValueObject {

	public:
		String& ToString() {
			return static_cast<T&>(this)->ToString();
		}

		static T Prase(String& s) {
			return static_cast<T&>(this)->Prase(s);
		}

		static bool  TryPrase(String& str, T& outResult) noexcept {
			return static_cast<T&>(this)->TryPrase(str, outResult);
		}
	};

}


#endif
