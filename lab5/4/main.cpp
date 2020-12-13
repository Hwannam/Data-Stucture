#include <iostream>
#include "QueType.h"
using namespace std;

int LengthClient(QueType& queue)
{
	QueType other;
	ItemType item;
	int count =0;
	while (!queue.IsEmpty())
	{
		queue.Dequeue(item);
		count++;
		other.Enqueue(item);
	}
	queue.MakeEmpty();
	while (!other.IsEmpty())
	{
		other.Dequeue(item);
		queue.Enqueue(item);
	}

	return count;
}

int main()
{
	QueType qu;
	ItemType a;
	qu.Enqueue(7);
	qu.Enqueue(4);
	qu.Enqueue(5);
	qu.Enqueue(6);
	qu.Enqueue(9);

	cout << "Client �������� ���� = " << LengthClient(qu) << endl;

	cout << "Member �������� ���� = " << qu.Length() << endl;
	return 0;
}