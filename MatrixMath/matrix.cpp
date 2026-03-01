#include "matrix.h"
#include <iostream>

// Constructors and destructors
 Matrix::Matrix(int row, int col) : m_Row(row), m_Column(col)
 {
	 m_Data = new double[row * col];
 }

 Matrix::Matrix(int row, int col, std::vector<double> inputArray) : m_Row(row), m_Column(col)
 {
	 m_Data = new double[row * col];
	 for (size_t i = 0; i < inputArray.size(); i++)
		 m_Data[i] = inputArray[i];
 }

 Matrix::~Matrix()
 {
	 delete[] m_Data;
	 m_Data = nullptr;
}




 //Getters and Setters

 void Matrix::SetData(int row, int col, double data)
 {
	 m_Data[col + row * m_Column] = data;
 }

 double Matrix::GetData(int row, int col)
 {
	 return m_Data[col + row * m_Column];
 }

 double Matrix::GetData(int index)
 {
	 return m_Data[index];
 }






 // Read and print functions

 void Matrix::PrintMatrix()
 {
	 for (int row = 0; row < m_Row; row++)
	 {
		 for (int col = 0; col < m_Column; col++)
		 {
			 std::cout << m_Data[col + row * m_Column] << " ";
		 }
		 std::cout << "\n";
	 }
	 std::cout << "\n";
 }









 // Functions for finding the inverse Matrix

 Matrix Matrix::Multiply(const Matrix& other)
 {
	 if (!(m_Column == other.m_Row))
		 std::cout << "ERROR: Not able to multiply them\n";

	 Matrix answer(m_Row, other.m_Column);
	 
	 for (int row = 0; row < answer.m_Row; row++)
	 {
		 for (int col = 0; col < answer.m_Column; col++)
		 {
			 answer.m_Data[col + row * answer.m_Column] = 0;

			 
			 for (int index = 0; index < m_Column; index++)
			 {
				 answer.m_Data[col + row * answer.m_Column] += 
					 m_Data[index + row * m_Column] * other.m_Data[col + index * other.m_Column];
			 }
			 
		 }
	 }


	 return answer;
 }



 double Matrix::Determinant()
 {
	 if (m_Row != m_Column)
		 std::cout << "ERROR: Matrix must be square\n";

	 double result = 0;


	 if (m_Row == 1)
		 result = m_Data[0];

	 else if (m_Row == 2)
		 // m_Data[column + row * columnSize]
		 //result = m_Data[0 + 0 * m_Column] * m_Data[1 + 1 * m_Column] - m_Data[1 + 0 * m_Column] * m_Data[0 + 1 * m_Column];
		 result = m_Data[0] * m_Data[3] - m_Data[1] * m_Data[2];

	 else
	 {
		 for (int col = 0; col < m_Column; col++)
		 {
			 Matrix minor = ShrinkMatrix(0, col);
			 double det = minor.Determinant();
			 result += m_Data[col + 0 * m_Column] * pow(-1.0, col) * det;
		 }
	 }
	 return result;
 }


 //Returns a matrix where a column and a row has been removed from the original matrix
 // Dont call if the size of the matrix is 1x1
 Matrix Matrix::ShrinkMatrix(const int row, const int col)
 {
	 if (m_Row < 2 || m_Column < 2)
		 std::cout << "ERROR: Can't shrink\n";

	 Matrix OutputMatrix(m_Row - 1, m_Column - 1);

	 for (int InputRow = 0, OutputRow = 0; InputRow < m_Row; InputRow++)
	 {
		 if (InputRow != row)
		 {

			 for (int InputCol = 0, OutputCol = 0; InputCol < m_Column; InputCol++)
			 {
				 if (InputCol != col)
					 // m_Data[column + row * columnSize]
					 OutputMatrix.m_Data[OutputCol++ + OutputRow * OutputMatrix.m_Column] = m_Data[InputCol + InputRow * m_Column];
			 }
			 OutputRow++;
		 }
	 }
	 
	 return OutputMatrix;
 }



 Matrix Matrix::Inverse()
 {
	 double det = Determinant();
	 
	 // Checks if the determinant is 0
	 if (det == 0)
		 std::cout << "ERROR: Determinant is 0. Inverse does not exist\n";
	 

	 Matrix Temp = MatrixOfMinor();
	 Temp.Cofactor();
	 Matrix inverseMatrix = Temp.Transpose();
	 
	 
	 for (int row = 0; row < m_Row; row++)
		 for (int col = 0; col < m_Column; col++)
			 inverseMatrix.m_Data[col + row * m_Column] *= 1/det;
			 


	 return inverseMatrix;
 }

 Matrix Matrix::MatrixOfMinor()
 {
	 Matrix OutputMatrix(m_Row, m_Column);
	 for (int row = 0; row < OutputMatrix.m_Row; row++)
		 for (int col = 0; col < OutputMatrix.m_Column; col++)
		 {
			 Matrix tempMinor = ShrinkMatrix(row, col);
			 double detMinor = tempMinor.Determinant();
			 OutputMatrix.m_Data[col + row * OutputMatrix.m_Column] = detMinor;
		 }


	 return OutputMatrix;
 }

 void Matrix::Cofactor()
 {

	 for (int row = 0; row < m_Row; row++)
		 for (int col = 0; col < m_Column; col++)
			 m_Data[col + row * m_Column] *= pow(-1.0, row + col);
 }



 Matrix Matrix::Transpose()
 {
	 Matrix temp(m_Row, m_Column);
	 for (int row = 0; row < m_Row; ++row) {
		 for (int col = 0; col < m_Column; ++col) {
			 temp.m_Data[col + row * m_Column] = m_Data[row + col * m_Column];
		 }
	 }

	 temp.m_Column = m_Row;
	 temp.m_Row = m_Column;
	 return temp;
 }

 void Matrix::LUDecomposition(Matrix& L, Matrix& U)
 {
	 if (m_Row != m_Column)
	 {
		 std::cout << "ERROR: Matrix must be square for LU decomposition\n";
		 return;
	 }

	 int n = m_Row;

	 // Create L and U (initialised to zero)
	 L = Matrix(n, n);
	 U = Matrix(n, n);
	 for (int i = 0; i < n; i++)
		 for (int j = 0; j < n; j++)
		 {
			 L.SetData(i, j, 0.0);
			 U.SetData(i, j, 0.0);
		 }

	 // L diagonal = 1, U = copy of A
	 for (int i = 0; i < n; i++) L.SetData(i, i, 1.0);
	 for (int i = 0; i < n; i++)
		 for (int j = 0; j < n; j++)
			 U.SetData(i, j, GetData(i, j));

	 // Gaussian elimination (no pivoting)
	 for (int k = 0; k < n; k++)
	 {
		 if (U.GetData(k, k) == 0.0)
		 {
			 std::cout << "ERROR: Zero pivot encountered (no pivoting implemented)\n";
			 return;
		 }

		 for (int i = k + 1; i < n; i++)
		 {
			 double factor = U.GetData(i, k) / U.GetData(k, k);
			 L.SetData(i, k, factor);

			 for (int j = k; j < n; j++)  // can start at k
			 {
				 U.SetData(i, j, U.GetData(i, j) - factor * U.GetData(k, j));
			 }
		 }
	 }
 }


