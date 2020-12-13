#include <iostream>
#include "SortedType.h"
using namespace std;

int main()
{
	SortedType<char> list;
	list.InsertItem('X');
	list.InsertItem('Y');
	list.InsertItem('Z');
	list.InsertItem('A');
	list.InsertItem('B');
	list.InsertItem('C');
	list.PrintReverse();
	return 0;
}