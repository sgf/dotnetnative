#pragma once
#include "pch.h"



namespace System {

	/// <summary>
	/// sizeof(Char)=2�ֽ�
	/// Char is the CodeUnit(���CodePoint ����һ��Char�Ǿͻ�������Char��ʾ)
	/// </summary>
	class Char {
	private:
		uint16_t m_char;
	public:
		Char() :m_char(0) {}
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

	//��չƽ��
	class SupplementaryPlane {


	};



	class CodePoint {
	private:
		Char Unit1;
		Char Unit2;
	};

}


