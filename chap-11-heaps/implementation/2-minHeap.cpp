#include<bits/stdc++.h>
using namespace std;

class MinHeap {
    int *arr;
    int size;
    int capacity;

    public:

    MinHeap(int n) {
        arr = new int[n];
        size = 0;
        capacity = n;
    }

    ~MinHeap() {
        delete[] arr;
    }

    void insert(int val) {
           
    }

};

int main() {
    
    return 0;
}