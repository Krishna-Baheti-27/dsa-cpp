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

Node *ceilInBST(Node *root, int key) {
    // only writing iterative versions for constant space
    // return the node havinh val >= key, val should be the first greater
    Node *ans = nullptr;
    while(root != nullptr) {
        if(root->data >= key) {
            ans = root; // i will take it as an aswer but would try to look for even smaller value
            // just like in lower bound of BST
            root = root->left; // to get slower value you have to traverse in left
        } else root = root->right; // else increase the value to get towards it
    }
    return ans; // no such node found
}

// Floor of a value refers to the value of the largest node in the Binary Search Tree that is smaller than or equal to the given key.

Node *floorInBST(Node *root, int key) {
    Node *ans = nullptr;
    while(root) {
        if(root->data <= key) {
            ans = root; // i will take it as an asnwer but since we have been asked to find the largest node so i will move right to find even greater
            root = root->right;
        } else root = root->left; // too large value and hence decrease it
    }
    return ans;
}

int main() {
    
    return 0;
}