#pragma once
#include <vector>


class Matrix
{

public:

	Matrix() = delete;


	Matrix(int row, int col);
	Matrix(int row, int col, std::vector<double> inputArray);

	~Matrix();


	void SetData(int row, int col, double data);
	double GetData(int row, int col);
	double GetData(int index);


	// Prints every element in the matrix
	void PrintMatrix();

	
	Matrix Multiply(const Matrix& second);

	double Determinant();


	//Returns a matrix where a column and a row has been removed from the original matrix
	Matrix ShrinkMatrix(const int row, const int col);
	Matrix Inverse();
	Matrix MatrixOfMinor();
	void Cofactor();

	Matrix Transpose();

	// LU factorization (A = L*U, L has 1's on diagonal, no pivoting)
	void LUDecomposition(Matrix& L, Matrix& U);

private:

	int m_Row, m_Column;
	double* m_Data;
};

Matrix SolveMatrix(Matrix& A, Matrix& b);

