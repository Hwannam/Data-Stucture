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

// unsorted list�� priority queue ������ stack���� Ȱ��
// A. �ֿ켱������ ���� �ʰ� �� �����̴�.
// C. 4�忡�� ������ push, pop�� O(1) �̾���.
// unsorted list�� �����߰� �ʰ� �� ���� ���� �켱������ ������ ����Ǿ��ֱ� ������ �׻� �� ���� ���Ұ� �߰�, ���� �ǹǷ�
// O(1)�� �����ϴ�. ������ �켱 ������ �ο��ϴ� ����� �ٸ��� �ϰų� pq�� ������ ����� �ٸ��� �Ѵٸ� �ð����⵵�� �޶��� ���̴�.
