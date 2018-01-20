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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    if(pListHead == nullptr || k == 0)
        return nullptr;
        ListNode *pAhead = pListHead;
        ListNode *pBehind = nullptr;

        for(unsigned int i = 0;i < k - 1;i++)
        {
            if(pAhead->next != nullptr)
                pAhead = pAhead->next;
            else
            {
            	return nullptr;
            }
        }

        pBehind = pListHead;
        while(pAhead->next != nullptr)
        {
            pAhead = pAhead->next;
            pBehind = pBehind->next;
        }
        return pBehind;
    }
};

int main()
{

}
