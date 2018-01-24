#include<iostream>
#include<vector>
#include<deque>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
		 std::vector<int> data;
        if(root!=NULL){
            std::deque<TreeNode*> dequeTreeNode;
            dequeTreeNode.push_back(root);
            TreeNode* node;
            while(!dequeTreeNode.empty()){
                node=dequeTreeNode.front();
                dequeTreeNode.pop_front();
                data.push_back(node->val);

                if(node->left)
                    dequeTreeNode.push_back(node->left);
                if(node->right)
                    dequeTreeNode.push_back(node->right);
            }
        }
        return data;
    }
};
