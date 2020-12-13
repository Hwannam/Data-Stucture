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
        x = tempPtr; // 먼저 푸는 것이 좋은 문제 변수
        y = tempPtr; // 늦게 푸는 것이 좋은 문제 변수
        while (tempPtr != NULL)
        {
            if (tempPtr->info == a)
                x = tempPtr; // x에 먼저 푸는 것이 좋은 문제 노드 
            else if (tempPtr->info == b)
                y = tempPtr; // y에 늦게 푸는 것이 좋은 문제 노드 
            tempPtr = tempPtr->next;
        }

        if (x->priority < y->priority)
        {
            pr = x->priority;
            x->priority = y->priority;
            y->priority = pr; // 우선 순위 swap
        }
 
        tempPtr = y; // 늦게 푸는 것이 좋은 문제 노드 부터 시작
        while (tempPtr != NULL)
        {
            if (tempPtr->info > y->info && tempPtr->priority > y->priority && tempPtr->info != x->info)
            { // 문제 번호가 더 큰데, 우선순위도 더 크면 우선순위 swap, 먼저 푸는 것이 좋은 문제는 제외
                pr = y->priority;
                y->priority = tempPtr->priority;
                tempPtr->priority = pr;
            }
            tempPtr = tempPtr->next;
        }

        if (i != 0) // 조건 처리후, 이전 조건을 만족하는 지 확인
        {
            while (1)
            {
                int count = 0;
                for (int j = 0; i - j >= 0; j++)
                {
                    a = orderList[j][0];
                    b = orderList[j][1];
                    tempPtr = linkedList.list();
                    while (tempPtr != NULL) //앞에서와 마찬가지로 x에 먼저, y에 늦게 푸는 것이 좋은 문제 노드
                    {
                        if (tempPtr->info == a)
                            x = tempPtr;
                        else if (tempPtr->info == b)
                            y = tempPtr;
                        tempPtr = tempPtr->next;
                    }
                    if (x->priority < y->priority) // 조건을 만족하지 않으면 우선순위 swap
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
    // 위까지는 node->priority 값만 바꿔줬기 때문에 node의 순서는 우선순위와 다름
    // 따라서, 출력 결과가 입력된 문제 순서대로 출력되므로 수정이 필요함
    NodeType<ItemType>* temp2;
    tempPtr = linkedList.list();
    temp2 = linkedList.list();
    while (tempPtr != NULL)
    {
        while (temp2 != NULL)
        {
            if (tempPtr->priority < temp2->priority) // priority가 높은 node의 info와 priority를 앞 node로 이동
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
    } //listdata가 우선순위가 가장 높은 node를 가리킴, 그 다음 노드들도 우선순위 순서로 정렬
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

