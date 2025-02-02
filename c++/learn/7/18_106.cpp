#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

//初版
class Solution {
public:
    
    //空间浪费,不必要的复制

    TreeNode* build(vector<int> inorder,vector<int> postorder){
        int n=inorder.size();
        if(n==0) return nullptr;
        TreeNode* node = new TreeNode(postorder[n-1]);

        auto rootPos = find(inorder.begin(),inorder.end(), postorder[n-1]);
        int leftSize = rootPos - inorder.begin();

        node->left = build(vector<int>(inorder.begin(),rootPos),vector<int>(postorder.begin(),postorder.begin()+leftSize));
        node->right = build(vector<int>(rootPos+1,inorder.end()),vector<int>(postorder.begin()+leftSize,postorder.end()-1));
        return node;
    }

    //不够简洁规范
    TreeNode* build(vector<int>& inorder,vector<int>& postorder,int left_low,int left_high,int right_low,int right_high){
        if(left_low>left_high||right_low>right_high) return nullptr;

        int rootVal = postorder[right_high];
        TreeNode* node = new TreeNode(rootVal);

        int rootPos = find(inorder.begin()+left_low,inorder.begin()+left_high+1,rootVal)-inorder.begin();
        int leftSize = rootPos - left_low;

        node->left = build(inorder,postorder,left_low,rootPos-1,right_low,right_low+leftSize-1);
        node->right = build(inorder,postorder,left_low+leftSize+1,left_high, right_low+leftSize,right_high-1);
        return node;
    }

    //一定要确定好区间
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        return build(inorder,postorder,0,n-1,0,n-1);
    }
};