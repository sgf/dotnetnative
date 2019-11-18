#pragma once
#include <math.h>



namespace System {
	class Math {

	private:
		static constexpr int maxRoundingDigits = 15;
		//static constexpr double doubleRoundLimit = 1e16d;DivRem
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


	/// @brief Provides constants and static methods for trigonometric, logarithmic, and other common mathematical functions.
   /// @par Examples
   /// This class cannot be inherited.
   /// @include Math.cpp
	class core_export_ Math static_ {
	public:
		/// @brief Represents the natural logarithmic base, specified by the constant, e. This field is constant.
		/// @remarks The value of this field is 2.7182818284590452354.
		static constexpr double E = 2.7182818284590452354;

		/// @brief Represents the ratio of the circumference of a circle to its diameter, specified by the constant, p. This field is constant.
		/// @remarks The value of this field is 3.14159265358979323846.
		static constexpr double PI = 3.14159265358979323846;

		/// @brief Returns the absolute value of a double-precision floating-point number
		/// @param value A number in the range double::MinValue <= value <= double::MaxValue
		/// @return double A double-precision floating-point number, x, such that 0 <= x <= double::MaxValue
		static decimal Abs(decimal value) { return value < 0 ? -value : value; }

		/// @brief Returns the absolute value of a double-precision floating-point number
		/// @param value A number in the range double::MinValue <= value <= double::MaxValue
		/// @return double A double-precision floating-point number, x, such that 0 <= x <= double::MaxValue
		static double Abs(double value) { return value < 0 ? -value : value; }

		/// @brief Returns the absolute value of a 16-bit signed integer.
		/// @param value A number in the range int16::MinValue < value <= int16::MaxValue
		/// @return int16 A 16-bit signed integer, x, such that 0 <= x <= int16::MaxValue
		/// @exception OverflowException value equals Int16::MinValue.
		static int16 Abs(int16 value) {
			if (value == Int16::MinValue)
				throw OverflowException(caller_);
			return value < 0 ? -value : value;
		}

		/// @brief Returns the absolute value of a 32-bit signed integer
		/// @param value A number in the range int32::MinValue < value <= int32::MaxValue
		/// @return int32 A 32-bit signed integer, x, such that 0 <= x <= int32::MaxValue
		/// @exception OverflowException value equals Int32::MinValue.
		static int32 Abs(int32 value) {
			if (value == Int32::MinValue)
				throw OverflowException(caller_);
			return value < 0 ? -value : value;
		}

		/// @brief Returns the absolute value of a 64-bit signed integer
		/// @param value A number in the range int64::MinValue < value <= int64::MaxValue
		/// @return int64 A 64-bit signed integer, x, such that 0 <= x <= int64::MaxValue
		/// @exception OverflowException value equals Int64::MinValue.
		static int64 Abs(int64 value) {
			if (value == Int64::MinValue)
				throw OverflowException(caller_);
			return value < 0 ? -value : value;
		}

		/// @brief Returns the absolute value of a 8-bit signed integer.
		/// @param value A number in the range sbyte::MinValue < value <= sbyte::MaxValue
		/// @return sbyte A 8-bit signed integer, x, such that 0 <= x <= sbyte::MaxValue
		/// @exception OverflowException value equals SByte::MinValue.
		static sbyte Abs(sbyte value) {
			if (value == SByte::MinValue)
				throw OverflowException(caller_);
			return value < 0 ? -value : value;
		}

		/// @brief Returns the absolute value of a single-precision floating-point number
		/// @param value A number in the range single::MinValue <= value <= single::MaxValue
		/// @return single A single-precision floating-point number, x, such that 0 <= x <= single::MaxValue
		static float Abs(float value) { return value < 0 ? -value : value; }

		/// @brief Returns the angle whose cosine is the specified number.
		/// @param value A number representing a cosine, where -1 <= value <= 1.
		/// @return double An angle, A, measured in radians, such that 0 <= A <= PI.
		/// -or-
		/// NaN if value < -1 or d > 1.
		static double Acos(double value);

