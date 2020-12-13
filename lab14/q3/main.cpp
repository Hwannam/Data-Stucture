#include <iostream>
#include "Student.h"
#include "TagSort.h"
using namespace std;

int main()
{
	Student stu[100];
	stu[0].InitValue(2003200111, "이웅재", 3.0);
	stu[1].InitValue(2004200121, "권오준", 3.2);
	stu[2].InitValue(2005200132, "김진일", 2.7);
	Student* stuPtrs[3];

	for (int k = 0; k < 3; k++)
		stuPtrs[k] = &stu[k];
	QuickSortPointer(stuPtrs, 0, 2);
	PrintByPointer(cout, stuPtrs, 3);

	cout << endl;

	Student stu2[100];
	stu2[0].InitValue(2003200111, "이웅재", 3.0);
	stu2[1].InitValue(2004200121, "권오준", 3.2);
	stu2[2].InitValue(2005200132, "김진일", 2.7);
	Student* stuPtrs2[3];
	for (int k = 0; k < 3; k++)
		stuPtrs2[k] = &stu2[k];
	MergeSortPointer(stuPtrs2, 0,2);
	PrintByPointer(cout, stuPtrs2, 3);

	return 0;
}