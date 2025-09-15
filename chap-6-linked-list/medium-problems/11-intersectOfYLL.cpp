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

// find the first common or intersecting node
// Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.
// Note that there are no cycles

Node *findIntersectionBrute(Node *headA, Node *headB) {
    // we will travers the first node and store all the nodes in map, and when traversing the second LL if we encounter a seen node we return it
    unordered_map<Node*,int> mpp;
    Node *temp = headA;
    while(temp) {
        mpp[temp]++;
        temp = temp->next;
    }
    temp = headB;
    while(temp) {
        if(mpp.find(temp) != mpp.end()) return temp;
        temp = temp->next;
    }
    return nullptr;
} // O(m + n) time and O(m or n) space 

Node *findIntersectionBetter(Node *headA, Node *headB) {
    // since both LL are not of same length we cant straight up start comparing nodes, so first we move the longer one and make it stand at same vertical level as shorter and then compare
    // for that we need to find length of both and make the longer one move by difference in their lengths
    int n1 = 0, n2 = 0;
    Node *temp = headA;
    while(temp) {
        n1++;
        temp = temp->next;
    }
    temp = headB;
    while(temp) {
        n2++;
        temp = temp->next;
    }
    Node *t1 = headA, *t2 = headB;
    if(n1 > n2) {
        for(int i = 1; i <= n1 - n2; i++) t1 = t1->next;
    } else if(n1 < n2) {
        for(int i = 1; i <= n2 - n1; i++) t2 = t2->next;
    } 
    // start comparing
    while(t1 && t2) {
        if(t1 == t2) return t1; // or t2
        t1 = t1->next;
        t2 = t2->next;
    }
    return nullptr;
} // O(n + m + n - m + m) => O(2n + m) considering n > m and O(1) space

Node *findIntersectionOptimal(Node *headA, Node *headB) {
    // here when one of them reaches last node we make them point at opp head so that they align, when both of them point to last node we return nullptr, and linked lists of equal length are by default handled in this case
    if(!headA || !headB) return nullptr;
    Node *t1 = headA, *t2 = headB;
    while(t1 != t2) {
        t1 = t1->next;
        t2 = t2->next;
        if(t1 == t2) return t1; // or t2 (found a collision point, it can also be nullptr)
        if(!t1) t1 = headB;
        if(!t2) t2 = headA;
    }
    return t1; // will never be executed, only if headA == headB
} // O(m + n) time and O(1) space

int main() {
    
    return 0;
}