#include "Student.h"

void BubbleSort(Student ary[], int numElems);

void BubbleSort(Student ary[], int numElems)
{
	int current = 0;

	while (current < numElems - 1)
	{
		for (int index = numElems - 1; index > current; index--)
		{
			if (strcmp(ary[index].getName(), ary[index - 1].getName()) < 0)
				Swap(ary[index], ary[index - 1]);
		}
		current++;
	}
}