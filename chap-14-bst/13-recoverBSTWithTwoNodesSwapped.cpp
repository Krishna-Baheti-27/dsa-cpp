#include <bits/stdc++.h>
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

// You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

////////////////////////////////////////////////////////////////////////////////////////

// the brute force is to do the traversal of tree and sort it so that it is now in inorder and now again traverse the tree and replace the nodes with correct value as per inorder

void inorderHelper(Node *root, vector<int> &inorder) {

    if(!root) {
        return;
    }

    inorderHelper(root->left, inorder);

    inorder.push_back(root->data);

    inorderHelper(root->right, inorder);
}

vector<int> inorderTrav(Node *root) {

    vector<int> inorder;
    inorderHelper(root, inorder);

    return inorder;
}

Node* replace(int &idx, vector<int> &inorder, Node *root) {

    if(idx == inorder.size() || !root) {
        return nullptr;
    }

    root->left = replace(idx, inorder, root->left);

    root->data = inorder[idx];

    idx++;

    root->right = replace(idx, inorder, root->right);

    return root;
}

void recoverTreeBrute(Node *root) {

    vector<int> inorder = inorderTrav(root);

    sort(inorder.begin(), inorder.end());

    int idx = 0;

    root = replace(idx, inorder, root);

} // O(n + nlogn + n) time and O(2n) space

////////////////////////////////////////////////////////////////////////////////////////

void optimalHelper(Node *root, Node* &prev, Node* &first, Node* &last) {

    if(!root) {
        return;
    }

    optimalHelper(root->left, prev, first, last);

    if(prev && root->data <= prev->data) {

        // capture the first element of first violation always (dont update if not first)

        if(first == nullptr) {
            first = prev; 
        }

        // always update the last element (be it single or 2nd violation)

        last = root;
    }

    prev = root;

    optimalHelper(root->right, prev, first, last);
}

void recoverTreeOptimal(Node *root) {

    Node *first = nullptr;
    Node *last = nullptr;
    Node *prev = nullptr;

    optimalHelper(root, prev, first, last);

    swap(first->data, last->data);

} // O(N) time and O(N) recursion stack space

///////////////////////////////////////////////////////////////////////////////////////

// use morris inorder for O(1) space traversal

int main() {
    
    return 0;
}