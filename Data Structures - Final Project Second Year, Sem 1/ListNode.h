#ifndef LISTNODE_H
#define LISTNODE_H


#include <iostream>

#pragma warning(disable 4996)




class ListNode
{
public:

	ListNode(float _heightOfBridge = 0);
	float GetHeightOfBridge() const;
	ListNode* GetNext() const;
	void SetHeightOfBridge(float _heightOfBridge);
	void SetNext(ListNode* _next);;
	void insertAfter(ListNode* newNode);

private:

	float m_heightOfBridge;
	ListNode* m_next;
};
#endif // !LISTNODE_H


