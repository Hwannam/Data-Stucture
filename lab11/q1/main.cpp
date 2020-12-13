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
	// PQType.h에서 reheapup_non, reheapdown_non으로 바꾼 상태 
	heap.Dequeue(item);
	cout << item << endl; // 가장 큰 k, enqueue하며 reheapup이 제대로 동작
	heap.Dequeue(item);
	cout << item << endl; // 그 다음 큰 j, 위에서 dequeue한 후 reheapdown 제대로 동작

	return 0;
}

/* C
둘다 O(logN)이다.
최악의 경우에도 트리구조의 단계 만큼만 테스트하면 동작이 완료되기 때문이다.
*/