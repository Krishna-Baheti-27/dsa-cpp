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

// to sort this we have mergeSort or quickSort but quickSort is difficult to implement for LL

Node *findMiddle(Node *head) {
    if(!head || !head->next) return head;
    Node *slow = head, *fast = head;
    // check if list is not empty before
    while(fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
} // this will return the first middle

Node *mergeLL(Node *leftHead, Node *rightHead) {
    // how to merge 2 sorted lists
    Node *dummyNode = new Node(-1);
    Node *temp = dummyNode;
    while(leftHead && rightHead) {
        if(leftHead->data >= rightHead->data) {
            temp->next = rightHead; // append it to our list
            temp = rightHead; // make it the new temp
            rightHead = rightHead->next; // move ahead since that node is already merged
        } else {
            temp->next = leftHead;
            temp = leftHead;
            leftHead = leftHead->next;
        }
    }
    if(leftHead) temp->next = leftHead; // thats it entire LL is already connected
    else if(rightHead) temp->next = rightHead;
    // here we cannot return temp but original head which we maintained using dummyNode
    return dummyNode->next;
}

Node* sortListOptimal(Node *head) {
    if(!head || !head->next) return head; // already sorted
    Node *middle = findMiddle(head);
    Node *leftHead = head, *rightHead = middle->next;
    middle->next = nullptr; // very imp so that they both act as separate LL
    leftHead = sortListOptimal(leftHead);
    rightHead = sortListOptimal(rightHead);
    return mergeLL(leftHead, rightHead);
} // O(logn * (n + n/2)) time, here we take extra n/2 time for finding middle
 // O(logn) stack space but not extra array or anything

int main() {
    
    return 0;
}