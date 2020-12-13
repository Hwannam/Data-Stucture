#include <iostream>
#include "matrix.h"
using namespace std;

Matrix operator+(Matrix A, Matrix B)
{
	return Matrix(A.mat[0][0] + B.mat[0][0], A.mat[0][1] + B.mat[0][1], A.mat[1][0] + B.mat[1][0], A.mat[1][1] + B.mat[1][1]);
}
Matrix operator-(Matrix A, Matrix B)
{
	return Matrix(A.mat[0][0] - B.mat[0][0], A.mat[0][1] - B.mat[0][1], A.mat[1][0] - B.mat[1][0], A.mat[1][1] - B.mat[1][1]);
}
ostream& operator<<(ostream& os, const Matrix& A)
{
	os << A.mat[0][0] << " " << A.mat[0][1] << endl << A.mat[1][0] << " " << A.mat[1][1] << endl;
	return os;
}

Matrix::Matrix(int x, int y, int z, int k)
{
	mat[0][0] = x;
	mat[0][1] = y;
	mat[1][0] = z;
	mat[1][1] = k;
}
int main()
{
	Matrix A(1, 2, 3, 4);
	Matrix B(5, 6, 7, 8);

	Matrix resultAdd = A + B;
	Matrix resultSubstract = A - B;

	cout << resultAdd;
	cout << resultSubstract;

	return 0;
}