#include <iostream>
#include "QueType.h"
using namespace std;


int main()
{
	QueType qu(4);
	QueType qu1(4);
	ItemType a;
	
	qu.Enqueue(5);
	qu.Enqueue(5);
	qu.Enqueue(5);
	qu.Dequeue(a);
	qu.Dequeue(a);
	qu.Enqueue(5);
	qu.Enqueue(5);
	qu.Enqueue(5);

	cout << qu.LengthIs() << endl; // �������ִ�. rear +1 = front

	qu1.Enqueue(5);
	qu1.Enqueue(5);
	qu1.Dequeue(a);
	qu1.Dequeue(a);

	cout << qu1.LengthIs() << endl; // ����ִ�. rear +1 = front
	return 0;
}