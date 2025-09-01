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

// the brute force would involve traversing across the tree and then inserting all the nodes in the container and then sorting that vector and returning the Kth element from first
// O(N) + O(NlogN) time and O(N) space for container

// the better approach would be to store the entire inorder traversal of the bst in a container and then return the Kth element from that container since the inorder traversal of a binary tree is always sorted
// O(N) time and O(N) space for container

// here is the optimal approach
// we use a counter and we increment it each time we visit a node when count == k we have our answer

int inorderHelper(Node *root, int k, int &count) {
    if(!root) return -1;
    if(count == k) return root->data;
    inorderHelper(root->left, k, count); // left
    count++; // root
    inorderHelper(root->right, k, count); // right
}

int kthSmallest(Node *root, int k) {
    int count = 0;
    return inorderHelper(root, k, count);
} // O(N) time and O(N) recursion stack space

// Even more optimised is 

int main() {
    
    return 0;
}