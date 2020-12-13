#include <iostream>
#include "QueType.h"
using namespace std;

void ReplaceItemClient(QueType &queue, int olditem, int newitem)
{
	ItemType item;
	QueType aa;
	while (!queue.IsEmpty())
	{
		queue.Dequeue(item);
		if (item == olditem)
			aa.Enqueue(newitem);
		else
			aa.Enqueue(item);
	}
	while (!aa.IsEmpty())
	{
		aa.Dequeue(item);
		queue.Enqueue(item);
	}
}

int main()
{
	QueType qu1,qu2;
	ItemType abc;
	qu1.Enqueue(2);
	qu1.Enqueue(6);
	qu1.Enqueue(7);
	qu1.Enqueue(4);
	qu1.Enqueue(5);
	qu1.Enqueue(6);
	qu1.Enqueue(10);
	qu1.Enqueue(15);
	qu1.Enqueue(6);

	ReplaceItemClient(qu1, 6, 20);
	while (!qu1.IsEmpty())  // client함수로 6을 20으로 바꾼 것을 출력
	{
		qu1.Dequeue(abc);
		cout << abc << endl;
		qu2.Enqueue(abc); // qu1의 item들을 qu2에 저장
	}
	cout << endl;

	qu2.ReplaceItemMember(20, 6);
	while (!qu2.IsEmpty()) // member함수로 20을 6으로 바꾼 것을 출력
	{
		qu2.Dequeue(abc);
		cout << abc << endl;
	}
	return 0;
}