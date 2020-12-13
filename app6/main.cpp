#include "SortedType.h"
#include <iostream>

using namespace std;

/*
Program Description
App 06
�迭�� ���� N�� �Է¹���
N���� ���ڸ� �Է¹���
N���� ���ڿ� �ùٸ� �迭�� �Ǵ� �迭�� �ִ��� Ȯ��
*/

int main() {
	SortedType<int> StoreArray;
	int arrayLength;
	int num1;
	int num2 = 0;
	int count = 0;
	bool right = false;

	//TODO 1: ���� �Է��� �޴� �κ�
	//�迭�� ���� N�� N���� ������ �Է¹޴� �ڵ� �ۼ�
	cin >> arrayLength;
	for (int i = 0; i < arrayLength; i++)
	{
		cin >> num1;
		StoreArray.InsertItem(num1);
	}
	cout << endl;

	//TODO 2: 
	//����Ʈ�� item���� �ùٸ� �迭�� �ִ��� �˻��ϴ� �ڵ� �ۼ�
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
	//�˻� ����� ����ϴ� �ڵ� �ۼ�
	if (right == true)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}