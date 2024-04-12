#include<iostream>
#include<vector>

using namespace std;

    // void min_down(vector<int> &heap,int index){
    //     int min=index;
    //     if(2*index+1<heap.size()&&heap[index]>heap[2*index+1])  min=2*index+1;
    //     if(2*index+2<heap.size()&&heap[index]>heap[2*index+2])  min=2*index+2;//应该是2*index+2<heap.size()&&heap[min]>heap[2*index+2]
    //     if(min!=index){
    //         swap(heap[index],heap[min]);
    //         min_down(heap,min);
    //     }
    // }
    // void max_down(vector<int> &heap,int index){
    //     int max=index;
    //     if(2*index+1<heap.size()&&heap[index]<heap[2*index+1])  max=2*index+1;
    //     if(2*index+2<heap.size()&&heap[index]<heap[2*index+2])  max=2*index+2;
    //     if(max!=index){
    //         swap(heap[index],heap[max]);
    //         max_down(heap,max);
    //     }
    // }

    void min_down(vector<int> &heap, int index) {
    int min = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < heap.size() && heap[index] > heap[leftChild])
        min = leftChild;

    if (rightChild < heap.size() && heap[min] > heap[rightChild])
        min = rightChild;

    if (min != index) {
        swap(heap[index], heap[min]);
        min_down(heap, min);
    }
}

void max_down(vector<int> &heap, int index) {
    int max = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < heap.size() && heap[index] < heap[leftChild])
        max = leftChild;

    if (rightChild < heap.size() && heap[max] < heap[rightChild])
        max = rightChild;

    if (max != index) {
        swap(heap[index], heap[max]);
        max_down(heap, max);
    }
}
    void printHeap(vector<int> heap){
        for(int i=0;i<heap.size();i++){
            cout<<heap[i];
            if(i!=heap.size()-1){
                cout<<" ";
            }

        }
        cout<<endl;
    }

int main(){
    int N;
    cin>>N;
    vector<int> heap(N);
    for(int i=0;i<N;i++){
        cin>>heap[i];
    }
    vector<int> minHeap=heap,maxHeap=heap;
    for(int i=heap.size()/2-1;i>=0;i--){
        min_down(minHeap,i);
    }
    for(int i=heap.size()/2-1;i>=0;i--){
        max_down(maxHeap,i);
    }
    printHeap(minHeap);
    printHeap(maxHeap);
    return 0;
}