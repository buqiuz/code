#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct HuffmanNode
{
    int weight;
    HuffmanNode* left;
    HuffmanNode* right;
    HuffmanNode(int value):weight(value),left(nullptr),right(nullptr){}
};

struct cmp
{
    bool operator()(HuffmanNode* a,HuffmanNode* b){
        return a->weight>b->weight;
    }
};

HuffmanNode* buildHuffmanTree(priority_queue<HuffmanNode*,vector<HuffmanNode*>,cmp> minheap){
    while (minheap.size()>1)
    {
        HuffmanNode* left=minheap.top();
        minheap.pop();
        HuffmanNode* right=minheap.top();
        minheap.pop();
        HuffmanNode* node=new HuffmanNode(left->weight+right->weight);
        node->left=left;
        node->right=right;
        minheap.push(node);
    }
    return minheap.top();
    
}
int calculateWPL(HuffmanNode* node,int depth){
    if(node==nullptr){
        return 0;
    }
    else if (node->left==nullptr&&node->right==nullptr)
    {
        return node->weight*depth;
    }
    
    return calculateWPL(node->right,depth+1)+calculateWPL(node->left,depth+1);
    
}
int main(){
    priority_queue<HuffmanNode*,vector<HuffmanNode*>,cmp> minheap;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int weight;
        cin>>weight;
        minheap.push(new HuffmanNode(weight));
    }
    HuffmanNode* HuffmanTree=buildHuffmanTree(minheap);
    int w=calculateWPL(HuffmanTree,0);
    cout<<w<<endl;

    return 0;
}