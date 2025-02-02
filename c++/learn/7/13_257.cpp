#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

//初版
class Solution {
public:
    void pathToLeaf(vector<string> &ret,string path,TreeNode* node){
        path+="->"+to_string(node->val);
        if(!node->left&&!node->right) {
            ret.push_back(path);
            return;
        }
        if(node->left) pathToLeaf(ret,path,node->left);
        if(node->right) pathToLeaf(ret,path,node->right);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return {};
        vector<string> ret;
        string path=to_string(root->val);
        if(!root->left&&!root->right) ret.push_back(path); 
        if(root->left) pathToLeaf(ret,path,root->left);
        if(root->right) pathToLeaf(ret,path,root->right);
        return ret;
    }
};

//精简版
class Solution {
public:
    void pathToLeaf(vector<string> &ret,string path,TreeNode* node){
        path+=to_string(node->val);
        if(!node->left&&!node->right) {
            ret.push_back(path);
            return;
        }
        if(node->left) pathToLeaf(ret,path+"->",node->left);
        if(node->right) pathToLeaf(ret,path+"->",node->right);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        if(root) pathToLeaf(ret,"",root);
        return ret;
    }
};