#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

//! SYSTEM Includes
#include <cstdint>
#include <type_traits>
#include <functional>
#include <new>
#include <memory>Byte
#include <type_traits>
#include <vcruntime_new.h>
#include <exception>
#include <stdexcept>
#include <cassert>
#include <cstdint>
#include <iterator>
#include <algorithm>


#include "xxhash.h"
#include "GlobalDefs.h"
#include "Memory.h"
#include "MemoryUtil.h"




#include "System/IEquatable.h"
#include "System/IComparable.h"
#include "System/Globalization/NumberStyles.h"

#include "System/Collections/IDictionary.h"
#include "System/Collections/IEqualityComparer.h"
#include "System/Collections/HashHelpers.h"
#include "System/Collections/EqualityComparer.h"
#include "System/ValueObject.h"
#include "System/Char.h"
#include "System/String.h"
#include "System/Object.h"
#include "System/ObjectImpl.h"
#include "System/UnicodeCategory.h"
#include "System/StringBuilder.h"
#include "System/Exception.h"
#include "System/CharUnicodeInfo.h"
#include "System/Collections/IEnumerable.h"
#include "System/Collections/IEnumerator.h"
#include "System/Collections/IReadOnlyList.h"
#include "System/Collections/GenericEnumerator.h"
#include "System/Collections/IReadOnlyDictionary.h"
#include "System/Collections/ICollection.h"
#include "System/Collections/IReadOnlyCollection.h"
#include "System/Collections/KeyValuePair.h"
#include "System/Globalization/NumberStyles.h"
#include "System/Array.h"
#include "System/BitConverter.h"
#include "System/Byte.h"
#include "System/CharEnumerator.h"
#include "System/CharUnicodeInfo.h"
#include "System/Environment.h"
#include "System/Int32.h"
#include "System/StringBuilder.h"
#include "System/ValueObject.h"
#include "System/Buffers/Binary/BinaryPrimitives.h"
