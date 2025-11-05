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

///////////////////////////////////////////////////////////////////////////////////////////

Node* arrayToLL(vector<int> &arr) {

    Node *head = new Node(arr[0]);

    Node *temp = head;

    for(int i = 1; i < arr.size(); i++) {

        Node *newNode = new Node(arr[i]);
        temp->next = newNode;
        temp = newNode;
    }

    return head;

} // O(N) time and O(1) space (not considering the space to return the answer)

////////////////////////////////////////////////////////////////////////////////////////

void display(Node *head) {

    // always take a temporary so we dont tamper the original head even though we are not really returning head here but still as good practice

    Node *temp = head; 

    while(temp != nullptr) {
        cout << temp->data << ' ';
        temp = temp->next;
    }

    cout << endl;
}

////////////////////////////////////////////////////////////////////////////////////////

int lengthOfLL(Node *head) {

    int count = 0;
    Node *temp = head;

    while(temp) {
        count++;
        temp = temp->next;
    }

    return count;

} // O(N) time and O(1) space

////////////////////////////////////////////////////////////////////////////////////

// this is linear search in linked list, there is nothing like binary search since we cant access middle node in linked list in constant time like we can in array

Node* search(Node *head, int data) {

    Node *temp = head;

    while(temp) {
        if(temp->data == data) return temp;
        temp = temp->next;
    }

    return nullptr;

} // O(N) time and O(1) space

///////////////////////////////////////////////////////////////////////////////////

Node* deleteHead(Node *head) {

    if(!head) return nullptr;

    Node *temp = head;
    head = head->next; // move head ahead

    delete temp; // delete the old head

    return head; // return new head

} // O(1) time and space

/////////////////////////////////////////////////////////////////////////////////

Node* deleteTail(Node *head) {

    if(!head) return nullptr; // cant delete

    if(!head->next) {
        delete head;
        return nullptr;
    }

    Node *temp = head;

    // while(temp) terminates on nullptr (points after last node)
    // while(temp->next) terminates on last node(points at last node)
    // while(temp->next->next) terminates on second last node(points at second last node)

    while(temp->next->next) {
        temp = temp->next;
    }

    delete temp->next; // from second last node we delete last node

    temp->next = nullptr; // second last node now becomes last and points to nullptr

    return head;

} // O(N) time and O(1) space

//////////////////////////////////////////////////////////////////////////////////////

Node *deleteKth(Node *head, int k) {

    // if first node doesnt exist or we want to delete at invalid index

    if(k < 1 || !head) return head; 

    if(k == 1) {
        // deleting the first node
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node *temp = head;

    for(int i = 1; i <= k - 2 && temp->next; i++) temp = temp->next; 

    // we basically stop one node before the node we want to delete using the condition i <= k - 2  but for large k, we will break out of the loop if temp->next becomes null, which basically means the node that we want to delete (that is temp->next) is null so we return without deleting 

    if(!temp->next) return head; // if temp->next is null we cant delete 

    Node *nodeToDelete = temp->next;
    temp->next = temp->next->next; // break the link for the node which is to be deleted

    delete nodeToDelete;

    return head;

} // O(N) time in worst case and O(1) space

////////////////////////////////////////////////////////////////////////////////////////

Node *deleteValue(Node *head, int value) {

    if(!head) return nullptr;

    Node *temp = head;

    if(head->data == value) { // delete head node
        head = head->next; 
        delete temp;
        return head;
    }

    // if we used temp then we would stop at the node having value but we want to stop one node before and hence temp->next

    while(temp->next) { 

        // so this tells us the temp->next is the node we want to delete since temp->next->data == value
        
        if(temp->next->data == value) { 

            Node *toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            return head;
        }

        temp = temp->next; // else move ahead
    }

    // this means temp->next == nullptr, so node we want to delete is null or doesnt exist and hence return head without deleting anything

    return head; 

} // O(N) time in worst case and O(1) space

///////////////////////////////////////////////////////////////////////////////////

Node* insertHead(Node *head, int data) {

    // create new node and make it the new head
    
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;

    return head;

} // O(1) time and space

/////////////////////////////////////////////////////////////////////////////////

Node* insertTail(Node *head, int data) {
    
    Node *newNode = new Node(data);

    // if no head exists then return the newNode as our head

    if(!head) return newNode;

    Node *temp = head;
    while(temp->next) temp = temp->next; // reach till second last node

    temp->next = newNode;

    return head;   

} // O(N) time in worst case and O(1) space

//////////////////////////////////////////////////////////////////////////////

Node* insertKth(Node *head, int k, int data) {

    if(k < 1) return head; 

    Node *newNode = new Node(data);
    if(!head) return newNode;

    if(k == 1) { // insert at first position or insert at head node
        newNode->next = head;
        head = newNode;
        return head;
    }

    Node *temp = head;

    for(int i = 1; i <= k - 2 && temp; i++) {
        temp = temp->next;
    }

    // o we want to insert at the position of temp->next so we traverse k - 1 nodes or till temp becomes null, if temp null then we cant insert 

    if(!temp) {
        delete newNode; // to avoid memory leak, we free the memory (no insertion possible)
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;

} // O(N) time in worst case and O(1) space

////////////////////////////////////////////////////////////////////////////////////

Node* insertBeforeValue(Node *head, int data, int value) {

    if(!head) return nullptr;

    Node *newNode = new Node(data);

    // insert before value, means insert before head in this case, which means inserting new head

    if(head->data == value) { 
        newNode->next = head;
        head = newNode;
        return head;
    }

    Node *temp = head;

    // we want to stop one node before the node having value and henc while temp->next != null

    while(temp->next) {
        if(temp->next->data == value) break;
        temp = temp->next;
    }

    if(!temp->next) return head; // the value before which we have to insert does not exist

    // since temp->next is equal to value so we have to insert before temp->next or insert at temp

    newNode->next = temp->next;
    temp->next = newNode;

    return head;

} // O(N) time and O(1) space

///////////////////////////////////////////////////////////////////////////////

Node* reverseSLL(Node *head) {

    Node *current = head, *prev = nullptr, *next = nullptr;

    while(current) {

        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev; // here current would point at nullptr, hence we return prev

} // O(N) time and O(1) space

/////////////////////////////////////////////////////////////////////////////////////

// here current is replaced by head in the recursive solution

Node* recursiveReverse(Node *head, Node *prev = nullptr) {

    if(!head) return prev;

    Node *next = head->next; // the next pointer is simply next node (same as next = current->next)

    head->next = prev; // changing the link (same as current->next = prev)

    // now we set current node as next node, and prev node to be current node (same as prev = current and current = next)

    return recursiveReverse(next, head); 

} // O(N) time and O(N) recursion stack space
 
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
    head = deleteKth(head, 7);
    display(head);
    return 0;
}