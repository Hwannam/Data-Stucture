#include <iostream>
#include "StackType.h"
using namespace std;

void ReplaceItemClient(StackType& stack, ItemType oldItem, ItemType newItem)
{
	StackType temp;
	ItemType item;

	while (!stack.IsEmpty())
	{
		item = stack.Top();
		if (item == oldItem)
			temp.Push(newItem);
		else
			temp.Push(item);
		stack.Pop();
	}
	while (!temp.IsEmpty())
	{
		stack.Push(temp.Top());
		temp.Pop();
	}
}


int main()
{
	StackType stack1, stack2;
	ItemType item;
	stack1.Push(1);
	stack1.Push(2);
	stack1.Push(3);
	stack1.Push(1);
	stack1.Push(2);
	stack1.Push(3);

	ReplaceItemClient(stack1, 1, 3);

	while (!stack1.IsEmpty()) // 323323
	{
		item = stack1.Top();
		cout << item << endl;
		stack1.Pop();
		stack2.Push(item);
	}
	cout << endl;
	while (!stack2.IsEmpty())
	{
		item = stack2.Top();
		stack2.Pop();
		stack1.Push(item);
	}

	stack1.ReplaceItemMember(3, 1);

	while (!stack1.IsEmpty()) // 121121
	{
		item = stack1.Top();
		cout << item << endl;
		stack1.Pop();
	}

	return 0;
}