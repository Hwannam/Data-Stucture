#include <iostream>
#include <string>
#include "StackTType.h"
using namespace std;


bool isBalance(string inp) {

	// 균형 잡힌 괄호 문자열인지 검사
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

	// Stack을 이용해서 올바른 괄호 문자열인지 검사
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

	// 입력이 빈문자열이 경우
	if (inp == "") {

		return x;
	}
	else {

		// 균형잡힌 괄호 문자열 y, z 분리
		for (int i = 0; i < x.length(); i++) {
			
			if (isBalance(y) == true)
				z = z + x[i];
			else 
				y = y + x[i];
	
		}
		// 올바른 괄호 문자열 처리
		if (isCorrect(y)){
			y = y + solution(z);
			return y;
		}
		// 아닌 경우에 대한 처리
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

