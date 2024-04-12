#include<iostream>
#include<vector>

using namespace std;

class MinHeap {
private:
    
public:
    vector<int> heap;
    MinHeap();
    ~MinHeap();
    
    void up(int index) {
        if (index == 0) {
            return;
        }

        int parent = (index - 1) / 2;
        if (heap[parent] > heap[index]) {
            swap(heap[parent], heap[index]);
            up(parent);
        }
    }

    void down(int index) {
        int minIndex = index;
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        if (leftChild < heap.size() && heap[leftChild] < heap[minIndex]) {
            minIndex = leftChild;
        }

        if (rightChild < heap.size() && heap[rightChild] < heap[minIndex]) {
            minIndex = rightChild;
        }

        if (minIndex != index) {
            swap(heap[minIndex], heap[index]);
            down(minIndex);
        }
    }

    void insert(int value) {
        heap.push_back(value);
        up(heap.size() - 1);
    }

    int erase() {
        if (heap.empty()) {
            cout << "Heap is empty!" << endl;
            return -1; // or throw an exception
        }

        int top = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        down(0);

        return top;
    }

    void printHeap() {
        for (int i = 0; i < heap.size(); i++) {
            cout << heap[i];
            if (i != heap.size() - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
};

MinHeap::MinHeap() {

}

MinHeap::~MinHeap() {

}

int main() {
    int N, K;
    cin >> N >> K;
    int a, b;
    MinHeap heap;
    for (int i = 0; i < K; i++) {
        cin >> a;
        if (a == 1 ) {
            cin >> b;
            if(heap.heap.size() < N)
            heap.insert(b);
        }
        if (a == -1 && heap.heap.size() > 0) {
            heap.erase();
        }
        heap.printHeap();
    }

    int m, c;
    cin >> m;
    MinHeap h;
    for (int i = 0; i < m; i++) {
        cin >> c;
        h.heap.push_back(c);
    }

    // 进行堆化，保持最小堆性质
    for (int i = h.heap.size() / 2 - 1; i >= 0; i--) {
        h.down(i);
    }

    h.printHeap();

    return 0;
}
