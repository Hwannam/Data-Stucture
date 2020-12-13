#include <iostream>
#include "doublestack.h"
using namespace std;

int main()
{
	doublestack stack;
	
	for (int i = 1; i < 11; i++)
	{
		stack.Push(i);
	}
	for (int i = 1003; i < 1013; i++)
	{
		stack.Push(i);
	}
	stack.Print(); // 1~10, 1003~1012 ���� ���� ���
	cout << endl;

	for (int i = 11; i < 192; i++)
	{
		stack.Push(i);
	} // ������ ������ i=191 �϶� stack�� item���� 200���� �������ֱ� ������ stack�� ����á�ٰ� �����.

	return 0;
}