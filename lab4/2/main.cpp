#include <iostream>
#include "StackTType.h"
#include "MaxItem.h"
using namespace std;

void Copy(StackType<int>& X,StackType<int>& Y)
{
	StackType<int> Z; //X와 Y사이의 중간 stack
	while (!X.IsEmpty())
	{
		int num = X.Top();
		Z.Push(num);
		X.Pop();
	}
	while (!Z.IsEmpty())
	{
		int num = Z.Top();
		X.Push(num);
		Y.Push(num);
		Z.Pop();
	}
}

int main(){
	StackType<int> A;
	StackType<int> B;
	A.Push(9);
	A.Push(8);
	A.Push(4);
	A.Push(7);
	A.Push(5);
	A.Push(3);

	Copy(A, B); // B에 A를 복사

	while (!A.IsEmpty())  // 스택 A 출력
	{
		int result = A.Top();
		A.Pop();
		cout << result << endl;
	}
	cout << endl;

	while (!B.IsEmpty()) // 스택 B 출력
	{
		int result = B.Top();
		B.Pop();
		cout << result << endl;
	}

	return 0;
}