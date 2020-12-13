#include <iostream>
#include <string>
#include "StackTType.h"
using namespace std;


bool isBalance(string inp) {

	// ���� ���� ��ȣ ���ڿ����� �˻�
	int left = 0;
	int right = 0;
	for (int i = 0; i < inp.length(); i++) {
		if (inp[i] == '(')
			left++;
		else if(inp[i] == ')')
			right++;
	}
	if (left == right && inp !="")
		return true;
	else return false;
}

bool isCorrect(string inp) {

	// Stack�� �̿��ؼ� �ùٸ� ��ȣ ���ڿ����� �˻�
	StackType<char> stack;
	for (int i = 0; i < inp.length(); i++) {

		if (inp[i] == '(')
			stack.Push('(');
		else if (inp[i] == ')' && !stack.IsEmpty())
			stack.Pop();
		else if (inp[i] == ')' && stack.IsEmpty())
			return false;
	}
	if (!stack.IsEmpty())
		return false;

	return true;
}

string solution(string inp) {


	string x = inp;
	string y = "";
	string z = "";
	string answer = "";

	// �Է��� ���ڿ��� ���
	if (inp == "") {

		return x;
	}
	else {

		// �������� ��ȣ ���ڿ� y, z �и�
		for (int i = 0; i < x.length(); i++) {
			
			if (isBalance(y) == true)
				z = z + x[i];
			else 
				y = y + x[i];
	
		}
		// �ùٸ� ��ȣ ���ڿ� ó��
		if (isCorrect(y)){
			y = y + solution(z);
			return y;
		}
		// �ƴ� ��쿡 ���� ó��
		else {
			answer = answer + '(';
			answer = answer + solution(z);
			answer = answer + ')';
			
			if(y!= "")
				y.erase(0,1);
			if (y != "")
				y.pop_back();
			
			for (int i = 0; i < y.length(); i++) {

				if (y[i] == '(')
					answer = answer + ')';
				else if(y[i] == ')')
					answer = answer + '(';
			}
		}

	}

	return answer;
}

int main() {

	string inp;
	string answer;

	cin >> inp;

	answer = solution(inp);

	cout << answer;

	return 0;
}

