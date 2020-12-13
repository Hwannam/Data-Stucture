#include <iostream>
#include "UnsortedType.h"
#include "TreeType.h"
using namespace std;

bool MatchingItem_Unsorted(TreeType& tree, UnsortedType<ItemType>& list)
{
	int list_length = list.LengthIs();
	int tree_length = tree.LengthIs();

	if (list_length != tree_length)
	{
		return false;
	}
	else
	{
		ItemType item;
		bool found;

		list.ResetList(); 
		for (int i = 0; i < list_length; i++) 
		{
			list.GetNextItem(item);
			tree.RetrieveItem(item, found); // O(logN)�� �ɸ�

			if (!found)
				return false;
		}
		return true;
	}
}

// bst���� leaf node�� ���� 2��� ������ų������ level�� 1�� �����ϴµ�, �־��� ��쿡�� log2(N)+1 �ܰ踸 Ž���ϸ� item�� �ִ��� Ȯ���� �� �ִ�.
// �ݸ鿡 list������ �־��� ��� ������ N ��°���� Ž���ؾ��Ѵ�.
bool MatchingItem_Unsorted_2(TreeType& tree, UnsortedType<ItemType>& list)
{
	int list_length = list.LengthIs();
	int tree_length = tree.LengthIs();
	
	if (list_length != tree_length)
	{
		return false;
	}
	else
	{
		ItemType item;
		bool found;
		
		tree.ResetTree(IN_ORDER); 
		for (int i = 0; i < list_length; i++) {
			tree.GetNextItem(item, IN_ORDER, found);
			list.RetrieveItem(item, found); // O(N)�� �ɸ�
			if (!found)
				return false;
		}
		return true;
	}
}

int main() 
{
	UnsortedType<char> list;
	list.InsertItem('a');
	list.InsertItem('e');
	list.InsertItem('b');
	list.InsertItem('h');
	list.InsertItem('z');
	list.InsertItem('k');
	list.InsertItem('g');
	
	TreeType tree;
	tree.InsertItem('g');
	tree.InsertItem('b');
	tree.InsertItem('k');
	tree.InsertItem('a');
	tree.InsertItem('e');
	tree.InsertItem('h');
	tree.InsertItem('z');

	bool tr = MatchingItem_Unsorted(tree, list);
	if (tr == true)
		cout << "������ ���� ���´�." << endl;
	else
		cout << "������ ���� ���� �ʴ´�." << endl;

	tr = MatchingItem_Unsorted_2(tree, list);
	if (tr == true)
		cout << "������ ���� ���´�." << endl;
	else
		cout << "������ ���� ���� �ʴ´�." << endl;

    return 0;
}

