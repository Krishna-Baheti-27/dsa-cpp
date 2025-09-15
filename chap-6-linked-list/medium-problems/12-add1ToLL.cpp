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

Node *add1ToLLBrute(Node *head) {
    int carry = 1; // initially we had to add 1
    // we have to start adding from back as we do in mathematics but we cannot traverse backward in SLL, and hence we reverse it
    head = reverseLL(head);
    Node *temp = head;
    while(temp) {
        if(carry == 0) break;
        int sum = temp->data + carry;
        temp->data = sum % 10; // new number
        carry = sum / 10; // new carry
        temp = temp->next;
    }
    head = reverseLL(head); // again reverse to get back the number
    if(carry != 0) {
        // create a new node and make it the head
        Node *newNode = new Node(carry);
        newNode->next = head;
        head = newNode;
    }
    return head;
} // O(3N) time

// if you want to do it without reversal then recursion is the only way becuase in that we have something known as backtracking so we can go all the way to end and do our work while returning

void helper(Node *&head, int &carry) {
    if(!head) return;
    helper(head->next, carry);
    if(carry == 0) return; // early return 
    int sum = head->data + carry;
    head->data = sum % 10;
    carry = sum / 10;
}

Node *add1ToLLOptimal(Node *head) {
    int carry = 1;
    helper(head, carry);
    if(carry != 0) { // handling this 999 + 1 case
        Node *newNode = new Node(carry);
        newNode->next = head;
        head = newNode;
    }
    return head;
} // O(N) time and O(N) recursion stack space
// here no tampering of data like reversal or anything, everything is in place

int main() {
    
    return 0;
}