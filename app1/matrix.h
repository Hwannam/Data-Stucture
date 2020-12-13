#pragma once

class Matrix
{
private:
	int mat[2][2];
public:
	Matrix(int, int, int, int);
	
	Matrix operator=(Matrix B)
	{
		mat[0][0] = B.mat[0][0];
		mat[0][1] = B.mat[0][1];
		mat[1][0] = B.mat[1][0];
		mat[1][1] = B.mat[1][1];

		return *this;
	}
	friend std::ostream& operator<<(std::ostream& o, const Matrix& A);
	friend Matrix operator+(Matrix A, Matrix B);
	friend Matrix operator-(Matrix A, Matrix B);
};


