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

// Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

/////////////////////////////////////////////////////////////////////////////////////

// we simply take the inorder traversal of the tree and that will be sorted so we keep two pointers one at start and other at end and solve it like a classic two sum question

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

bool findTargetBrute(Node *root, int k) {

    vector<int> inorder = inorderTrav(root);

    int l = 0, r = inorder.size() - 1;

    while(l < r) {

        int sum = inorder[l] + inorder[r];

        if(sum == k) {
            return true;
        } else if(sum > k) {
            r--;
        } else {
            l++;
        }
    }

    return false;

} // O(N) time and space

////////////////////////////////////////////////////////////////////////////////////

// the optimal approach is to similar to how we implement next in bst iterator we also implement the before which will be exactly opposite and will help us get elements in descending order (greatest first)

class BSTIteratorBetter {

    stack<Node*> st1;
    stack<Node*> st2;

public:

    BSTIteratorBetter(Node *root) {

        Node *temp = root;

        while(temp) {
            st1.push(temp);
            temp = temp->left;
        }

        temp = root;

        while(temp) {
            st2.push(temp);
            temp = temp->right;
        }
    }
    
    // O(N/N) time which is on avg O(1) time since total N nodes will be inserted and it will be called total of N times

    int next() {
        
        Node *topNode = st1.top();

        st1.pop();

        int val = topNode->data;

        if(topNode->right) {

            topNode = topNode->right;
            while(topNode) {
                st1.push(topNode);
                topNode = topNode->left;
            }
        } 

        return val;
    }

    int before() {

        Node *topNode = st2.top();

        st2.pop();

        int val = topNode->data;

        if(topNode->left) {

            topNode = topNode->left;

            while(topNode) {
                st2.push(topNode);
                topNode = topNode->right;
            }
        }

        return val;
    }
    
    bool hasNext() {
        return !st1.empty();
    }
};

bool findTargetBetter(Node *root, int k) {

    BSTIteratorBetter b(root);

    int l = b.next(), r = b.before();

    while(l < r) {

        int sum = l + r;

        if(sum == k) {
            return true;
        } else if(sum > k) {
            r = b.before();
        } else {
            l = b.next();
        }
    }

    return false;

} // O(2h) space and O(N) time

// instead of using the two stack we should create two iterators one for the next and other for the before using flags to separate the iterator logic for the next and before

///////////////////////////////////////////////////////////////////////////////////////

// if you use the complement strategy of standing at each node and looking for k - root->data the complexity explodes to O(N * H)

int main() {
    
    return 0;
}