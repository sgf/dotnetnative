#pragma once
#include "../pch.h"

namespace System
{
	class StringBuilder
	{
	private:
		struct Block
		{
			unique_ptr<Block>       m_nextBlock;
			unique_ptr<uint16_t[]> m_characters;
			int                     m_blockLength;
			int                     m_offset;
			int                     m_count;
		};

	private:
		unique_ptr<Block>       m_blocks;
		Block* m_currentBlock;
		shared_ptr<uint16_t[]> m_string;
		int                     m_length;
		int                     m_capacity;

	private:
		static void CopyBlocks(uint16_t* destination, const int destSize, const StringBuilder& src);
		static unique_ptr<Block> AllocateBlock(const int capacity);

	public:
		StringBuilder();
		StringBuilder(const String& str);
		StringBuilder(const uint16_t* str, const int length);
		StringBuilder(const char* str, const int length);
		StringBuilder(const int capacity);
		StringBuilder(const StringBuilder& copy);
		StringBuilder(StringBuilder&& mov) noexcept;

		StringBuilder& operator=(const StringBuilder& copy);
		StringBuilder& operator=(StringBuilder&& mov) noexcept;
		StringBuilder& operator=(const char* str);
		StringBuilder& operator=(const uint16_t* str);
		StringBuilder& operator=(const String& str);

		uint16_t operator[](const int index) const&;
		uint16_t& operator[](const int index)&;

		String ToString();
		String ToString(const int startIndex, const int length) const;
		int EnsureCapacity(int capacity);
		StringBuilder& Remove(int startIndex, int length);

		StringBuilder& Append(const uint16_t value);
		StringBuilder& Append(const char value);
		StringBuilder& Append(const uint16_t value, int repeatCount);
		StringBuilder& Append(const uint16_t* value, int length);
		StringBuilder& Append(const char* value, int length);
		StringBuilder& Append(const String& value);
		StringBuilder& Append(const StringBuilder& value);

		inline int Capacity() const noexcept { return m_capacity; }
		inline int GetLength() const noexcept { return m_length; }
		void SetLength(const int length);
	};
}
