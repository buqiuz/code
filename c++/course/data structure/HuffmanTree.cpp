#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 定义哈夫曼树结点
struct HuffmanNode {
    int weight;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(int w) : weight(w), left(nullptr), right(nullptr) {}
};

// 定义比较函数，用于优先队列
struct Compare {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->weight > b->weight;
    }
};

// 构建哈夫曼树
HuffmanNode* buildHuffmanTree(priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare>& pq) {
    while (pq.size() > 1) {
        HuffmanNode* left = pq.top();
        pq.pop();
        HuffmanNode* right = pq.top();
        pq.pop();

        HuffmanNode* internalNode = new HuffmanNode(left->weight + right->weight);
        internalNode->left = left;
        internalNode->right = right;

        pq.push(internalNode);
    }

    return pq.top();
}

// 计算哈夫曼树带权路径长度
int calculateWPL(HuffmanNode* root, int depth) {
    if (!root) {
        return 0;
    }

    if (!root->left && !root->right) {
        return root->weight * depth;
    }

    return calculateWPL(root->left, depth + 1) + calculateWPL(root->right, depth + 1);
}

int main() {
    int n;
    cin >> n;

    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;

    for (int i = 0; i < n; ++i) {
        int weight;
        cin >> weight;
        pq.push(new HuffmanNode(weight));
    }

    HuffmanNode* root = buildHuffmanTree(pq);

    int wpl = calculateWPL(root, 0);

    cout << wpl << endl;

    return 0;
}


//5
//1 2 2 5 9



#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <unordered_map>
#include <stack>

using namespace std;

const int MAX_NODES = 26;  // 假设节点数不超过26个

// 图的邻接矩阵表示
vector<vector<pair<int, int>>> graph(MAX_NODES);

void dijkstra(int start, int numNodes, const vector<char>& nodes) {
    vector<int> dist(numNodes, 256);  // 保存起点到各点的最短距离
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    vector<int> path(numNodes, -1);

    while (!pq.empty()) {
        int u = pq.top().second;
        int currentDistance=pq.top().first;
        pq.pop();
        
                    // 如果当前距离大于已知的最短距离，忽略该节点
            if (currentDistance > dist[u]) {
                continue;
            }


        for (const auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
                path[v] = u;
            }
        }
    }

    // 输出结果
    for (int i = 0; i < numNodes; ++i) {
		if (dist[i]==256)
		{
			cout << "dist[" << nodes[start] << "][" << nodes[i] << "]=" << dist[i]<<endl;
			cout<<nodes[i]<<endl;
		}else
		{
			cout << "dist[" << nodes[start] << "][" << nodes[i] << "]=" << dist[i];
            if (dist[i] != INT_MAX) {
                cout << endl << nodes[start];
                int current = i;
                stack<int> s;
                while (current != -1) {
                    s.push(current);
                    current = path[current];
                }
                s.pop();  // 弹出起点节点，确保不重复输出
                while (!s.empty()) {
                    cout << "->" << nodes[s.top()];
                    s.pop();
                }
            }
            cout << endl;
		}
		
		
        

        
    }
}

int main() {
    int numNodes, numEdges;
    cin >> numNodes >> numEdges;

    vector<char> nodes(numNodes);
    for (int i = 0; i < numNodes; ++i) {
        cin >> nodes[i];
    }

    for (int i = 0; i < numEdges; ++i) {
        char u, v;
        int weight;
        cin >> u >> v >> weight;

        int uIndex = u - 'A';
        int vIndex = v - 'A';

        graph[uIndex].emplace_back(vIndex, weight);
        graph[vIndex].emplace_back(uIndex, weight);
    }

    dijkstra(0, numNodes, nodes);

    return 0;
}
