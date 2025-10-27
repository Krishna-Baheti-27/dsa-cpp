#include <iostream>
#include <stdexcept>

using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int d) {
        data = d;
        next = nullptr;
    }
};

class Queue {
    Node *m_front; 
    Node *m_rear;  
    int m_size;    

public:
    Queue() {
        m_front = nullptr;
        m_rear = nullptr;
        m_size = 0;
    }

    ~Queue() {
        while (m_front != nullptr) {
            pop();
        }
    }

    void push(int x) {
        Node *newNode = new Node(x);
        
        // Handle insertion into an empty queue
        if (m_rear == nullptr) {
            m_front = newNode;
            m_rear = newNode;
        } else {
            m_rear->next = newNode;
            m_rear = newNode;
        }
        m_size++;
    }

    void pop() {
        if (m_front == nullptr) { // Or check if m_size == 0
            return;
        }
        
        Node *temp = m_front;
        m_front = m_front->next;
        delete temp;
        m_size--;

        // If the queue becomes empty, update rear as well, basically reset the queue
        if (m_front == nullptr) {
            m_rear = nullptr;
        }
    }

    int front() {
        if (m_size == 0) {
            throw out_of_range("Queue is empty");
        }
        return m_front->data;
    }

    int back() {
        if (m_size == 0) {
            throw out_of_range("Queue is empty");
        }
        return m_rear->data;
    }

    int size() {
        return m_size;
    }

    bool isEmpty() {
        return m_front == nullptr; // or m_size == 0
    }
};

int main() {
    
    return 0;
}