		/// @brief Returns the angle whose sine is the specified number.
		/// @param value A number representing a sine, where -1 <= value <= 1.
		/// @return double An angle, A, measured in radians, such that -PI/2 <= A <= PI/2.
		/// -or-
		/// NaN if value < -1 or d > 1.
		static double Asin(double value);

		/// @brief Returns the angle whose tangent is the specified number.
		/// @param value A number representing a tangent.
		/// @return double An angle, A, measured in radians, such that -PI/2 <= ? <= PI/2.
		/// -or-
		/// NaN if value equals NaN, -PI/2 rounded to double precision (-1.5707963267949) if d equals NegativeInfinity, or PI/2 rounded to double precision (1.5707963267949) if d equals PositiveInfinity
		static double Atan(double value);

		/// @brief Returns the angle whose tangent is the specified number.
		/// @param y The y coordinate of a point.
		/// @param x The x coordinate of a point.
		/// @return double An angle, A, measured in radians, such that -PI <= A <= PI, and tan(?) = y / x, where (x, y) is a point in the Cartesian plane. Observe the following:
		/// * For (x, y) in quadrant 1, 0 < A < PI/2.
		/// * For (x, y) in quadrant 2, PI/2 < A <= PI.
		/// * For (x, y) in quadrant 3, -PI < A < -PI/2.
		/// * For (x, y) in quadrant 4, -PI/2 < A < 0.
		/// * For points on the boundaries of the quadrants, the return value is the following:
		/// * If x is 0 and y is not negative, A = 0.
		/// * If x is 0 and y is negative, A = PI.
		/// * If x is positive and y is 0, A = PI/2.
		/// * If x is negative and y is 0, A = -PI/2.
		/// @remarks The return value is the angle in the Cartesian plane formed by the x-axis, and a vector starting from the origin, (0,0), and terminating at the point, (x,y).
		static double Atan2(double y, double x);

		/// @brief Produces the full product of two 32-bit numbers.
		/// @param a The first int32 to multiply.
		/// @param b The second int32 to multiply.
		/// @return int64 The int64 containing the product of the specified numbers.
		static int64 BigMul(int32 a, int32 b) { return as<int64>(a) * as<int64>(b); }

		/// @brief Returns the smallest integer greater than or equal to the specified double-precision floating-point number.
		/// @param value A double-precision floating-point number.
		/// @return double The smallest integer greater than or equal to value. If value is equal to NaN, NegativeInfinity, or PositiveInfinity, that value is returned.
		static decimal Ceiling(decimal value);

		/// @brief Returns the smallest integer greater than or equal to the specified double-precision floating-point number.
		/// @param value A double-precision floating-point number.
		/// @return double The smallest integer greater than or equal to value. If value is equal to NaN, NegativeInfinity, or PositiveInfinity, that value is returned.
		static double Ceiling(double value);

		/// @brief Returns the cosine of the specified angle.
		/// @param value An angle, measured in radians.
		/// @return double The cosine of value. If value is equal to NaN, NegativeInfinity, or PositiveInfinity, this method returns NaN.
		static double Cos(double value);

		/// @brief Returns the hyperbolic cosine of the specified angle.
		/// @param value An angle, measured in radians.
		/// @return double The hyperbolic cosine of value. If value is equal to NegativeInfinity or PositiveInfinity, PositiveInfinity is returned. If value is equal to NaN, NaN is returned.
		static double Cosh(double value);

		/// @brief Calculates the quotient of two 32-bit signed integers and also returns the remainder in an output parameter.
		/// @param dividend The dividend.
		/// @param divisor The divisor.
		/// @param remainder An angle, measured in radians.
		/// @return int32 The remainder.
		static int32 DivRem(int32 dividend, int32 divisor, int32& remainder) {
			remainder = dividend % divisor;
			return dividend / divisor;
		}

