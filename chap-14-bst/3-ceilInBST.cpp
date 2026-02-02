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

// you have to return the node having val >= key, val should be the first greater or find the min value of val satisfying val >= key

//////////////////////////////////////////////////////////////////////////////////////

Node *ceilInBSTIterative(Node *root, int key) {
   
    Node *ans = nullptr;

    while(root != nullptr) {

        // i will take it as an aswer but would try to look for even smaller value
        // just like in lower bound in case of arrays

        if(root->data >= key) {
            ans = root; 
            root = root->left; // to get smaller value you have to traverse in left
        } else {
            root = root->right; // else increase the value to get towards it
        }
    }

    return ans; 

} // O(logn) time and O(1) space

// a smart optimisation we can do here is that if root->data == key then put ans = root and break out as no more smaller value can be found saving some iterations when we have a lot of duplicates

///////////////////////////////////////////////////////////////////////////////////////

// this is recursive version but uses a global variable (or maintaing referenced variable) whose value is maintained across function calls and is not copied

void helper(Node *root, int key, Node* &ans) {

    if(!root) {
        return;
    }

    if(root->data >= key) {
        ans = root;
        helper(root->left, key, ans); // but look for even smaller on left
    } else {
        helper(root->right, key, ans); // try to reach the answer by going right 
    }
}

Node *ceilRecursive(Node *root, int key) {

    Node *ans = nullptr;

    helper(root, key, ans);

    return ans;

} // O(logn) time and space

//////////////////////////////////////////////////////////////////////////////////////

// this is purely recursive solution and is more simple and elegant

Node *ceilPurelyRecursive(Node *root, int key) {

    if(!root) {
        return root;
    }

    if(root->data < key) {
        return ceilPurelyRecursive(root->right, key);
    }

    Node *potentialAns = ceilPurelyRecursive(root->left, key); // (root->data >= key)

    if(potentialAns != nullptr) {
        return potentialAns;
    }

    return root; // this is our answer as we couldnt get any better potential answer

} // O(logn) time and space

///////////////////////////////////////////////////////////////////////////////////////

// Floor of a value refers to the value of the largest node in the Binary Search Tree that is smaller than or equal to the given key., val <= key, max possible value of val

Node *floorInBSTIterative(Node *root, int key) {

    Node *ans = nullptr;

    while(root) {

        // i will take it as an asnwer but since we have been asked to find the largest node so i will move right to find even greater

        if(root->data <= key) {
            ans = root; 
            root = root->right;
        } else {
            root = root->left; // too large value and hence decrease it
        }
    }

    return ans;

} // O(logn) time and O(1) space

// again same optimisation here of breaking out is root->data == key by putting ans = root

///////////////////////////////////////////////////////////////////////////////////////

void helperFloor(Node *root, int key, Node* &ans) {

    if(!root) {
        return;
    }

    if(root->data > key) {
        helperFloor(root->left, key, ans);
    } else {
        ans = root; 
        helperFloor(root->right, key, ans);
    }
}

Node* floorRecursive(Node *root, int key) {

    Node *ans = nullptr;

    helperFloor(root, key, ans);

    return ans;

} // O(logn) time and space

/////////////////////////////////////////////////////////////////////////////////////////

Node* floorPurelyRecursive(Node *root, int key) {

    if(!root) {
        return root;
    }

    if(root->data > key) {
        return floorPurelyRecursive(root->left, key);
    }

    Node *potentialAns = floorPurelyRecursive(root->right, key);

    if(potentialAns != nullptr) {
        return potentialAns;
    }

    return root;

} // O(logn) time and space

int main() {
    
    return 0;
}