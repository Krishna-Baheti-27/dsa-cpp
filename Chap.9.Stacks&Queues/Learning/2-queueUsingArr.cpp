#include <iostream>
#include <stdexcept>

using namespace std;

class Queue {
    int capacity; 
    int *arr;
    int frontIndex;
    int rearIndex;

public:
    Queue(int s) {
        capacity = s;
        arr = new int[capacity];
        frontIndex = -1;
        rearIndex = -1;
    }

    ~Queue() {
        delete[] arr; 
    }

    bool isEmpty() {
        return frontIndex == -1;
    }

    void push(int x) {
        if ((rearIndex + 1) % capacity == frontIndex) {
            cout << "Queue is full!" << endl;
            return;
        }
        if (isEmpty()) { 
            frontIndex = 0;
            rearIndex = 0;
        } else { 
            rearIndex = (rearIndex + 1) % capacity;
        }
        arr[rearIndex] = x;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Queue is empty, cannot pop!" << endl;
            return;
        }

        // If this is the last element in the queue, reset to empty state
        if (frontIndex == rearIndex) {
            frontIndex = -1;
            rearIndex = -1;
        } else {
            frontIndex = (frontIndex + 1) % capacity;
        }
    }

    int front() {
        if (isEmpty()) {
            throw out_of_range("Queue is empty");
        }
        return arr[frontIndex];
    }

    int back() {
        if (isEmpty()) {
            throw out_of_range("Queue is empty");
        }
        return arr[rearIndex];
    }
    
    int size() {
        if (isEmpty()) {
            return 0;
        }
        // Formula to find the current number of elements in queue
        return (rearIndex - frontIndex + capacity) % capacity + 1;
    }
};

int main() {
    return 0;
} 