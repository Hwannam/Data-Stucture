#include <iostream>
#include "QueType.h"
using namespace std;


int main()
{
	QueType qu(6);
	ItemType a;
	qu.Enqueue(5);
	qu.Enqueue(4);
	qu.Enqueue(2);
	qu.Enqueue(3);
	qu.Enqueue(1);
	qu.Enqueue(8);

	qu.MinDequeue(a);
	
	cout << a << endl;
	return 0;
}