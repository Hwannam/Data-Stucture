#include "Student.h"

void Split(Student* values[], int first, int last, int& splitPoint) 
{
	// �� ���� ����
	Student* splitVal = values[first];
	int saveFirst = first;
	bool onCorrectSide;
	
	first++;
	do {
		onCorrectSide = true;
		// �� ����� �ε����� �� ū������ �̵��Ͽ� �л����� ����
		while (onCorrectSide) 
		{
			// �̸��� �������� ���� �ε����� �л��� �������� �л��� �񂑳���.
			if (strcmp(values[saveFirst]->getName(), values[first]->getName()) < 0)
				onCorrectSide = false;
			else {
				first++;
				onCorrectSide = (first <= last);
			}
		}
		onCorrectSide = (first <= last);
		while (onCorrectSide) 
		{
			// �̸��� �������� ���� �ε����� �л��� �������� �л��� ���Ѵ�.
			if (strcmp(values[saveFirst]->getName(), values[last]->getName()) > 0)
				onCorrectSide = false;
			else {
				last--;
				onCorrectSide = (first <= last);
			}
		}

		if (first < last) 
		{
			Swap(*values[first], *values[last]);
			first++;
			last--;
		}
	} while (first <= last);

	splitPoint = last;
	Swap(*values[saveFirst], *values[splitPoint]);
}

void QuickSortPointer(Student* values[], int first, int last)
{
	if (first < last)
	{
		int splitPoint;

		Split(values, first, last, splitPoint);

		QuickSortPointer(values, first, splitPoint - 1);
		QuickSortPointer(values, splitPoint + 1, last);
	}
}


void Merge(Student* values[], int leftFirst, int leftLast, int rightFirst, int rightLast)
{
	int arySize = rightLast - leftFirst + 1;
	Student** tempArray = new Student * [arySize];
	int index = leftFirst;
	int saveFirst = leftFirst;

	while ((leftFirst <= leftLast) && (rightFirst <= rightLast)) {
		if (strcmp(values[leftFirst]->getName(), values[rightFirst]->getName()) < 0) {
			tempArray[index] = values[leftFirst];
			leftFirst++;
		}
		else {
			tempArray[index] = values[rightFirst];
			rightFirst++;
		}
		index++;
	}

	while (leftFirst <= leftLast) {
		tempArray[index] = values[leftFirst];
		leftFirst++;
		index++;
	}

	while (rightFirst <= rightLast) {
		tempArray[index] = values[rightFirst];
		rightFirst++;
		index++;
	}

	for (index = saveFirst; index <= rightLast; index++)
	{
		values[index] = tempArray[index];
	}

	delete[] tempArray;
}

void MergeSortPointer(Student* values[], int first, int last)
{
	if (first < last)
	{
		int middle = (first + last) / 2;
		MergeSortPointer(values, first, middle);
		MergeSortPointer(values, middle + 1, last);
		Merge(values, first, middle, middle + 1, last);
	}
}