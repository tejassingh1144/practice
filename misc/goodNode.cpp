#include <bits/stdc++.h>
using namespace std;
struct node{
    int val;
    struct node* left;
    struct node* right;
};
int goodNodes;
void traverseTree(struct node* x,int currentMax){
    if(x->val >= currentMax){
        goodNodes++;
        currentMax = x->val;
    }
    if(x->left == NULL && x->right == NULL)
        return;
    if(x->left != NULL)
        traverseTree(x->left,currentMax);
    if(x->right != NULL) 
        traverseTree(x->right,currentMax);
}
int main(){

}