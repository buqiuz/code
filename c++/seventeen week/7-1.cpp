#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> topologicalSort(vector<vector<int>> &graph,vector<int> &inDgree){
    priority_queue<int,vector<int>,greater<int>> pq;
    for (int i = 0; i < inDgree.size(); i++)
    {
        if (inDgree[i]==0)
        {
            pq.push(i);
        }
        
    }
    vector<int> result;
    while (!pq.empty())
    {
        int current=pq.top();
        pq.pop();
        result.push_back(current);
        for (auto &&i : graph[current])
        {
            if (--inDgree[i]==0)
            {
                pq.push(i);
            }
            
        }
        
    }
    return result;  
    
}

int main() {
    int n,e;
    cin>>n>>e;
    vector<vector<int>> graph(n);
    vector<int> inDgree(n,0);
    for (int i = 0; i < e; i++)
    {
        int start,end;
        cin>>start>>end;
        graph[start].push_back(end);
        inDgree[end]++;

    }
    vector<int> result=topologicalSort(graph,inDgree);
    if (result.size()==n)
    {
        for (auto &&i : result)
        {
            cout<<i<<" ";
        }
    }else
    cout<<"unworkable project";
    
    
    
}

