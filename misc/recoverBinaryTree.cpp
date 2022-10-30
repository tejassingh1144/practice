#include <bits/stdc++.h>
#include "createTree.cpp"
using namespace std;
int key = 0;
struct TreeNode* bust; 
void rangeFix(int* mainRange,int* subRange){
    if(mainRange[0] > subRange[0])
        mainRange[0] = subRange[0];
    if(mainRange[1] < subRange[1])
        mainRange[1] = subRange[1];
}
int* traverseTree(TreeNode* x){
    int* range = new int[2];
    range[0] = x->val;
    range[1] = x->val;
    if(key == 1)
        return range;
    if(x->left == NULL && x->right == NULL)
        return range; 
    if(x->left != NULL){
        int* lRange = traverseTree(x->left);
        if(x->val < lRange[1]){ //found the faulty node
            key = 1;
            bust = x;
        }
        rangeFix(range,lRange);
        delete lRange;
    }
    if(x->right != NULL){
        int* rRange = traverseTree(x->right);
        if(x->val > rRange[0]){ // found the faulty node
            key=1;
            bust = x;
        }
        rangeFix(range,rRange);
        delete rRange;
    }
    return range;
}
void traverse(TreeNode* x){
    cout << x->val << " ";
    if(x->left == NULL && x->right == NULL)
        return;
    if(x->left != NULL)
        traverse(x->left);
    if(x->right != NULL)
        traverse(x->right);
}
int main(){
    TreeNode* root = makeTree();
    traverseTree(root);
    cout << bust->val << endl;
    cout << endl;
    return 0;
}