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

Node *ceilInBSTIterative(Node *root, int key) {
    // only writing iterative versions for constant space
    // return the node having val >= key, val should be the first greater
    Node *ans = nullptr;
    while(root != nullptr) {
        if(root->data >= key) {
            ans = root; // i will take it as an aswer but would try to look for even smaller value
            // just like in lower bound in case of arrays
            root = root->left; // to get slower value you have to traverse in left
        } else root = root->right; // else increase the value to get towards it
    }
    return ans; // no such node found
} // O(logn) time and O(1) space

///////////////////////////////////////////////////////////////////////////

void helper(Node *root, int key, Node* &ans) {
    if(!root) return;
    if(root->data >= key) {
        ans = root;
        helper(root->left, key, ans); // but look for even smaller on left
    } else {
        helper(root->right, key, ans); // try to reach the answer by going right as it increases root->data 
    }
}

Node *ceilRecursive(Node *root, int key) {
    Node *ans = nullptr;
    helper(root, key, ans);
    return ans;
}

////////////////////////////////////////////////////////////////////////

Node *ceilPurelyRecursive(Node *root, int key) {
    if(!root) return root;
    if(root->data < key) return ceilPurelyRecursive(root->right, key);
    Node *potentialAns = ceilPurelyRecursive(root->left, key); // (root->data <= key)
    if(potentialAns != nullptr) return potentialAns;
    return root; // this is our answer as we couldnt get any better potential answer
}

////////////////////////////////////////////////////////////////////////

// Floor of a value refers to the value of the largest node in the Binary Search Tree that is smaller than or equal to the given key., val <= key, max possible value of val

Node *floorInBSTIterative(Node *root, int key) {
    Node *ans = nullptr;
    while(root) {
        if(root->data <= key) {
            ans = root; // i will take it as an asnwer but since we have been asked to find the largest node so i will move right to find even greater
            root = root->right;
        } else root = root->left; // too large value and hence decrease it
    }
    return ans;
}

void helperFloor(Node *root, int key, Node* &ans) {
    if(!root) return;
    if(root->data > key) helperFloor(root->left, key, ans);
    else {
        ans = root; // could be a possible answer but we are looking for largest value of val and hence check on right as well
        helperFloor(root->right, key, ans);
    }
}

Node* floorRecursive(Node *root, int key) {
    Node *ans = nullptr;
    helperFloor(root, key, ans);
    return ans;
}

Node* floorPurelyRecursive(Node *root, int key) {
    if(!root) return root;
    if(root->data > key) return floorPurelyRecursive(root->left, key);
    Node *potentialAns = floorPurelyRecursive(root->right, key);
    if(potentialAns != nullptr) return potentialAns;
    return root;
}

int main() {
    
    return 0;
}