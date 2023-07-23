#include <iostream>
using namespace std;

class MinHeap {
private:
    int* minheap;
    int maxSize;
    int currentSize;

public:
    MinHeap(int s) {
        minheap = new int[s + 1];
        maxSize = s;
        currentSize = 0;
    }
    void heapification(int minheap[], int i, int size) {
        int parent = i;
        int lChild = 2 * i;
        int rChild = 2 * i + 1;
        if (lChild <= size && minheap[lChild] < minheap[parent]) {
            parent = lChild;
        }
        if (rChild <= size && minheap[rChild] < minheap[parent]) {
            parent = rChild;
        }
        if (parent != i) {
            int temp = minheap[i];
            minheap[i] = minheap[parent];
            minheap[parent] = temp;
            heapification(minheap, parent, size);
        }
    }
};
