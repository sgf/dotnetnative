﻿#pragma once

#include "../../pch.h"


namespace System
{
	namespace Collections
	{
		template <typename T>
		class IReadOnlyCollection
			: public virtual IEnumerable<T>
		{
		protected:
			IReadOnlyCollection() = default;
			IReadOnlyCollection(const IReadOnlyCollection<T>& copy) = default;
			IReadOnlyCollection(IReadOnlyCollection<T>&& mov) noexcept = default;

		public:
			virtual ~IReadOnlyCollection() {}

			virtual int64_t Count() const = 0;
		};
	}
}