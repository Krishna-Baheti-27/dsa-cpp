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

// given a bst we have to insert the node having a certain value in it

/////////////////////////////////////////////////////////////////////////////////////

// there are multiple possible places to insert but we will follow a general pattern to insert a new node as a leaf node and if the root has greater value than key then go to left else right and stop right before root becomes null so that you can insert

// and we are given that given val doesnt exist in the bst and hence this works and if even if have duplicates the else part which is val <= root->data automatically handles this and inserts the duplicate as the leaf

// and we will always be inserting in the leaf position according to this logic

Node *insertInBSTIterative(Node *root, int val) {

    if(!root) {
        root = new Node(val);
        return root; // handling the edge case of inserting the root itself
    }

    Node *trueRoot = root; // preserve the root since it will be lost in traversal

    while(true) {

        // so insert in the right

        if(val > root->data) {

            if(root->right) {

                // traverse further only if right exists
                root = root->right;

            } else {
                
                // if root->right is null, then insert the node to root->right and break
                root->right = new Node(val);
                break;
            }

        } else {  // (we wont have any case of root->data == val)

            if(root->left) {

                // traverse further only if left exists
                root = root->left; 

            } else { 

                root->left = new Node(val);
                break;
            } 
        }
    }

    return trueRoot;

} // O(logN) time and O(1) space

/////////////////////////////////////////////////////////////////////////////////////////

Node* insertInBSTRecursive(Node *root, int val) {

    if(!root) {
        return new Node(val); // handling insertion of root
    }

    if(root->data > val) {
        root->left = insertInBSTRecursive(root->left, val);
    } else {
        root->right = insertInBSTRecursive(root->right, val);
    } 

    return root;

} // O(logn) time and space

int main() {
    
    return 0;
}