		/// @brief Calculates the quotient of two 64-bit signed integers and also returns the remainder in an output parameter.
		/// @param dividend The dividend.
		/// @param divisor The divisor.
		/// @param remainder An angle, measured in radians.
		/// @return int64 The remainder.
		static int64 DivRem(int64 dividend, int64 divisor, int64& remainder) {
			remainder = dividend % divisor;
			return dividend / divisor;
		}

		/// @brief Returns e raised to the specified power.
		/// @param value A number specifying a power.
		/// @return double The number e raised to the power d. If value equals NaN or PositiveInfinity, that value is returned. If value equals NegativeInfinity, 0 is returned.
		static double Exp(double value);

		/// @brief Returns the largest integer less than or equal to the specified decimal number.
		/// @param value A double-precision floating-point number.
		/// @return  double The largest integer less than or equal to value.
		static decimal Floor(decimal value);

		/// @brief Returns the largest integer less than or equal to the specified decimal number.
		/// @param value A double-precision floating-point number.
		/// @return  double The largest integer less than or equal to value.
		static double Floor(double value);

		/// @brief Returns the remainder resulting from the division of a specified number by another specified number.
		/// @param dividend A dividend.
		/// @param divisor A divisor.
		/// @return double A number equal to x - (y Q), where Q is the quotient of x / y rounded to the nearest integer (if x / y falls halfway between two integers, the even integer is returned).
		/// * If x - (y Q) is zero, the value +0 is returned if x is positive, or -0 if x is negative.
		/// * If y = 0, NaN is returned.
		static double IEEERemainder(double dividend, double divisor) { return divisor == 0 ? Double::NaN : dividend - (divisor * Round(dividend / divisor)); }

		/// @brief Returns the natural (base e) logarithm of a specified number.
		/// @param value A number whose logarithm is to be found.
		/// @return double One of the values in the following table.
		/// | value parameter           | Return value                                                  |
		/// |---------------------------|---------------------------------------------------------------|
		/// | Positive                  | The natural logarithm of d; that is, ln value, or log e value |
		/// | Zero                      | NegativeInfinity                                              |
		/// | Negative                  | NaN                                                           |
		/// | Equal to NaN              | NaN                                                           |
		/// | Equal to PositiveInfinity | PositiveInfinity                                              |
		/// @remarks Parameter value is specified as a base 10 number.
		static double Log(double value);

		/// @brief Returns the logarithm of a specified number in a specified base.
		/// @param a The number whose logarithm is to be found.
		/// @param newBase The base of the logarithm.
		/// @return One of the values in the following table. (+Infinity denotes PositiveInfinity, -Infinity denotes NegativeInfinity, and NaN denotes NaN.)
		/// [ a             | newBase                             | Return value    |
		/// |---------------|-------------------------------------| ----------------|
		/// | a > 0         | (0 < newBase < 1) -or-(newBase > 1) | log newBase (a) |
		/// | a < 0         | (any value)                         | NaN             |
		/// | (any value)   | newBase < 0                         | NaN             |
		/// | a != 1        | newBase = 0                         | NaN             |
		/// | a != 1        | newBase = +Infinity                 | NaN             |
		/// | a = NaN       | (any value)                         | NaN             |
		/// | (any value)   | newBase = NaN                       | NaN             |
		/// | (any value)   | newBase = 1                         | NaN             |
		/// | a = 0         | 0 < newBase < 1                     | +Infinity       |
		/// | a = 0         | newBase > 1                         | -Infinity       |
		/// | a = +Infinity | 0 < newBase < 1                     | -Infinity       |
		/// | a = +Infinity | newBase > 1                         | +Infinity       |
		/// | a = 1         | newBase = 0                         | 0               |
		/// | a = 1         | newBase = +Infinity                 | 0               |
		static double Log(double a, double newBase) {
			if (a < 0 || newBase < 0 || (a != 1 && newBase == 0) || (a != 1 && Double::IsPositiveInfinity(newBase)) || Double::IsNaN(a) || Double::IsNaN(newBase) || newBase == 1)
				return Double::NaN;
			if ((a == 0 && 0 < newBase && newBase < 1) || (Double::IsPositiveInfinity(a) && newBase > 1))
				return Double::PositiveInfinity;
			if ((a == 0 && newBase > 1) || (Double::IsPositiveInfinity(a) && 0 < newBase && newBase < 1))
				return Double::NegativeInfinity;
			return (Log(a) / Log(newBase));
		}

