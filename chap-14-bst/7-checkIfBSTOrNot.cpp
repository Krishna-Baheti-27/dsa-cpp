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

// Given the root of a binary tree, determine if it is a valid binary search tree (BST).

// A valid BST is defined as follows:

// The left subtree of a node contains only nodes with keys strictly less than the node's key.
// The right subtree of a node contains only nodes with keys strictly greater than the node's key.
// Both the left and right subtrees must also be binary search trees.

//////////////////////////////////////////////////////////////////////////////////////

// we cant simply check for each node like if its greater than all on its left and lesser than all on its right because we also have to enforce this from a subtree level like that node must be greater than all the nodes in the left subtree and smaller than all nodes on right

bool isBSTIncorrect(Node *root) {
    
    if(!root) {
        return true;
    }

    if(root->left && root->data <= root->left->data) {
        return false;
    }

    if(root->right && root->data >= root->right->data) {
        return false;
    }

    return isBSTIncorrect(root->left) && isBSTIncorrect(root->right);
}

///////////////////////////////////////////////////////////////////////////////////////

// to do this we maitain a range of values that each node must have so that it satisfies the bst property 

// but we long min and long max since the values of nodes is from [INT_MIN, INT_MAX] and hence can cause problems with this root->data >= maxel || root->data <= minel

bool isBSTBetterHelper(Node *root, long long minel, long long maxel) {

    if(!root) {
        return true;
    }

    if(root->data >= maxel || root->data <= minel) {
        return false;
    }

    return isBSTBetterHelper(root->left, minel, root->data) && isBSTBetterHelper(root->right, root->data, maxel);

} // O(N) time and space

bool isBSTBetter(Node *root) {
    return isBSTBetterHelper(root, LONG_MIN, LONG_MAX);
}

///////////////////////////////////////////////////////////////////////////////////////

// the most optimal way to do this is to do a simply inorder traversal maitaining a prev node so that we can compare if the current node is greater than prev then continue else false since inorder traversal of a bst is sorted

// but since the inorder traversal jumps around we need to pass the prev by reference so that its value is maitained across function calls

bool isBSTOptimalHelper(Node *root, Node* &prev) {

    if(!root) {
        return true;
    }

    bool leftCheck = isBSTOptimalHelper(root->left, prev);

    if(!leftCheck) {
        return false;
    }

    if(prev && root->data <= prev->data) {
        return false;
    }

    prev = root;

    return isBSTOptimalHelper(root->right, prev);
}

bool isBSTOptimal(Node *root) {

    Node *prev = nullptr;
    return isBSTOptimalHelper(root, prev);

} // O(N) time and space

/////////////////////////////////////////////////////////////////////////////////////

// now we can do the above inordere traversal in O(1) space using morris traversal

// we simply maintain the prevNode traversed or put in the traversal when we change the curr to right since that is when we are done with left and starting fresh on right with new nodes

bool isBSTMostOptimal(Node *root) {

    Node *curr = root, *prevNode = nullptr;

    bool isPossible = true;

    while(curr != nullptr) {

        if(curr->left == nullptr) {

            if(prevNode && curr->data <= prevNode->data) {
                isPossible = false;   
            }

            prevNode = curr;
            curr = curr->right;

        } else {

            Node *prev = curr->left;

            while(prev->right && prev->right != curr) {
                prev = prev->right;
            }

            if(!prev->right) {
                prev->right = curr;
                curr = curr->left;
            } else {
                prev->right = nullptr;
                if(prevNode && curr->data <= prevNode->data) {
                    isPossible = false;
                }
                prevNode = curr;
                curr = curr->right;   
            }
        }
    }

    if(isPossible) {
        return true;
    } 

    return false;

} // O(N) time and O(1) space

int main() {
    
    return 0;
}