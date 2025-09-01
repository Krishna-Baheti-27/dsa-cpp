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

Node *findRightMost(Node *root) {
    while(root && root->right) root = root->right;
    return root; 
}

Node *deleteHelper(Node *nodeToDelete) {
    // we have to return the nodeToDelete->left but before join the right most node of the subtree nodeToDelete->left with nodeToDelete->right
    // but some edge cases are there
    if(!nodeToDelete->left) return nodeToDelete->right; // if left doesnt exist then directly attach to right
    if(!nodeToDelete->right) return nodeToDelete->left; // if right doesnt exists then directly attach to left
    // if both left and right exists then,
    Node *rightChild = nodeToDelete->right; 
    Node *rightMostChild = findRightMost(nodeToDelete->left); 
    rightMostChild->right = rightChild; // vvip step
    return nodeToDelete->left; // now again return the nodeToDelete after successful modification in subtree
}

Node *deleteInBST(Node *root, int key) {
    if(!root) return root; // we cant delete
    if(root->data == key) {
        // here we want to delete the root itself
        Node *toDelete = root;
        root = deleteHelper(root); // would return the new Node
        delete toDelete; // delete old root
        return root;
    }
    // we now search for node to delete, basically the parent of node to delete since we want to mainatain links and we cannot traverse up the tree
    Node *parent = root;
    while(parent) {
        if(parent->data > key) {
            // key is on the left, now we check if parent->left->data == key, because of thats the case then parent->left is the node that we want to delete and parent is the parent of node we want to delete
            if(parent->left && parent->left->data == key) {
                // what do we do, 
                // we assign parent->left = parent->left->left and the right most node in the subtree of parent->left will point to parent->left->right, visualise this in tree diagram
                Node *toDelete = parent->left;
                // do our modification
                parent->left = deleteHelper(parent->left);
                delete toDelete; // remove that node
                break;
            } else {
                // key is on the right, we follow the same procedure as in left
                parent = parent->left; // try to get the parent of key to be deleted
            } 
        } else {
            if(parent->right && parent->right->data == key) {
                Node *toDelete = parent->right;
                // do our modification
                parent->right = deleteHelper(parent->right);
                delete toDelete; // remove that node
                break;
            } else {
                parent = parent->right; // try to get the parent of key to be deleted
            }
        }
    }
    return root;
} // O(logN) time and O(1) space for iterative version

// The recursive version is more easier to understand,but does take O(logN) recursion stack space
// write recursive code here

int main() {
    
    return 0;
}