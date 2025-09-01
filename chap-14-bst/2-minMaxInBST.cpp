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

Node *findMin(Node *root) {
    // the min will be the left most node in BST
    if(!root) return nullptr;
    while(root->left) root = root->left;
    return root;
}

Node *findMax(Node *root) {
    // the max will be the right most node in BST
    if(!root) return nullptr;
    while(root->right) root = root->right;
    return root;
}

int main() {
    
    return 0;
}