#include<iostream>
#include<stdlib.h>
#include<vector>
#include<stack>
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

////////////////////////////////////////////////////////////////////////////////////

Node *arrayToDLL(vector<int> &arr) {

    Node *head = new Node(arr[0]);

    Node *temp = head;

    // similar to sll but here we maintain both next and prev links (using next and prev pointers)

    for(int i = 1; i < arr.size(); i++) {
        Node *newNode = new Node(arr[i]);
        temp->next = newNode;
        newNode->prev = temp;
        temp = newNode;
    }

    return head;

} // O(N) time and O(1) space

///////////////////////////////////////////////////////////////////////////////////////

void display(Node *head) {

    Node *temp = head;

    while(temp) {
        cout << temp->data << ' ';
        temp = temp->next;
    }

    cout << endl;

} // O(N) time and O(1) space

//////////////////////////////////////////////////////////////////////////////////////

Node *deleteHead(Node *head) {

    if(!head) return nullptr;

    if(!head->next) {
        delete head;
        return nullptr;
    }

    Node *temp = head;
    head = head->next;
    head->prev = nullptr; // for single node this would break and hence already dealt with
    
    delete temp;
    return head;

} // O(1) time and space

/////////////////////////////////////////////////////////////////////////////////

// same as in SLL, although here we can also reach the last node instead of reaching second last node since we have access to prev pointers to change links with 

Node *deleteTail(Node *head) {

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

} // O(N) time and O(1) space

//////////////////////////////////////////////////////////////////////////////////////

// here we could have also used prev pointers for more cleaner code and take advantage of dll
// Node* deleteTail(Node* head) {
//     if (!head) return nullptr;
//     if (!head->next) {   // Only one node
//         delete head;
//         return nullptr;
//     }

//     Node* tail = head;
//     while (tail->next) {
//         tail = tail->next;
//     }

//     // tail is at last node now
//     tail->prev->next = nullptr;
//     delete tail;

//     return head;
// }

//////////////////////////////////////////////////////////////////////////////////////

Node *deleteKth(Node *head, int k) {

    if(k < 1 || !head) return head; // no head or invalid index

    if(k == 1) { // when you have to delete head

        if(!head->next) {
            delete head;
            return nullptr;
        }

        Node *temp = head;
        head = head->next;
        head->prev = nullptr;

        delete temp;
        return head;
    }

    Node *temp = head;

    for(int i = 1; i <= k - 2 && temp->next; i++) temp = temp->next;

    if(!temp->next) return head;

    Node *toDelete = temp->next;
    temp->next = temp->next->next;

    // if we are not at last node, then we also have to update prev

    if(toDelete->next) {
        toDelete->next->prev = temp;
    }

    delete toDelete;

    return head;

} // O(N) time and O(1) space

///////////////////////////////////////////////////////////////////////////////////////

Node *deleteValue(Node* head, int value) {

    if(!head) return nullptr; // no head means no linked list

    if(head->data == value) { // when head is the value you want to delete

        if(!head->next) {
            delete head;
            return nullptr;
        }

        Node *temp = head;
        head = head->next;
        head->prev = nullptr;

        delete temp;
        return head;

    }

    Node* temp = head;

    while(temp->next) {
        if(temp->next->data == value) break;
        temp = temp->next;
    }

    if(!temp->next) return head; // no deletion since value does not exist

    Node *toDelete = temp->next;
    temp->next = temp->next->next;

    if(toDelete->next) {
        toDelete->next->prev = temp; // if not the last node then update prev pointers
    }

    delete toDelete;

    return head;

} // O(N) time and O(1) space

///////////////////////////////////////////////////////////////////////////////////

Node* insertHead(Node *head, int data) {

    Node* newNode = new Node(data);

    if(!head) return newNode; // if no linked list then return new node as head

    newNode->next = head;
    head->prev = newNode;
    head = newNode;

    return head;

} // O(1) time and space

////////////////////////////////////////////////////////////////////////////////

