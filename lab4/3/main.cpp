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
	stack.Print(); // 1~10, 1003~1012 까지 스택 출력
	cout << endl;

	for (int i = 11; i < 192; i++)
	{
		stack.Push(i);
	} // 루프의 마지막 i=191 일때 stack의 item수가 200으로 가득차있기 때문에 stack이 가득찼다고 출력함.

	return 0;
}