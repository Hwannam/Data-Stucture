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
    // 반복문과 Stack을 이용하여 입력 받은 괄호가 올바른 괄호 문자열인지 판단
    // 아래의 사항은 is_balance가 false
    // 예외사항 1. ( ) 의 짝이 안맞음
    // 예외사항 2. ( 보다 ) 이 많다, 반대의 경우도 동일 => (와 )의 개수 카운팅으로 구현은 X
    // 예외사항 3. (보다 )이 먼저 나와서 먼저 닫아버림

    char a;
    for (int i = 0;  i< symbol.length() ; i++) 
    {
        a = symbol.at(i);

        if (a == '(') // (은 push
            stack.Push(a);
        else if (a == ')') // )가 나오면 (를 pop으로 제거
        {
            if (stack.IsEmpty() == 1) // )가 나왔는데 스택이 비어있으면 먼저 닫아버림
                is_balance = false;
            else
                stack.Pop();
        }
    }
    if(stack.IsEmpty() == 0) // for문이 끝났는데 스택이 비어있지 않다면 (가 더 많음
        is_balance = false;

    // 결과 출력
	if (is_balance) cout << "O" << endl;
	else cout << "X" << endl;

    return 0;
}
   