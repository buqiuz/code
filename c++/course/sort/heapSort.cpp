#include <iostream>
#include <vector>

using namespace std;

class MaxHeap {
public:
    vector<int> heap;

    void maxHeapify(int i, int heapSize) {
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;
        int largest = i;

        if (leftChild < heapSize && heap[leftChild] > heap[largest]) {
            largest = leftChild;
        }

        if (rightChild < heapSize && heap[rightChild] > heap[largest]) {
            largest = rightChild;
        }

        if (largest != i) {
            swap(heap[i], heap[largest]);
            maxHeapify(largest, heapSize);
        }
    }

    void buildMaxHeap() {
        int heapSize = heap.size();
        for (int i = heapSize / 2 - 1; i >= 0; i--) {
            maxHeapify(i, heapSize);
        }
    }

    void heapSort() {
        buildMaxHeap();
        int heapSize = heap.size();

        for (int i = heapSize - 1; i > 0; i--) {
            swap(heap[0], heap[i]);
            maxHeapify(0, i);
        }
    }
};

int main() {
    MaxHeap maxHeap;

    // Input elements into the heap
    int element;
    while (cin >> element) {
        maxHeap.heap.push_back(element);
    }

    // Perform heap sort
    maxHeap.heapSort();

    // Output sorted elements
    for (int i = 0; i < maxHeap.heap.size(); i++) {
        cout << maxHeap.heap[i] << " ";
    }

    return 0;
}
