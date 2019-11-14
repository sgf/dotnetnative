#pragma once
#include "_.h"
#include "Int32.h"

namespace System
{

	class String;

	/// <summary>A Static class for command line window operations.</summary>
	class Console abstract
	{
	public:
		/// <summary>Write to the command line window.</summary>
		/// <param name="string">Content to write.</param>
		/// <param name="length">Size of the content in wchar_t. The zero terminator is not included.</param>
		static void Write(const wchar_t* string, i32 length);

		/// <summary>Write to the command line window.</summary>
		/// <param name="string">Content to write.</param>
		static void Write(const wchar_t* string);

		/// <summary>Write to the command line window.</summary>
		/// <param name="string">Content to write.</param>
		static void Write(const String& string);

		/// <summary>Write to the command line window with a CRLF.</summary>
		/// <param name="string">Content to write.</param>
		static void WriteLine(const String& string);

		/// <summary>Read from the command line window.</summary>
		/// <returns>The whole line read from the command line window.</returns>
		static String Read();

		static void SetColor(bool red, bool green, bool blue, bool light);
		static void SetTitle(const String& string);
	};


}
