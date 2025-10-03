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

Node *insertInBST(Node *root, int val) {
    if(!root) {
        root = new Node(val);
        return root; // handling the edge case of inserting the root itself
    }
    Node *trueRoot = root; // preserve the root since it will be lost in traversal
    while(true) {
        if(val > root->data) {
            // so insert in the right
            if(root->right) root = root->right; // traverse further only if right exists
            else {
                // if root->right is null, then insert the node to root->right and break
                root->right = new Node(val);
                break;
            }
        } else { // (we wont have any case of root->data == val)
            if(root->left) root = root->left; // traverse further only if left exists
            else { 
                root->left = new Node(val);
                break;
            } 
        }
    }
    return trueRoot;
} // O(logN) time and O(1) space

Node* insertInBSTRecursive(Node *root, int val) {
    if(!root) return new Node(val); // handling insertion of root
    if(root->data > val) {
        root->left = insertInBSTRecursive(root->left, val);
    } else {
        root->right = insertInBSTRecursive(root->right, val);
    }  
    return root;
} // O(logn) time and O(h) space

int main() {
    
    return 0;
}