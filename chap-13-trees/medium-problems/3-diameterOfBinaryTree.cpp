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

// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
// The length of a path between two nodes is represented by the number of edges between them

// the most naive solution for finding the diameter would be standing at a node and then calculating its distance from all other nodes and store the maxDistance and then repeat this process for all other nodes but this is extremely time consuming and difficult to implement as we can traverse up the tree

////////////////////////////////////////////////////////////////////////////

// the naive way to find the diameter would be standing at the node, and find the height of the left subtree and right subtree and adding those together, that represents the length of logest path throught it

int height(Node *root) {
    if(root == nullptr) return 0;
    return 1 + max(height(root->left), height(root->right));
}

int diameterHelperBrute(Node *root, int maxDiameter) {
     
    if(root == nullptr) return 0; // no path if no tree exists

    int heightLeft = height(root->left);
    int heightRight = height(root->right);

    maxDiameter = max(maxDiameter, heightLeft + heightRight); 
    // how to find max lenth path through a particular node

    diameterOfTreeBrute(root->left); // check for more better answer on left subtree
    diameterOfTreeBrute(root->right); // similarly for right

    return maxDiameter;

} // O(N^2) again since for traversing we require O(N) time and for each we are checking height so O(N) time there

int diameterOfTreeBrute(Node *root) {
    return diameterHelperBrute(root, INT_MIN);
}

////////////////////////////////////////////////////////////////////////

// now instead of separately calculating the height and then calculating maxDiamter for left and right subtree we can instead calculate maxDiamter while calculating height on the fly so we dont have to recursively check for left and right subtree to find maxDiameter

int diameterHelperOptimal(Node *root, int &maxDiamter) {
    if(!root) return 0; // height == 0 if no tree exists

    int leftHeight = diameterHelperOptimal(root->left, maxDiamter); // calcuate leftHeight
    int rightHeight = diameterHelperOptimal(root->right, maxDiamter); // calculate rightHeight

    maxDiamter = max(maxDiamter, leftHeight + rightHeight); // find maxDiameter 

    return 1 + max(leftHeight, rightHeight); 
    // return the height so it can be used to find maxDiamter
}

int diameterOfTreeOptimal(Node *root) {
    int maxDiameter = INT_MIN;
    diameterHelperOptimal(root, maxDiameter);
    return maxDiameter;
} // O(N) time, O(N) space

int main() {
    
    return 0;
}