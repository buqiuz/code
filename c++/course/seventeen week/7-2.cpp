#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<queue>
#include<vector>
#include<set>
#define INF 0x3f3f3f3f
#define PI acos(-1.0)
#define N 101
#define MOD 123
#define E 1e-6
using namespace std;
int g[N][N];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)
                g[i][j]=0;
            else
                g[i][j]=INF;
        }
    }
 
    for(int i=1;i<=m;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        g[x][y]=w;
        g[y][x]=w;
    }
 
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(g[i][j]>g[i][k]+g[k][j])
                    g[i][j]=g[i][k]+g[k][j];
 
    int maxx=-INF;
    for(int i=1;i<=n;i++)
        if(g[1][i]>maxx)
            maxx=g[1][i];
 
    if(maxx==INF)
        cout<<"-1"<<endl;
    else
        cout<<maxx<<endl;
 
    return 0;
}


// #include <iostream>
// #include <vector>
// #include <queue>
// #include <limits>

// using namespace std;

// const int INF = numeric_limits<int>::max();

// struct Edge {
//     int to;
//     int cost;
// };

// int dijkstra(const vector<vector<Edge>>& graph, int start, int n) {
//     vector<int> distance(n + 1, INF);
//     distance[start] = 0;

//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//     pq.push({0, start});

//     while (!pq.empty()) {
//         int current = pq.top().second;
//         int currentDistance = pq.top().first;
//         pq.pop();

//         if (currentDistance > distance[current]) {
//             continue;
//         }

//         for (const Edge& edge : graph[current]) {
//             int newDistance = distance[current] + edge.cost;

//             if (newDistance < distance[edge.to]) {
//                 distance[edge.to] = newDistance;
//                 pq.push({newDistance, edge.to});
//             }
//         }
//     }

//     int maxDistance = 0;
//     for (int i = 1; i <= n; ++i) {
//         if (distance[i] == INF) {
//             // 有哨所无法接收到信
//             return -1;
//         }
//         maxDistance = max(maxDistance, distance[i]);
//     }

//     return maxDistance;
// }

// int main() {
//     int n, m;
//     cin >> n >> m;

//     vector<vector<Edge>> graph(n + 1);

//     for (int i = 0; i < m; ++i) {
//         int a, b, k;
//         cin >> a >> b >> k;
//         graph[a].push_back({b, k});
//         graph[b].push_back({a, k});
//     }

//     int result = dijkstra(graph, 1, n);

//     cout << result << endl;

//     return 0;
// }
