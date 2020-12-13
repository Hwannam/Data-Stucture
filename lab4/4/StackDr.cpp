// Test driver
#include <iostream>
#include "StackType.h"

using namespace std;

void ReplaceItemClient(StackType& st, int olditem, int newitem)  // a. Client �Լ�
{
	StackType im;
	int num;
	while (!st.IsEmpty())
	{
		num = st.Top();
		if (num == olditem)
			num = newitem;
		im.Push(num);
		st.Pop();
	}
	while (!im.IsEmpty())
	{
		num = im.Top();
		st.Push(num);
		im.Pop();
	}
}

int main()
{
	StackType stack;
	stack.Push(8);
	stack.Push(3);
	stack.Push(9);
	stack.Push(8);
	stack.Push(3);
	stack.Push(7);
	stack.Push(5);
	stack.Push(3);
	int item;

	ReplaceItemClient(stack, 3, 5); // Client �Լ� ���
	while (!stack.IsEmpty())
	{
		item= stack.Top();
		stack.Pop();
		cout << "Item: " << item << endl;  // Client �Լ��� 3�� 5�� �ٲ㼭 ���
	}
	cout << endl;

	stack.Push(8);
	stack.Push(3);
	stack.Push(9);
	stack.Push(8);
	stack.Push(3);
	stack.Push(7);
	stack.Push(5);
	stack.Push(3); 

	stack.ReplaceItemMember(3, 5); // Member �Լ� ���
	while (!stack.IsEmpty())
	{
		item = stack.Top();
		stack.Pop();
		cout << "Item: " << item << endl;  // Member �Լ��� 3�� 5�� �ٲ㼭 ���
	}

	return 0;
}
