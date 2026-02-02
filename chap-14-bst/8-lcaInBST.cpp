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

// Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

//////////////////////////////////////////////////////////////////////////////////////

// the naive approach is using the same what we used in BT

Node *lcaHelper(Node *root, Node *p, Node *q) {

    if(root == nullptr || root == p || root == q) {
        return root;
    }

    Node *leftCheck = lcaHelper(root->left, p, q);

    Node *rightCheck = lcaHelper(root->right, p, q);

    if(leftCheck && rightCheck) {
        return root;
    }

    if(!leftCheck) {
        return rightCheck;
    }

    return leftCheck;

} // O(N) time and space

Node* lcaBrute(Node *root, Node *p, Node *q) {
    return lcaHelper(root, p, q);
}

///////////////////////////////////////////////////////////////////////////////////////

// the optimal approach here takes advantage of the property of bst that if either p is lesser and q is greater than root or vice versa then we have a split and that node is lca
// else recursively find p and q only where they exist hence logh time and space 

Node *lcaBetterHelper(Node *root, Node *p, Node *q) {

    if(root == nullptr || root == p || root == q) {
        return root;
    }

    if((p->data > root->data && q->data < root->data) || (p->data < root->data && q->data > root->data)) {
        return root;
    }

    if(p->data > root->data && q->data > root->data) {
        return lcaBetterHelper(root->right, p, q);
    }

    return lcaBetterHelper(root->left, p, q);

} // O(logn) time and space (basically height of the bst)

Node* lcaInBSTBetter(Node *root, Node *p, Node *q) {
    return lcaBetterHelper(root, p, q);
}

//////////////////////////////////////////////////////////////////////////////////////

// but the above logic is redundant as we can simply check if both are not on the left and both not on the right then simply that node is lca so check left and right first

Node *lcaBetterReadable(Node *root, Node *p, Node *q) {

    if(!root) {
        return nullptr;
    }

    if(p->data < root->data && q->data < root->data) {
        return lcaBetterReadable(root->left, p, q);
    }

    if(p->data > root->data && q->data > root->data) {
        return lcaBetterReadable(root->right, p, q);
    }

    return root;

} // O(logh) time and space

/////////////////////////////////////////////////////////////////////////////////////

// but we are still using recursive stack space and hence we write the iterative version of it

// we can comfortably write the iterative version here with no worries of anything wrong since there is no backtracking logic and we are simply going on a side in each iteration and do not need to go back

Node *lcaOptimal(Node *root, Node *p, Node *q) {

    Node *curr = root;

    while(curr) {

        if(p->data < curr->data && q->data < curr->data) {
            curr = curr->left;
        } else if(p->data > curr->data && q->data > curr->data) {
            curr = curr->right;
        } else {
            break;
        }
    }

    return curr;
    
} // O(logh) time and O(1) space

int main() {
    
    return 0;
}