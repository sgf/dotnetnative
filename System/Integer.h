#pragma once
#include "pch.h"
#include "String.h"

namespace System {

	class Integer {

	public:
		static const String& ToString(int32_t value, String& format) {

			//if (value >= 0 && format.Length == 0)
			//{
			//	//return UInt32ToDecStr((uint)value, digits: -1);
			//}
			return String{};
		}




		internal static unsafe string UInt32ToDecStr(uint value, int digits)
		{
			int bufferLength = Math.Max(digits, FormattingHelpers.CountDigits(value));

			// For single-digit values that are very common, especially 0 and 1, just return cached strings.
			if (bufferLength == 1)
			{
				return s_singleDigitStringCache[value];
			}

			string result = string.FastAllocateString(bufferLength);
			fixed(char* buffer = result)
			{
				char* p = buffer + bufferLength;
				if (digits <= 1)
				{
					do
					{
						value = Math.DivRem(value, 10, out uint remainder);
						*(--p) = (char)(remainder + '0');
					} while (value != 0);
				}
				else
				{
					p = UInt32ToDecChars(p, value, digits);
				}
				Debug.Assert(p == buffer);
			}
			return result;
		}



	};


}