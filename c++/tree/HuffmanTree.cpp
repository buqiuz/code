#include <iostream>
#include <queue>
#include <vector>

// 哈夫曼树的节点
struct HuffmanNode {
    char data;             // 节点的数据（字符）
    int frequency;         // 节点的频率
    HuffmanNode* left;     // 左子树
    HuffmanNode* right;    // 右子树

    HuffmanNode(char data, int frequency) : data(data), frequency(frequency), left(nullptr), right(nullptr) {}
};

// 用于比较节点频率的比较函数
struct CompareNodes {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->frequency > b->frequency;
    }
};

// 哈夫曼树类
class HuffmanTree {
public:
    HuffmanNode* root;

    // 构造函数，接受一个字符频率表
    HuffmanTree(std::vector<std::pair<char, int>> charFrequencies) {
        buildHuffmanTree(charFrequencies);
    }

    // 构建哈夫曼树
    void buildHuffmanTree(std::vector<std::pair<char, int>> charFrequencies) {
        std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, CompareNodes> minHeap;

        // 创建叶子节点并将它们添加到最小堆中
        for (const auto& entry : charFrequencies) {
            HuffmanNode* newNode = new HuffmanNode(entry.first, entry.second);
            minHeap.push(newNode);
        }

        // 构建哈夫曼树
        while (minHeap.size() > 1) {
            HuffmanNode* left = minHeap.top();
            minHeap.pop();
            HuffmanNode* right = minHeap.top();
            minHeap.pop();

            // 创建一个新的内部节点，其频率为左右子树的频率之和
            HuffmanNode* internalNode = new HuffmanNode('\0', left->frequency + right->frequency);
            internalNode->left = left;
            internalNode->right = right;
            minHeap.push(internalNode);
        }

        // 最后剩下的节点是根节点
        root = minHeap.top();
    }
};
