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

///////////////////////////////////////////////////////////////////////////////

Node *reverseLL(Node *head) {

    Node *curr = head, *prev = nullptr, *next = nullptr;

    while(curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

// for right rotate first we reverse the entire array then reverse from 0 to k - 1 and then from k to n - 1

Node *rotateOptimal(Node *head, int k) {

    int n = 0;

    Node *temp = head;
    while(temp) {
        n++;
        temp = temp->next;
    }

    k = k % n;

    head = reverseLL(head);

    temp = head;
    int count = 0;

    while(count < k - 1) {
        count++;
        temp = temp->next;
    }
    
    Node *nextNode = temp->next;
    temp->next = nullptr;

    head = reverseLL(head);
    head->next = reverseLL(nextNode);

    return head;
}

int main() {
    
    return 0;
}