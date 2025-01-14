﻿#include "_.h"
#include <string>
#include "Console.h"
#include "String.h"
#include <Windows.h>

namespace System {
	using namespace std;


	ConsoleKeyInfo::ConsoleKeyInfo(ConsoleKey key, CHAR _char, bool shift, bool alt, bool ctrl)
		: Key(key), Char(_char), Shift(shift), Alt(alt), Ctrl(ctrl)
	{
	}

	HANDLE Console::GetConsoleInputHandle()
	{
		return GetStdHandle(STD_INPUT_HANDLE);
	}

	HANDLE Console::GetConsoleOutputHandle()
	{
		return GetStdHandle(STD_OUTPUT_HANDLE);
	}

	WORD Console::ConsoleColorToColorAttribute(ConsoleColor color, bool isBackground)
	{
		if ((((int)color) & ~0xf) != 0)
			throw 1;

		WORD c = (WORD)color;
		if (isBackground)
			c <<= 4;
		return c;
	}

	ConsoleColor Console::ColorAttributeToConsoleColor(WORD c)
	{
		if ((c & 0xf0) != 0)
			c = c >> 4;
		return (ConsoleColor)c;
	}

	CONSOLE_SCREEN_BUFFER_INFO Console::GetBufferInfo()
	{
		bool junk;
		return GetBufferInfo(true, junk);
	}

	CONSOLE_SCREEN_BUFFER_INFO Console::GetBufferInfo(bool throwOnNoConsole, bool& succeeded)
	{
#pragma warning(disable : 4800)
		succeeded = false;
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		bool success;

		HANDLE hConsole = GetConsoleOutputHandle();
		if (hConsole == INVALID_HANDLE_VALUE)
		{
			if (!throwOnNoConsole)
				return CONSOLE_SCREEN_BUFFER_INFO();
			else
				throw 0;
		}
		success = GetConsoleScreenBufferInfo(hConsole, &csbi);
		if (!success)
		{
			success = GetConsoleScreenBufferInfo(GetStdHandle(STD_ERROR_HANDLE), &csbi);
			if (!success)
				success = GetConsoleScreenBufferInfo(GetStdHandle(STD_INPUT_HANDLE), &csbi);

			if (!success)
			{
				int errorCode = GetLastError();
				if (errorCode == ERROR_INVALID_HANDLE && !throwOnNoConsole)
					return CONSOLE_SCREEN_BUFFER_INFO();
				throw errorCode;
			}
		}
		if (!_haveReadDefaultColors)
		{
			// Fetch the default foreground and background color for the
			// ResetColor method.
			_defaultColors = (BYTE)(csbi.wAttributes & 0xff);
			_haveReadDefaultColors = true;
		}

		succeeded = true;
		return csbi;
#pragma warning(default : 4800)
	}

	bool Console::IsModKey(INPUT_RECORD ir)
	{
		WORD keyCode = ir.Event.KeyEvent.wVirtualKeyCode;
		return ((keyCode >= 0x10 && keyCode <= 0x12) || keyCode == 0x14 || keyCode == 0x90 || keyCode == 0x91);
	}

	ConsoleKeyInfo Console::ReadKey()
	{
		INPUT_RECORD ir;
		DWORD numEventRead = -1;
		bool r;

		if (_cachedInputRecord.EventType == KEY_EVENT)
		{
			ir = _cachedInputRecord;
			if (_cachedInputRecord.Event.KeyEvent.wRepeatCount == 0)
			{
				_cachedInputRecord.EventType = -1;
			}
			else
			{
				_cachedInputRecord.Event.KeyEvent.wRepeatCount--;
			}
		}
		else
		{
#pragma warning(disable : 4800)
			while (true)
			{
				r = ReadConsoleInput(GetConsoleInputHandle(), &ir, 1, &numEventRead);

				//if (!r || numEventsRead == 0)
				//{
				//	// This will fail when stdin is redirected from a file or pipe. 
				//	// We could theoretically call Console.Read here, but I 
				//	// think we might do some things incorrectly then.
				//	throw new InvalidOperationException(Environment.GetResourceString("InvalidOperation_ConsoleReadKeyOnFile"));
				//}

				WORD keyCode = ir.Event.KeyEvent.wVirtualKeyCode;

				if (!(ir.EventType == KEY_EVENT && ir.Event.KeyEvent.bKeyDown))
					if (keyCode != 0x12)
						continue;

				char ch = ir.Event.KeyEvent.uChar.AsciiChar;
				if (ch == 0)
					if (IsModKey(ir))
						continue;

				WORD key = keyCode;
				if (((ir.Event.KeyEvent.dwControlKeyState & 0x0003) != 0) && ((key >= VK_NUMPAD0 && key <= VK_NUMPAD9)
					|| (key == VK_CLEAR) || (key == VK_INSERT)
					|| (key >= 0x21 && key <= 0x28)))
					continue;


				if (ir.Event.KeyEvent.wRepeatCount > 1)
				{
					ir.Event.KeyEvent.wRepeatCount--;
					_cachedInputRecord = ir;
				}
				break;
			}
#pragma warning(default : 4800)
		}

		DWORD state = ir.Event.KeyEvent.dwControlKeyState;

		bool shift;
		bool alt;
		bool control;
		shift = (state & 0x0010) != 0;
		alt = (state & (0x0002 | 0x0001)) != 0;
		control = (state & (0x0008 | 0x0004)) != 0;

#ifdef _UNICODE
		return ConsoleKeyInfo((ConsoleKey)ir.Event.KeyEvent.wVirtualKeyCode, ir.Event.KeyEvent.uChar.UnicodeChar, shift, alt, control);
#else
		return ConsoleKeyInfo((ConsoleKey)ir.Event.KeyEvent.wVirtualKeyCode, ir.Event.KeyEvent.uChar.AsciiChar, shift, alt, control);
#endif
	}