		/// @brief Returns the base 10 logarithm of a specified number.
		/// @param value A number whose logarithm is to be found.
		/// @return double One of the values in the following table.
		/// | value parameter           | Return value                                                  |
		/// |---------------------------|---------------------------------------------------------------|
		/// | Positive                  | The natural logarithm of d; that is, ln value, or log e value |
		/// | Zero                      | NegativeInfinity                                              |
		/// | Negative                  | NaN                                                           |
		/// | Equal to NaN              | NaN                                                           |
		/// | Equal to PositiveInfinity | PositiveInfinity                                              |
		/// @remarks Parameter value is specified as a base 10 number.
		static double Log10(double value);

		/// @brief Returns the larger of two 8-bit unsigned integers.
		/// @param a The first of two 8-bit unsigned integers to compare.
		/// @param b The second of two 8-bit unsigned integers to compare.
		/// @return Parameter a or b, whichever is larger.
		static byte Max(byte a, byte b) { return a > b ? a : b; }

		/// @brief Returns the larger of two double single.
		/// @param a The first of two double single to compare.
		/// @param b The second of two double single to compare.
		/// @return Parameter a or b, whichever is larger.
		static decimal Max(decimal a, decimal b) { return a > b ? a : b; }

		/// @brief Returns the larger of two double single.
		/// @param a The first of two double single to compare.
		/// @param b The second of two double single to compare.
		/// @return Parameter a or b, whichever is larger.
		static double Max(double a, double b) { return a > b ? a : b; }

		/// @brief Returns the larger of two 16-bit signed integers.
		/// @param a The first of two 16-bit signed integers to compare.
		/// @param b The second of two 16-bit signed integers to compare.
		/// @return Parameter a or b, whichever is larger.
		static int16 Max(int16 a, int16 b) { return a > b ? a : b; }

		/// @brief Returns the larger of two 32-bit signed integers.
		/// @param a The first of two 32-bit signed integers to compare.
		/// @param b The second of two 32-bit signed integers to compare.
		/// @return Parameter a or b, whichever is larger.
		static int32 Max(int32 a, int32 b) { return a > b ? a : b; }

		/// @brief Returns the larger of two 64-bit signed integers.
		/// @param a The first of two 64-bit signed integers to compare.
		/// @param b The second of two 64-bit signed integers to compare.
		/// @return Parameter a or b, whichever is larger.
		static int64 Max(int64 a, int64 b) { return a > b ? a : b; }

		/// @brief Returns the larger of two 8-bit signed integers.
		/// @param a The first of two 8-bit signed integers to compare.
		/// @param b The second of two 8-bit signed integers to compare.
		/// @return Parameter a or b, whichever is larger.
		static sbyte Max(sbyte a, sbyte b) { return a > b ? a : b; }

		/// @brief Returns the larger of two single single.
		/// @param a The first of two signle single to compare.
		/// @param b The second of two single single to compare.
		/// @return Parameter a or b, whichever is larger.
		static float Max(float a, float b) { return a > b ? a : b; }

		/// @brief Returns the larger of two 16-bit unsigned integers.
		/// @param a The first of two 16-bit unsigned integers to compare.
		/// @param b The second of two 16-bit unsigned integers to compare.
		/// @return Parameter a or b, whichever is larger.
		static uint16 Max(uint16 a, uint16 b) { return a > b ? a : b; }

		/// @brief Returns the larger of two 32-bit unsigned integers.
		/// @param a The first of two 32-bit unsigned integers to compare.
		/// @param b The second of two 32-bit unsigned integers to compare.
		/// @return Parameter a or b, whichever is larger.
		static uint32 Max(uint32 a, uint32 b) { return a > b ? a : b; }

