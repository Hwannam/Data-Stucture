#include <iostream>
#include <random>
#include <ctime>
#include "QueType.h"
using namespace std;

int main()
{
	QueType qu;
	ItemType item;

	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int q = rand()%20+1;
		cout << q << endl;
		qu.Enqueue(q);
	}
	cout << endl;

	for (int i = 0; i < 10; i++)
	{
		qu.Dequeue(item);
		cout << item << endl;
	}

	return 0;
}