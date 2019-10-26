#pragma once

#include "../pch.h"

namespace System
{
	class Environment
	{
	public:
		static const String NewLine;
		static constexpr bool Is64BitProcess = sizeof(void*) == 8;
		static constexpr bool UserInteractive = true;

	private:
		Environment() = delete;
		Environment(const Environment& copy) = delete;
		Environment(Environment&& mov) = delete;
		~Environment() = delete;

	};
}