		/// @brief Returns the larger of two 64-bit unsigned integers.
		/// @param a The first of two 64-bit unsigned integers to compare.
		/// @param b The second of two 64-bit unsigned integers to compare.
		/// @return Parameter a or b, whichever is larger.
		static uint64 Max(uint64 a, uint64 b) { return a > b ? a : b; }

		/// @brief Returns the smaller of two 8-bit unsigned integers.
		/// @param a The first of two 8-bit unsigned integers to compare.
		/// @param b The second of two 8-bit unsigned integers to compare.
		/// @return Parameter a or b, whichever is smaller.
		static byte Min(byte a, byte b) { return a < b ? a : b; }

		/// @brief Returns the smaller of two double single.
		/// @param a The first of two double single to compare.
		/// @param b The second of two double single to compare.
		/// @return Parameter a or b, whichever is smaller.
		static decimal Min(decimal a, decimal b) { return a < b ? a : b; }

		/// @brief Returns the smaller of two double single.
		/// @param a The first of two double single to compare.
		/// @param b The second of two double single to compare.
		/// @return Parameter a or b, whichever is smaller.
		static double Min(double a, double b) { return a < b ? a : b; }

		/// @brief Returns the smaller of two 16-bit signed integers.
		/// @param a The first of two 16-bit signed integers to compare.
		/// @param b The second of two 16-bit signed integers to compare.
		/// @return Parameter a or b, whichever is smaller.
		static int16 Min(int16 a, int16 b) { return a < b ? a : b; }

		/// @brief Returns the smaller of two 32-bit signed integers.
		/// @param a The first of two 32-bit signed integers to compare.
		/// @param b The second of two 32-bit signed integers to compare.
		/// @return Parameter a or b, whichever is smaller.
		static int32 Min(int32 a, int32 b) { return a < b ? a : b; }

		/// @brief Returns the smaller of two 64-bit signed integers.
		/// @param a The first of two 64-bit signed integers to compare.
		/// @param b The second of two 64-bit signed integers to compare.
		/// @return Parameter a or b, whichever is smaller.
		static int64 Min(int64 a, int64 b) { return a < b ? a : b; }

		/// @brief Returns the smaller of two 8-bit signed integers.
		/// @param a The first of two 8-bit signed integers to compare.
		/// @param b The second of two 8-bit signed integers to compare.
		/// @return Parameter a or b, whichever is smaller.
		static sbyte Min(sbyte a, sbyte b) { return a < b ? a : b; }

		/// @brief Returns the smaller of two single single.
		/// @param a The first of two signle single to compare.
		/// @param b The second of two single single to compare.
		/// @return Parameter a or b, whichever is smaller.
		static float Min(float a, float b) { return a < b ? a : b; }

		/// @brief Returns the smaller of two 16-bit unsigned integers.
		/// @param a The first of two 16-bit unsigned integers to compare.
		/// @param b The second of two 16-bit unsigned integers to compare.
		/// @return Parameter a or b, whichever is smaller.
		static uint16 Min(uint16 a, uint16 b) { return a < b ? a : b; }

		/// @brief Returns the smaller of two 32-bit unsigned integers.
		/// @param a The first of two 32-bit unsigned integers to compare.
		/// @param b The second of two 32-bit unsigned integers to compare.
		/// @return Parameter a or b, whichever is smaller.
		static uint32 Min(uint32 a, uint32 b) { return a < b ? a : b; }

		/// @brief Returns the smaller of two 64-bit unsigned integers.
		/// @param a The first of two 64-bit unsigned integers to compare.
		/// @param b The second of two 64-bit unsigned integers to compare.
		/// @return Parameter a or b, whichever is smaller.
		static uint64 Min(uint64 a, uint64 b) { return a < b ? a : b; }


		static double Pow(double x, double y);

		/// @brief Rounds a double-precision floating-point value to the nearest integral value.
		/// @param value A double-precision floating-point number to be rounded.
		/// @return double The integer nearest value. If the fractional component of a is halfway between two integers, one of which is even and the other odd, then the even number is returned. Note that this method returns a double instead of an integral type.
		static decimal Round(decimal value) { return Round(value, 0); }

