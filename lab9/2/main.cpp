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
	tree.Print(fout); // o 삭제된 tree를 txt파일에 출력

	cout << "o자리에 들어온 값은 " << tree.pp() << endl; // k->right 출력
	
	fout.close();

	return 0;
}