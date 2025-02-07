#include<bits/stdc++.h>
using namespace std;

//初版,内存爆了,因为遍历了所有情况 并且代码也不够优美
class Solution {
private:
    vector<vector<string>> ret;
    vector<string> path;
    void backTracing(vector<vector<string>>& tickets,int depth,vector<bool>& used){
        if(depth==tickets.size()){
            ret.push_back(path);
            return;
        }

        for(int i=0;i<tickets.size();i++){
            if(path.empty()){
                if(!used[i]&&tickets[i][0]=="JFK"){
                    path.push_back(tickets[i][0]);
                    path.push_back(tickets[i][1]);
                    used[i]=true;
                    backTracing(tickets,depth+1,used);
                    used[i]=false;
                    path.pop_back();
                    path.pop_back();
                }
                else continue;
            }else {
                if(!used[i]&&tickets[i][0]==path.back()){
                    path.push_back(tickets[i][1]);
                    used[i]=true;
                    backTracing(tickets,depth+1,used);
                    used[i]=false;
                    path.pop_back();
                }
            }
        }
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<bool> used(tickets.size(),false);
        sort(tickets.begin(), tickets.end());
        backTracing(tickets,0,used);
        return  ret.front();
    }
};



//利用回溯+剪枝(避免重复陷入死循环)
class Solution {
private:
    vector<string> ret;
    vector<string> path;
    void backTracing(vector<vector<string>>& tickets,vector<bool>& used){
        if(!ret.empty()) return ;
        if(path.size()==tickets.size()+1){
            ret = path;
            return;
        }

        for(int i=0;i<tickets.size();i++){
            if(i>0&&tickets[i]==tickets[i-1]&&!used[i-1]) continue;

            if(!used[i]&&tickets[i][0]==path.back()){
                path.push_back(tickets[i][1]);
                used[i]=true;
                backTracing(tickets,used);
                used[i]=false;
                path.pop_back();
            } 
        }
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<bool> used(tickets.size(),false);
        sort(tickets.begin(), tickets.end());
        path.push_back("JFK");
        backTracing(tickets,used);
        return  ret;
    }
};



//图论解法
class Solution {
private:
    // 使用邻接表存储图，用优先队列确保字典序
    unordered_map<string, priority_queue<string, vector<string>, greater<>>> graph;
    vector<string> path;
    
    void dfs(const string& curr) {
        // 遍历所有邻接点
        while (!graph[curr].empty()) {
            string next = graph[curr].top();
            graph[curr].pop();
            dfs(next);
        }
        // 逆序插入结果
        path.push_back(curr);
    }
    
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // 构建图
        for (const auto& ticket : tickets) {
            graph[ticket[0]].push(ticket[1]);
        }
        
        dfs("JFK");
        // 反转得到正确顺序
        reverse(path.begin(), path.end());
        return path;
    }
};


//利用图+回溯
class Solution {
private:
    // 邻接表存储图
    unordered_map<string, map<string, int>> targets;
    vector<string> path;
    
    bool backtrack(string curr, int ticketNum) {
        // 找到有效路径
        if (path.size() == ticketNum + 1) {
            return true;
        }
        
        // 遍历当前机场的所有目的地
        for (auto& [dst, count] : targets[curr]) {   //结构化绑定命名，c++17支持
            if (count > 0) {  // 还有票可以用
                count--;  // 使用一张票
                path.push_back(dst);
                
                if (backtrack(dst, ticketNum)) {
                    return true;
                }
                
                count++;  // 回溯，归还机票
                path.pop_back();
            }
        }
        return false;
    }
    
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // 构建邻接表，记录每个目的地的票数
        for (const auto& ticket : tickets) {
            targets[ticket[0]][ticket[1]]++;
        }
        
        path = {"JFK"};  // 起始机场
        backtrack("JFK", tickets.size());
        return path;
    }
};