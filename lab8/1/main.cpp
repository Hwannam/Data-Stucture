#include <iostream>
#include "UnsortedType.h"
using namespace std;

template <class ItemType>
ItemType SumSquares_a(NodeType<ItemType>* list) // return의 위치가 잘못되었다.
{
	if (list != NULL)
		return (list->info * list->info) + SumSquares_a(list->next);
	return 0;
}
template <class ItemType>
ItemType SumSquares_b(NodeType<ItemType>* list) //info의 제곱을 더해주어야 하는데 그냥 info를 더해주도록 되어있었다.
{
	int sum = 0;
	while (list != NULL)
	{
		sum = (list->info)*(list->info) + sum;
		list = list->next;
	}
	return sum;
}
template <class ItemType>
ItemType SumSquares_c(NodeType<ItemType>* list) // 문제 X
{
	if (list == NULL)
		return 0;
	else
		return list->info * list->info + SumSquares_c(list->next);
}
template <class ItemType>
ItemType SumSquares_d(NodeType<ItemType>* list) // 문제 X
{
	if (list->next == NULL)
		return list->info * list->info;
	else
		return list->info * list->info + SumSquares_d(list->next);
}
template <class ItemType>
ItemType SumSquares_e(NodeType<ItemType>* list) // 함수 내부에 item(info) 값을 다루는 구문이 전혀 없어서, 그냥 0을 리턴하게 된다.
{
	if (list == NULL)
		return 0;
	else
		return (list ->info*list->info + SumSquares_e(list->next));
}

int main()
{
	int item1 = 1;
	int item2 = 3;
	int item3 = 2;
	int item4 = 5;

	UnsortedType<int> list;

	list.InsertItem(item1);
	list.InsertItem(item2);
	list.InsertItem(item3);
	list.InsertItem(item4);

	list.PrintSumSquares();

	return 0;
}