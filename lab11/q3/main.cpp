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
sorted linkedlist로 구현한 경우,
enqueue는 sortedlist의 insertlist 함수를 사용하므로 O(N)이고
dequeue는 무조건 맨 앞에 있는 요소를 꺼내오기 때문에 O(1)이다.
(sorted list가 오름차순이었다면 O(N)일 것이다.)

heap은 
enqueue와 dequeue모두 O(logN) 이었다. 

따라서 enqueue는 sortedlist가 더 느리고
dequeue는 sortedlist가 더 빠르다.
*/