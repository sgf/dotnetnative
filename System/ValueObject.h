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
			//todo:δʵ�� std::string �� String��ת�� 
		}
	};

	ValueObject::ValueObject()
	{
	}

	ValueObject::~ValueObject()
	{
	}



}
