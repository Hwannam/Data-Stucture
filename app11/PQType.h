// Definition of class PQType, which represents the Priority Queue ADT
#include <iostream>
using namespace std;
class FullPQ{};
class EmptyPQ{};
#include "SortedType.h"
template<class ItemType>
class PQType
{
public:
  PQType();          // parameterized class constructor
  ~PQType();            // class destructor
  
  void MakeEmpty();
  // Function: Initializes the queue to an empty state.
  // Post: Queue is empty.
  
  bool IsEmpty() const;
  // Function: Determines whether the queue is empty.
  // Post: Function value = (queue is empty)
  
  bool IsFull() const;
  // Function: Determines whether the queue is full.
  // Post: Function value = (queue is full)
  
  void Enqueue(int priority, ItemType newItem);
  // Function: Adds newItem to the rear of the queue.
  // Post: if (the priority queue is full) exception FullPQ is thrown;
  //       else newItem is in the queue.
  
  void Dequeue(ItemType& item);
  // Function: Removes element with highest priority from the queue
  // and returns it in item.
  // Post: If (the priority queue is empty) exception EmptyPQ is thrown;
  //       else highest priority element has been removed from queue.
  //       item is a copy of removed element.
    void Ordering(int** orderList, int M);
private:
  int length;
 SortedType<ItemType> linkedList;
  //int maxItems;
};

template<class ItemType>
PQType<ItemType>::PQType()
{
  length = linkedList.LengthIs();
}

template<class ItemType>
void PQType<ItemType>::MakeEmpty()
{
  length = 0;
}

template<class ItemType>
PQType<ItemType>::~PQType()
{
	linkedList.MakeEmpty();
}

template<class ItemType>
void PQType<ItemType>::Ordering(int** orderList, int M)
{
    // Input Your Code
    // You only need to write the code that changes the priority according to the orderlist.
    NodeType<ItemType>* tempPtr;
    NodeType<ItemType>* x;
    NodeType<ItemType>* y;
    int pr;
    for (int i = 0; i < M; i++) 
    {
        int a = orderList[i][0];
        int b = orderList[i][1];

        tempPtr = linkedList.list(); 
        x = tempPtr; // ���� Ǫ�� ���� ���� ���� ����
        y = tempPtr; // �ʰ� Ǫ�� ���� ���� ���� ����
        while (tempPtr != NULL)
        {
            if (tempPtr->info == a)
                x = tempPtr; // x�� ���� Ǫ�� ���� ���� ���� ��� 
            else if (tempPtr->info == b)
                y = tempPtr; // y�� �ʰ� Ǫ�� ���� ���� ���� ��� 
            tempPtr = tempPtr->next;
        }

        if (x->priority < y->priority)
        {
            pr = x->priority;
            x->priority = y->priority;
            y->priority = pr; // �켱 ���� swap
        }
 
        tempPtr = y; // �ʰ� Ǫ�� ���� ���� ���� ��� ���� ����
        while (tempPtr != NULL)
        {
            if (tempPtr->info > y->info && tempPtr->priority > y->priority && tempPtr->info != x->info)
            { // ���� ��ȣ�� �� ū��, �켱������ �� ũ�� �켱���� swap, ���� Ǫ�� ���� ���� ������ ����
                pr = y->priority;
                y->priority = tempPtr->priority;
                tempPtr->priority = pr;
            }
            tempPtr = tempPtr->next;
        }

        if (i != 0) // ���� ó����, ���� ������ �����ϴ� �� Ȯ��
        {
            while (1)
            {
                int count = 0;
                for (int j = 0; i - j >= 0; j++)
                {
                    a = orderList[j][0];
                    b = orderList[j][1];
                    tempPtr = linkedList.list();
                    while (tempPtr != NULL) //�տ����� ���������� x�� ����, y�� �ʰ� Ǫ�� ���� ���� ���� ���
                    {
                        if (tempPtr->info == a)
                            x = tempPtr;
                        else if (tempPtr->info == b)
                            y = tempPtr;
                        tempPtr = tempPtr->next;
                    }
                    if (x->priority < y->priority) // ������ �������� ������ �켱���� swap
                    {
                        pr = x->priority;
                        x->priority = y->priority;
                        y->priority = pr;
                        count++;
                    }
                }
                if (count == 0)
                break;
            }
        }
        tempPtr = linkedList.list();
        while (tempPtr != NULL) 
        {
            cout << tempPtr->priority << " " << tempPtr->info << endl;
           tempPtr = tempPtr->next;
        }
        cout << endl;
    }
    // �������� node->priority ���� �ٲ���� ������ node�� ������ �켱������ �ٸ�
    // ����, ��� ����� �Էµ� ���� ������� ��µǹǷ� ������ �ʿ���
    NodeType<ItemType>* temp2;
    tempPtr = linkedList.list();
    temp2 = linkedList.list();
    while (tempPtr != NULL)
    {
        while (temp2 != NULL)
        {
            if (tempPtr->priority < temp2->priority) // priority�� ���� node�� info�� priority�� �� node�� �̵�
            {
                pr = tempPtr->priority; // priority swap
                tempPtr->priority = temp2->priority;
                temp2->priority = pr;

                pr = tempPtr->info; // info swap
                tempPtr->info = temp2->info;
                temp2->info = pr;
            }
            temp2 = temp2->next;
        }
        tempPtr = tempPtr->next;
        temp2 = tempPtr;
    } //listdata�� �켱������ ���� ���� node�� ����Ŵ, �� ���� ���鵵 �켱���� ������ ����
    delete tempPtr, temp2,x,y;
}


template<class ItemType>
void PQType<ItemType>::Dequeue(ItemType& item)
// Post: element with highest priority has been removed 
//       from the queue; a copy is returned in item.
{
  if (length == 0)
    throw EmptyPQ();
  else
  {
	
	linkedList.ResetList();
    linkedList.GetNextItem(item);
	linkedList.DeleteItem(item);
    length--;
  
  }
}

template<class ItemType>
void PQType<ItemType>::Enqueue(int priority, ItemType newItem)
// Post: newItem is in the queue.
{
  if (linkedList.IsFull())
    throw FullPQ();
  else
  {
    length++;
	linkedList.InsertItem(priority, newItem);
  }
}
template<class ItemType>
bool PQType<ItemType>::IsFull() const
// Post: Returns true if the queue is full; false, otherwise.
{
  return linkedList.IsFull();
}

template<class ItemType>
bool PQType<ItemType>::IsEmpty() const
// Post: Returns true if the queue is empty; false, otherwise.
{
  return length == 0;
}

