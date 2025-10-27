#include<bits/stdc++.h>
using namespace std;

// What is Priority Queue ?
// A Priority Queue is a special type of queue where each element is assigned a priority, and instead of being processed in the order they arrive (like a normal queue), the element with the highest priority is always processed first.

// If two elements have the same priority, they are handled based on their insertion order.
// Think of it like an emergency room in a hospital patients are not treated just by arrival time, but by how critical their condition is; someone with a heart attack gets attention before someone with a cold, regardless of who came first. This makes priority queues super useful in scenarios like task scheduling, pathfinding algorithms, and real-time systems.

// THE MOST EFFICIENT METHOD TO IMPLEMENT PRIORITY QUEUES IS USING BINARY HEAPS OR SIMPLY HEAPS

// Heaps or Binary Heaps are basically complete binary trees satisfying the heap property
// there can be twp types of heap
// max-heap where each parent node has value >= left and right child (root is the maximum)
// min-heap where each parent node has value <= left and right child (root is the minimum)

// we create a heap by always inserting the element at last available position and then make it propagate up depending upon its value so heap property is satisfied
// but we dont implement heap using binary trees (even though heap is a complete binary tree) since its difficult to traverse up the binary tree and lot time consuming hence we implement heaps using arrays

// since in array, if we know the parent's index = i
// left child = 2*i + 1 and right child = 2*i + 2
// if we know the index of child = i, then its parent is (i - 1) / 2, (floor value)
// now we get child and parent easily compared to binary trees

class MaxHeap {
    int *arr;
    int size; // current elements in heap
    int capacity; // max elements that can be inserted in heap

    public:

    MaxHeap(int n){
        arr = new int[n];
        size = 0;
        capacity = n;
    }

    ~MaxHeap() {
        delete[] arr;
    }

    // use vectors instead which are completely memory safe and no need to write destructors or copy constructors

    void insert(int val) {
        if(size == capacity) {
            cout << "heap overflow\n";
            return;
        }
        arr[size] = val; // we always insert it in the end and then propagate up
        int index = size; // index at which we inserted
        size++; // increase since one more element added to heap
        
        // compare it with parent and propagate up till it reaches correct position
        while(index > 0 && arr[index] > arr[(index - 1) / 2]) {
            swap(arr[index], arr[(index - 1) / 2]);
            index = (index - 1) / 2; // update the index to its parent or new position
        }
        // this also ensure that max element would always be on the root or index 0
    }

    int getMax() {
        return size == 0 ? -1 : arr[0];
    }

    void print() {
        for(int i = 0; i < size; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
    }

    void heapify(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        
        // store the greater of parent, left and right in the largest index but first check if left and right child exist

        if(left < size && arr[left] > arr[largest]) largest = left;
        if(right < size && arr[right] > arr[largest]) largest = right;

        if(largest != index) {
            swap(arr[index], arr[largest]);
            heapify(largest); // now again apply heapify for the next index
        }

    }

    void extract_max() { // this process is also known heapify
        // as we place the last element into root and then make the root place on its correct position and hence heapify, since we are maintaing the heap property
        if(size == 0) {
            cout << "Heap underflow\n";
            return;
        }
        arr[0] = arr[size - 1];
        size--; // decrease the size
        if(size == 0) return; // nothing left to be heapifyed
        heapify(0); // now heapify or place our root at its correct position
    }

};


int main() {
    
    return 0;
}