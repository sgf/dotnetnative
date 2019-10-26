#pragma once

#include "../../pch.h"



namespace System::Collections
{
	class HashHelpers
	{
	private:
		HashHelpers() = delete;
		HashHelpers(const HashHelpers& copy) = delete;
		HashHelpers(HashHelpers&& mov) = delete;
		~HashHelpers() = delete;

	public:
		static bool IsPrime(const int candidate);
		static int GetPrime(const int min);
		static int ExpandPrime(const int oldSize);
	};
}
