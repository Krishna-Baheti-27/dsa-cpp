#include<bits/stdc++.h>
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

class Stack {
    int m_size;
    Node *top;
    public:
    Stack() {
        m_size = 0;
        top = nullptr;
    }
    ~Stack() {
        while (top != nullptr) {
            pop();
        }
    } // if stack object containing nodes were to be destoryed

    void push(int x) {
        // insertion at beginning
        Node *node = new Node(x);
        node->next = top;
        top = node;
        m_size++;
    }
    void pop() {
        if(m_size == 0) return;
        Node *temp = top;
        top = top->next;
        delete temp;
        m_size--;
    }
    int size() {
        return m_size;
    }
    int top() {
        if(m_size == 0) {
            throw out_of_range("Stack is empty");
        }
        return top->data;
    }
};

int main() {
    
    return 0;
}