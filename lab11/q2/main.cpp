#include <iostream>
#include "PQType.h"
using namespace std;

int main()
{
	PQType<int> pqueue(50);

	pqueue.Enqueue(56);
	pqueue.Enqueue(27);
	pqueue.Enqueue(42);
	pqueue.Enqueue(26);
	pqueue.Enqueue(15);
	pqueue.Enqueue(3);
	pqueue.Enqueue(19);
	pqueue.Enqueue(25);
	pqueue.Enqueue(24);
	pqueue.Enqueue(5);

	int x, y, z;
	pqueue.Enqueue(28);
	pqueue.Enqueue(2);
	pqueue.Enqueue(40);

	pqueue.Dequeue(x);
	pqueue.Dequeue(y);
	pqueue.Dequeue(z);

	cout << x << " " << y << " " << z << endl;

	return 0;
}

/*
28�� �߰��ϸ�, 28�� 56�� ���� �ڽ� + 28�� 26�� �����ڽ� 27�� ������ �ڽ����� ������ ���� ���̴�.
2�� �߰��ϸ� 3�� ���� �ڽ����� 2�� �߰��ȴ�.
40�� �߰��ϸ� 42�� ���� �ڽĿ� ��ġ�ϵ��� ���� ���̴�.
dequeue�� ó�� �����ϸ� x = 56�� �ǰ� 42�� root�� �ȴ�.
dequeue�� �ι�° �����ϸ� y = 42�� �ǰ� 40�� root�� �ȴ�.
dequeue�� ����° �����ϸ� z = 40�̵ǰ� 28�� root�� �ȴ�.

���� ����� x=56, y=42, z=40 �̴�.
*/