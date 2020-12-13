#include <iostream>
using namespace std;

/* 재귀 버전이 비효율적이다.
   비재귀 버전의 경우 시간복잡도가 O(n) 이지만
   재귀 버전의 경우 같은 항을 여러번 반복하게 되어 시간복잡도가 O(2^n)이 되기 때문이다.
 */
int Fibonacci_recursive(int n);
int Fibonacci_non_recursive(int n);

int Fibonacci_recursive(int n)
{
	if (n == 0 || n == 1)
		return n;
	else
		return Fibonacci_recursive(n - 2) + Fibonacci_recursive(n - 1);
}

int Fibonacci_non_recursive(int n)
{
	int temp;
	int sum = 1;
	int pre = 0;
	if (n == 0 || n == 1)
		return n;
	else
	{
		for (int i = 2; i <= n; i++)
		{
			temp = sum;
			sum = sum + pre;
			pre = temp;
		}
		return sum;
	}
}

int main()
{
	cout << Fibonacci_recursive(10) << endl;
	cout << Fibonacci_non_recursive(10) << endl;

	return 0;
}