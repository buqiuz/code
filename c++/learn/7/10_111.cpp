#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

//初版
class Solution {
public:
    int minDep(TreeNode* root) {
        if(!root) return INT32_MAX;
        if(!root->left&&!root->right) return 1;
        return min(minDep(root->left),minDep(root->right))+1;
    }
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        return minDep(root);
    }
};

//版本一
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root->left&&root->right) return minDepth(root->right)+1;
        if(root->left&&!root->right) return minDepth(root->left)+1;
        return min(minDepth(root->left),minDepth(root->right))+1;
    }
};

//迭代
class Solution {
public:

    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int depth = 0;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            int size = que.size();
            depth++; // 记录最小深度
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
                if (!node->left && !node->right) { // 当左右孩子都为空的时候，说明是最低点的一层了，退出
                    return depth;
                }
            }
        }
        return depth;
    }
};
