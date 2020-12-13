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

	cout << qu.LengthIs() << endl; // 가득차있다. rear +1 = front

	qu1.Enqueue(5);
	qu1.Enqueue(5);
	qu1.Dequeue(a);
	qu1.Dequeue(a);

	cout << qu1.LengthIs() << endl; // 비어있다. rear +1 = front
	return 0;
}