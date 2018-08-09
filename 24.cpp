#include<iostream>
#include<vector>
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
    vector<vector<int> > result;
    vector<int>temp;
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root != NULL)
            findOnePath(root,expectNumber);
        return result;
    }
    
    void findOnePath(TreeNode* root,int expectNumber){
        temp.push_back(root->val);
        if(expectNumber - root->val==0 && root->right ==NULL && root->left == NULL)
            result.push_back(temp);
        if(root->left != NULL)findOnePath(root->left,expectNumber-root->val);
        if(root->right != NULL)findOnePath(root->right,expectNumber-root->val);
        temp.pop_back();
        
    }
};