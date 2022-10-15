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
int gNodes;
public:
void traverseTree(struct TreeNode* x,int currentMax){
    if(x->val >= currentMax){
        gNodes++;
        currentMax = x->val;
    }
    if(x->left == NULL && x->right == NULL)
        return;
    if(x->left != NULL)
        traverseTree(x->left,currentMax);
    if(x->right != NULL) 
        traverseTree(x->right,currentMax);
}
public:
    int goodNodes(TreeNode* root) {
        gNodes = 0;
        traverseTree(root,root->val);
        return gNodes;
    }
};
