#include <iostream>
#include "TreeType.h"
using namespace std;

int main()
{
	TreeType tree, tree2;
	
	tree.InsertItem('k');
	tree.InsertItem('f');
	tree.InsertItem('o');
	tree.InsertItem('c');
	tree.InsertItem('g');
	tree.InsertItem('p');
	tree.InsertItem('a');

	TreeNode * nroot;
	nroot = new TreeNode;
	tree2.forfalse(nroot);

	nroot->info = 'k';

	TreeNode* f;
	f = new TreeNode;
	f->info = 'f';
	nroot->left = f;

	TreeNode* o;
	o = new TreeNode;
	o->info = 'o';
	nroot->right = o;
	o->left = NULL;

	TreeNode* c;
	c = new TreeNode;
	c->info = 'c';
	f->left = c;
	c->right = NULL;

	TreeNode* q;
	q = new TreeNode;
	q->info = 'q';
	c->left = q;
	q->left = NULL;
	q->right = NULL;

	TreeNode* a;
	a = new TreeNode;
	a->info = 'a';
    f->right = a;
	a->left = NULL;
	a->right = NULL;

	TreeNode* p;
	p = new TreeNode;
	p->info = 'p';
	o->right = p;
	p->left = NULL;
	p->right = NULL;


	if (tree.IsBST()) 
		cout << "tree1 = true" << endl;
	else				  
		cout << "tree1 = false" << endl;

	if (tree2.IsBST())  // 위의 tree2 코드를 tree1과 같은 문자로 설정했을시엔 true가 출력되고 tree2의 문자로 설정했을시엔 false가 출력됨을 확인하였음
		cout << "tree2 = true" << endl;
	else
		cout << "tree2 = false" << endl;

	return 0;
}