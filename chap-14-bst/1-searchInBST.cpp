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

///////////////////////////////////////////////////////////////////////////////////////

// every node should be greater than all the nodes in it left subtree and should be smaller than all the node in its right subtree 

// there is no concept of equal in the bst but we can define it ourself like less than or equal to on the left and on right strict inequality and vice versa

// one more way to integrate duplicates is by storing the freq along with the data and left and right pointers

// in the worst case the height of bst can be N (skewed tree) but it is generally kept as logN so we can perform efficient searching on it

// now how do we use the property of bst to search effectively ??

Node* searchInBSTRecursive(Node *root, int target) {

    // node doesnt exist

    if(!root) {
        return nullptr;
    }

    // found the node

    if(root->data == target) {
        return root;
    } else if(root->data > target) {
        return searchInBSTRecursive(root->left, target);
    } else {
        return searchInBSTRecursive(root->right, target);
    }

} // O(logN) time and space

// you are not traversing the entire tree but in zig zag fashion sometimes on left or right so essentially only traversing height of the tree and hence time will be O(H) or O(logN) in avg case and O(logN) space also in avg case but in worst case O(N) time and space

///////////////////////////////////////////////////////////////////////////////////////

// we can simulate the above process iteratively just as easily

Node* searchInBSTIterative(Node *root, int target) {

    while(root != nullptr && root->data != target) {
        root = root->data > target ? root->left : root->right;
    }

    // return either nullptr or the required node

    return root; 
    
} // O(logN) time and O(1) space

int main() {
     
    return 0;
}