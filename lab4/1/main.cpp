#include <iostream>
#include "StackTType.h"
#include "MaxItem.h"
using namespace std;

int main(){
	StackType<int> A;
	for (int i = 1; i <= 6; i++) {
		A.Push(i);
	}

	while (!A.IsEmpty())
	{
		int result = A.Top();
		A.Pop();
		cout << result << endl;
	}
	return 0;
}