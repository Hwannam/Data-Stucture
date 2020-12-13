#include <iostream>
#include <ctime>
using namespace std;

typedef long clock_t;
#define CLOCKS_PER_SEC ((clock_t)1000)

int NumPaths(int row, int col, int n)
{
	if ((row == n) || (col == n))
		return 1;
	else
		return NumPaths(row + 1, col, n) + NumPaths(row, col + 1, n);
}

int mat[100][100];
int NumPaths_C(int row, int col, int n)
{
	if (mat[row][col] == -1) 
	{ 
		if ((row == n) || (col == n))
			mat[row][col] = 1;
		else
		{
			mat[row][col] = NumPaths_C(row + 1, col,n) + NumPaths_C(row,col+1,n);
		}
	}
	return mat[row][col];
}
int main()
{
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
			mat[i][j] = -1;
	}

	clock_t begin, end;
	begin = clock();
	cout << NumPaths(1,1,14) << endl;
	end = clock();
	clock_t result = end - begin;
	cout << "A번 수행시간 = " << result << "ms"<< endl << endl;

	begin = clock();
	cout << NumPaths_C(1,1,14) << endl;
	end = clock();
	result = end - begin;
	cout << "B번 수행시간 = " << result << "ms" << endl;

	return 0;
}