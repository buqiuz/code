#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value):data(value),left(nullptr),right(nullptr){}
};

class bst
{
private:
    TreeNode* root;

    TreeNode* insert(TreeNode* &node,int value){
        if(node==nullptr){
            return new TreeNode(value);
        }
        else{
            if(node->data>value){
                node->left=insert(node->left,value);
            }else{
                node->right=insert(node->right,value);
            }
        }
        return node;
    }
    TreeNode* search( TreeNode* &node,int key){
        if(node->data==key){
            return node;
        }else if (node->data<key)
        {
            return search(node->right,key);
        }else{
            return search(node->left,key);
        }
        
    }

    void pre(TreeNode* node){
        if(node==nullptr){
            return;
        }
        else{
            cout<<node->data<<" ";
            pre(node->left);
            pre(node->right);
        }
    }
    void mid(TreeNode* node){
        if(node==nullptr){
            return;
        }
        else{
            mid(node->left);
            cout<<node->data<<" ";
            mid(node->right);
        }
    }
    void post(TreeNode* node){
        if(node==nullptr){
            return;
        }
        else{
            post(node->left);
            post(node->right);
            cout<<node->data<<" ";
        }
    }
    void levleorder(){
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();
            if (node!=nullptr)
            {
                cout<<node->data<<" ";           
                q.push(node->left);
                q.push(node->right);
            }
        }
    }
    int depth (TreeNode* node){
        if(node==nullptr){
            return 0;
        }
        else{
            return max(depth(node->left),depth(node->right))+1;
        }
    }
    int countLeaf(TreeNode* node){
        if (node==nullptr)
        {
            return 0;
        }
        if(node->left==nullptr&&node->right==nullptr){
            return 1;
        }
        return countLeaf(node->left)+countLeaf(node->right);
    }
    int NodeCount(TreeNode* node){
        if(node==nullptr){
            return 0;
        }
        return NodeCount(node->left)+NodeCount(node->right)+1;
    }
public:
    bst():root(nullptr){};

    void insert(int value){
        root=insert(root,value);
    }

    TreeNode* search(int key){
        return search(root,key);
    }

    void pre(){
        pre(root);
    }

    void mid(){
        mid(root);
    }

    void post(){
        post(root);
    }
    void levle(){
        levleorder();
    }
    int depth(){
        return depth(root);
    }
    int countLeaf(){
        return countLeaf(root);
    }
    int NodeCount(){
        return NodeCount(root);
    }

    ~bst(){};
};
struct cmp
{
    bool operator()(TreeNode* a,TreeNode* b){
        return a->data>b->data;
    }
};

// bool cmp(TreeNode* a,TreeNode* b){
//     return a->data>b->data;
// }


TreeNode* buildHuffmanTree(vector<int> v) {
    priority_queue<TreeNode*, vector<TreeNode*>, cmp> minheap;

    for (int i = 0; i < v.size(); i++) {
        minheap.push(new TreeNode(v[i]));
    }

    while (minheap.size() > 1) {
        TreeNode* left = minheap.top();
        minheap.pop();
        TreeNode* right = minheap.top();
        minheap.pop();
        TreeNode* node = new TreeNode(left->data + right->data);
        node->left = left;
        node->right = right;
        minheap.push(node);
    }
    return minheap.top();
}

int wpl(TreeNode* node,int depth){
    if(node==nullptr){
        return 0;
    }
    else if(node->left==nullptr&&node->right==nullptr){
        return node->data*depth;
    }
    return wpl(node->left,depth+1)+wpl(node->right,depth+1);
}

int main(){
    // bst t;
    // t.insert(15);
    // t.insert(12);
    // t.insert(3);
    // t.insert(45);
    // t.insert(3);
    // t.insert(4);
    // t.insert(52);
    // t.insert(18);
    // t.insert(13);
    // t.insert(2);
    // t.insert(6);
    // t.pre();
    // cout<<endl;
    // t.mid();
    // cout<<endl;
    // t.post();
    // cout<<endl;
    // t.levle();
    // cout<<endl;
    // cout<<t.depth();
    // cout<<endl;
    // cout<<t.countLeaf();
    // cout<<endl;
    // cout<<t.NodeCount();

    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    TreeNode* huffmantree=buildHuffmanTree(v);
    cout<<wpl(huffmantree,0);
    

    return 0;
}