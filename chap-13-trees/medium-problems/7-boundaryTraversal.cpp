#include<bits/stdc++.h>
using namespace std; 

// to get the boundary traversal of a tree in anticlockwise fashion we must first get the left boundary of tree excluding the leaf, then the leaf nodes and then the right boundary of the tree excluding the leaf nodes and thus it will give us the entire boundary traversal of the tree in anticlockwise sense

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

bool isLeaf(Node *root) {
    if(!root->left && !root->right) return true;
    return false;
}

void leftBoundary(Node *root, vector<int> &arr) {
    Node *rootLeft = root->left;
    while(rootLeft) {
        if(!isLeaf(rootLeft)) arr.push_back(rootLeft->data); // if it is not the leaf then only insert since we are going to insert the leaves separately
        if(rootLeft->left) rootLeft = rootLeft->left; // since left boundary we only take left 
        else rootLeft = rootLeft->right; // else when we dont have left then we take right
    }
}

void addLeaves(Node *root, vector<int> &arr) {
    // preorder traversal using root left right and adding all leaves
    // do for the root only if it is a leaf
    if(isLeaf(root)) {
        arr.push_back(root->data);
        return;
    }
    // check for left subtree
    if(root->left) addLeaves(root->left, arr);
    // check for right subtree
    if(root->right) addLeaves(root->right, arr);
}

void rightBoundary(Node *root, vector<int> &arr) {
    Node *rootRight = root->right;
    while(rootRight) {
        if(!isLeaf(rootRight)) arr.push_back(rootRight->data);
        if(rootRight->right) rootRight = rootRight->right;
        else rootRight = rootRight->left;
    }
}

vector<int> boundaryTraversal(Node *root) {
    vector<int> ans; 
    if(root == nullptr) return ans;
    if(!isLeaf(root)) ans.push_back(root->data); // adding the root separately
    leftBoundary(root, ans); // adding the left boundary
    addLeaves(root, ans); // adding the leaves
    rightBoundary(root, ans); // adding the right boundary
    return ans;
}

int main() {
    
    return 0;
}