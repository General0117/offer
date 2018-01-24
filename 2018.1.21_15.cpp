#include<iostream>
using namespace std;


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
		ListNode* pReversdHead = nullptr;
        ListNode* pNode = pHead;
        ListNode* pPrev = nullptr;
        while(pNode != nullptr)
        {
            ListNode* pNext = pNode->next;
            if(pNext == nullptr)
            	pReversdHead = pNode;

            pNode->next = pPrev;
            pPrev = pNode;
            pNode = pNext;
        }
        return pReversdHead;
    }
};
