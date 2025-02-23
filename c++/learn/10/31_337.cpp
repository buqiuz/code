#include "TreeNode.h"
#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    pair<int, int> post(TreeNode *node) {
        if (!node)
            return {0, 0};
        auto [x1, y1] = post(node->left);

        auto [x2, y2] = post(node->right);

        return {max(x1, y1) + max(x2, y2), x1 + node->val + x2};
    }

public:
    int rob(TreeNode *root) {
        auto [x, y] = post(root);
        return max(x, y);
    }
};