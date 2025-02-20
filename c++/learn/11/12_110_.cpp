#include <bits/stdc++.h>
using namespace std;

bool is_next(string s1, string s2) {
    int count = 0;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != s2[i])
            count++;
    }
    return count == 1;
}

int ret = 0;

void dfs(vector<vector<int>> &graph, vector<bool> &visited, int node, int count) {
    if (node == 1) {
        if (ret == 0)
            ret = count;
        else
            ret = min(ret, count);
        return;
    }

    for (int i = 0; i < graph[node].size(); i++) {
        if (visited[graph[node][i]])
            continue;

        visited[graph[node][i]] = true;
        dfs(graph, visited, graph[node][i], count + 1);
        visited[graph[node][i]] = false;
    }
}

int bfs(const vector<vector<int>> &graph, int start, int end) {
    queue<pair<int, int>> q;
    vector<bool> visited(graph.size(), false);

    q.push({start, 1});
    visited[start] = true;

    while (!q.empty()) {
        auto [cur, step] = q.front();
        q.pop();

        if (cur == end)
            return step; // 找到目标单词，返回步数

        for (int neighbor : graph[cur]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push({neighbor, step + 1});
            }
        }
    }
    return 0; // 无法转换
}

int main() {

    int n;
    cin >> n;
    string beginStr, endStr;
    cin >> beginStr >> endStr;

    vector<string> words;
    words.push_back(beginStr);
    words.push_back(endStr);

    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        words.push_back(word);
    }

    int totalWords = words.size();
    vector<vector<int>> graph(totalWords);

    for (int i = 0; i < totalWords; i++) {
        for (int j = i + 1; j < totalWords; j++) {
            if (is_next(words[i], words[j])) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }

    // vector<bool> visited(n+2,false);
    // visited[0]=true;
    // dfs(graph,visited,0,1);
    ret = bfs(graph, 0, 1);

    cout << ret << endl;

    return 0;
}