#include <iostream>
#include "TreeType.h"
using namespace std;

int main() {

	TreeType tree;

	int node_num = 0;
	int num = 0;

	cin >> node_num;
	for (int i = 0; i < node_num; i++) {
		cin >> num;
		tree.InsertItem(num);
	}

	int node1 = 0;
	int node2 = 0;

	cin >> node1 >> node2;
	/*
	TODO : ���� ����� ���� ���� ���ϱ�
	*/
	ItemType* list1, * list2;
	list1 = new ItemType[node_num];
	list2 = new ItemType[node_num];
	for (int i = 0; i < node_num; i++)
	{
		list1[i] = -1;
		list2[i] = -1;
	}
	tree.Anscestors(node1, list1, node_num);
	tree.Anscestors(node2, list2, node_num);
	ItemType near=0;
	for (int i = 0; i < node_num; i++)
	{
		for (int j = 0; j < node_num; j++)
		{
			if (list1[i] == list2[j] && list1[i] != -1)
			{
				near = list1[i]; // list���� �� index�� �� ���� ��带 �̹Ƿ� �ڵ����� ���� ����� �������� near�� ������.
			}
		}
	}
	cout << near << '\n';

	return 0;
}