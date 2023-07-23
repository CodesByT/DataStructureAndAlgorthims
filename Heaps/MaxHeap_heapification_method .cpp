#include <iostream>
using namespace std;

class MaxHeap {
private:
    int* maxheap;
    int maxSize;
    int currentSize;

public:
    MaxHeap(int s) {
        maxheap = new int[s + 1];
        maxSize = s;
        currentSize = 0;
    }
    void heapification(int maxheap[], int i, int size) {
        int parent = i;
        int lChild = 2 * i;
        int rChild = 2 * i + 1;
        if (lChild <= size && maxheap[lChild] > maxheap[parent]) {
            parent = lChild;
        }
        if (rChild <= size && maxheap[rChild] > maxheap[parent]) {
            parent = rChild;
        }
        if (parent != i) {
            int temp = maxheap[i];
            maxheap[i] = maxheap[parent];
            maxheap[parent] = temp;
            heapification(maxheap, parent, size);
        }
    }
};
