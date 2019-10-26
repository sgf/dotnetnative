#pragma once

#include "../../pch.h"

namespace System
{
	namespace Collections
	{
		template <typename T>
		class IReadOnlyList
			: public virtual IReadOnlyCollection<T>
		{
		protected:
			IReadOnlyList() = default;
			IReadOnlyList(const IReadOnlyList<T>& copy) = default;
			IReadOnlyList(IReadOnlyList<T>&& mov) noexcept = default;

		public:
			virtual ~IReadOnlyList() {}

			virtual const T& operator[](const int64_t index) const& = 0;
		};
	}
}
