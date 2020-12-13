#include "Student.h"

void Split(Student values[], int first, int last, int& splitPoint) 
{
	// 비교 기준 설정
	Student splitVal = values[first];
	int saveFirst = first;
	bool onCorrectSide;

	first++;
	do {
		onCorrectSide = true;
		// 비교 대상을 인덱스가 더 큰쪽으로 이동하여 학생들을 비교함
		while (onCorrectSide) 
		{
			// 이름을 기준으로 현재 인덱스의 학생과 기준점의 학생을 비굫나다.
			if (strcmp(values[saveFirst].getName(), values[first].getName()) < 0)
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
			if (strcmp(values[saveFirst].getName(), values[last].getName()) > 0)
				onCorrectSide = false;
			else {
				last--;
				onCorrectSide = (first <= last);
			}
		}

		if (first < last) 
		{
			Swap(values[first], values[last]);
			first++;
			last--;
		}
	} while (first <= last);

	splitPoint = last;
	Swap(values[saveFirst], values[splitPoint]);
}


void QuickSort(Student values[], int first, int last)
{
	if (first < last)
	{
		int splitPoint;

		Split(values, first, last, splitPoint);

		QuickSort(values, first, splitPoint - 1);
		QuickSort(values, splitPoint + 1, last);
	}
}