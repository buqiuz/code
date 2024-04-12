#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// const int INF = numeric_limits<int>::max(); // 用于表示无穷大的值

// class Graph {
// private:
//     int numVertices;
//     vector<vector<int>> adjacencyMatrix;

// public:
//     Graph(int vertices) : numVertices(vertices), adjacencyMatrix(vertices, vector<int>(vertices, INF)) {}

//     void addEdge(int start, int end, int weight) {
//         adjacencyMatrix[start][end] = weight;
//     }

//     vector<int> dijkstra(int start) {
//         vector<int> distance(numVertices, INF);
//         distance[start] = 0;

//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//         pq.push({0, start});

//         while (!pq.empty()) {
//             int current = pq.top().second;
//             int currentDistance = pq.top().first;
//             pq.pop();

//             // 如果当前距离大于已知的最短距离，忽略该节点
//             if (currentDistance > distance[current]) {
//                 continue;
//             }

//             for (int neighbor = 0; neighbor < numVertices; ++neighbor) {
//                 int weight = adjacencyMatrix[current][neighbor];

//                 if (weight != INF) {
//                     int newDistance = distance[current] + weight;

//                     if (newDistance < distance[neighbor]) {
//                         distance[neighbor] = newDistance;
//                         pq.push({newDistance, neighbor});
//                     }
//                 }
//             }
//         }

//         return distance;
//     }
// };

// int main() {
//     // 创建一个包含4个顶点的有向图
//     Graph graph(4);

//     // 添加边和权重
//     graph.addEdge(0, 1, 10);
//     graph.addEdge(0, 3, 5);
//     graph.addEdge(1, 2, 1);
//     graph.addEdge(1, 3, 2);
//     graph.addEdge(3, 1, 3);
//     graph.addEdge(3, 2, 9);

//     // 从节点0开始运行Dijkstra算法
//     vector<int> shortestDistances = graph.dijkstra(0);

//     // 输出最短路径
//     cout << "Shortest distances from node 0:" << endl;
//     for (int i = 0; i < shortestDistances.size(); ++i) {
//         cout << "To node " << i << ": " << shortestDistances[i] << endl;
//     }

//     return 0;
// }




#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

// 图的邻接列表表示
struct Edge {
    int to;
    int weight;
};

// Dijkstra算法
void dijkstra(vector<vector<Edge>>& graph, int start, vector<int>& distance, vector<int>& parent) {
    int n = graph.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    distance.assign(n, INF);
    parent.assign(n, -1);

    distance[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int dist_u = pq.top().first;
        pq.pop();

        if (dist_u > distance[u]) {
            continue; // 已经找到更短的路径
        }

        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            int weight_uv = edge.weight;

            if (distance[u] + weight_uv < distance[v]) {
                distance[v] = distance[u] + weight_uv;
                parent[v] = u;
                pq.push({distance[v], v});
            }
        }
    }
}

// 打印最短路径
void printShortestPath(vector<int>& parent, int node) {
    if (parent[node] == -1) {
        cout << node;
        return;
    }
    printShortestPath(parent, parent[node]);
    cout << " -> " << node;
}

int main() {
    // 构建图
    int n = 6; // 顶点数
    vector<vector<Edge>> graph(n);

    // 添加边
    graph[0].push_back({1, 2});
    graph[0].push_back({2, 4});
    graph[1].push_back({2, 1});
    graph[1].push_back({3, 7});
    graph[2].push_back({4, 3});
    graph[3].push_back({4, 1});
    graph[3].push_back({5, 5});
    graph[4].push_back({5, 2});

    // 运行Dijkstra算法
    vector<int> distance, parent;
    int startNode = 0;
    dijkstra(graph, startNode, distance, parent);

    // 打印结果
    for (int i = 0; i < n; ++i) {
        cout << "Shortest Path from " << startNode << " to " << i << ": ";
        printShortestPath(parent, i);
        cout << ", Distance = " << distance[i] << endl;
    }

    return 0;
}
