#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};
vector<vector<TreeNode*>> dp;
vector<int> dp2;
int uniqueTrees(int n){
    if( n==1 || n == 0 )
        return 1;
    if(dp2[n] != -1)
        return dp2[n];
    int ans = 0;
    for(int i = 0;i<n;i++)
        ans += uniqueTrees(i)*uniqueTrees(n-1-i);
    
    dp2[n] = ans;
    return dp2[n];
}
void dfs(TreeNode* original,TreeNode* tmp,int iFactor){
    tmp->val= original->val + iFactor;
    if(original->left == NULL && original->right == NULL)
        return ;
    if(original->left != NULL){
        TreeNode* newNode = new TreeNode;
        tmp->left = newNode;
        dfs(original->left,newNode,iFactor);
    }
    if(original->right != NULL){
        TreeNode* newNode = new TreeNode;
        tmp->right = newNode;
        dfs(original->right,newNode,iFactor);
    }
}
vector<TreeNode*> generateTrees(int n){
    if( n==1 )
        return dp[1];
    if( n== 0)
        return dp[0];
    if(dp[n].size() != 0)
        return dp[n];
    int trees;
    vector<TreeNode*> leftTrees;
    vector<TreeNode*> rightTrees;
    for(int i=0;i<n;i++){   
        leftTrees = generateTrees(i);
        rightTrees = generateTrees(n-1-i);
        for(int j=0;j< leftTrees.size()  || j==0;j++){
            for(int k=0;k<rightTrees.size() || k==0;k++){
                TreeNode* root = new TreeNode;
                root->val = i+1;
                root->left = NULL;
                root->right = NULL;
                if( rightTrees.size() ){
                    TreeNode* rightChild = new TreeNode;
                    root->right = rightChild;
                    dfs(rightTrees[k],rightChild,i+1);        
                }
                if( leftTrees.size() ){
                    TreeNode* leftChild = new TreeNode;
                    root->left = leftChild;
                    dfs(leftTrees[j],leftChild,0);        
                }
                dp[n].push_back(root);
            }
        }
    }
    return dp[n];
}
int main(){
    int n;
    cin >> n;
    for(int i=0;i<=n;i++){
        vector<TreeNode*> tmp;
        dp.push_back(tmp);
    }
    dp2.assign(n+1,-1);
    TreeNode* root = new TreeNode;
    root->val= 1;
    root->left = NULL;
    root->right = NULL;
    dp[1].push_back(root);
    int k;
}