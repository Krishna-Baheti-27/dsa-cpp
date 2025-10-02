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

int countNodes = 0; // no need to use a globar variable we can use a helper function 
int countNodesBrute(Node* root) {
    if(!root) return countNodes;
    countNodes++;
    countNodesBrute(root->left);
    countNodesBrute(root->right);
    return countNodes;
} // O(N) time and O(logn) space (since its complete tree, the space is guranteed to be logn,not n)

int findLeftHeight(Node *node) {
    int height = 0;
    while(node) {
        node = node->left;
        height++;
    }
    return height;
}

int findRightHeight(Node *node) {
    int height = 0;
    while(node) {
        node = node->right;
        height++;
    }
    return height;
}

// for a full binary tree, the number of nodes is 2^h - 1, so if left height of the tree == right height of the tree then it is a full binary tree with everything filled
// so if we get such a subtree we calculate the number of nodes in it directly
int countNodesOptimal(Node *root) {
    if(!root) return 0;
    int leftHeight = findLeftHeight(root->left);
    int rightHeight = findRightHeight(root->right);
    if(leftHeight == rightHeight) return (1 << leftHeight) - 1;
    // if we dont have complete BT then try to countNodes recursively 
    return 1 + countNodesOptimal(root->left) + countNodesOptimal(root->right);
} // O((logn) ^ 2) time as the max height of the tree is logn and in the worst case we will travel logn when we wont encounter any full binary tree and in each traversal you are finding height which again takes logn time since its a complete BT
// O(logn) space used in recursion

int main() {
    
    return 0;
}