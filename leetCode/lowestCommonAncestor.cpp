/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
TreeNode* desiredNode;
public:
    TreeNode* traverseTree(TreeNode* root,TreeNode* p,TreeNode* q){
        bool leftSubTree = false;
        bool rightSubTree = false;
        bool thisNode = false;
        TreeNode* temp;
        if(root->left == NULL && root->right == NULL){
            if(root == p || root == q)
                return root;
            return NULL;
        }
        if(root == p || root == q)
            thisNode = true;
        if(root->left != NULL){
            temp = traverseTree(root->left,p,q);
            if(temp != NULL)
                leftSubTree = true;
        }
        if(root->right != NULL){
            temp = traverseTree(root->right,p,q);
            if(temp != NULL)
                rightSubTree = true;
        }
        if( (leftSubTree && thisNode) || (leftSubTree && rightSubTree) || (rightSubTree && thisNode))
            desiredNode = root;
        if(thisNode || leftSubTree || rightSubTree)
            return root;
        return NULL;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        traverseTree(root,p,q);
        return desiredNode;
    }
};
