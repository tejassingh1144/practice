class Solution {

struct node{
    vector<struct node*> siblings;
    int key;
    int totalDist;
    int subNodes;
};
public:
void connectNodes(struct node* p,struct node* q){
    p->siblings.push_back(q);
    q->siblings.push_back(p);
}
public:
int findSubNodes(struct node* x,struct node* parent){
    if(x->siblings.size() == 1 && parent != NULL){
        x->subNodes = 0;
        return 1; 
    }
    int num = 0;
    for(auto itr = x->siblings.begin();itr < x->siblings.end();itr++){
        if(*itr == parent)
            continue;
        num += findSubNodes(*itr,x); 
    }
    x->subNodes = num;
    return num+1;
}
public:
int subNodesDistance(struct node* x, struct node* parent){
    if(x->subNodes == 0){
        x->totalDist = 0;
        return 1;
    }
    int relDist = 0;
    for(auto itr = x->siblings.begin();itr < x->siblings.end(); itr++){
        if(*itr == parent)
            continue;
        relDist +=subNodesDistance(*itr,x);
    }
    x->totalDist = relDist;
    return relDist + x->subNodes + 1;
}
public:
void calcTotalDistance(struct node*x,struct node* parent,int n){
    x->totalDist += (parent->totalDist - (x->totalDist + x->subNodes + 1)) + (n - x->subNodes - 1);
}
public:
void traverseGraph(struct node* x,struct node* parent, int n){
    if(parent != NULL)
        calcTotalDistance(x,parent,n);
    for(auto itr = x->siblings.begin(); itr < x->siblings.end(); itr++){
        if(*itr == parent)
            continue;
        traverseGraph(*itr,x,n);
    }
}
public:
vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
    if(n==1){
        vector<int> g1;
        g1.push_back(0);
        return g1;
    }
    struct node** nodes = new struct node*[n];
    for(int i=0;i<n;i++){
        struct node* p = new struct node; 
        nodes[i] = p;
        p->key = i;
        p->totalDist = 0;
        p->subNodes = 0;
        vector<struct node*> g1;
        p->siblings = g1;
    }

    //connecting nodes
    for(int i=0;i<n-1;i++)
        connectNodes(nodes[edges[i][0]],nodes[edges[i][1]]);

    //assigning root
    struct node* root;
    int max=0;
    for(int i = 0; i<n; i++){
        if(nodes[i]->siblings.size() > max){
            max = nodes[i]->siblings.size();
            root = nodes[i];
        }
    }

    //finding subNodes;
    findSubNodes(root,NULL);

    //subNodesDistance
    subNodesDistance(root,NULL); 

    //traverse graph
    traverseGraph(root,NULL,n);

    vector<int> ans;
    for(int i=0;i<n;i++)
        ans.push_back(nodes[i]->totalDist);
    return ans; 
    }
};
