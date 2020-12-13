#include <iostream>
using namespace std;

/* ��� ������ ��ȿ�����̴�.
   ����� ������ ��� �ð����⵵�� O(n) ������
   ��� ������ ��� ���� ���� ������ �ݺ��ϰ� �Ǿ� �ð����⵵�� O(2^n)�� �Ǳ� �����̴�.
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