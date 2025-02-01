#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

//递归
class Solution {
public:
    void mid(vector<int>& v,TreeNode* node){
        if(!node) return ;
        mid(v,node->left);
        v.push_back(node->val);
        mid(v,node->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        mid(ret,root);
        return ret;
    }
};

//迭代
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while(cur||!st.empty()){
            if(cur){
                st.push(cur);
                cur=cur->left;
            }else{
                cur=st.top();
                st.pop();
                ret.push_back(cur->val);
                cur=cur->right;
            }
        }
        return ret;
    }
};

//统一风格的迭代
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> st;
        if(root) st.push(root);
        while(!st.empty()){
            TreeNode* node=st.top();
            st.pop();
            if(node){
                if(node->right) st.push(node->right);
                st.push(node);
                st.push(nullptr);
                if(node->left) st.push(node->left);
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