#include<iostream>
#include<stdlib.h>
#include<vector>
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

void display(Node *head) {
    Node *temp = head;
    while(temp != nullptr) {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << endl;
}


Node *separateOddEven(Node *head) {
    Node *odd = head, *even = head->next;
    while(odd->next && even) {
        odd->next = even->next;
        even->next = even->next->next;
        odd = even->next;
        even = odd->next;
    }
    odd->next = head->next;
    return head;
}

int main() {
    vector<int> arr = {1,2,3,4,5};
    Node *head = arrayToLL(arr);
    display(head);
    head = separateOddEven(head);
    display(head);
}