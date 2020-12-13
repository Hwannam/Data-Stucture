#include <iostream>
#include "QueType.h"
using namespace std;

QueType::QueType(int max)
// Parameterized class constructor
// Post: maxQue, front, and rear have been initialized.
//       The array to hold the queue elements has been dynamically
//       allocated.
{
    maxQue = max + 1;
    front = maxQue - 1;
    rear = maxQue - 1;
    items = new ItemType[maxQue];
    minimum_pos = -1;
}
QueType::QueType()          // Default class constructor
// Post: maxQue, front, and rear have been initialized.
//       The array to hold the queue elements has been dynamically
//       allocated.
{
    maxQue = 501;
    front = maxQue - 1;
    rear = maxQue - 1;
    items = new ItemType[maxQue];
    minimum_pos = -1;
}
QueType::~QueType()         // Class destructor
{
    delete[] items;
}

void QueType::MakeEmpty()
// Post: front and rear have been reset to the empty state.
{
    front = maxQue - 1;
    rear = maxQue - 1;
}

bool QueType::IsEmpty() const
// Returns true if the queue is empty; false otherwise.
{
    return (rear == front);
}

bool QueType::IsFull() const
// Returns true if the queue is full; false otherwise.
{
    return ((rear + 1) % maxQue == front);
}

void QueType::Enqueue(ItemType newItem)
// Post: If (queue is not full) newItem is at the rear of the queue;
//       otherwise a FullQueue exception is thrown.  
{ 
    int i = 0;
    int small = -100;
    bool tr = true;

    if (IsEmpty())
    {
        rear = (rear + 1) % maxQue;
        items[rear] = newItem;
        minimum_pos = rear;
    }
    else
    {
            if (IsFull())
                throw FullQueue();
            else
            {
                for(int k=0; k <maxQue; k++)
                {
                    if (items[k] == -1)
                    {
                        tr = false;
                        items[k] = newItem;
             
                        break;
                    }
              
                }
                if (tr == true)

                {
                    rear = (rear + 1) % maxQue;
                    items[rear] = newItem;
                }
            } 
            
            for(int k=0; k <maxQue; k++)
            {
                if (k == 0)
                {
                    small = items[k];
                    minimum_pos = k;
                }
                else
                {
                    if (items[k] < small && items[k] >=0 )
                    {
                        small = items[k];
                        minimum_pos = k;
                    }
                }
            }
    }
    cout << minimum_pos << endl;
}

void QueType::Dequeue(ItemType& item)
// Post: If (queue is not empty) the front of the queue has been 
//       removed and a copy returned in item; 
//       othersiwe a EmptyQueue exception has been thrown.
{
    if (IsEmpty())
        throw EmptyQueue();
    else
    {
        front = (front + 1) % maxQue;
        item = items[front];
    }
}

void QueType::MinDequeue(ItemType& item)
{
    item = items[minimum_pos];
    items[minimum_pos] = -1;

    int small =-100;
    
    for (int k = 0; k < maxQue; k++)
    {
        if (k == 0)
        {
            small = items[k];
            minimum_pos = k;
        }
        else
        {
            if (items[k] < small && items[k] >0)
            {
                small = items[k];
                minimum_pos = k;
            }     
        }
    }
}
