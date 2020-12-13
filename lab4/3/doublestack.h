#pragma once

const int Max_items = 200;

class doublestack
{
private:
	int top_small, top_big;
	int items[Max_items];
public:
	doublestack();
	void Push(int item);
	void Print();
	bool IsFull() const;
};