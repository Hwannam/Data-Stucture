#include <iostream>
#include "UnsortedType.h"
using namespace std;

int main()
{
	UnsortedType<int> list;
	list.InsertItem(4);
	list.InsertItem(1);
	list.InsertItem(7);
	list.InsertItem(5);

	list.Sorting();

	int item;
	list.ResetList();
	for (int i = 0; i < list.LengthIs(); i++)
	{
		list.GetNextItem(item);
		cout << item << " ";
	}
	cout << endl;
	return 0;
}