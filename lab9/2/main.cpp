#include <iostream>
#include <fstream>
#include "TreeType.h"
using namespace std;

int main()
{
	ofstream fout;
	fout.open("result.txt");

	TreeType tree;

	tree.InsertItem('k');
	tree.InsertItem('d');
	tree.InsertItem('o');
	tree.InsertItem('a');
	tree.InsertItem('f');
	tree.InsertItem('x');
	tree.InsertItem('v');
	

	tree.DeleteItem('o');
	tree.Print(fout); // o ������ tree�� txt���Ͽ� ���

	cout << "o�ڸ��� ���� ���� " << tree.pp() << endl; // k->right ���
	
	fout.close();

	return 0;
}