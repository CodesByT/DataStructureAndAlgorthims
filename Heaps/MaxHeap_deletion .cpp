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
    void heapify(int maxheap[], int i, int size) {
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
            heapify(maxheap, parent, size);
        }
    }
    void InsertInHeap(int val) {
        if (currentSize >= maxSize) {
            cout << "Heap is full" << endl;
            return;
        }

        currentSize++;
        int x = currentSize;
        maxheap[x] = val;

        for (int i = currentSize; i > 1; i /= 2) {
            // perform heapify on each insertion into heap
            heapify(maxheap, i / 2, currentSize);
        }
    }
    void displayHeap() {
        cout << "\n\nMaxHeap = ";
        for (int i = 1; i <= currentSize; i++) {
            cout << maxheap[i] << "  ";
        }
        cout << endl;
    }
    void DeleteFromHeap(int value) {
        int index = 0;
        for (int i = 1; i <= currentSize; i++) {
            if (maxheap[i] == value)
                index = i;
        }
        if (index <= 0 || index > currentSize) {
            cout << "Invalid Number" << endl;
            return;
        }
        maxheap[index] = maxheap[currentSize];  // Replace node at index with the last element
        currentSize--;  // Decrease currentSize

        // Perform heapify on the node at index
        heapify(maxheap, index, currentSize);
    }
};

int main() {

    MaxHeap heap(10);

    heap.InsertInHeap(39);
    heap.displayHeap();
    heap.InsertInHeap(16);
    heap.displayHeap();
    heap.InsertInHeap(35);
    heap.displayHeap();
    heap.InsertInHeap(9);
    heap.displayHeap();
    heap.InsertInHeap(45);
    heap.displayHeap();
    heap.InsertInHeap(40);
    heap.displayHeap();
    heap.InsertInHeap(70);
    heap.displayHeap();
    heap.InsertInHeap(50);
    heap.displayHeap();
    heap.InsertInHeap(80);
    heap.displayHeap();

    cout << "\nAfter deletion :";
    heap.DeleteFromHeap(40);
    heap.displayHeap();
    heap.DeleteFromHeap(16);
    heap.displayHeap();
    heap.DeleteFromHeap(9);
    heap.displayHeap();
    return 0;
}
