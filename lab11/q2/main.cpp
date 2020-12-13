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
28을 추가하면, 28이 56의 왼쪽 자식 + 28은 26을 왼쪽자식 27을 오른쪽 자식으로 갖도록 변할 것이다.
2를 추가하면 3의 왼쪽 자식으로 2가 추가된다.
40을 추가하면 42의 왼쪽 자식에 위치하도록 변할 것이다.
dequeue를 처음 실행하면 x = 56이 되고 42가 root가 된다.
dequeue를 두번째 실행하면 y = 42가 되고 40이 root가 된다.
dequeue를 세번째 실행하면 z = 40이되고 28이 root가 된다.

실제 결과도 x=56, y=42, z=40 이다.
*/