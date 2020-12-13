#include <iostream>
#include "UnsortedType.h"
using namespace std;

template <class ItemType>
ItemType SumSquares_a(NodeType<ItemType>* list) // return�� ��ġ�� �߸��Ǿ���.
{
	if (list != NULL)
		return (list->info * list->info) + SumSquares_a(list->next);
	return 0;
}
template <class ItemType>
ItemType SumSquares_b(NodeType<ItemType>* list) //info�� ������ �����־�� �ϴµ� �׳� info�� �����ֵ��� �Ǿ��־���.
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
ItemType SumSquares_c(NodeType<ItemType>* list) // ���� X
{
	if (list == NULL)
		return 0;
	else
		return list->info * list->info + SumSquares_c(list->next);
}
template <class ItemType>
ItemType SumSquares_d(NodeType<ItemType>* list) // ���� X
{
	if (list->next == NULL)
		return list->info * list->info;
	else
		return list->info * list->info + SumSquares_d(list->next);
}
template <class ItemType>
ItemType SumSquares_e(NodeType<ItemType>* list) // �Լ� ���ο� item(info) ���� �ٷ�� ������ ���� ���, �׳� 0�� �����ϰ� �ȴ�.
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