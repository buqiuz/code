#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

//初版
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        this->visited = vector<bool> (n+1,false);
        this->k=k;

        vector<int> v;
        backTracking(v,0,1);
        return ret;
    }
private:
    vector<bool> visited;
    vector<vector<int>> ret;
    int k;

    void backTracking(vector<int>& v,int cnt,int index){
        if(cnt==this->k) {
            this->ret.push_back(v);
            return;
        }

        for(int i=index;i<this->visited.size();i++){
            if(!visited[i]) {
                visited[i]=true;
                v.push_back(i);
                cnt++;

                backTracking(v,cnt,i+1);
            
                visited[i]=false;
                v.pop_back();
                cnt--;
            }
        }
    }
};

//版本一
class Solution {
private:
    vector<vector<int>> result; // 存放符合条件结果的集合
    vector<int> path; // 用来存放符合条件结果
    void backtracking(int n, int k, int startIndex) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i <= n - (k-path.size())+1; i++) {  //剪枝
            path.push_back(i); // 处理节点
            backtracking(n, k, i + 1); // 递归
            path.pop_back(); // 回溯，撤销处理的节点
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return result;
    }
};