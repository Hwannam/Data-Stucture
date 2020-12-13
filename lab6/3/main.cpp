#include <iostream>
#include "SortedType.h"
#include "UnsortedType.h"
using namespace std;

template<class ItemType>
void MergeListsSorted(SortedType<ItemType>& l_a, SortedType<ItemType>& l_b, SortedType<ItemType>& result)
{
	ItemType item;

	for (int i = 0; i < l_a.LengthIs(); i++)
	{
		l_a.GetNextItem(item);
		result.InsertItem(item);
	}
	for (int i = 0; i < l_b.LengthIs(); i++)
	{
		l_b.GetNextItem(item);
		result.InsertItem(item);
	}
}

template<class ItemType>
void MergeListsUnsorted(UnsortedType<ItemType>& l_a, UnsortedType<ItemType>& l_b, UnsortedType<ItemType>& result)
{
	ItemType item;
for (int i = 0; i < l_b.LengthIs(); i++)
	{
		l_b.GetNextItem(item);
		result.InsertItem(item);
	}
	for (int i = 0; i < l_a.LengthIs(); i++)
	{
		l_a.GetNextItem(item);
		result.InsertItem(item);
	}
	
}

int main()
{
	SortedType<int> list1, list2, list3,list4;
	UnsortedType<int> list5, list6,list7,list8;
	int item;

	list1.InsertItem(1);
	list1.InsertItem(3);
	list1.InsertItem(5);
	list1.InsertItem(7);
	list1.InsertItem(9);
	list2.InsertItem(2);
	list2.InsertItem(4);
	list2.InsertItem(6);
	list2.InsertItem(8);
	list2.InsertItem(10);

	list5.InsertItem(3);
	list5.InsertItem(2);
	list5.InsertItem(5);
	list5.InsertItem(6);
	list5.InsertItem(1);
	list6.InsertItem(7);
	list6.InsertItem(4);
	list6.InsertItem(9);
	list6.InsertItem(8);
	list6.InsertItem(10);

	list1.ResetList();
	list2.ResetList();
	MergeListsSorted(list1, list2, list3);

	for (int i = 0; i < list3.LengthIs(); i++)
	{
		list3.GetNextItem(item);
		cout << item << endl;
	}
	cout << endl;


	list1.ResetList();
	list2.ResetList();
	list1.MergeListsSoMember(list2, list4);

	for (int i = 0; i < list4.LengthIs(); i++)
	{
		list4.GetNextItem(item);
		cout << item << endl;
	}
	cout << endl;


	list5.ResetList();
	list6.ResetList();
	MergeListsUnsorted(list5, list6, list7);

	for (int i = 0; i < list7.LengthIs(); i++)
	{
		list7.GetNextItem(item);
		cout << item << endl;
	}
	cout << endl;

	
	list5.ResetList();
	list6.ResetList();
	list5.MergeListsUnMember(list6, list8);

	for (int i = 0; i < list8.LengthIs(); i++)
	{
		list8.GetNextItem(item);
		cout << item << endl;
	}
	cout << endl;


	return 0;
}
