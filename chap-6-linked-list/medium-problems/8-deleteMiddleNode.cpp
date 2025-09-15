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

// we have to delete the second middle in case of ll with even nodes else delete middle
// brute force is just finding the length of ll and delete the (n/2 + 1)th node from beginning

// optimal solution uses tortoise and hare algo

Node* deleteMiddle(Node *head) {
    if(!head || !head->next) return nullptr;
    Node *slow = head, *fast = head;
    while(fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    // slow now points to first middle and hence we can easily delete second middle
    Node *toDelete = slow->next;
    slow->next = slow->next->next;
    delete toDelete;
    return head; 
} // O(N/2) time


int main() {
    
    return 0;
}