		/// @brief Rounds a decimal value to a specified number of fractional digits.
		/// @param value A double-precision floating-point number to be rounded.
		/// @param decimals The number of decimal places in the return value.
		/// @return The number nearest to d that contains a number of fractional digits equal to decimals.
		static decimal Round(decimal value, int32 decimals) {
			decimal muliplicator = 1;
			for (int32 index = 0; index < decimals; index++)
				muliplicator *= 10;
			return Floor((value * muliplicator) + 0.5) / muliplicator;
		}

		/// @brief Rounds a double-precision floating-point value to the nearest integral value.
		/// @param value A double-precision floating-point number to be rounded.
		/// @return double The integer nearest value. If the fractional component of a is halfway between two integers, one of which is even and the other odd, then the even number is returned. Note that this method returns a double instead of an integral type.
		static double Round(double value) { return Round(value, 0); }

		/// @brief Rounds a decimal value to a specified number of fractional digits.
		/// @param value A double-precision floating-point number to be rounded.
		/// @param decimals The number of decimal places in the return value.
		/// @return The number nearest to d that contains a number of fractional digits equal to decimals.
		static double Round(double value, int32 decimals) {
			double muliplicator = 1;
			for (int32 index = 0; index < decimals; index++)
				muliplicator *= 10;
			return Floor((value * muliplicator) + 0.5) / muliplicator;
		}

		/// @brief Returns a value indicating the sign of a double-precision floating-point number.
		/// @param value A signed number.
		/// @return int32 A number that indicates the sign of value, as shown in the following table.
		/// | Return value | Meaning                     |
		/// |--------------|-----------------------------|
		/// | -1           | value is less than zero.    |
		/// | 0            | value is equal to zero.     |
		/// | 1            | value is greater than zero. |
		/// @exception ArithmeticException value is equal to NaN.
		static int32 Sign(decimal value) {
			if (Decimal::IsNaN(value))
				throw ArithmeticException(caller_);
			return value < 0 ? -1 : value == 0 ? 0 : 1;
		}

		/// @brief Returns a value indicating the sign of a double-precision floating-point number.
		/// @param value A signed number.
		/// @return int32 A number that indicates the sign of value, as shown in the following table.
		/// | Return value | Meaning                     |
		/// |--------------|-----------------------------|
		/// | -1           | value is less than zero.    |
		/// | 0            | value is equal to zero.     |
		/// | 1            | value is greater than zero. |
		/// @exception ArithmeticException value is equal to NaN.
		static int32 Sign(double value) {
			if (Double::IsNaN(value))
				throw ArithmeticException(caller_);
			return value < 0 ? -1 : value == 0 ? 0 : 1;
		}

		static int32 Sign(int16 value) { return value < 0 ? -1 : value == 0 ? 0 : 1; }

		static int32 Sign(int32 value) { return value < 0 ? -1 : value == 0 ? 0 : 1; }

		static int32 Sign(int64 value) { return value < 0 ? -1 : value == 0 ? 0 : 1; }


		static int32 Sign(sbyte value) { return value < 0 ? -1 : value == 0 ? 0 : 1; }


		static int32 Sign(float value) {
			if (Single::IsNaN(value))
				throw ArithmeticException(caller_);
			return value < 0 ? -1 : value == 0 ? 0 : 1;
		}

		static double Sin(double value);

		static double Sinh(double value);

		static double Sqrt(double value);

		static double Tan(double value);

		static double Tanh(double value);

		static decimal Truncate(decimal value) { return (value > 0) ? Floor(value) : Ceiling(value); }

		static double Truncate(double value) { return (value > 0) ? Floor(value) : Ceiling(value); }
	};
}
}

using namespace Switch;

/// @cond
inline float operator%(const System::Single& a, const System::Single& b) { return std::fmod(a, b); }
inline double operator%(const System::Double& a, const System::Double& b) { return std::fmod(a, b); }
/// @endcond
}
