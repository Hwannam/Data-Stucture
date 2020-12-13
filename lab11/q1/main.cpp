#include <iostream>
#include "PQType.h"
using namespace std;

int main()
{
	PQType<char> heap(11);
	heap.Enqueue('J');
	heap.Enqueue('H');
	heap.Enqueue('I');
	heap.Enqueue('D');
	heap.Enqueue('G');
	heap.Enqueue('F');
	heap.Enqueue('A');
	heap.Enqueue('B');
	heap.Enqueue('C');
	heap.Enqueue('E');
	heap.Enqueue('K');

	char item;	
	// PQType.h���� reheapup_non, reheapdown_non���� �ٲ� ���� 
	heap.Dequeue(item);
	cout << item << endl; // ���� ū k, enqueue�ϸ� reheapup�� ����� ����
	heap.Dequeue(item);
	cout << item << endl; // �� ���� ū j, ������ dequeue�� �� reheapdown ����� ����

	return 0;
}

/* C
�Ѵ� O(logN)�̴�.
�־��� ��쿡�� Ʈ�������� �ܰ� ��ŭ�� �׽�Ʈ�ϸ� ������ �Ϸ�Ǳ� �����̴�.
*/