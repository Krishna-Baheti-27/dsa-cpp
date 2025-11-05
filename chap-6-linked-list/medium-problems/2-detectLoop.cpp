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

////////////////////////////////////////////////////////////////////////////////////

// a minimum of one node exists where when we start from that node, we come back to the same node again means the linked list has cycle

///////////////////////////////////////////////////////////////////////////////////

bool hasLoop(Node *head) {

    unordered_map<Node*,bool> mpp; // to keep track of visited nodes in the linked list
    Node *temp = head;

    while(temp) {

        // found the same nodes again means we have a cycle and hence return true

        if(mpp.find(temp) != mpp.end()) {
            return true; 
        }

        mpp[temp] = true;
        temp = temp->next;
    }

    // no cycle since we didnt encounter the same node again and our iteration was over and hence return false so state no cycle found

    return false; 

} // O(N) time in worst case and O(N) space for unordered map

///////////////////////////////////////////////////////////////////////////////////

// using the tortoise and hare method for optimal solution
// we start with slow and fast pointer and move them accordingly and if they meet again (other than initial head node then we have a cycle)

// the intuition or mathematical proof of why this works
// they got to collide in a loop becuase slow moves by one step and fast moves by two steps so the distance between them would never reduce but reduce by 1 only when we have cycle and ultimately reach 0, for no cycle condition the distance will never reduce and only increase

bool hasLoopOptimal(Node *head) {

    Node *slow =  head, *fast = head;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        // if they ever meet or point to same node we have a cycle

        if(slow == fast) {
            return true;
        }
    }

    return false; 
    
} // O(N) time and O(1) space

int main() {
    
    return 0;
}