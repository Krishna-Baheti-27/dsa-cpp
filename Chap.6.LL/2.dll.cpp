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

Node *arrayToDLL(vector<int> &arr) {
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for(int i = 1; i < arr.size(); i++) {
        Node *newNode = new Node(arr[i]);
        temp->next = newNode;
        newNode->prev = temp;
        temp = newNode;
    }
    return head;
}

void display(Node *head) {
    Node *temp = head;
    while(temp) {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << endl;
}

Node *deleteHead(Node *head) {
    if(!head) return nullptr;
    if(!head->next) {
        delete head;
        return nullptr;
    }
    Node *temp = head;
    head = head->next;
    head->prev = nullptr; // this line would break the code if DLL has single element hence already dealt with
    // this wasnt the case for SLL since we didnt had to update any prev links
    delete temp;
    return head;
}

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
}

Node *deleteKth(Node *head, int k) {
    if(k < 1 || !head) return nullptr;
    if(k == 1) {
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
    temp->next = toDelete->next;
    if(toDelete->next) {
        // if we are not at last node, then we also have to update prev
        toDelete->next->prev = temp;
    }
    delete toDelete;
    return head;
}

Node *deleteValue(Node* head, int value) {
    if(!head) return nullptr;
    if(head->data == value) {
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
}

Node* insertHead(Node *head, int data) {
    Node* newNode = new Node(data);
    if(!head) return newNode;
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    return head;
}

Node* insertTail(Node *head, int data) {
    Node *newNode = new Node(data);
    if(!head) return newNode;
    Node *temp = head;
    while(temp->next) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

Node *insertKth(Node *head, int data, int k) {
    if(k < 1) return head;
    Node *newNode = new Node(data);
    if(!head) return newNode;
    if(k == 1) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return head;
    }
    Node *temp = head;
    for(int i = 1; i <= k - 2 && temp; i++) temp = temp->next;
    if(!temp) return head;
    newNode->next = temp->next;
    if(temp->next) {
        temp->next->prev = newNode; // also update prev pointer if node is not last
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

Node *insertBeforeValue(Node *head, int data, int value) {
    if(!head) return nullptr;
    Node *newNode = new Node(data);
    if(head->data == value) {
        // since head->data = value, this means we have to insert before head
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return head;
    }
    Node *temp = head;
    while(temp->next) {
        if(temp->next->data == value) {
            // since temp->next stores the value, we have to insert before temp->next
            break;
        }
        temp = temp->next;
    }  
    if(!temp->next) {
        delete newNode; // free the allocated memory
        return head; // cant insert since that value is not present in list
    }
    newNode->next = temp->next;
    
    temp->next->prev = newNode; 
    // here we dont have to check whether temp->next is null or not since while loop make sures it it, and if its not then if(!temp->next) gest encountered hence no need
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

Node* reverseDLL(Node *head) {
    // naive solution using stack and just swapping data not modifying the links
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
}

Node* reverseDLLOptimised(Node *head) {
    // same as in SLL just also have to take care of prev pointer while reversing
    // REVERSING DLL simply means next pointer points to prev node and prev pointer points to next node, thats it
    Node *current = head, *prev = nullptr, *next = nullptr;
    while(current) {
        next = current->next;
        current->next = prev; // reversing links
        current->prev = next; // reversing links
        prev = current;
        current = next;
    }
    return prev; // new head
}

Node* recursiveReverse(Node *head, Node* prev = nullptr) {
    if(!head) return prev;
    Node *next = head->next; // we store the next pointer so that when we reverse links using head, we dont looose the chain
    head->next = prev; // reversing the next link
    head->prev = next; // reversing the prev link
    return recursiveReverse(next,head); // calling the reverse for new set of nodes
}

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