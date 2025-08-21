#include <iostream>
#include <stdexcept> // For std::out_of_range

using namespace std;

class Stack {
    int topIndex; // Renamed 'top' to 'topIndex' for clarity
    int capacity; // Renamed 'size' to 'capacity'
    int *arr;     // Renamed 'st' to 'arr'

public:
    // Constructor
    Stack(int size) {
        topIndex = -1;
        capacity = size;
        arr = new int[capacity];
    }

    // Destructor to prevent memory leak
    ~Stack() {
        delete[] arr;
    }

    void push(int x) {
        if (topIndex >= capacity - 1) { 
            cout << "Stack Overflow!" << endl;
            return;
        }
        topIndex++;
        arr[topIndex] = x;
    }

    
    int peek() {
        if (topIndex == -1) {
            throw out_of_range("Stack Underflow: Cannot peek an empty stack!");
        }
        return arr[topIndex];
    }

    void pop() {
        if (topIndex == -1) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        topIndex--;
    }

    int size() {
        return topIndex + 1;
    }

    bool isEmpty() {
        return topIndex == -1;
    }
};

int main() {
    // Create stack on the heap
    Stack *myStack = new Stack(5);

    myStack->push(10);
    myStack->push(20);
    myStack->push(30);

    cout << "Top element is: " << myStack->peek() << endl; 
    cout << "Stack size is: " << myStack->size() << endl; 

    myStack->pop();
    cout << "Top element after pop is: " << myStack->peek() << endl; 

    // Deallocate the stack to prevent memory leak
    delete myStack;

    return 0;
}