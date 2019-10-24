#include "MemoryUtil.h"

using namespace System;

#ifndef DNN_NO_MEMORY_OVERLOAD

_Ret_notnull_ _Post_writable_byte_size_(size)
_VCRT_ALLOCATOR void* operator new(size_t size)
{
#ifdef _DEBUG
	void* memory = Memory::DebugAlloc(size, __FILE__, __LINE__);
#else
	void* memory = Memory::Alloc(size);
#endif

	if (!memory)
	{
		throw std::bad_alloc();
	}

	return memory;
}

_Ret_maybenull_ _Success_(return != NULL) _Post_writable_byte_size_(size)
_VCRT_ALLOCATOR void* operator new(size_t size, std::nothrow_t const&) noexcept
{
#ifdef _DEBUG
	return Memory::DebugAlloc(size, __FILE__, __LINE__);
#else
	return Memory::Alloc(size);
#endif
}

_Ret_notnull_ _Post_writable_byte_size_(size)
_VCRT_ALLOCATOR void* operator new(size_t size, const char* fileName, int lineNumber)
{
#ifdef _DEBUG
	void* memory = Memory::DebugAlloc(size, fileName, lineNumber);
#else
	void* memory = Memory::Alloc(size);
#endif

	if (!memory)
	{
		throw std::bad_alloc();
	}

	return memory;
}

void operator delete(void* memory)
{
#ifdef _DEBUG
	Memory::DebugFree(memory, __FILE__, __LINE__);
#else
	Memory::Free(memory);
#endif
}

void operator delete(void* memory, const char* fileName, int lineNumber)
{
#ifdef _DEBUG
	Memory::DebugFree(memory, fileName, lineNumber);
#else
	Memory::Free(memory);
#endif
}

#endif
