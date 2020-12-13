#include <iostream>
using namespace std;

template <class ItemType>
void Swap(ItemType& x, ItemType& y) {
    ItemType t = x;
    x = y;
    y = t;
}

template<class ItemType>
void ReheapDown(ItemType elements[], int root, int bottom)
// Post: Heap property is restored.
{
    int maxChild;
    int rightChild;
    int leftChild;

    leftChild = root * 2 + 1;
    rightChild = root * 2 + 2;
    if (leftChild <= bottom)
    {
        if (leftChild == bottom)
            maxChild = leftChild;
        else
        {
            if (elements[leftChild] <= elements[rightChild])
                maxChild = rightChild;
            else
                maxChild = leftChild;
        }
        if (elements[root] < elements[maxChild])
        {
            Swap(elements[root], elements[maxChild]);
            ReheapDown(elements, maxChild, bottom);
        }
    }
}


template<class ItemType>
void HeapSort(ItemType values[], int numValues)
{
    int index;

    cout << "입력= ";
    for (index = 0; index < numValues; index++)
    {
        cout << values[index] << " ";
    }
    cout << endl;
    
    for (index = numValues / 2 - 1; index >= 0; index--)
        ReheapDown(values, index, numValues - 1);
    cout << "Heap= ";
    for (index = 0; index < numValues; index++)
    {
        cout << values[index] << " ";
    }
    cout << endl;

    for (index = numValues - 1; index >= 1; index--)
    {
        Swap(values[0], values[index]);
        ReheapDown(values, 0, index - 1);
    }
    cout << "최종= ";
    for (index = 0; index < numValues; index++)
    {
        cout << values[index] << " ";
    }
    cout << endl;
  
}
