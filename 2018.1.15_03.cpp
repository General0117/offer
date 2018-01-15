#include<iostream>
#include<vector>
#include<stdlib.h>
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
    vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> result;
        ListNode* p;
        p = head;
        while(p)
        {
            result.push_back(p->val);
            p = p->next;
        }
        vector<int> result2;
        for(auto i = result.end()-1;i != result.begin() - 1;i--)
            result2.push_back(*i);
        return result2;
    }
};
