#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

//递归
class Solution {
public:
    void post(vector<int>& v,TreeNode* node){
        if(!node) return ;
        post(v,node->left);
        post(v,node->right);
        v.push_back(node->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        post(ret,root);
        return ret;
    }
};

//迭代
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> st;
        TreeNode* cur;
        st.push(root);
        while(!st.empty()){
            cur=st.top();
            st.pop();
            if(cur){
                ret.push_back(cur->val);
                st.push(cur->left);
                st.push(cur->right);
            }
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};

//统一风格的迭代
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> st;
        if(root) st.push(root);
        while(!st.empty()){
            TreeNode* node=st.top();
            st.pop();
            if(node){
                st.push(node);
                st.push(nullptr);
                if(node->right) st.push(node->right);
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