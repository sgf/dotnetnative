#pragma once
#include "pch.h"

namespace System {

	/// <summary>
	/// sizeof(Char)=2字节
	/// Char is the CodeUnit(如果CodePoint 大于一个Char那就会用两个Char表示)
	/// </summary>
	class Char {
	private:
		uint16_t m_char;
	public:
		Char(uint16_t _char) :m_char(_char) {

		}




	};



	//surrogate pairs
	//Basic Multilinfgual Plan(BMP)
	class  BMP
	{
	public:
		BMP();
		~BMP();

	private:

	};

	BMP::BMP()
	{
	}

	BMP::~BMP()
	{
	}


	class CodePoint {
	private:
		Char Unit1;
		Char Unit2;


	};

}


