#pragma once
#include "pch.h"
#include "String.h"


namespace System {

	//template<class T>
	struct  ValueObject
	{
	public:
		ValueObject();
		~ValueObject();

	private:
		String& ToString() {

			//return to_string(static_cast<T*>(this)->m_val);
			typeid(this).name();
			//todo:未实现 std::string 到 String的转换 
		}
	};

	ValueObject::ValueObject()
	{
	}

	ValueObject::~ValueObject()
	{
	}



}
