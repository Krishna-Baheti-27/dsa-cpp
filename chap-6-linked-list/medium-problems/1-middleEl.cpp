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

//////////////////////////////////////////////////////////////////////////////////////

// to return the second middle in case of even length linked list

Node* middleNodeBrute(Node *head) {

    int length = 0;
    Node *temp = head;

    while(temp) {
        length++;
        temp = temp->next;
    }

    int middle = length / 2;
    temp = head;

    for(int i = 1; i <= middle; i++) temp = temp->next;

    return temp;

} // O(n + n / 2) time

//////////////////////////////////////////////////////////////////////////////////

// using tortoise and hare algorithm, basically the concept of fast and slow pointers

Node *middleNodeOptimal(Node *head) {
    
    Node *slow = head, *fast = head;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;

} // O(N / 2) time in single pass

//////////////////////////////////////////////////////////////////////////////////

// to get the first middle for even length linked list

Node *middleNodeOptimal(Node *head) {

    if(!head) return head; // we have to check this since fast->next might give error for empty list
    
    Node *slow = head, *fast = head;
    
    while(fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;

} // O(N/2) time and O(1) space

int main() {
    
    return 0;
}