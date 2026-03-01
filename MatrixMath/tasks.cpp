#define _USE_MATH_DEFINES 
#include "tasks.h"
#include "matrix.h"
#include "mathFunctions.h"
#include <cmath>



void Task4_6_4()
{
	printf("Task 4.6.4: \n\n");
	std::vector<double> AVec = SetPFunction(0, 0.5, 1.5, 3);

	std::vector<double> BVec =
	{
		1,
		0.5625,
		-0.3125,
		4
	};

	Matrix MatA(4, 4, AVec);
	Matrix MatB(4, 1, BVec);


	Matrix MatX = SolveMatrix(MatA, MatB);
	MatX.PrintMatrix();

	double a = MatX.GetData(0);
	double b = MatX.GetData(1);
	double c = MatX.GetData(2);
	double d = MatX.GetData(3);
	printf("The equation is: %fx^3 - %fx^2 - %fx + %f\n\n\n\n", a, -b, -c, d);
}

void Task4_6_7()
{
	printf("Task 4.6.7: \n\n");
	double piValue = M_PI;
	std::vector<double> AVec = SetPFunctionHermiteInterpolation(1, piValue);


	std::vector<double> BVec =
	{
		0,
		0,
		1,
		-1
	};

	Matrix MatA(4, 4, AVec);
	Matrix MatB(4, 1, BVec);

	Matrix MatX = SolveMatrix(MatA, MatB);
	MatX.PrintMatrix();

	double b = MatX.GetData(1);
	double c = MatX.GetData(2);
	double d = MatX.GetData(3);
	printf("The equation is: - %fx^2 + %fx - %f\n\n\n\n", -b, c, -d);
}

void Task4_6_14()
{
	printf("Task 4.6.14: \n\n");

	//(4, 3), (0, 1), (2, 0) and (3, 4).
	std::vector<double> y =
	{
		3,
		1,
		0,
		4
	};


	std::vector<double> A =
	{
		4, 1,
		0, 1,
		2, 1,
		3, 1
	};


	Matrix MatY(4, 1, y);
	Matrix MatA(4, 2, A);
	Matrix MatA_t = MatA.Transpose();


	Matrix MatB = MatA_t.Multiply(MatA);
	Matrix MatC = MatA_t.Multiply(MatY);

	Matrix MatBInverse = MatB.Inverse();

	Matrix MatX = MatBInverse.Multiply(MatC);

	MatX.PrintMatrix();
	double a = MatX.GetData(0);
	double b = MatX.GetData(1);
	printf("The equation is: %fx + %f\n\n\n\n", a, b);


}


void Task4_6_15()
{
	printf("Task 4.6.15: \n\n");

	//(0.5, 0.5), (0.5, 1.5), (2.5, −1), (3,0.5), (4, 3)

	std::vector<double> y =
	{
		0.5,
		1.5,
		-1,
		0.5,
		3
	};


	std::vector<double> A =
	{
		pow(0.5, 2), 0.5, 1,
		pow(0.5, 2), 0.5, 1,
		pow(2.5, 2), 2.5, 1,
		pow(3, 2), 3, 1,
		pow(4, 2), 4, 1
	};


	Matrix MatA(5, 3, A);
	Matrix MatY(5, 1, y);

	Matrix MatA_t = MatA.Transpose();


	Matrix MatB = MatA_t.Multiply(MatA);


	Matrix MatC = MatA_t.Multiply(MatY);

	Matrix MatBInverse = MatB.Inverse();

	Matrix MatX = MatBInverse.Multiply(MatC);

	MatX.PrintMatrix();

	double a = MatX.GetData(0);
	double b = MatX.GetData(1);
	double c = MatX.GetData(2);

	printf("The equation is: %fx^2 - %fx + %f\n\n\n\n", a, -b, c);


}

