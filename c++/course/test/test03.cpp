#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template<typename T>
class TreeNode{
public:
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;
    TreeNode(T value):data(value),left(nullptr),right(nullptr){}
};

template<typename T>
class binarytree{
private:
    TreeNode<T>* root;
public:
    int NodeCount(TreeNode<T>* node){
        if(node==nullptr){
            return 0;
        }
        return NodeCount(node->left)+NodeCount(node->right)+1;
    }
    int depth(TreeNode<T>* node){
        if(node==nullptr){
            return 0;
        }
        return max(depth(node->left),depth(node->right))+1;
    }
    void creat(TreeNode<T>* &node){   //要用引用，否则不能更改
        T a;
        cin>>a;
        if(a=='#'){
            return ;
        }else
        {
            node=new TreeNode<T> (a);
            creat(node->left);
            creat(node->right);
        }
    }
    void preorder(TreeNode<T>* node){
        if(node==nullptr)
        cout<<"# ";
        else
        {
            cout<<node->data<<" ";
            preorder(node->left);
            preorder(node->right);
        }
        
    }
    void levleorder(){
        queue<TreeNode<T>*> q;
        q.push(root);
        TreeNode<T>* node;
        while (!q.empty())
        {
            node=q.front();
            q.pop();
            if(node!=nullptr){
                cout<<node->data<<" ";
                q.push(node->left);
                q.push(node->right);
            }else
            cout<<"# ";
        }
        
    }
    int NodeCount(){
        return NodeCount(root);
    }
    int depth(){
        return depth(root);
    }
    void creat(){
        creat(root);
    }
    void preorder(){
        preorder(root);
    }
    binarytree():root(nullptr){}
};


int main(){
    // binarytree<char> tree;
    // tree.creat();
    // cout<<tree.depth()<<endl;
    // cout<<tree.NodeCount()<<endl;
    // tree.preorder();
    // cout<<endl;
    // tree.levleorder();
    

    return 0;
}