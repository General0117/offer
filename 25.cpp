/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:

    RandomListNode* Clone(RandomListNode* pHead)
    {
        ClaoneNodes(pHead);
        ConnectSilblingNodes(pHead);
        return ReconnectNodes(pHead);
    }

    void ClaoneNodes(RandomListNode* pHead) {
        RandomListNode* pNode = pHead;
        while(pNode != nullptr) {
            RandomListNode* pCloned = new RandomListNode(0);
            pCloned->label = pNode->label;
            pCloned->next = pNode->next;
            pCloned->random = nullptr;

            pNode->next = pCloned;
            pNode = pCloned->next;
        }
    }

    void ConnectSilblingNodes(RandomListNode* pHead) {
        RandomListNode* pNode = pHead;
        while(pNode != nullptr) {
            RandomListNode* pCloned = pHead->next;
            if(pNode->random != nullptr) 
                pCloned->random = pNode->random->next;
            
            pNode = pCloned->next;

        }
    }
    
    RandomListNode* ReconnectNodes(RandomListNode* pHead) {
        RandomListNode* pNode = pHead;
        RandomListNode* pCloneHead = nullptr;
        RandomListNode* pCloneNode = nullptr;

        if(pNode != nullptr) {
            pCloneHead = pCloneNode = pNode->next;
            pNode->next = pCloneNode->next;
            pNode = pNode->next;
        }

        while(pNode != nullptr) {
            pCloneNode->next = pNode->next;
            pCloneNode = pCloneNode->next;
            pNode->next = pCloneNode->next;
            pNode = pNode->next;
        }
        return pCloneHead;
    }
};