Node* insertTail(Node *head, int data) {

    Node *newNode = new Node(data);

    if(!head) return newNode;

    Node *temp = head;
    while(temp->next) temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    return head;

} // O(N) time and O(1) space

/////////////////////////////////////////////////////////////////////////////

Node *insertKth(Node *head, int data, int k) {

    if(k < 1) return head; // cant insert due to invalid index

    Node *newNode = new Node(data);

    if(!head) return newNode; // when no head then make the new node as head

    if(k == 1) { // insert at head
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return head;
    }

    Node *temp = head;

    for(int i = 1; i <= k - 2 && temp; i++) temp = temp->next;

    if(!temp) return head; // cant insert since we want to insert at temp->next position

    newNode->next = temp->next;
    if(temp->next) {
        temp->next->prev = newNode; // also update prev pointer if node is not last
    }

    temp->next = newNode;
    newNode->prev = temp;
    
    return head;

} // O(N) time and O(1) space

///////////////////////////////////////////////////////////////////////////////////

Node *insertBeforeValue(Node *head, int data, int value) {

    Node *newNode = new Node(data);

    if(!head) {
        return newNode; // if node linked list then return the newNode as head
    }

    // since head->data = value, this means we have to insert before head or in simple words we have to insert at head position

    if(head->data == value) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return head;
    }

    Node *temp = head;

    while(temp->next) {
        if(temp->next->data == value) {
            break;
        }
        temp = temp->next;
    }  

    if(!temp->next) {
        delete newNode; // free the allocated memory
        return head; // cant insert since that value is not present in list
    }

    newNode->next = temp->next;
    temp->next->prev = newNode; // temp->next not null check already done

    temp->next = newNode;
    newNode->prev = temp;

    return head;

} // O(N) time and O(1) space

////////////////////////////////////////////////////////////////////////////////////////

// naive solution using stack and just swapping data not modifying the links, this isnt really reversing as the links are same and we could have done this for sll also

Node* reverseDLL(Node *head) {
    
    stack<int> st;

    Node* temp = head;

    while(temp) {
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;

    while(temp) {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }

    return head;

} // O(2N) time and O(N) space for stack

////////////////////////////////////////////////////////////////////////////////////////

// same as in SLL just also have to take care of prev pointer while reversing
// REVERSING DLL simply means next pointer points to prev node and prev pointer points to next node, thats it

Node* reverseDLLOptimised(Node *head) {
    
    Node *current = head, *prev = nullptr, *next = nullptr;

    while(current) {

        next = current->next;

        // here we have to reverse two links, instead of just one as in regular sll

        current->next = prev; // reversing links
        current->prev = next; // reversing links

        prev = current;
        current = next;
    }

    return prev; // new head

} // O(N) time and O(1) space

//////////////////////////////////////////////////////////////////////////////////

Node* recursiveReverse(Node *head, Node* prev = nullptr) {

    if(!head) return prev;

    Node *next = head->next; 

    head->next = prev; // reversing the next link
    head->prev = next; // reversing the prev link

    return recursiveReverse(next, head); // calling the reverse for new set of nodes

} // O(N) time and O(N) recursion stack space

int main() {
    vector<int> arr = {1,2,3,4,5};
    Node *head = arrayToDLL(arr);
    display(head);
    head = deleteHead(head);
    display(head);
    head = deleteTail(head);
    display(head);
    head = deleteKth(head,3);
    display(head);
    head = insertHead(head,99);
    display(head);
    head = insertTail(head,500);
    display(head);
    head = insertKth(head, 11, 5);
    display(head);
    head = insertBeforeValue(head, 111,99);
    display(head);
    head = insertBeforeValue(head, 999, 11);
    display(head);
    head = insertBeforeValue(head, 321,11);
    display(head);
    head = deleteValue(head, 500);
    display(head);
    head = insertKth(head, 600, 9);
    display(head);
    head = reverseDLLOptimised(head);
    display(head);
    head = recursiveReverse(head);
    display(head);
    return 0;
}