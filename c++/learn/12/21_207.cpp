#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        // 记录节点入度
        vector<int> inDegree(numCourses, 0);

        for (auto x : prerequisites) {
            inDegree[x[1]]++;
        }

        queue<int> q;
        // 找出入度为零的节点加入queue
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0)
                q.push(i);
        }
        vector<int> ret;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            ret.push_back(cur);
            // 删除当前节点的边,即更新入度,然后同时更新q
            for (auto &edge : prerequisites) {
                if (edge[0] == cur)
                    inDegree[edge[1]]--;
                if (inDegree[edge[1]] == 0)
                    q.push(edge[1]);
            }
        }
        return ret.size() == numCourses ? true : false;
    }
};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        // 记录节点入度
        vector<int> inDegree(numCourses, 0);

        for (auto x : prerequisites) {
            inDegree[x[1]]++;
        }

        queue<int> q;
        // 找出入度为零的节点加入queue
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0)
                q.push(i);
        }
        vector<int> ret;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            ret.push_back(cur);
            // 删除当前节点的边,即更新入度,然后同时更新q
            // 错误遍历，每次都从头遍历会导致节点重复入队，应该只遍历当前节点的边，所以应该创建邻接表
            for (auto &edge : prerequisites) {
                if (edge[0] == cur)
                    inDegree[edge[1]]--;
                if (inDegree[edge[1]] == 0)
                    q.push(edge[1]);
            }
        }
        return ret.size() == numCourses ? true : false;
    }
};