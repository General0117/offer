#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
		int length = pre.size(); //节点个数
        if(length == 0)
            return NULL;
        int rootValue = pre[0];//先序的第一个节点为根节点
        TreeNode *rootNode = new TreeNode(rootValue);
        if(length == 1)
            return rootNode;
        vector<int>::iterator iterPre=pre.begin();
        vector<int>::iterator iterIn=vin.begin();

        while(*iterIn != rootValue)
            iterIn++;

       	vector<int> vinLeft(vin.begin(),iterIn);
        vector<int> vinRight(iterIn+1,vin.end());
        int leftSubTreeLength = vinLeft.size();

        vector<int> preLeft(pre.begin()+1,pre.begin()+1+leftSubTreeLength);
        vector<int> preRight(pre.begin()+1+leftSubTreeLength,pre.end());
        rootNode->left=reConstructBinaryTree(preLeft,vinLeft);
        rootNode->right=reConstructBinaryTree(preRight,vinRight);

        return rootNode;

    }
};