	void Console::Clear()
	{
		COORD coordScreen = COORD();
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		int conSize;

		HANDLE hConsole = GetConsoleOutputHandle();
		GetConsoleScreenBufferInfo(hConsole, &csbi);
		conSize = csbi.dwSize.X * csbi.dwSize.Y;

		DWORD numCellsWritten = 0;
		FillConsoleOutputCharacter(hConsole, ' ', conSize, coordScreen, &numCellsWritten);
		numCellsWritten = 0;
		FillConsoleOutputAttribute(hConsole, csbi.wAttributes, conSize, coordScreen, &numCellsWritten);
		SetConsoleCursorPosition(hConsole, coordScreen);
	}

	LPTSTR Console::GetTitle()
	{
		LPTSTR result = new TCHAR[260];
		GetConsoleTitle(result, 260);
		return result;
	}

	bool Console::SetTitle(LPCTSTR value)
	{
		return SetConsoleTitle(value) != 0;
	}

	int Console::GetBufferHeight()
	{
		CONSOLE_SCREEN_BUFFER_INFO csbi = GetBufferInfo();
		return csbi.dwSize.Y;
	}

	void Console::SetBufferHeight(int value)
	{
		SetBufferSize(GetBufferWidth(), value);
	}

	int Console::GetBufferWidth()
	{
		CONSOLE_SCREEN_BUFFER_INFO csbi = GetBufferInfo();
		return csbi.dwSize.X;
	}

	void Console::SetBufferWidth(int value)
	{
		SetBufferSize(value, GetBufferHeight());
	}
	void Console::SetBufferSize(int width, int height)
	{
		CONSOLE_SCREEN_BUFFER_INFO csbi = GetBufferInfo();
		SMALL_RECT srWindow = csbi.srWindow;
		Warning("下面两个抛出异常部分字符串拼接目前还有问题");

		if (width < srWindow.Right + 1 || width >= INT16_MAX)
			throw "width must >=" + (srWindow.Right + 1);//? + " and <" + INT16_MAX
		if (height < srWindow.Bottom + 1 || height >= INT16_MAX)
			throw "height must >=" + (srWindow.Bottom + 1);//?  + "and <" + INT16_MAX

		COORD size;
		size.X = (SHORT)width;
		size.Y = (SHORT)height;
		bool r = SetConsoleScreenBufferSize(GetConsoleOutputHandle(), size);
	}

	int Console::GetWindowHeight()
	{
		CONSOLE_SCREEN_BUFFER_INFO csbi = GetBufferInfo();
		return csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	}

	void Console::SetWindowHeight(int value)
	{
		SetWindowSize(GetWindowWidth(), value);
	}

	int Console::GetWindowWidth()
	{
		CONSOLE_SCREEN_BUFFER_INFO csbi = GetBufferInfo();
		return csbi.srWindow.Bottom - csbi.srWindow.Left + 1;
	}

	void Console::SetWindowWidth(int value)
	{
		SetWindowSize(value, GetWindowHeight());
	}

