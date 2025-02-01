#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

//递归
class Solution {
public:
    void level(vector<vector<int>>& ret,TreeNode* node,int depth){
        if(!node) return ;
        // if (depth == (int)ret.size()) ret.push_back({}); // 也可以这样写
        if(depth== ret.size()) ret.resize(depth+1);
        
        ret[depth].push_back(node->val);
        level(ret,node->left,depth+1);
        level(ret,node->right,depth+1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        level(ret,root,0);
        return ret;
    }
};

//迭代
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ret;
        if(root) q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int> v;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                v.push_back(node->val);
            }
            ret.push_back(v);
        }
        return ret;
    }
};