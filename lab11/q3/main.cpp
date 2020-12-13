#include <iostream>
#include "PQType.h"
using namespace std;

int main()
{
	PQLLType<int> pq;

	pq.Enqueue(4);
	pq.Enqueue(3);
	pq.Enqueue(1);
	pq.Enqueue(2);
	pq.Enqueue(6);
	pq.Enqueue(5);
	
	while (!pq.IsEmpty())
	{
		int a;
		pq.Dequeue(a);
		cout << a << " ";
	}

	cout << endl;
	return 0;
}

/*
sorted linkedlist�� ������ ���,
enqueue�� sortedlist�� insertlist �Լ��� ����ϹǷ� O(N)�̰�
dequeue�� ������ �� �տ� �ִ� ��Ҹ� �������� ������ O(1)�̴�.
(sorted list�� ���������̾��ٸ� O(N)�� ���̴�.)

heap�� 
enqueue�� dequeue��� O(logN) �̾���. 

���� enqueue�� sortedlist�� �� ������
dequeue�� sortedlist�� �� ������.
*/