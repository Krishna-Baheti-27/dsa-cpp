#include<iostream>
#include<stdlib.h>
#include<vector>

using namespace std;
// tortosie and hare algorithm to find the middle node of the LL, also called slow and fast pointer
// for odd value of n we return middle simply, for even value we return the second middle

class Node {
    public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

Node* arrayToLL(vector<int> &arr) {
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for(int i = 1; i < arr.size(); i++) {
        Node *newNode = new Node(arr[i]);
        temp->next = newNode;
        temp = newNode;
    }
    return head;
}

Node* findMiddle(Node *head) { // return second middle
    Node *slow = head, *fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* findFirstMiddle(Node *head) {
    Node *slow = head, *fast = head->next;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *findMiddleNaiveSolution(Node *head) {
    int n = 0;
    Node *temp = head;
    while(temp) {
        n++;
        temp = temp->next;
    }
    // answer would ne (n/2 + 1)th node for 1-based indexing
    temp = head;
    for(int i = 1; i <= n/2; i++) {
        temp = temp->next;
    }
    return temp; // middle node
}

int main() {
    vector<int> arr = {1,2,4,6,7};
    Node *head = arrayToLL(arr);
    Node *middle = findMiddleNaiveSolution(head);
    cout << middle->data << endl;
    return 0;
}