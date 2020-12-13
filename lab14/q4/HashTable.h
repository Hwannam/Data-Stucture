#include "Student.h"
#define MAX_ITEMS 100

template <class ItemType>
class HashTable
{
public:
	HashTable();
	int Hash(char* key) const;
	void InsertItem(ItemType item);
	void RetrieveItem(ItemType& item, bool& found);
private:
	Student info[MAX_ITEMS];
	int length;
	Student emptyItem;
};

template <class ItemType>
HashTable<ItemType>::HashTable()
{
	for (int i = 0; i < MAX_ITEMS; i++)
	{
		info[i].InitValue(0,"empty",0.0);
	}
	length = 0;
	emptyItem.InitValue(0, "empty", 0.0);
}

int getIntFromString(char* key);

template <class ItemType>
int HashTable<ItemType>::Hash(char* key) const
{
	return (getIntFromString(key) % MAX_ITEMS);
}

template <class ItemType>
void HashTable<ItemType>:: InsertItem(ItemType item)
{
	int location;
	location = Hash(item.Key());
	while (info[location] != emptyItem)
	{
		location = (location + 1) % MAX_ITEMS;
	}
	info[location] = item;
	length++;
}

template<class ItemType>
void HashTable<ItemType>::RetrieveItem(ItemType& item, bool& found)
{
	int location;
	int startLoc;
	bool moreToSearch = true;

	startLoc = Hash(item.getName()); // hash addr를 구한다
	location = startLoc;
	do {
		if (info[location] == item || info[location] == emptyItem)
			moreToSearch = false;
		else
			location = location+1; // linear probing
	} while (moreToSearch);

	found = (info[location]== item);
	if (found)
	{
		item = info[location]; // copy item
	}
}

int getIntFromString(char* key)
{
	int sum = 0;
	int len = strlen(key);
	if (len % 2 == 1) len++;
	for (int j = 0; j < len; j += 2)
		sum = (sum + 100 * key[j] + key[j + 1]) % 19937;
	return sum;
}