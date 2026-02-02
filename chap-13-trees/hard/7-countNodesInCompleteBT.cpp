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

// Given the root of a complete binary tree, return the number of the nodes in the tree
// a complete binary tree has all levels filled except possibly the last level and all the nodes in last level are as left as possible

/////////////////////////////////////////////////////////////////////

// purely recursive solution to count all the nodes (standard recursion pattern)
// using preorder traversal

int countNodesBrute(Node *root) {

    if(!root) return 0;

    int leftNodes = countNodesBrute(root->left);
    int rightNodes = countNodesBrute(root->right);

    return 1 + leftNodes + rightNodes;

} // O(N) time and O(logN) space since complete tree is always balanced

/////////////////////////////////////////////////////////////////////

// if it is a prefect tree and then we know the number of nodes = 2^h - 1, so we can return right away but if the tree is not perfect then we would have to 1 + leftNodes + rightNodes and we try to find left and right nodes recursively using the prefect tree formula

// to determine if its prefect tree or not we only have to check if leftHeight == rightHeight where leftHeight and rightHeight simply means how much can you go in depth on left subtree and rightHeight means how much can you go in depth on right subtree

// now why does it work is extremely logical, it only works for complete tree
// for complete tree we know that leftHeight == actual height of tree since nodes are filled as left as possible
// when we have leftHeight == rightHeight we are essentially having height == rightHeight, so we it means we can actually go in right side by height depth which is the max we can go which means there is node at the rightmost edge of tree on last level and since tree is complete we can have all nodesas left as possible it means all the in between nodes are guaranteed to be filled making it a prefect binary tree for which we can return early 

// so keep in mind that this findLeftHeight and findRightHeight are not actual height functions but they simply calculate max possible depth you can go only on left or right but for complete tree leftHeight == actual height of tree by definition of complete tree

int findLeftHeight(Node *node) {

    int height = 0;

    while(node) {
        node = node->left;
        height++;
    }

    return height;

} // O(logn) time in worst case since the height for complete tree cannot exceed that

int findRightHeight(Node *node) {

    int height = 0;

    while(node) {
        node = node->right;
        height++;
    }

    return height;

} // O(logn) time in worst case since the height for complete tree cannot exceed that

int countNodesOptimal(Node *root) {

    if(!root) return 0;

    // calculate height from current root not children

    int leftHeight = findLeftHeight(root);
    int rightHeight = findRightHeight(root);

    // return early by returning 2^h - 1 nodes for a perfect tree of height h

    if(leftHeight == rightHeight) {
        return (1 << leftHeight) - 1; 
    }

    // apply this normal formula for trees which are not perfect

    return 1 + countNodesOptimal(root->left) + countNodesOptimal(root->right); 
} 

// for this tree we have total logN levels and on each level we are findining leftHeight and rightHeight which take at max logN time and since its complete binary tree on of the left or right is guranteed to be perfect so we are effectively skipping computation for one of substrees and taking logN for other

// so time complexity = logN levels * (logN + logN + logN + logN) so nearly O((logn) ^ 2) time and O(logn) space

int main() {
    
    return 0;
}