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

// You're given a binary tree. Your task is to find the size of the largest subtree within this binary tree that also satisfies the properties of a Binary Search Tree (BST). The size of a subtree is defined as the number of nodes it contains.

// Note: A subtree of the binary tree is considered a BST if for every node in that subtree, the left child is less than the node, and the right child is greater than the node, without any duplicate values in the subtree.

/////////////////////////////////////////////////////////////////////////////////////////

// the brute force approach is to check for each node considering as a new tree that whether it forms a valid bst or not

int isBSTBetterHelper(Node *root, int minel, int maxel) {

    if(!root) {
        return 0;
    }

    if(root->data >= maxel || root->data <= minel) {
        return -1;
    }

    int leftNodes = isBSTBetterHelper(root->left, minel, root->data);

    if(leftNodes == -1) {
        return -1;
    }

    int rightNodes = isBSTBetterHelper(root->right, root->data, maxel);

    if(rightNodes == -1) {
        return -1;
    }

    return  1 + leftNodes + rightNodes;

} // O(N) time and space

int isBSTBetter(Node *root) {
    return isBSTBetterHelper(root, INT_MIN, INT_MAX);
}

int largestBSTBruteHelper(Node *root) {

    if(!root) {
        return 0;
    }

    int currSize = isBSTBetter(root);

    int leftMax = largestBSTBruteHelper(root->left);
    int rightMax = largestBSTBruteHelper(root->right);

    return max({currSize, leftMax, rightMax});
}

int largestBSTBrute(Node *root) {

    return largestBSTBruteHelper(root);

} // O(N^2) time and O(N) recursion stack space

////////////////////////////////////////////////////////////////////////////////////////


int main() {
    
    return 0;
}