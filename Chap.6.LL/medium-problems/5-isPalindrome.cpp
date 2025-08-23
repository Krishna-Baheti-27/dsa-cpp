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

bool isPalindromeBrute(Node *head) {
    stack<int> st;
    Node *temp = head;
    while(temp) {
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp) {
        if(temp->data != st.top()) return false;
        st.pop();
        temp = temp->next;
    }
    return true;
} // O(2N) time and O(N) space

Node *reverseLL(Node *head) {
    Node *current = head, *prev = nullptr, *next = nullptr;
    while(current) {
        next = current->next;
        current->next = prev; // switch the link
        prev = current; // make prev point to current
        current = next; // make current point to next
    }
    return prev;
}

bool isPalindromeOptimal(Node *head) {
    // finding the middle node, then changing the links, the from end to middle so that we can apply two pointer approach to check for palindrome
    // here we have to find first middle
    Node *slow = head, *fast = head;
    while(fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    // now slow->next points to the second half, since slow is the first middle
    Node *newHead = reverseLL(slow->next); // you reverse the second half
    // Now keep two pointers one at start of ll and other at start of second half and compare them for palindrome since we have reversed the second half so need to start from back (its already reversed)
    Node *first = head, *second = newHead;
    while(second) {
        if(first->data != second->data) {
            // before returning the answer again change the LL to original position
            reverseLL(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    // same applies here
    reverseLL(newHead);
    return true;
} // O(2n) time overall

int main() {
    
    return 0;
}