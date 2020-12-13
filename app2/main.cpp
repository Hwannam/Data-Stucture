#include <iostream>
#include "ItemType.h"
#include "unsorted.h"
using namespace std;

int main() 
{
	
	UnsortedType X;
	ItemType b;

	int a;
	cin >> a;

	int arr[20];
	int index = 0;

	for (int i = 0; i < a; i++)
	{
		int c;
		cin >> c;
		
		if (c > 0)
		{
			b.Initialize(c);
			X.InsertItem(b);
			arr[index] = c;
			index++;
		}
		else if (c == 0)
		{
			X.DeleteItem(b);
			b.Initialize(arr[index]);
			index--;
		}
	}

	cout << endl << X.prints() << endl;

	return 0;
}