#include <iostream>
#include "ItemType.h"
#include "sorted.h"
using namespace std;

void MergeList(SortedType list1, SortedType list2, SortedType& result) {
	list1.ResetList();                  //{
	list2.ResetList();                  //{                 O(1)
	int leng1 = list1.LengthIs();		//{
	int leng2 = list2.LengthIs();		//{

	for (int i = 0; i < leng1; i++) {   //{
		ItemType item;					//{                 O(n)
        list1.GetNextItem(item);		//{
		result.InsertItem(item);		//{
	}

	for (int i = 0; i < leng2; i++) {   //{
		ItemType item;					//{                 O(n)
		list2.GetNextItem(item);		//{
		result.InsertItem(item);		//{
	}
 }                                       //                 따라서 MergeList 함수는 O(n)


int main() {

	
	SortedType s_list1, s_list2, s_list3;
	ItemType item1, item2, item3, item4, item5, item6, item7, item8, item9, item10;
	item1.Initialize(1);
	item2.Initialize(2);
	item3.Initialize(3);
	item4.Initialize(4);
	item5.Initialize(5);
	item6.Initialize(6);
	item7.Initialize(7);
	item8.Initialize(8);
	item9.Initialize(9);
	item10.Initialize(10);

	s_list1.InsertItem(item6);
	s_list1.InsertItem(item3);
	s_list1.InsertItem(item5);
	s_list1.InsertItem(item9);
	s_list1.InsertItem(item8);
	
	s_list2.InsertItem(item2);
	s_list2.InsertItem(item1);
	s_list2.InsertItem(item7);
	s_list2.InsertItem(item4);
	s_list2.InsertItem(item10);

	MergeList(s_list1, s_list2, s_list3);
	s_list1.Show();
	s_list2.Show();
	s_list3.Show();

	return 0;
}