#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

//初版  利用左右子树的前序和后序遍历序列进行比较
class Solution {
public:
    void pre(vector<int> &v, TreeNode* node){
        if(!node){
            v.push_back(INT32_MIN);
            return ;
        }
        v.push_back(node->val);
        pre(v,node->left);
        pre(v,node->right);
    }
    void post(vector<int> &v, TreeNode* node){
        if(!node){
            v.push_back(INT32_MIN);
            return ;
        }
        post(v,node->left);
        post(v,node->right);
        v.push_back(node->val);
    }
    bool isSymmetric(TreeNode* root) {
        vector<int> v1,v2;
        if(!root) return true;
        pre(v1,root->left);
        post(v2,root->right);
        if(v1.size()!= v2.size()) return false;

        reverse(v2.begin(),v2.end());
        for(int i=0;i<v1.size();i++){
            if(v1[i]!=v2[i]) return false;
        }
        return true;
    }
};

//改进版  利用递归进行比较
class Solution {
public:
    bool isSymmet(TreeNode* left,TreeNode* right){
        if(!left&&!right) return true;
        if(!left||!right) return false;
        if(left->val!=right->val) return false;
        return isSymmet(left->left,right->right)&&isSymmet(left->right,right->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return isSymmet(root->left,root->right);
    }
};