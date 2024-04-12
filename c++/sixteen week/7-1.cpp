#include <iostream>
#include <vector>

using namespace std;

#define MaxVexNum 20

typedef struct {
    int arcs[MaxVexNum][MaxVexNum];
    int vexnum, arcnum;
} AMGraph;

int visited[MaxVexNum];

void DFS(AMGraph& G, int v) {
    cout << v << " ";
    visited[v] = 1;

    for (int w = 0; w < G.vexnum; ++w) {
        if (G.arcs[v][w] && !visited[w]) {
            DFS(G, w);
        }
    }
}

int main() {
    AMGraph G;

    // 读入图的顶点数和边数
    cin >> G.vexnum >> G.arcnum;

    // 初始化图的邻接矩阵
    for (int i = 0; i < G.vexnum; ++i) {
        for (int j = 0; j < G.vexnum; ++j) {
            G.arcs[i][j] = 0;
        }
    }

    // 读入边信息，构建邻接矩阵
    for (int i = 0; i < G.arcnum; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        G.arcs[v1][v2] = G.arcs[v2][v1] = 1;
    }

    // 初始化访问标记数组
    for (int i = 0; i < G.vexnum; ++i) {
        visited[i] = 0;
    }


    int components = 0;
    for (int i = 0; i < G.vexnum; ++i) {
        if (!visited[i]) {
            DFS(G, i);
            components++;
        }
    }

    // 计算边数
    int edges = 0;
    for (int i = 0; i < G.vexnum; ++i) {
        for (int j = i + 1; j < G.vexnum; ++j) {
            if (G.arcs[i][j]) {
                edges++;
            }
        }
    }

    cout << "\n" << components << "\n" << edges << "\n";

    return 0;
}
