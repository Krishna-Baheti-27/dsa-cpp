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

/////////////////////////////////////////////////////////////////////////////////////

// the most naive solution for finding the diameter would be standing at a node and then calculating its distance from all other nodes and store the maxDistance and then repeat this process for all other nodes but this is extremely time consuming and difficult to implement as we can not traverse up the tree

////////////////////////////////////////////////////////////////////////////////////

// the naive way to find the diameter would be standing at the node, and find the height of the left subtree and right subtree and adding those together, that represents the length of longest path through it

int height(Node *root) {
    if(root == nullptr) return 0;
    return 1 + max(height(root->left), height(root->right));
}

int diameterBrute(Node *root) {
     
    if(root == nullptr) return 0; // no path if no tree exists

    // these are the heights of left and right subtrees which are individual trees and dont include the root node, if you consider it with root then the formula is wrong

    int heightLeft = height(root->left);
    int heightRight = height(root->right);

    // how to find max lenth path through a particular node, that is sum of leftHeight + rightHeight

    int diameterAtRoot = heightLeft + heightRight;

    // check for more better answer on left subtree

    int diameterFromLeft = diameterBrute(root->left); 

    // check for more better answer on right subtree

    int diameterFromRight = diameterBrute(root->right); 

    return max(diameterAtRoot, max(diameterFromLeft, diameterFromRight));

} // O(N^2) time and O(N) recursion stack space
// again since for traversing we require O(N) time and for each we are checking height so O(N) time there

// this is a purely recursive implementation but you can also pass maxDiameter variable using reference if you dont want to do if functionally although this is more elegant 

//////////////////////////////////////////////////////////////////////////////////

// now instead of separately calculating the height and then calculating maxDiamter for left and right subtree we can instead calculate maxDiamter while calculating height on the fly so we dont have to recursively check for left and right subtree to find maxDiameter

int diameterHelperOptimal(Node *root, int &maxDiamter) {

    if(!root) return 0; // height == 0 if no tree exists

    int leftHeight = diameterHelperOptimal(root->left, maxDiamter); // calcuate leftHeight
    int rightHeight = diameterHelperOptimal(root->right, maxDiamter); // calculate rightHeight

    // find maxDiameter using our logic while calculating the height of tree from each node using the logic of max value of leftHeight + rightHeight

    maxDiamter = max(maxDiamter, leftHeight + rightHeight); 

    // very important that it has to return the height so it can be used to find maxDiamter and the code will be functional else it would fail

    return 1 + max(leftHeight, rightHeight); 
}

int diameterOfTreeOptimal(Node *root) {

    int maxDiameter = INT_MIN;

    diameterHelperOptimal(root, maxDiameter);

    return maxDiameter;

} // O(N) time, O(N) space

// the purely recursive way to do this would be to let the function return both the values of height and maxDiameter using a pair but that kind of seems like cheating so this approach of passing by reference is much better

int main() {
    
    return 0;
}