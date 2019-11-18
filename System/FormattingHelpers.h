#pragma once
#include "STD.h"
#include "Self.h"

namespace System {
	class FormattingHelpers {
	public:
		static int32_t CountDigits(uint64_t value)
		{
			int32_t digits = 1;
			uint32_t part;
			if (value >= 10000000)
			{
				if (value >= 100000000000000)
				{
					part = (uint32_t)(value / 100000000000000);
					digits += 14;
				}
				else
				{
					part = (uint32_t)(value / 10000000);
					digits += 7;
				}
			}
			else
			{
				part = (uint32_t)value;
			}

			if (part < 10)
			{
				// no-op
			}
			else if (part < 100)
			{
				digits += 1;
			}
			else if (part < 1000)
			{
				digits += 2;
			}
			else if (part < 10000)
			{
				digits += 3;
			}
			else if (part < 100000)
			{
				digits += 4;
			}
			else if (part < 1000000)
			{
				digits += 5;
			}
			else
			{
				Debug::Assert(part < 10000000);
				digits += 6;
			}

			return digits;
		}

		static int32_t CountDigits(uint32_t value)
		{
			int32_t digits = 1;
			if (value >= 100000)
			{
				value = value / 100000;
				digits += 5;
			}

			if (value < 10)
			{
				// no-op
			}
			else if (value < 100)
			{
				digits += 1;
			}
			else if (value < 1000)
			{
				digits += 2;
			}
			else if (value < 10000)
			{
				digits += 3;
			}
			else
			{
				Debug::Assert(value < 100000);
				digits += 4;
			}

			return digits;
		}

		static int32_t CountHexDigits(uint64_t value)
		{
			return (64 - BitOperations.LeadingZeroCount(value | 1) + 3) >> 2;
		}

		// Counts the number of trailing '0' digits in a decimal number.
		// e.g., value =      0 => retVal = 0, valueWithoutTrailingZeros = 0
		//       value =   1234 => retVal = 0, valueWithoutTrailingZeros = 1234
		//       value = 320900 => retVal = 2, valueWithoutTrailingZeros = 3209
		static int32_t CountDecimalTrailingZeros(uint32_t value, uint32_t& valueWithoutTrailingZeros)
		{
			int32_t zeroCount = 0;
			if (value != 0)
			{
				while (true)
				{
					uint32_t temp = value / 10;
					if (value != (temp * 10))
					{
						break;
					}

					value = temp;
					zeroCount++;
				}
			}
			valueWithoutTrailingZeros = value;
			return zeroCount;
		}




	};
}
