#include "StackType.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string symbol;
    StackType stack;
    bool is_balance = true;

    cin >> symbol;

	// To-Do 1
    // �ݺ����� Stack�� �̿��Ͽ� �Է� ���� ��ȣ�� �ùٸ� ��ȣ ���ڿ����� �Ǵ�
    // �Ʒ��� ������ is_balance�� false
    // ���ܻ��� 1. ( ) �� ¦�� �ȸ���
    // ���ܻ��� 2. ( ���� ) �� ����, �ݴ��� ��쵵 ���� => (�� )�� ���� ī�������� ������ X
    // ���ܻ��� 3. (���� )�� ���� ���ͼ� ���� �ݾƹ���

    char a;
    for (int i = 0;  i< symbol.length() ; i++) 
    {
        a = symbol.at(i);

        if (a == '(') // (�� push
            stack.Push(a);
        else if (a == ')') // )�� ������ (�� pop���� ����
        {
            if (stack.IsEmpty() == 1) // )�� ���Դµ� ������ ��������� ���� �ݾƹ���
                is_balance = false;
            else
                stack.Pop();
        }
    }
    if(stack.IsEmpty() == 0) // for���� �����µ� ������ ������� �ʴٸ� (�� �� ����
        is_balance = false;

    // ��� ���
	if (is_balance) cout << "O" << endl;
	else cout << "X" << endl;

    return 0;
}
   