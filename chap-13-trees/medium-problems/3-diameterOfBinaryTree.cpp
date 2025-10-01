#include<bits/stdc++.h>
using namespace std;

// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
// The length of a path between two nodes is represented by the number of edges between them

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

int height(Node *root) {
    if(root == nullptr) return 0;
    return 1 + max(height(root->left), height(root->right));
}

int maxDiameter = INT_MIN;
int diameterOfTreeBrute(Node *root) {
    // the naive way to find the diameter would be standing at the node, and find the height of the left subtree and right subtree and adding those together 
    if(root == nullptr) return 0; 
    int heightLeft = height(root->left);
    int heightRight = height(root->right); 
    maxDiameter = max(maxDiameter, heightLeft + heightRight);
    diameterOfTreeBrute(root->left);
    diameterOfTreeBrute(root->right); 
    return maxDiameter;
} // O(N^2) again since for traversing we require O(N) time and for each we are checking height so O(N) time there

// now to do this in optimal O(N) time, we tweak the function using which we find height of tree
// basically we can maintain a maxD variable w=in that function which when calculating the height will also set new value of max if its greater than leftHeight + rightHeight and then we simply return this maxD

int heightTweaked(Node *root, int &maxDiameter) { // take by reference
    if(root == nullptr) return 0; 
    int heightLeft = heightTweaked(root->left, maxDiameter);
    int heightRight = heightTweaked(root->right, maxDiameter);
    maxDiameter = max(maxDiameter, heightLeft + heightRight);
    return 1 + max(heightLeft, heightRight);
    // maintaing maxDiameter accross function calls so we can traverse the tree and calculate the height while traversing hence saving crucial time
}

int diameterOfTreeOptimal(Node *root) {
    int maxDiameter = INT_MIN;
    heightTweaked(root, maxDiameter);
    return maxDiameter;
}

int main() {
    
    return 0;
}