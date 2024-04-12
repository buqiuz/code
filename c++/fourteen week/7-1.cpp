#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct treeNode
{
    char data;
    treeNode *lchild=nullptr,*rchild=nullptr;
};

void creat(treeNode* &tree){
    char a;
    cin >> a;
    if (cin.eof()) {
            // 如果到达文件末尾，结束循环
            return;
        }
    if(a == '*'){
        tree = nullptr; // 将当前节点设置为 null，表示叶子节点
    }
    else{
        tree = new treeNode;
        tree->data = a;
        creat(tree->lchild);
        creat(tree->rchild);
    }
}


void mid_each(treeNode* tree,vector<char> &v){
    if(tree!=nullptr){
        mid_each(tree->lchild,v);
        v.push_back(tree->data);
        mid_each(tree->rchild,v);
    }
}

int main(){
    while (true)
    {   
        if (cin.eof()) {
            // 如果到达文件末尾，结束循环
            break;
        }
        treeNode *tree=nullptr;
        vector<char> v;
        creat(tree);
        if(tree==nullptr) break;
        mid_each(tree,v);
        vector<char> v1(v);
        sort(v1.begin(),v1.end());
        if(v1==v) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
    }   

    
    return 0;
    

}




// #include<iostream>
// #include<vector>
// #include<algorithm>

// using namespace std;

// struct treeNode
// {
//     char data;
//     treeNode *lchild=nullptr,*rchild=nullptr;
// };

// void creat(treeNode* &tree,char a){
//     if(a == '*'){
//         tree = nullptr; // 将当前节点设置为 null，表示叶子节点
//     }
//     else{
//         tree = new treeNode;
//         tree->data = a;
//         cin>>a;
//         creat(tree->lchild,a);
//         cin>>a;
//         creat(tree->rchild,a);
//     }
// }


// void mid_each(treeNode* tree,vector<char> &v){
//     if(tree!=nullptr){
//         mid_each(tree->lchild,v);
//         v.push_back(tree->data);
//         mid_each(tree->rchild,v);
//     }
// }

// int main(){
//     char a;
//     while (cin>>a)
//     {
//         treeNode *tree=nullptr;
//         vector<char> v;
//         creat(tree,a);
//         mid_each(tree,v);
//         vector<char> v1(v);
//         sort(v1.begin(),v1.end());
//         if(v1==v) cout<<"YES"<<endl;
//         else cout<<"NO"<<endl;
//     }  
	
//     return 0;
    

// }




// #include<iostream>
// #include<vector>
// #include<algorithm>

// using namespace std;

// struct TreeNode
// {
//     char data;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(char value):data(value),left(nullptr),right(nullptr){}
// };

// class bst
// {
// private:
//     TreeNode* root;
//     void creat(TreeNode* &node,string &s){
//         if (s[0]=='*')
//         {
//             return; 
//         }else{
//             node = new TreeNode(s[0]);
//             s.erase(s.begin());
//             creat(node->left,s);
//             creat(node->right,s);
//         }
        
//     }
//     void mid(TreeNode* node,vector<char>& v){
//         if (node==nullptr)
//         {
//             return ;
//         }
//         mid(node->left,v);
//         v.push_back(node->data);
//         mid(node->right,v);    
//     }
// public:
//     bst():root(nullptr){};
//     void creat(string s){
//         creat(root,s);
//     }
//     vector<char> mid (vector<char> &v){
//         mid(root,v);
//         return v;
//     }
//     ~bst(){};
// };
// int main(){
//     string s;
//     while (cin>>s)
//     {   
//         bst tree;
//         vector<char> v;
//         tree.creat(s);
//         tree.mid(v);
//         if(is_sorted(v.begin(),v.end())) cout<<"YES"<<endl;
//         else cout<<"NO"<<endl;
//     }
//     return 0;
    

// }

