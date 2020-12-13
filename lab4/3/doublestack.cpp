#include <iostream>
#include "doublestack.h"
using namespace std;

doublestack::doublestack()
{
	top_small = -1;
	top_big = 200;
}

void doublestack::Push(int item)
{
	if (item <= 1000)
	{
		if (IsFull())   
			cout << "stackÀÌ °¡µæ Ã¡½À´Ï´Ù." << endl;
		top_small++;
		items[top_small] = item;
	}
	else if (item > 1000)
	{
		if (IsFull())
			cout << "stackÀÌ °¡µæ Ã¡½À´Ï´Ù." << endl;
		top_big--;
		items[top_big] = item;
	}
}

void doublestack::Print()
{
	int small = top_small;
	int big = top_big;
	for (top_small; top_small > -1; top_small--)
	{
		cout << items[top_small] << endl;
	}
	cout << endl;
	for (top_big; top_big < 200; top_big++)
	{
		cout << items[top_big] << endl;
	}

	top_small = small;
	top_big = big;
}

bool doublestack::IsFull() const
{
	return (top_small == top_big -1); // 2°³ÀÇ flag°¡ ¿¬¼ÓÀÌ¸é °¡µæÂ÷ÀÖ´Ù.
}