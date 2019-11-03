#pragma once
#include "pch.h"
#include "String.h"


namespace System {


	class Environment
	{
	public:
		static const String& NewLine;
		static constexpr bool Is64BitProcess = sizeof(void*) == 8;
		static constexpr bool UserInteractive = true;
		Environment(const Environment& copy) = delete;
		Environment(Environment&& mov) = delete;
		~Environment() = delete;

	private:

	};

	const String& Environment::NewLine = u"\r\n";



}