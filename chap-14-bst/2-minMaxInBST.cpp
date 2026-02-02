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

/////////////////////////////////////////////////////////////////////////////////////////

// the min is leftmost node

Node *findMin(Node *root) {
    
    if(!root) {
        return nullptr;
    }

    while(root->left) {
        root = root->left;
    }

    return root;

} // O(logn) time and O(1) space

///////////////////////////////////////////////////////////////////////////////////////////

// the max is rightmost node

Node *findMax(Node *root) {
    
    if(!root) {
        return nullptr;
    }

    while(root->right) {
        root = root->right;
    }

    return root;

} // O(logn) time and O(1) space

int main() {
    
    return 0;
}