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

/////////////////////////////////////////////////////////////////////////////////////

// given there is a 

Node *startingNodeInLoopBrute(Node *head) {
    // same approach of hashing which we used in detectLoop
    unordered_map<Node*, int> mpp;
    Node *temp = head;
    while(temp) {
        if(mpp.find(temp) != mpp.end()) return temp; // starting node of loop
        mpp[temp]++;
        temp = temp->next;
    }
    return nullptr; // no loop
}

Node* startingNodeInLoopOptimal(Node *head) {
    Node *slow = head, *fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) break;
    }
    if(!fast || !fast->next) return nullptr; // no loop
    slow = head; // make slow point to head again whereas fast points to the location where they collided
    while(slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow; // or fast, as they again recollide but at this time at the node starting the loop
    // mathemaitcally we can prove that the distance of the heead from the starting node of loop is equal to the distance of the node where slow and fast collide to the starting node of loop
    // hence we move both by one for equal distance and they meet at starting node of loop
}

int main() {
    
    return 0;
}