#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

//主要是中序遍历中对众数的处理，保存当前遍历到的众数，出现新的众数时清空之前的众数，更新众数
//不要在多重递归（比如这里的2重）中传递参数，会混乱。
class Solution {
public:
    void countMode(TreeNode* root) {
        if (!root) return;
        countMode(root->left);

        if (pre == nullptr) { // 第一个节点
            currentCount = 1; // 频率为1
        } else if (pre->val == root->val) { // 与前一个节点数值相同
            currentCount++;
        } else { // 与前一个节点数值不同
            currentCount = 1;
        }
        
        if(currentCount==maxCount){
            ret.push_back(root->val);
        }
        if (currentCount > maxCount) {
            maxCount = currentCount;
            ret.clear();
            ret.push_back(root->val);
        }
        pre = root;
        countMode(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        countMode(root);
        return ret;
    }

private:
    int currentCount = 0;
    int maxCount = 0;
    vector<int> ret;
    TreeNode* pre = nullptr;
};


//传递参数，用返回值接收count的修改
class Solution {
public:
    // 用返回值传递count
    int countMode(TreeNode* root, int count) {
        if (!root) return count;
        
        // 先遍历左子树，将其返回的count拿到这里
        count = countMode(root->left, count);

        // 中序位置：处理当前节点
        if (pre == nullptr) { 
            // 第一个节点
            count = 1; 
        } else if (pre->val == root->val) { 
            // 与前一个节点数值相同
            count++;
        } else { 
            // 与前一个节点数值不同
            count = 1;
        }

        // 更新全局最大频率
        if (count > this->maxCount) {
            this->maxCount = count;
        }

        pre = root;

        // 继续处理右子树，并把count带过去
        return countMode(root->right, count);
    }

    // 第二次遍历，用返回值来带回count，如果匹配到maxCount就收集结果
    int countMode2(TreeNode* root, int count) {
        if (!root) return count;
        
        count = countMode2(root->left, count);

        if (pre == nullptr) { 
            count = 1; 
        } else if (pre->val == root->val) {
            count++;
        } else {
            count = 1;
        }

        // 若本次count等于maxCount，则收集当前值
        if (count == this->maxCount) {
            ret.push_back(root->val);
        }

        pre = root;

        return countMode2(root->right, count);
    }

    vector<int> findMode(TreeNode* root) {
        if (!root) return {};
        // 第一次遍历：按中序计算最大频率
        countMode(root, 0);

        // 重置
        pre = nullptr;
        // 第二次遍历：收集所有等于maxCount的值
        countMode2(root, 0);
        return ret;
    }

private:
    int maxCount = 0;       // 记录全局最大频率
    vector<int> ret;
    TreeNode* pre = nullptr; 
};

//引用传递
class Solution {
public:
    void countMode(TreeNode* root,int& count){
        if(!root) return ;
        countMode(root->left,count);

        if (pre == nullptr) { // 第一个节点
            count = 1; // 频率为1
        } else if (pre->val == root->val) { // 与前一个节点数值相同
            count++;
        } else { // 与前一个节点数值不同
            count = 1;
        }
        if(count>this->count) this->count = count;
        pre = root;

        countMode(root->right,count);
    }

    void countMode2(TreeNode* root,int& count){
        if(!root) return ;
        countMode2(root->left,count);

        if (pre == nullptr) { // 第一个节点
            count = 1; // 频率为1
        } else if (pre->val == root->val) { // 与前一个节点数值相同
            count++;
            cout<<count<<endl;
        } else { // 与前一个节点数值不同
            count = 1;
        }

        if(count==this->count) ret.push_back(root->val);
        pre = root;

        countMode2(root->right,count);
    }

    vector<int> findMode(TreeNode* root) {
        int count1 =0;
        countMode(root,count1);
        
        count1=0;
        this->pre=nullptr;

        countMode2(root,count1);
        return this->ret;
    }
private:
    int count = 0;
    vector<int> ret;
    TreeNode* pre = nullptr;
};