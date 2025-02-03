#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

//初版,时间复杂度有点高
class Solution {
public:
    bool pre (TreeNode* node,int& val){
        if(!node) return false;
        if(node->val==val) return true;
        return pre(node->left,val)||pre(node->right,val); 
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        queue<TreeNode*> que;
        if(root) que.push(root);
        TreeNode* ret = nullptr;
        TreeNode* old = nullptr;
        while(!que.empty()){
            int size = que.size();
            for(int i=0;i<size;i++){
                TreeNode* node = que.front();
                que.pop();
                if(pre(node,p->val)&&pre(node,q->val)) {
                    old = ret;  //标记是否更新过
                    ret = node;
                }
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            if(old==ret) break;
        }
        return ret;
    }
};

//递归 利用后续遍历的回溯
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root||root==p||root==q) return root;
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        if(left&&right) return root;
        if(!left) return right;
        return left; 
    }
};