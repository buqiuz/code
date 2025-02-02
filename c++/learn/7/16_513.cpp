#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

//递归
class Solution {
public:
    void level (vector<vector<int>>& ret,TreeNode* node,int depth){
        if(!node) return;
        if(ret.size()==depth) ret.resize(depth+1); // 避免多次resize
        ret[depth].push_back(node->val);
        level(ret,node->left,depth+1);
        level(ret,node->right,depth+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        vector<vector<int>> ret;
        level(ret,root,0);
        return ret[ret.size()-1][0];
    }
};

//迭代
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        if (root != NULL) que.push(root);
        int result = 0;
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if (i == 0) result = node->val; // 记录最后一行第一个元素
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        return result;
    }
};