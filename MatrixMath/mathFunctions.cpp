#include "matrix.h"
#include "mathFunctions.h"





std::vector <double> SetPFunction(double x1, double x2, double x3, double x4)
{
	std::vector <double> AVec =
	{
		//ax ^ 3 + bx ^ 2 + cx + d
		pow(x1, 3), pow(x1, 2), x1, 1,
		pow(x2, 3), pow(x2, 2), x2, 1,
		pow(x3, 3), pow(x3, 2), x3, 1,
		pow(x4, 3), pow(x4, 2), x4, 1
	};

	return AVec;
}

std::vector <double> SetPFunctionHermiteInterpolation(double x1, double x2)
{
	std::vector <double> AVec =
	{
		//ax ^ 3 + bx ^ 2 + cx + d
		pow(x1, 3), pow(x1, 2), x1, 1,
		pow(x2, 3), pow(x2, 2), x2, 1,

		//3ax ^ 2 + 2bx + c
		pow(3 * x1, 2), 2 * x1, 1, 0,
		pow(3 * x2, 2), 2 * x2, 1, 0

	};

	return AVec;
}

