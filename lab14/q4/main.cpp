#include "HashTable.h"
#include "Student.h"

int main()
{
	Student stu[100];
	stu[0].InitValue(2003200111, "aaa", 3.0);
	stu[1].InitValue(2004200121, "bbb", 3.2);
	stu[2].InitValue(2005200132, "ccc", 2.7);

	HashTable<Student> ht;
	for (int i = 0; i < 3; i++) 
	{
		ht.InsertItem(stu[i]);
	}

	char key[100];
	cin >> key;
	bool found;
	Student item;
	item.InitValue(0, key, 0.0);
	ht.RetrieveItem(item, found);
	cout << item;
	return 0;
}