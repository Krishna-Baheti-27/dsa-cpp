#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *next;
    Node *prev;
    Node(int data) {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};

// delete all the occurences of the given key in DLL and return new head

Node *deleteAllKey(Node *head, int key) {
    Node *temp = head;
    while(temp) {
        if(temp->data == key) {
            // we have to delete temp
            if(temp == head) head = head->next; // since we will delete head so next will be new head
            Node *nextNode = temp->next;
            Node *prevNode = temp->prev;
            if(nextNode) nextNode->prev = prevNode; // changing links
            if(prevNode) prevNode->next = nextNode; // changing links
            delete temp;
            // when we delete temp, that memory is gone so we cant do temp = temp->next and hence we assing temp to nextNode instead to keep it moving
            temp = nextNode;
            // we move temp to nextNode 
        } else {
            temp = temp->next; // not the key to delete 
        }
    }
    return head;
} // O(N) time and O(1) space

Node *deleteAllKeyBetter(Node *head, int key) {
    Node *dummy = new Node(-1);
    Node *curr = dummy, *temp = head;
    while(temp) {
        if(temp->data == key) {
            Node *nextNode = temp->next;
            delete temp; // delete this node and move temp ahead, since this node will be deleted we wont add it in our new list
            temp = nextNode;
        } else {
            // add the temp to our new list
            curr->next = temp; 
            temp->prev = curr;
            curr = temp;
            temp = temp->next;
        }
    }
    // after the termination the curr->next points to temp which was probably deleted from memory and hence is a dangling pointer so list doesnt terminate properly so make
    curr->next = nullptr;
    head = dummy->next; // this is our new head
    if(head) head->prev = nullptr; // since we are not sure if the new list is null
    delete dummy;
    return head;
} // O(N) time and O(1) space

int main() {
    
    return 0;
}