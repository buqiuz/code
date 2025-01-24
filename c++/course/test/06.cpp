#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct TreeNode
{
    char data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char value):data(value),left(nullptr),right(nullptr){}
};

class bst
{
private:
    TreeNode* root;
    void creat(TreeNode* &node,string &s){
        if (s[0]=='*')
        {
            return; 
        }else{
            node = new TreeNode(s[0]);
            s.erase(s.begin());
            creat(node->left,s);
            creat(node->right,s);
        }
        
    }
    void mid(TreeNode* node,vector<char>& v){
        if (node==nullptr)
        {
            return ;
        }
        mid(node->left,v);
        v.push_back(node->data);
        mid(node->right,v);    
    }
public:
    bst():root(nullptr){};
    void creat(string s){
        creat(root,s);
    }
    vector<char> mid (vector<char> &v){
        mid(root,v);
        return v;
    }
    ~bst(){};
};
int main(){
    string s;
    while (cin>>s)
    {   
        bst tree;
        vector<char> v;
        tree.creat(s);
        tree.mid(v);
        if(is_sorted(v.begin(),v.end())) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
    

}