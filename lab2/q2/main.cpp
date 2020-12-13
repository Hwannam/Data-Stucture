#include <iostream>
#include <fstream>
#include "ItemType.h"
#include "unsorted.h"
using namespace std;

int main() 
{
	ItemType a,b,c,d;
	UnsortedType X;
	
	ofstream fout1("deleteA.txt");
	ofstream fout2("deleteA_diff.txt");
	ofstream fout3("deleteC.txt");

	a.Initialize(1);
	b.Initialize(2);
	c.Initialize(3);
	d.Initialize(4);
	X.InsertItem(a);
	X.InsertItem(b);
	X.InsertItem(c);
	X.InsertItem(a);
	X.InsertItem(c); // list�� 12313 �� ����

	X.DeleteItem_a(d); // 4�� ���� -> list ���� ����
	X.show(fout1); // deleteA.txt�� 12313 ���	

	X.DeleteItem_a(a); // 1�� ���� -> 1�� 2�������� DeleteItem_a �Լ����� �ߺ� ���� ����� �����Ƿ�, 1�� �� ���� ����(�� ���� 3�� �� ������ �´�)
	X.show(fout2); // deleteA_diff.txt�� 3231 ���	

	X.DeleteItem_c(c); // 3�� ���� -> 3�� 2�� �����Ƿ� ��� ���� (�� ���� 1�� �� ������ �´�)
	X.show(fout3); // deleteC.txt.�� 12 ���



	fout1.close();
	fout2.close();
	fout3.close();
	return 0;
}
