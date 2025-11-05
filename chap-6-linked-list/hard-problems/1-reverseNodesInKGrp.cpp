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

// we are given a linked list and a value k, we have to find all groups of length k and reverse them individually, if length of linked list is not multiple of k and some nodes remain at end then they should remain as it is

///////////////////////////////////////////////////////////////////////////////////

// in the brute force i start from head of linked list and then store all the nodes of linked list in the order required in the final answer, that first goinf through K nodes then reversing and storing them in an array and then in the end we simply copy the elements of array to form a new linked list and return it

Node *reverseKNodesBrute(Node *head, int k) {

    Node *temp = head;
    vector<int> tempArr;

    int arrStart = 0, arrEnd = k;

    while(temp) {
        int i;
        for(i = 0; i < k && temp; i++) {
            tempArr.push_back(temp->data);
            temp = temp->next;
        }
        if(i >= k) {
            reverse(tempArr.begin() + arrStart, tempArr.begin() + arrEnd);
        }  
        arrStart += k;
        arrEnd += k;
    }

    Node *newHead = new Node(tempArr[0]);
    temp = newHead;
    for(int i = 1; i < tempArr.size(); i++) {
        Node *newNode = new Node(tempArr[i]);
        temp->next = newNode;
        temp = newNode;
    }

    return newHead;
} // O(N + N) for traversal and O(N/K * K) for reversal time so total O(3N) and O(2N) space

/////////////////////////////////////////////////////////////////////////////////////

// the more optimal approach does not use extra space and simply reverses the linked list in place

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

Node *reverseKNodesOptimal(Node *head, int k) {
    Node *dummy = new Node(-1);
    Node *newHead = dummy;
    Node *temp = head;

    while(temp) {
        int i;
        for(i = 0; i < k - 1 && temp; i++) {
            temp = temp->next;
        }
        Node *nextNode = temp->next;
        if(i >= k - 1) {
            temp->next = nullptr;
            newHead->next = reverseLL(temp);   
        }
    }
}

int main() {
    
    return 0;
}