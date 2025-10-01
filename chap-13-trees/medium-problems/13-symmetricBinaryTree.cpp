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

// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

bool isSymmetric(Node *root) {
    // so we will do traversal on both the left and right trees simultaneously and then compare them 
    if(root->left->data != root->right->data);
}

int main() {
    
    return 0;
}