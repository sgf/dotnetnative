#pragma once
public class OverflowException : ArithmeticException
{
	public OverflowException()
		: base(SR.Arg_OverflowException)
	{
		HResult = HResults.COR_E_OVERFLOW;
	}

	public OverflowException(string ? message)
		: base(message)
	{
		HResult = HResults.COR_E_OVERFLOW;
	}

	public OverflowException(string ? message, Exception ? innerException)
		: base(message, innerException)
	{
		HResult = HResults.COR_E_OVERFLOW;
	}

	protected OverflowException(SerializationInfo info, StreamingContext context) : base(info, context)
	{
	}
}