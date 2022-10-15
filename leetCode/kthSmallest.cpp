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
TreeNode* desiredNode;
int kVal;
int key;
public:
    void traverse(TreeNode* root){
        if(root->left == NULL && root->right == NULL){
            cout << root->val << ": " << kVal << endl;
            key = 1;
            if(key == 1){
                kVal--;
                if(kVal == 0)
                    desiredNode = root;
            }
            return;
        }
        if(root->left != NULL)
            traverse(root->left);
        key = 1;
        if( key == 1){
            kVal--;
            if(kVal == 0)
                desiredNode = root;

        }
        if(root->right != NULL)
            traverse(root->right);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        kVal=k;
        key =0;
        traverse(root);
        return desiredNode -> val;
    }
};
