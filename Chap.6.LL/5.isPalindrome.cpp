#include<iostream>
#include<stdlib.h>
#include<vector>
#include<stack>

using namespace std;


class Node {
    public:
    int data;
    Node *next;
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

int isPalindromeNaive(Node *head) {
    // we simply store the elements in stack and when we pop the element should be equal to respective temp->data where temp starts from beginning
    stack<int> st;
    Node *temp = head;
    while(temp) {
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp) {
        if(temp->data != st.top()) return 0;
        st.pop();
        temp = temp->next;
    }
    return 1; // it is a palindrome
}

int isPalindromeOptimised(Node *head) {
    
}

int main() {
    vector<int> arr = {1,2,2,1};
    Node *head = arrayToLL(arr);
    cout << isPalindromeNaive(head) << endl;
    return 0;
}