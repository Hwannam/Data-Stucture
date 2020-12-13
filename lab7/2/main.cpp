#include <iostream>
#include "StackType.h"
using namespace std;

int main()
{
	StackType stack,copy;

	stack.Push('X');
	stack.Push('Y');
	stack.Push('Z');

	stack.Copy(copy);

	copy.Push('A');
	stack.Push('B');

	while (!copy.IsEmpty())
	{
		cout << copy.Top() << " ";
		copy.Pop();
	}
	cout << endl << endl;

	while (!stack.IsEmpty())
	{
		cout << stack.Top() << " ";
		stack.Pop();
	}
	cout << endl;
	return 0;
}