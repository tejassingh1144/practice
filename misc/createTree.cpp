#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};
void connectNodes(TreeNode*** nodes, int layers){
    for(int i=0; i < layers-1;i++){
        for(int j=0;j<pow(2,i);j++){
            if(nodes[i][j] == NULL)
                continue;
            nodes[i][j]->left = nodes[i+1][2*j];
            nodes[i][j]->right = nodes[i+1][2*j+1];
        }
    }
    for(int j=0;j<pow(2,layers-1);j++){
        if(nodes[layers-1][j] == NULL)
            continue;
        nodes[layers-1][j]->left = NULL;
        nodes[layers-1][j]->right= NULL;
    }
}  
TreeNode* makeTree(){
    cout << "Number of layers: " ;
    int layers,val;
    string strVal,gar;
    cin >> layers;
    getline(cin,gar);
    TreeNode*** nodes = new TreeNode**[layers];
    for(int i=0;i<layers;i++){
        cout << "Layer " << i+1 << ": ";
        int size = (int)pow(2,i);
        nodes[i] = new TreeNode*[size];
        for(int j=0;j<pow(2,i);j++){
            TreeNode* node = new TreeNode;
            getline(cin,strVal);
            if(strVal.length() == 0){
                nodes[i][j] = NULL;
                continue;
            }
            val = stoi(strVal);
            node -> val = val; 
            nodes[i][j] = node;
        }
    }
    connectNodes(nodes,layers);
    return nodes[0][0];
}