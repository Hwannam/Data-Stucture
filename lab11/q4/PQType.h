// Definition of class PQType, which represents the Priority Queue ADT
template<class ItemType>
struct NodeType
{
    ItemType info;
    int timestamp;
    NodeType* next;
};

class FullPQ {};
class EmptyPQ {};

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

    void Enqueue(ItemType newItem);
    // Function: Adds newItem to the rear of the queue.
    // Post: if (the priority queue is full) exception FullPQ is thrown;
    //       else newItem is in the queue.

    void Dequeue();
    // Function: Removes element with highest priority from the queue
    // and returns it in item.
    // Post: If (the priority queue is empty) exception EmptyPQ is thrown;
    //       else highest priority element has been removed from queue.
    //       item is a copy of removed element.

    void GetNextItem(ItemType& item);
private:
    int length;
    NodeType<ItemType>* listData;
};

template<class ItemType>
PQType<ItemType>::PQType()
{
    listData = NULL;
    length = 0;
}

template<class ItemType>
void PQType<ItemType>::MakeEmpty()
{
    NodeType<ItemType>* tempPtr;

    while (listData != NULL)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
    length = 0;
}

template<class ItemType>
PQType<ItemType>::~PQType()
{
    MakeEmpty();
}

template<class ItemType>
void PQType<ItemType>::Dequeue()
// Post: element with highest priority has been removed 
//       from the queue; a copy is returned in item.
{
    NodeType<ItemType>* location = listData;
    NodeType<ItemType>* tempLocation;

    // Locate node to be deleted.
    if (length == listData->timestamp)
    {
        tempLocation = location;
        listData = listData->next;		// Delete first node.
    }
    else
    {
        while (!length == (location->next)->timestamp)
            location = location->next;

        // Delete node at location->next
        tempLocation = location->next;
        location->next = (location->next)->next;
    }
    delete tempLocation;
    length--;
}

template<class ItemType>
void PQType<ItemType>::Enqueue(ItemType newItem)
// Post: newItem is in the queue.
{
    NodeType<ItemType>* location;

    location = new NodeType<ItemType>;
    location->info = newItem;
    location->next = listData;
    location->timestamp = length + 1;
    listData = location;
    length++;
}
template<class ItemType>
bool PQType<ItemType>::IsFull() const
// Post: Returns true if the queue is full; false, otherwise.
{
    NodeType<ItemType>* location;
    try
    {
        location = new NodeType<ItemType>;
        delete location;
        return false;
    }
    catch (std::bad_alloc exception)
    {
        return true;
    }
}

template<class ItemType>
bool PQType<ItemType>::IsEmpty() const
// Post: Returns true if the queue is empty; false, otherwise.
{
    return length == 0;
}

template<class ItemType>
void PQType<ItemType>::GetNextItem(ItemType& item)
{
    bool tr = true;
    NodeType<ItemType>* location = listData;
    while (tr)
    {
        if (location->timestamp = length)
        {
            item = location->info;
            tr = false;
        }
        else
        {
            location = location->next;
        }
    }
}

