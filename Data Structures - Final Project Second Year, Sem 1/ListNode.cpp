#include "ListNode.h"

ListNode::ListNode(float _heightOfBridge) : m_heightOfBridge(_heightOfBridge) { ; }

float ListNode::GetHeightOfBridge() const { return m_heightOfBridge; }
	
ListNode* ListNode::GetNext() const { return m_next; }

void ListNode::SetHeightOfBridge(float _heightOfBridge) { m_heightOfBridge = _heightOfBridge; }
	
void ListNode::SetNext(ListNode* _next) { m_next = _next; }

void ListNode::insertAfter(ListNode* newNode)
{
	newNode->m_next = m_next;
	m_next = newNode;
}
