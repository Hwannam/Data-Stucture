#include <iostream>
#include "QueType.h"
using namespace std;

template<class ItemType>
void ReplaceItemClient(QueType<ItemType>& queue, ItemType oldItem, ItemType newItem)
{
	QueType<ItemType> temp;
	ItemType item;
	while (!queue.IsEmpty())
	{
		queue.Dequeue(item);
		if (item == oldItem)
			temp.Enqueue(newItem);
		else
			temp.Enqueue(item);
	}

	while (!temp.IsEmpty())
	{
		temp.Dequeue(item);
		queue.Enqueue(item);
	}
}

int main()
{
	QueType<int> q1, q2;
	int item;
	q1.Enqueue(1);
	q1.Enqueue(2);
	q1.Enqueue(3);
	q1.Enqueue(1);
	q1.Enqueue(2);
	q1.Enqueue(3);

	ReplaceItemClient(q1, 1, 3);
	while (!q1.IsEmpty()) // 323323
	{
		q1.Dequeue(item);
		q2.Enqueue(item);
		cout << item << endl;
	}
	cout << endl;

	q2.ReplaceItemMember(3, 1);
	while (!q2.IsEmpty()) // 121121
	{
		q2.Dequeue(item);
		cout << item << endl;
	}
	return 0;
}