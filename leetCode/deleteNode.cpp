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
	TreeNode* traverse(TreeNode* node,int key){
		TreeNode* toDelete = NULL;
		if(node->val == key)
			toDelete = node;	
		if(node->left != NULL && toDelete == NULL)
			toDelete = traverse(node->left,key);
		if(node->right != NULL && toDelete == NULL)
			toDelete = traverse(node->right,key);
		return toDelete;
	}
	TreeNode* largestNode(TreeNode* node){
		if(node->right == NULL)
			return node;
		return  largestNode(node->right);
	}
	TreeNode* smallestNode(TreeNode* node){
		if(node->left == NULL)
			return node;
		return smallestNode(node->left);
	}
	TreeNode* findParent(TreeNode* node,TreeNode* target){
		TreeNode* parent = NULL;
		if(node->left == target || node->right == target)
			parent = node;
		if(node->left != NULL && parent == NULL)
			parent = findParent(node->left,target);
		if(node->right != NULL && parent == NULL)
			parent = findParent(node->right, target);	
		return parent;
	}
	int unlink(TreeNode* parent, TreeNode* child){
		if(parent->left == child){
			parent->left = NULL;
			return 0;
		}
		parent->right = NULL;
		return 1;
	}
	void link(TreeNode* parent, TreeNode* child, int edge){
		if(edge == 0 )
			parent->left = child;
		else
			parent->right = child;	
	}
	TreeNode* deleteNode(TreeNode* root, int key) {
		if(root == NULL)
			return root;
		TreeNode* toDelete = traverse(root,key); 
		if(toDelete == NULL)
			return root;
		TreeNode* justSmaller = NULL;
		TreeNode* justBigger = NULL;
		if(toDelete->left != NULL)
			justSmaller = largestNode(toDelete->left);
		if(toDelete->right != NULL)
			justBigger = smallestNode(toDelete->right);
		TreeNode* toDelParent = findParent(root,toDelete);
		if(justSmaller != NULL){
			if(toDelete == root)
				root = justSmaller;
			TreeNode* justSmallerParent = findParent(toDelete,justSmaller);
			if(toDelParent != NULL){
				int edge = unlink(toDelParent,toDelete);
				link(toDelParent,justSmaller,edge);
			}
			TreeNode* justSmallerLeft = justSmaller -> left;
			unlink(justSmallerParent,justSmaller);
			link(justSmaller,toDelete->right,1);
			link(justSmaller,toDelete->left,0);
			if(justSmallerParent == toDelete)
				link(justSmaller,justSmallerLeft,0);
			else
				link(justSmallerParent,justSmallerLeft,1);

		}else if(justBigger != NULL){
			if(toDelete ==root)
				root = justBigger;
			TreeNode* justBiggerParent = findParent(toDelete,justBigger);
			if(toDelParent != NULL){
				int edge = unlink(toDelParent,toDelete);
				link(toDelParent,justBigger,edge);
			}
			TreeNode* justBiggerRight = justBigger -> right;
			unlink(justBiggerParent,justBigger);
			link(justBigger,toDelete->left,0);
			link(justBigger,toDelete->right,1);
			if(justBiggerParent == toDelete)
				link(justBigger,justBiggerRight,1);
			else
				link(justBiggerParent,justBiggerRight,0);
			
		}else{
			if(toDelete == root)
				return NULL;
			unlink(toDelParent,toDelete);
		}
		return root;
	}
};
