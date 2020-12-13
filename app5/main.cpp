#include "QueType.h"

int main() {
	// 변수 초기화
	char input[INPUT_MAX_SIZE];
	bool isPalindromes = true;
	

	// To-Do 1: INPUT_MAX_SIZE를 전달하여 QueType 변수 queue, reverseQueue초기화 
	QueType queue(INPUT_MAX_SIZE);
	QueType reverseQueue(INPUT_MAX_SIZE);


	// To-Do 3: input변수에 입력받기 
	cin.getline(input, INPUT_MAX_SIZE);
	

	// To-Do 4: queue, reverseQueue에 enqueue
	for (int i = 0; i < strlen(input); i++) {
		if (isalpha(input[i]) != 0)
		{
			input[i] = tolower(input[i]);
			queue.Enqueue(input[i]);
		}
		if (isalpha(input[strlen(input) - i - 1]) != 0)
		{
			input[strlen(input) - i - 1] = tolower(input[strlen(input) - i - 1]);
			reverseQueue.Enqueue(input[strlen(input) - i - 1]);
		}
	}

	// To-Do 5: Palindromes check 
	ItemType item, reverseItem;
	while (true) { 
		if (queue.Length() != 0 && reverseQueue.Length() != 0)
		{
			queue.Dequeue(item);
			reverseQueue.Dequeue(reverseItem);
			
			if (item != reverseItem)
			isPalindromes = false;
		}
		
		if (queue.Length() == 0 || reverseQueue.Length() == 0 || isPalindromes == false)
		{
			break;
		}
		// 빠져나오는 조건은 queue의 length == 0이거나
		// dequeue한 ItemType의 값이 다른 경우 
	}
	
	// 출력
	if (isPalindromes) cout << "O" << endl;
	else cout << "X" << endl;

	return 0;
}