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
			tree.RetrieveItem(item, found); // O(logN)이 걸림

			if (!found)
				return false;
		}
		return true;
	}
}

// bst에서 leaf node의 수를 2배로 증가시킬때마다 level은 1씩 증가하는데, 최악의 경우에도 log2(N)+1 단계만 탐색하면 item이 있는지 확인할 수 있다.
// 반면에 list에서는 최악의 경우 마지막 N 번째까지 탐색해야한다.
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
			list.RetrieveItem(item, found); // O(N)이 걸림
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
		cout << "동일한 값을 갖는다." << endl;
	else
		cout << "동일한 값을 갖지 않는다." << endl;

	tr = MatchingItem_Unsorted_2(tree, list);
	if (tr == true)
		cout << "동일한 값을 갖는다." << endl;
	else
		cout << "동일한 값을 갖지 않는다." << endl;

    return 0;
}

