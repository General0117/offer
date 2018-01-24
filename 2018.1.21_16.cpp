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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1 == nullptr)
            return pHead2;
        if(pHead2 == nullptr)
            return pHead1;
        /*ListNode* pMergedHead = nullptr;

        if(pHead2->val < pHead2->val)
        {
            pMergedHead= pHead2;
            pMergedHead->next = Merge(pHead1->next,pHead2);
        }
        else
        {
            pMergedHead= pHead1;
            pMergedHead->next = Merge(pHead1,pHead2->next);
        }

        return pMergedHead;*/
        ListNode* tempNode = new ListNode(-1);
        // 指向合并链表的尾结点
        ListNode* node = tempNode;

        // 两链表都不为空进行比较合并
        while(pHead1 !=nullptr && pHead2 !=nullptr) {
            if(pHead1->val < pHead2->val) {
                node->next = pHead1;
                pHead1 = pHead1->next;
            } else {
                node->next = pHead2;
                pHead2 = pHead2->next;
            }
            node = node->next; // 将指针移动到合并后链表的结尾，方便下次
        }
        // 如果第一个链表的元素未处理完，将其接到合并链表的最后一个结点之后
        if(pHead1 != nullptr) {
            node->next = pHead1;
        }

        // 如果第二个链表的元素未处理完，将其接到合并链表的最后一个结点之后
        if(pHead2 != nullptr) {
            node->next = pHead2;
        }
        return tempNode->next;
    }
};
