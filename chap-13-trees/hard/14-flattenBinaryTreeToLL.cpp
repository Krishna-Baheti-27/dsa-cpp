#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// what we want is to store a preorder traversal of a given tree in linked list without creating a new linked list but simply setting right to be the next pointer and left to be nullptr

void flattenHelper(Node *root, Node* &prev) {
    // here take prev by reference otherwise it would just be a local copy which will be lost, life for root we know at each step that 
    if(!root) return;
    // first traverse all the way till right then left and then finally change links
    flattenHelper(root->right, prev);
    flattenHelper(root->left, prev);
    root->right = prev; // change to point to someone who has recently been assigned prev
    root->left = nullptr; // as question asks
    prev = root; // make this newly processed node to be our prev
}

void flattenTreeRecursive(Node *root) {
    Node *prev = nullptr;
    flattenHelper(root, prev);
} // O(N) time and O(N) space

void flattenTreeIterative(Node *root) {
    if(!root) return;
    stack<Node*> st;
    st.push(root);
    while(!st.empty()) {
        Node *curr = st.top(); st.pop();
        if(curr->right) st.push(curr->right);
        if(curr->left) st.push(curr->left);
        if(!st.empty()) {
            curr->right = st.top();
            curr->left = nullptr;
        }
    }
} // O(N) time and O(N) space

// methode three involving morris traversal gives us O(N) time and O(1) space
// that is the most optimal solution

void flattenTreeOptimal(Node *root) {
    
}

int main() {
    
    return 0;
}