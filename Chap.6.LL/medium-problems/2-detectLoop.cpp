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

// a minimum of one node exists where when we start from that node, we come back to the same node again
bool hasLoop(Node *head) {
    unordered_map<Node*,int> mpp;
    Node *temp = head;
    while(temp) {
        if(mpp.find(temp) != mpp.end()) return true;
        mpp[temp]++;
        temp = temp->next;
    }
    return false;
}

bool hasLoopOptimal(Node *head) {
    Node *slow =  head, *fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false; 
    // they got to collide in a loop becuase slow moved by one step and fast moves by two steps so the distance between them would reduce by one and ultimately reahc 0, for no loop condition the distance will never reduce and only increase
} // O(N)

int main() {
    
    return 0;
}