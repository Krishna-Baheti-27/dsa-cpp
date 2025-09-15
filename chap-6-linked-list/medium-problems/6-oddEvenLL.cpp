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

Node *oddEvenListBrute(Node *head) {
    if(!head || !head->next) return head;
    vector<int> tempArr;
    Node *temp = head;
    // storing all odd elements first
    while(temp && temp->next) {
        tempArr.push_back(temp->data);
        temp = temp->next->next;
    }
    if(temp) tempArr.push_back(temp->data); // for odd length list we may miss it
    temp = head->next;
    // storing all even elements now
    while(temp && temp->next) {
        tempArr.push_back(temp->data);
        temp = temp->next->next;
    }
    if(temp) tempArr.push_back(temp->data);
    temp = head;
    for(int i = 0; i < tempArr.size(); i++) {
        temp->data = tempArr[i]; // now copying back into linked list
        temp = temp->next;
    }
    return head;
} // O(2N) time and O(N) space

// But here we were asked to segregate on the basis of odd/even indexing so we have to do it by reference using links and not by changing values

Node *oddEvenListOptimal(Node *head) {
    if(!head || !head->next) return head;
    // if we first connect all the oddOnes and evenOnes and finally do odd->next = even to join them
    Node *odd = head, *even = head->next, *evenHead = head->next;
    // we need evenHead since head nodes next would be manipulated
    while(even && even->next) {
        odd->next = odd->next->next;
        odd = odd->next;
        even->next = even->next->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
} // O(N/2 * 2) = O(N) since we are doing two operations of ->next->next which have to be computed

int main() {
    
    return 0;
}