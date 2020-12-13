#include "Student.h"

void SelectionSort(Student ary[], int numElems);

void SelectionSort(Student ary[], int numElems)
{
	
	int endIndex = numElems - 1;
	for (int current = 0; current < endIndex; current++)
	{
		int indexOfMin = current;
		for (int index = current + 1; index <= endIndex; index++)
		{
			if (strcmp(ary[index].getName() , ary[indexOfMin].getName())<0)
				indexOfMin = index;
		}
		Swap(ary[current], ary[indexOfMin]);
	}
}