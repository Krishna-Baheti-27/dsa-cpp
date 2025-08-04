#include<iostream>
#include<stdlib.h>
#include<vector>
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

Node* arrayToLL(vector<int> &arr) {
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for(int i = 1; i < arr.size(); i++) {
        Node *newNode = new Node(arr[i]);
        temp->next = newNode;
        temp = newNode;
    }
    return head;
}

void display(Node *head) {
    Node *temp = head;
    while(temp != nullptr) {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << endl;
}

int lengthOfLL(Node *head) {
    int count = 0;
    Node *temp = head;
    while(temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

Node* search(Node *head, int data) {
    Node *temp = head;
    while(temp) {
        if(temp->data == data) return temp;
        temp = temp->next;
    }
    return nullptr;
}

Node* deleteHead(Node *head) {
    if(!head) return nullptr;
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* deleteTail(Node *head) {
    if(!head) return nullptr;
    if(!head->next) {
        delete head;
        return nullptr;
    }
    Node *temp = head;
    while(temp->next->next) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

Node *deleteKth(Node *head, int k) {
    if(k < 1 || !head) return head;
    if(k == 1) {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node *temp = head;
    for(int i = 1; i <= k - 2 && temp; i++) temp = temp->next; // we basically stop one node before the node we want to delete using the condition i <= k - 2  but for large k, we will break out of the loop if temp becomes null
    if(!temp || !temp->next) return head; // if either temp or temp->nex is null we cant delete 
    Node *nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
    return head;
}

Node *deleteValue(Node *head, int value) {
    if(!head) return nullptr;
    Node *temp = head;
    if(head->data == value) { // delete head node
        head = head->next;
        delete temp;
        return head;
    }
    while(temp->next) { // we have to make sure temp->next is not nullptr since we are continuously accessing it
        if(temp->next->data == value) { // we basically stop one node before the node we want to delete
            Node *toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            return head;
        }
        temp = temp->next; // else move ahead
    }
    return head; // if temp comes on last node we cant delete anything hence return head
}

Node* insertHead(Node *head, int data) {
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
    return head;
}

Node* insertTail(Node *head, int data) {
    Node *newNode = new Node(data);
    if(!head) return newNode;
    Node *temp = head;
    while(temp->next) temp = temp->next;
    temp->next = newNode;
    return head;   
}

Node* insertKth(Node *head, int k, int data) {
    if(k < 1) return head;
    Node *newNode = new Node(data);
    if(!head) return newNode;
    if(k == 1) {
        newNode->next = head;
        head = newNode;
        return head;
    }
    Node *temp = head;
    for(int i = 1; i <= k - 2 && temp; i++) {
        temp = temp->next;
    }
     // node where you want to insert is after temp, so we stop at k-1th node or also for large k we stop when temp becomes null
    if(!temp) {
        // if temp becomes null we cant insert
        delete newNode; // to avoid memory leak, we free the memory (no insertion possible)
        return head;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

Node* insertBeforeValue(Node *head, int data, int value) {
    if(!head) return nullptr;
    Node *newNode = new Node(data);
    if(head->data == value) { // insert before value, means insert before head in this case
        newNode->next = head;
        head = newNode;
        return head;
    }
    Node *temp = head;
    while(temp->next) {
        if(temp->next->data == value) break;
        temp = temp->next;
    }
    if(!temp->next) return head; // the value before which we have to insert does not exist
    // since temp->next is equal to value so we have to insert before temp->next or insert at temp
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

Node* reverseSLL(Node *head) {
    Node *current = head, *prev = nullptr, *next = nullptr;
    while(current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

Node* recursiveReverse(Node *head, Node *prev = nullptr) {
    if(!head) return prev;
    Node *next = head->next; // the next pointer is simply next node
    head->next = prev; // changing the link
    return recursiveReverse(next, head); // now we set current node as next node, and prev node to be current node
}
 
int main() {
    // vector<int> arr = {1,2,2,3};
    // Node *first = new Node(arr[0]); 
    // cout << sizeof(first) << '\n';
    // cout << first << '\n';
    // cout << first->data << '\n';
    // cout << first->next << '\n';

    vector<int> arr = {1,2,3,4,5,10};
    Node *head = arrayToLL(arr);
    display(head);
    cout << lengthOfLL(head) << '\n';
    head = deleteHead(head);
    display(head);
    head = deleteTail(head);
    display(head);
    head = deleteKth(head, 4);
    display(head);
    head = deleteValue(head,2);
    display(head);
    head = insertHead(head,1);
    display(head);
    head = insertTail(head, 100);
    display(head);
    head = insertKth(head,1,99);
    display(head);
    head = insertKth(head,6,400);
    display(head);
    head = insertKth(head, 12,11);
    display(head);
    head = insertBeforeValue(head,5,101);
    display(head);
    head = reverseSLL(head);
    display(head);
    head = recursiveReverse(head);
    display(head);
    return 0;
}