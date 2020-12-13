#include "Student.h"

void InsertionSort(Student ary[], int numElems);

void InsertionSort(Student ary[], int numElems)
{
	for (int count = 0; count < numElems; count++)
	{
		bool finished = false;
		int current = count;
		bool moreToSearch = (current != 0);

		while (moreToSearch && !finished)
		{
			if (strcmp(ary[current].getName(), ary[current-1].getName()) <0)
			{
				Swap(ary[current], ary[current - 1]);
				current--;
				moreToSearch = (current != 0);
			}
			else
				finished = true;
		}
	}
}