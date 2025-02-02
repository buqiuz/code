#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
//初版
class Solution {
public:
    int getHeight(TreeNode* node){
        if(!node) return 0;
        return max(getHeight(node->left),getHeight(node->right))+1;
    }

    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        return isBalanced(root->left)&&isBalanced(root->right)&&
                abs(getHeight(root->left)-getHeight(root->right))<=1;
    }
};

//改进版
class Solution {
public:
    int getHeight (TreeNode* node){
        if(!node) return 0;
        int leftHeight =getHeight(node->left);
        if(leftHeight==-1) return -1;
        int rightHeight = getHeight(node->right);
        if(rightHeight==-1) return -1;

        return abs(leftHeight-rightHeight)>1?-1:max(leftHeight,rightHeight)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        return getHeight(root)==-1?false:true;
    }
};