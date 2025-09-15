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

int lengthOfLoopBrute(Node *head) {
    int length = 0;
    unordered_map<Node*, int> mpp;
    Node *temp = head;
    while(temp) {
        if(mpp.find(temp) != mpp.end()) {
            Node* loopStart = temp;
            do {
                length++;
                loopStart = loopStart->next;
            } while(loopStart != temp);
            return length;
        }
        mpp[temp]++;
        temp = temp->next;
    }
    return 0; // no loop
} 

int lengthOfLoopBetter(Node *head) {
    int timer = 1;
    unordered_map<Node*, int> mpp;
    Node *temp = head;
    while(temp) {
        if(mpp.find(temp) != mpp.end()) return timer - mpp[temp];
        mpp[temp] = timer;
        timer++;
        temp = temp->next;
    }
    return 0; // no loop
}

int lengthOfLoopOptimal(Node *head) {
    // using tortoise and hare
    Node *slow = head, *fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            // we have a loop
            int length = 0;
            do {
                length++;
                slow = slow->next; // make fast wait there and let slow take a full loop again to count lengthS
            } while(slow != fast);
            return length;
        }
    }
    return 0; // no loop
}

int main() {
    
    return 0;
}