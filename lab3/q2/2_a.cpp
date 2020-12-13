#include <iostream>
using namespace std;

int BinarySearch(int array[], int sizeOfArray, int value)
{
	int midpoint;
	int first = 0;
	int last = sizeOfArray - 1;
	bool moreToSearch = (first <= last);
	bool found = false;
	while (moreToSearch && !found)
	{
		midpoint = (first + last) / 2;
		if (value < array[midpoint])
		{
			last = midpoint - 1;
			moreToSearch = (first <= last);
		}
		else if(value > array[midpoint])
		{
			first = midpoint + 1;
			moreToSearch = (first <= last);
		}
		else if(value == array[midpoint])
		{
			found = true;
			return midpoint;
		}

		if (moreToSearch == 0)
		{
			return -1;
		}
	}
}

int main(){
	
	int list[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int result = BinarySearch(list, 10, 11);
	cout << result << endl; // -1 출력
	result = BinarySearch(list, 10, 7); 
	cout << result << endl; // 6 출력

	return 0;
}