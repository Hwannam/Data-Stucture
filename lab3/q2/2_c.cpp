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
			return array[midpoint];
		}

		if (moreToSearch == 0)
		{
			return array[first];
		}
	}
}

int main(){
	
	int list[5] = {2,4,5,6,10};
	int result = BinarySearch(list, 5, 8);
	cout << result << endl; // 10 출력
	result = BinarySearch(list, 5, 4); 
	cout << result << endl; // 4 출력

	return 0;
}