#include <iostream>
#include "cl.h"
using namespace std;

void SquareMatrix::MakeEmpty(int n)
{
	int i, j = 0;
	size = n;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			matrix[i][j] = 0;
}

void SquareMatrix::StoreValue(int i, int j, int value)
{
	matrix[i][j] = value;
}

void SquareMatrix::Add(SquareMatrix A)
{
	int i = 0, j = 0;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			matrix[i][j] = matrix[i][j] + A.matrix[i][j];
		}

	}

}

void SquareMatrix::Subtract(SquareMatrix A)
{
	int i = 0, j = 0;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			matrix[i][j] = matrix[i][j] - A.matrix[i][j];
		}

	}

}

void SquareMatrix::Copy(SquareMatrix A)
{
	int i = 0, j = 0;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			matrix[i][j] = A.matrix[i][j];
		}

	}
}

void SquareMatrix::show()
{
	int i = 0, j = 0;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	SquareMatrix A;
	SquareMatrix B;
	SquareMatrix C;

	SquareMatrix D;
	SquareMatrix E;

	int size = 5;
	A.MakeEmpty(size);
	A.show(); //5x5의 0으로 이루어진 행렬 출력
	cout << endl;

	D.MakeEmpty(0);
	D.show(); //아무것도 출력되지 않음
	cout << endl;

	E.MakeEmpty(50);
	E.show(); //50x50 0으로 이루어진 행렬 출력
	cout << endl;

	A.StoreValue(1, 1, 7);
	A.show(); //1행 1열만 7, 나머지는 0인 행렬 출력
	cout << endl;
	B.MakeEmpty(size);
	B.StoreValue(2, 2, 6); 
	
	A.Add(B); //A에 B를 더한다. 7과 6이 나와야 할것
	A.show(); 
    
	cout << endl;

	C.MakeEmpty(size);
	C.Copy(B); //C에 B를 복사
	A.Subtract(C);
	A.show(); // A에서 C=B를 뺐으니 1행 1열에 7만 출력 
	cout << endl;

	return 0;
}