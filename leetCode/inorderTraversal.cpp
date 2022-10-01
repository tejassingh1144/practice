/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
    		vector<int> ans,temp;	
        if(root == NULL )
        	return ans;
        if(root->left){
        	temp=inorderTraversal(root->left);
          for(int value : temp)
          	ans.push_back(value);
        }
        ans.push_back(root->val);
        if(root->right){
        	temp=inorderTraversal(root->right);
          for(int value : temp)
          	ans.push_back(value);
        }
        return ans;
    }
};
