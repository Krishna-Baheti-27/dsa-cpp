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

Node* sortListBrute(Node *head) {
    // using temporary array
    vector<int> tempArr;
    Node *temp = head;
    while(temp) {
        tempArr.push_back(temp->data);
        temp = temp->next;
    }
    sort(tempArr.begin(), tempArr.end());
    temp = head;
    for(int i = 0; i < tempArr.size(); i++) {
        temp->data = tempArr[i];
        temp = temp->next;
    }
    return head;
} // O(nlogn + 2n) time and O(n) space

Node* sortListOptimal(Node *head) {
    
}

int main() {
    
    return 0;
}