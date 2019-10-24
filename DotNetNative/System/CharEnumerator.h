#ifndef _DOTNETNATIVE_SYSTEM_CHARENUMERATOR_H_
#define _DOTNETNATIVE_SYSTEM_CHARENUMERATOR_H_

#include "../MemoryUtil.h"
#include "Object.h"
#include "Collections/IEnumerator.h"
#include "Char.h"


namespace System
{
	class CharEnumerator
		: public Object
		, public Collections::IEnumerator<uint16_t>
	{
	private:
		shared_ptr<uint16_t[]> m_chars;
		int                     m_length;
		int                     m_index;
		uint16_t               m_current;

	public:
		CharEnumerator(const shared_ptr<uint16_t[]>& chars, const int length);
		CharEnumerator(const CharEnumerator& copy);
		CharEnumerator(CharEnumerator&& mov) noexcept;
		virtual ~CharEnumerator() {}

		CharEnumerator& operator=(const CharEnumerator& copy);
		CharEnumerator& operator=(CharEnumerator&& mov) noexcept;

		//
		// Summary:
		//     Gets the element in the collection at the current position of the enumerator.
		//
		// Returns:
		//     The element in the collection at the current position of the enumerator.
		virtual const uint16_t& Current() const& override;

		//
		// Summary:
		//     Gets the element in the collection at the current position of the enumerator.
		//
		// Returns:
		//     The element in the collection at the current position of the enumerator.
		virtual uint16_t& Current() & override;

		//
		// Summary:
		//     Advances the enumerator to the next element of the collection.
		//
		// Returns:
		//     true if the enumerator was successfully advanced to the next element; false if
		//     the enumerator has passed the end of the collection.
		//
		// Exceptions:
		//   T:System.InvalidOperationException:
		//     The collection was modified after the enumerator was created.
		virtual bool MoveNext() override;

		//
		// Summary:
		//     Sets the enumerator to its initial position, which is before the first element
		//     in the collection.
		//
		// Exceptions:
		//   T:System.InvalidOperationException:
		//     The collection was modified after the enumerator was created.
		virtual void Reset() override;
	};
}


#endif
