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

// brute would be to use a extra container to sort it

Node *sort012Better(Node *head) {
    int count0 = 0, count1 = 0, count2 = 0;
    Node *temp = head;
    while(temp) {
        if(temp->data == 0) count0++;
        else if(temp->data == 1) count1++;
        else count2++;
    }
    temp = head;
    while(count0--) {
        temp->data = 0;
        temp = temp->next;
    }
    while(count1--) {
        temp->data = 1;
        temp = temp->next;
    }
    while(count2--) {
        temp->data = 2;
        temp = temp->next;
    }
    return head;
} // O(2N) time, we can write it more cleanly using if-else instead of 4 while loops

// this DNF OR dutch national flag algo but linked list style
// Here we will try to create 3 lists, one of 0s, one of 1s and one of 2s and in the end connect them
Node* sort012Optimal(Node *head) {
    if(!head || !head->next) return head; // already sorted 
    Node *dummy0 = new Node(-1), *dummy1 = new Node(-1), *dummy2 = new Node(-1);
    Node *zero = dummy0, *one = dummy1, *two = dummy2;
    Node *temp = head;
    while(temp) {
        if(temp->data == 0) {
            zero->next = temp;
            zero = temp;
        } else if(temp->data == 1) {
            one->next = temp;
            one = temp;
        } else {
            two->next = temp;
            two = temp;
        }
        temp = temp->next;
    } 
    // now just attach them

    if(dummy1->next) zero->next = dummy1->next;
    else zero->next = dummy2->next;
    // because if we dont have any 1s then we point it to 2s, not nullptr
    one->next = dummy2->next; // always
    two->next = nullptr; // always
    Node *newHead = dummy0->next;
    delete dummy0;
    delete dummy1;
    delete dummy2;
    return newHead;
} // O(N) time 
 
int main() {
    
    return 0;
}