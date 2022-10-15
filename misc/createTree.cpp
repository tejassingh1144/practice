#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};
void connectNodes(TreeNode** layersOfNode, int layers){
    int deep = 0;
    while( deep < layers ){
        for(int i=0;i<pow(2,deep);i++){
            TreeNode node = layersOfNode[deep][i];
            node.left = &layersOfNode[deep+1][2*i];
            node.right = &layersOfNode[deep+1][2*i + 1];
        }
        deep++;
    }
    for(int i=0;i<pow(2,deep);i++){
        TreeNode node = layersOfNode[deep][i];
        node.left = NULL;
        node.right = NULL;
    }
}  
TreeNode* makeTree(){
    cout << "Number of nodes: ";
    int n,val;
    cin >> n;
    vector<int> nodesKey;
    cout << "Value of each node: ";
    for(int i=0;i<n;i++){
        cin >> val;
        nodesKey.push_back(val);
    }
    double depth = log(n)/log(2);
    if(depth != (int)depth)
        depth++;
    int layers = (int)depth;
    TreeNode* root;
    TreeNode** layersOfNodes = new TreeNode*[layers];
    int deep = 0,factor = 0;
    while(deep < depth){
        TreeNode* layer = new TreeNode[(int)pow(2,deep)];
        for(int i=0;i<pow(2,deep);i++){
            TreeNode node;
            node.val = nodesKey[factor + i];
            layer[i] = node;
        }
        factor = factor + pow(2,deep);
        layersOfNodes[deep] = layer;
        deep++;
    }
    connectNodes(layersOfNodes,layers);
    return &layersOfNodes[0][0]; 
}
// [1,2,3,4,5,6,7,8]
//  0 1 2 3 4 5 6 7