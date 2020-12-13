#include "QueType.h"

int main() {
	// ���� �ʱ�ȭ
	char input[INPUT_MAX_SIZE];
	bool isPalindromes = true;
	

	// To-Do 1: INPUT_MAX_SIZE�� �����Ͽ� QueType ���� queue, reverseQueue�ʱ�ȭ 
	QueType queue(INPUT_MAX_SIZE);
	QueType reverseQueue(INPUT_MAX_SIZE);


	// To-Do 3: input������ �Է¹ޱ� 
	cin.getline(input, INPUT_MAX_SIZE);
	

	// To-Do 4: queue, reverseQueue�� enqueue
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
		// ���������� ������ queue�� length == 0�̰ų�
		// dequeue�� ItemType�� ���� �ٸ� ��� 
	}
	
	// ���
	if (isPalindromes) cout << "O" << endl;
	else cout << "X" << endl;

	return 0;
}