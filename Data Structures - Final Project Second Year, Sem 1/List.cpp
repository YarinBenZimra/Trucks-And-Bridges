#include "List.h"
#include "ListNode.h"
#include <iomanip>

List::List() :sizeOfList(0) // c'tor
{
    tail = head = new ListNode;
    tail->SetNext(nullptr);
}

List::~List() //d'tor
{   
    ListNode* saver;
    ListNode* curr = First();

    while (curr != nullptr)
    {
        saver = curr->GetNext();
        delete curr;
        curr = saver;
    }
}

ListNode* List::First() const { return head; }

ListNode* List::Last() const { return tail; }

int List::isEmptyList() const
{ 
    return head == nullptr;  
}

int List::GetListSize() const { return sizeOfList; }

void List::CreateNewListNode(float h)
{
    ListNode* newNode = new ListNode(h);
    tail->insertAfter(newNode);
    tail = newNode;
    tail->SetNext(nullptr);
    sizeOfList++;
}

void List::Print() const
{
    const ListNode* curr = head->GetNext();
    
    while (curr != nullptr)
    {
        if (curr->GetNext() == nullptr)
        {
            std::cout << std::fixed << std::setprecision(4) << curr->GetHeightOfBridge() << " ";
        }
        else
        {
            std::cout << std::fixed << std::setprecision(4) << curr->GetHeightOfBridge() << ", ";
        }
        curr = curr->GetNext();
    }
    std::cout << std::endl;
}
