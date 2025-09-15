#include<bits/stdc++.h>
using namespace std;

class Node {  // can also use struct but you miss all the OOP advantages
    public:
    int data;
    Node *next;
    Node(int data, Node *next) {
        this->data = data; // instead of this you can also use simply data = data1 (change the parameter name)
        this->next = next;
    }
    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

Node *addTwoNumbers(Node *l1, Node *l2) {
    Node *dummy = new Node(-1);
    Node *temp = dummy;
    Node *t1 = l1, *t2 = l2;
    int carry = 0;
    while(t1 && t2) {
        int sum = t1->data + t2->data + carry;
        Node *newNode = new Node(sum % 10);
        temp->next = newNode;
        temp = newNode;
        carry = sum / 10;
        t1 = t1->next;
        t2 = t2->next;
    }
    while(t1) {
        int sum = t1->data + carry;
        Node *newNode = new Node(sum % 10);
        temp->next = newNode;
        temp = newNode;
        carry = sum / 10;
        t1 = t1->next;
    }
    while(t2) {
        int sum = t2->data + carry;
        Node *newNode = new Node(sum % 10);
        temp->next = newNode;
        temp = newNode;
        carry = sum / 10;
        t2 = t2->next;
    }
    // add carry at the last if its left
    if(carry != 0) {
        Node *newNode = new Node(carry);
        temp->next = newNode;
    }
    return dummy->next;
} //  O(max(m,n)) time and O(max(m,n)) space for creating nodes (not for solving)
// the code is bit redundant so here is a better way to write

Node *addTwoNumbersBetter(Node *l1, Node *l2) {
    Node *dummy = new Node(-1);
    Node *temp = dummy;
    Node *t1 = l1, *t2 = l2;
    int carry = 0;
    while(t1 || t2) {
        int sum = carry;
        if(t1) sum += t1->data;
        if(t2) sum += t2->data;
        int num = sum % 10;
        carry = sum / 10;
        Node *newNode = new Node(num);
        temp->next = newNode;
        temp = newNode;
        if(t1) t1 = t1->next;
        if(t2) t2 = t2->next;
    }
    if(carry != 0) {
        Node *newNode = new Node(carry);
        temp->next = newNode;
    }
    return dummy->next;
}

int main() {
    
    return 0;
}