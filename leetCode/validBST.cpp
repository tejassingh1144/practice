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
	bool compareLeft(TreeNode* root, TreeNode* left){
		if(left == NULL)
			return true;
		if(left->val < root-> val)
			return true;
		return false;
	}
public:
	bool compareRight(TreeNode* root, TreeNode* right){
		if(right == NULL )
			return true;
		if(root->val < right->val)
			return true;
		return false;
	}
public:
	int getSmallest(TreeNode* root){
		TreeNode* temp=root;
		while(temp->left != NULL){
			temp->left;
		}
		return temp->val;
	}
public:
	int getLargest(TreeNode* root){
		TreeNode* temp=root;
		while(temp->right != NULL){
			temp->right;
		}
		return temp->val;
	}
public:
    bool isValidBST(TreeNode* root) {
	if(root == NULL)
		return true;
 	if(root->left == NULL && root->right == NULL )
 		return true;
	if(!isValidBST(root->left) || !isValidBST(root->right))
		return false;
	if(!(compareLeft(root,root->left) && compareRight(root,root->right)))
		return false;
	
	if(root->left == NULL){
		if(!(root->val < getSmallest(root->right)))
			return false;
	}else if(root->right == NULL){
		if(!(getLargest(root->left) < root->val))
			return false;
	}
	else{
		if( !(getLargest(root->left) < root->val && root->val < getSmallest(root->right)))
			return false;	
	}
	return true;
    }
};
