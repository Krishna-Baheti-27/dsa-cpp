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

Node *removeNthNodeFromEndBrute(Node *head, int n) {
    // given 1 <= n << length
    // nth node from end is length - n + 1 node from the beginning
    // if only node is head
    int length = 0;
    Node *temp = head;
    while(temp) {
        length++;
        temp = temp->next;
    }
    if(length - n + 1 == 1) { // separate case for head
        temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    // now delete length - n + 1th node from beginning
    temp = head;
    for(int i = 1; i <= (length - n + 1) - 2 && temp->next; i++) {
        temp = temp->next;
    }
    if(temp->next) {
        Node *toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    } // no need to delete if temporary is on last node since temp->next is already null
    return head;
} // O(2N) time, basically two passes

Node *removeNthNodeFromEndOptimal(Node *head, int n) {
    // see lets assume, that we have to delete node at n = 2, from LL of length = 5, so this means the node 5 - 2 = 3 steps from start, is then node previous to the node we want to delete
    // but wihthout knowing 5 how will know 3, answer is we initially move the 2 steps with our fast pointer and move both slow and fast till fast reaches last node, so technincally the slow pointer moved length - n steps or (5 - 2) 
    Node *slow = head, *fast = head;
    for(int i = 1; i <= n; i++) {
        fast = fast->next;
    }
    if(fast == nullptr) {
        // we have to delete the head of the linked list
        Node *toDelete = head;
        head = head->next;
        delete toDelete;
        return head;
    }
    while(fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
    // slow now points to the prev node of the node which we want to delete
    Node *toDelete = slow->next;
    slow->next = slow->next->next;
    delete toDelete;
    return head;
}
 
int main() {
    
    return 0;
}