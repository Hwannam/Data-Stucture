#include "Student.h"

void Split(Student* values[], int first, int last, int& splitPoint) 
{
	// 비교 기준 설정
	Student* splitVal = values[first];
	int saveFirst = first;
	bool onCorrectSide;
	
	first++;
	do {
		onCorrectSide = true;
		// 비교 대상을 인덱스가 더 큰쪽으로 이동하여 학생들을 비교함
		while (onCorrectSide) 
		{
			// 이름을 기준으로 현재 인덱스의 학생과 기준점의 학생을 비굫나다.
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
			// 이름을 기준으로 현재 인덱스의 학생과 기준점의 학생을 비교한다.
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