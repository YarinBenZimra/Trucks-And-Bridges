#ifndef LIST_H
#define LIST_H 

#pragma warning(disable 4996)



class ListNode;

class List
{
public:
    //C'tors
    List();
    ~List();
    //Functions
    ListNode* First() const;
    ListNode* Last() const;
    int isEmptyList() const;
    int GetListSize() const;
    void CreateNewListNode(float h);
    void Print() const;




private:

    ListNode* head;
    ListNode* tail;
    int sizeOfList;

};


#endif // !LIST_H