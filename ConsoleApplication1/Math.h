#pragma once
#include <math.h>



namespace System {
	class Math {

	private:
		static constexpr int maxRoundingDigits = 15;
		//static constexpr double doubleRoundLimit = 1e16d;
		static constexpr double roundPower10Double[] = {
			1E0, 1E1, 1E2, 1E3, 1E4, 1E5, 1E6, 1E7, 1E8,
				1E9, 1E10, 1E11, 1E12, 1E13, 1E14, 1E15
		};


	public:
		////Pi: Defines how much accurate the mathematical Pi value is.
		////const float PI_Z = (float)(4.0 * Atan(1.0));
		//// 1/Pi: Defines how much accurate the mathematical Pi value is to calculate its inverse.
		////const float INVERSE_PI_Z = (float)(1.0 / PI_Z);
		static constexpr double E = 2.7182818284590452354;

		static constexpr double PI = 3.14159265358979323846;


		template<class T>
		inline static T Abs(T val)
		{
			if (val < 0)
			{
				val = (T)-val;
				if (value < 0)
				{
					return val;//? ThrowAbsOverflow();

				}
			}
			return val;
		}


		template<class T>
		inline static T Max(T v1, T v2) {
			return  (v1 >= v2) ? v1 : v2;
		}


		inline static 	double Sin(double fRadians) {
			return	sin(fRadians);
		}

		inline static 	double Sinh(double fRadians) {
			return	sinh(fRadians);
		}
		inline static 	double Cos(double fRadians) {
			return	cos(fRadians);
		}
		inline static 	double Cosh(double fRadians) {
			return	cosh(fRadians);
		}
		inline static 	double Tan(double fRadians) {
			return	tan(fRadians);
		}
		inline static 	double Tanh(double fRadians) {
			return	tanh(fRadians);
		}
		inline static 	double Asin(double fRadians) {
			return	asin(fRadians);
		}
		inline static 	double Acos(double fRadians) {
			return	acos(fRadians);
		}
		inline static 	double Atan(double fRadians) {
			return	atan(fRadians);
		}
		inline static 	double Atan2(double fY, double fX) {
			return	atan2(fY, fX);
		}
		inline static 	double Exp(double fValue) {
			return	exp(fValue);
		}
		inline static 	double Pow(double fValue, double exponent) {
			return	pow(fValue, exponent);
		}

		inline static 	double Log(double fValue) {
			return	log(fValue);
		}

		inline static 	double Log10(double fValue) {
			return	log10(fValue);
		}

		inline static 	double Sqrt(double fValue) {
			return	sqrt(fValue);
		}
		inline static 	float Hypotf(float fX, float fY) {
			return	_hypotf(fX, fY);
		}

		inline static 	double Hypot(double fX, double fY) {
			return	_hypotf(fX, fY);
		}

		inline static 	float Fmodf(float fX, float fY) {
			return	fmodf(fX, fY);
		}


		inline static 	double Fmod(double fX, double fY) {
			return	fmod(fX, fY);
		}


	};

}