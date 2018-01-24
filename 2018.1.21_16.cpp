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
        // ָ��ϲ������β���
        ListNode* node = tempNode;

        // ��������Ϊ�ս��бȽϺϲ�
        while(pHead1 !=nullptr && pHead2 !=nullptr) {
            if(pHead1->val < pHead2->val) {
                node->next = pHead1;
                pHead1 = pHead1->next;
            } else {
                node->next = pHead2;
                pHead2 = pHead2->next;
            }
            node = node->next; // ��ָ���ƶ����ϲ�������Ľ�β�������´�
        }
        // �����һ�������Ԫ��δ�����꣬����ӵ��ϲ���������һ�����֮��
        if(pHead1 != nullptr) {
            node->next = pHead1;
        }

        // ����ڶ��������Ԫ��δ�����꣬����ӵ��ϲ���������һ�����֮��
        if(pHead2 != nullptr) {
            node->next = pHead2;
        }
        return tempNode->next;
    }
};
