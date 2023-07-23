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
    void heapify(int minheap[], int i, int size) {
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
            heapify(minheap, parent, size);
        }
    }
    void InsertInHeap(int val) {
        if (currentSize >= maxSize) {
            cout << "Heap is full" << endl;
            return;
        }

        currentSize++;
        int x = currentSize;
        minheap[x] = val;

        for (int i = currentSize; i > 1; i /= 2) {
            // perform heapify on each insertion into heap
            heapify(minheap, i / 2, currentSize);
        }
    }
    void displayHeap() {
        cout << "\n\nMinHeap = ";
        for (int i = 1; i <= currentSize; i++) {
            cout << minheap[i] << "  ";
        }
        cout << endl;
    }
    void DeleteFromHeap(int value) {
        int index = 0;
        for (int i = 1; i <= currentSize; i++) {
            if (minheap[i] == value)
                index = i;
        }
        if (index <= 0 || index > currentSize) {
            cout << "Invalid Number" << endl;
            return;
        }
        minheap[index] = minheap[currentSize];  // Replace node at index with the last element
        currentSize--;  // Decrease currentSize

        // Perform heapify on the node at index
        heapify(minheap, index, currentSize);
    }
};

int main() {

    MinHeap heap(10);

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
