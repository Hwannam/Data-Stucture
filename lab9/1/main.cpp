#include <iostream>
#include <fstream>
#include "TreeType.h"
using namespace std;

int main()
{
	ofstream fout;
	fout.open("result.txt");

	TreeType tree,tree2,tree3,tree4;
	TreeNode* root;
	TreeNode* su;

	tree.InsertItem('f');
	tree.InsertItem('h');
	tree.InsertItem('d');
	tree.InsertItem('j');

	tree2.InsertItem('f');
	tree2.InsertItem('h');
	tree2.InsertItem('d');
	tree2.InsertItem('j');
	tree2.InsertItem('e');

	tree3.InsertItem('f');
	tree3.InsertItem('h');
	tree3.InsertItem('d');
	tree3.InsertItem('j');

	tree4.InsertItem('f');
	tree4.InsertItem('h');
	tree4.InsertItem('d');
	tree4.InsertItem('j');
	tree4.InsertItem('e');
	
	root = tree.getroot(); // case1 recursive  
	su = tree.PtrToSuccessorRe(root);
	cout << "case1 recursive = " << su ->info<< endl; // d
	tree.Print(fout);
	fout << endl;

	root = tree2.getroot();
	su = tree2.PtrToSuccessorRe(root); // case2 recursive
	cout << "case2 recursive = " << su->info << endl;// d
	tree2.Print(fout);
	fout << endl;

	root = tree3.getroot();
	su = tree3.PtrToSuccessorNon(root); // case1 non recursive
	cout << "case1 Nonrecursive = " << su->info << endl;// d
	tree3.Print(fout);
	fout << endl;

	root = tree4.getroot();
	su = tree4.PtrToSuccessorNon(root); // case 2 non recursive
	cout << "case2 Nonrecursive = " << su->info << endl;// d
	tree4.Print(fout);

	fout.close();
	return 0;
}