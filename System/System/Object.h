#pragma once
#include "Object.h"

namespace System
{
	class String;

	class Object
	{
	public:
		virtual ~Object() {}

		virtual bool Equals(const Object& obj) const noexcept;
		virtual String ToString();
		virtual int GetHashCode() const;

		template <typename T>
		static String ToString(T& obj);

		template <typename T>
		static int GetHashCode(const T& obj);
	};


}
