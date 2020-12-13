#include <iostream>
#include "StackType.h"
using namespace std;

int main()
{
	StackType<int> stack;

	stack.Push(1);
	stack.Push(2);
	stack.Push(3);
	stack.Push(4);
	stack.Push(5);
	stack.Push(6);
	stack.Push(7);

	while (!stack.IsEmpty())
	{
		cout << stack.Top() << " ";
		stack.Pop();
	}
	cout << endl;
	return 0;
}

// unsorted list로 priority queue 구현후 stack에서 활용
// A. 최우선순위는 가장 늦게 들어간 원소이다.
// C. 4장에서 구현된 push, pop은 O(1) 이었다.
// unsorted list로 구현했고 늦게 들어간 것이 가장 우선순위가 높도록 설계되어있기 때문에 항상 맨 앞의 원소가 추가, 제거 되므로
// O(1)로 동일하다. 하지만 우선 순위를 부여하는 방식을 다르게 하거나 pq를 구현한 방법을 다르게 한다면 시간복잡도도 달라질 것이다.
