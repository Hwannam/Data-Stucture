#include "SortedType.h"
#include <iostream>

using namespace std;

/*
Program Description
App 06
배열의 길이 N을 입력받음
N개의 숫자를 입력받음
N개의 숫자에 올바른 배열이 되는 배열이 있는지 확인
*/

int main() {
	SortedType<int> StoreArray;
	int arrayLength;
	int num1;
	int num2 = 0;
	int count = 0;
	bool right = false;

	//TODO 1: 숫자 입력을 받는 부분
	//배열의 길이 N과 N개의 숫자을 입력받는 코드 작성
	cin >> arrayLength;
	for (int i = 0; i < arrayLength; i++)
	{
		cin >> num1;
		StoreArray.InsertItem(num1);
	}
	cout << endl;

	//TODO 2: 
	//리스트의 item들이 올바른 배열이 있는지 검사하는 코드 작성
	StoreArray.ResetList();
	for (int i = 0; i < arrayLength; i++)
	{ 
		StoreArray.GetNextItem(num1);
		if (i == 0)
			num2 = num1;
		else
		{
			if (num1 == num2 + 1)
				count++;
			else
				count = 0;
			num2 = num1;
		}

		if (count == 4)
			right = true;
	}


	//TODO 3:
	//검사 결과를 출력하는 코드 작성
	if (right == true)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}