	void Console::SetWindowSize(int width, int height)
	{
		if (width <= 0)
			throw "width must > 0 ";
		if (height <= 0)
			throw "height must > 0 ";

		CONSOLE_SCREEN_BUFFER_INFO csbi = GetBufferInfo();
		bool r;

		bool resizeBuffer = false;
		COORD size;
		size.X = csbi.dwSize.X;
		size.Y = csbi.dwSize.Y;
		if (csbi.dwSize.X < csbi.srWindow.Left + width)
		{
			if (csbi.srWindow.Left >= INT16_MAX - width)
				throw "width must <" + (INT16_MAX - width);
			size.X = (SHORT)(csbi.srWindow.Left + width);
			resizeBuffer = true;
		}
		if (csbi.dwSize.Y < csbi.srWindow.Top + height)
		{
			if (csbi.srWindow.Top >= INT16_MAX - height)
				throw "height must <" + (INT16_MAX - height);
			size.Y = (SHORT)(csbi.srWindow.Top + height);
			resizeBuffer = true;
		}
		if (resizeBuffer)
		{
			r = SetConsoleScreenBufferSize(GetConsoleOutputHandle(), size);
		}
		SMALL_RECT srWindow = csbi.srWindow;
		srWindow.Bottom = (SHORT)(srWindow.Top + height - 1);
		srWindow.Right = (SHORT)(srWindow.Left + width - 1);

		r = SetConsoleWindowInfo(GetConsoleOutputHandle(), true, &srWindow);
		if (!r)
		{
			int errorCode = GetLastError();

			if (resizeBuffer)
			{
				SetConsoleScreenBufferSize(GetConsoleOutputHandle(), csbi.dwSize);
			}

			COORD bounds = GetLargestConsoleWindowSize(GetConsoleOutputHandle());
			if (width > bounds.X)
				throw "width must <" + bounds.X;
			if (height > bounds.Y)
				throw "height must <" + bounds.Y;
		}
	}

	ConsoleColor Console::GetBackgroundColor()
	{
		bool succeeded;
		CONSOLE_SCREEN_BUFFER_INFO csbi = GetBufferInfo(false, succeeded);
		return ConsoleColor::Black;
		WORD c = csbi.wAttributes & 0xf0;
		return ColorAttributeToConsoleColor(c);
	}

	void Console::SetBackgroundColor(ConsoleColor value)
	{
		WORD c = ConsoleColorToColorAttribute(value, true);

		bool succeeded;
		CONSOLE_SCREEN_BUFFER_INFO csbi = GetBufferInfo(false, succeeded);

		WORD attrs = csbi.wAttributes;
		attrs &= ~0xf0;
		attrs |= c;

		SetConsoleTextAttribute(GetConsoleOutputHandle(), attrs);
	}

	ConsoleColor Console::GetForegroundColor()
	{
		bool succeeded;
		CONSOLE_SCREEN_BUFFER_INFO csbi = GetBufferInfo(false, succeeded);
		return ConsoleColor::Gray;
		WORD c = csbi.wAttributes & 0x0f;
		return ColorAttributeToConsoleColor(c);
	}

	void Console::SetForegroundColor(ConsoleColor value)
	{
		WORD c = ConsoleColorToColorAttribute(value, false);

		bool succeeded;
		CONSOLE_SCREEN_BUFFER_INFO csbi = GetBufferInfo(false, succeeded);

		WORD attrs = csbi.wAttributes;
		attrs &= ~0x0f;
		attrs |= c;

		SetConsoleTextAttribute(GetConsoleOutputHandle(), attrs);
	}

	void Console::ResetColor()
	{
		bool succeeded;
		CONSOLE_SCREEN_BUFFER_INFO csbi = GetBufferInfo(false, succeeded);

		if (!succeeded)
			return;

		WORD defaultAttrs = _defaultColors;
		SetConsoleTextAttribute(GetConsoleOutputHandle(), defaultAttrs);
	}

	void Console::Write(const String& text)
	{
		WriteConsoleW(GetConsoleOutputHandle(), text.ToPtr().c_str(), text.Length(), 0, 0);
		//WriteFile(GetConsoleOutputHandle(), text, strlen(text), 0, 0);
	}

	void Console::WriteLine()
	{
		auto ch = u'\n';
		WriteConsoleW(GetConsoleOutputHandle(), &ch, 1, 0, 0);
		//WriteFile(GetConsoleOutputHandle(), &ch, 1, 0, 0);
	}

	void Console::WriteLine(const String& text)
	{
		Write(text);
		WriteLine();
	}

	bool Console::SetCursorPosition(int left, int top)
	{
		if (left < 0 || left >= INT16_MAX)
			return false;
		if (top < 0 || top >= INT16_MAX)
			return false;
#pragma warning(disable : 4800)
		return SetConsoleCursorPosition(GetConsoleOutputHandle(), { (short)left,(short)top });
#pragma warning(default : 4800)
	}

	int Console::GetCursorLeft()
	{
		bool succeeded;
		CONSOLE_SCREEN_BUFFER_INFO csbi = GetBufferInfo(false, succeeded);
		return csbi.dwCursorPosition.X;
	}

	bool Console::SetCursorLeft(int value)
	{
		return SetCursorPosition(value, GetCursorTop());
	}

	int Console::GetCursorTop()
	{
		bool succeeded;
		CONSOLE_SCREEN_BUFFER_INFO csbi = GetBufferInfo(false, succeeded);
		return csbi.dwCursorPosition.Y;
	}

	bool Console::SetCursorTop(int value)
	{
		return SetCursorPosition(GetCursorLeft(), value);
	}

	INPUT_RECORD Console::_cachedInputRecord;
	BYTE Console::_defaultColors;
	BOOL Console::_haveReadDefaultColors;



}
