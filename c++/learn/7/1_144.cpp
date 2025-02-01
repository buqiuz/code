#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

//递归
class Solution {
public:
    void pre(vector<int> &v,TreeNode* node){
        if(!node) return ;
        v.push_back(node->val);
        pre(v,node->left);
        pre(v,node->right);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        pre(ret,root);
        return ret;
    }
};


//迭代
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> st;
        st.push(root);
        TreeNode* cur;
        while(!st.empty()){
            cur=st.top();
            st.pop();
            if(cur){
                ret.push_back(cur->val);
                st.push(cur->right);
                st.push(cur->left);
            }
        }
        return ret;
    }
};

//统一风格的迭代
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> st;
        if(root) st.push(root);
        while(!st.empty()){
            TreeNode* node=st.top();
            st.pop();
            if(node){
                if(node->right) st.push(node->right);  //右
                if(node->left) st.push(node->left);    //左
                st.push(node);                         //根
                st.push(nullptr);
            }
            else{
                node=st.top();
                st.pop();
                ret.push_back(node->val);
            }
        }
        return ret;
    }
};