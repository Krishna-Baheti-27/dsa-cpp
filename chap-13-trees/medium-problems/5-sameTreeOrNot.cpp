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

// literally do any traversal of your choice and if both are exactly identical then the trees are same else not, here we are doing preorder traversal, that is root, left, right

bool areSameTrees(Node *root1, Node *root2) {
    
    if(root1 == nullptr && root2 == nullptr) return true; // both are same as they are null

    if(root1 && root2) {
        if(root1->data != root2->data) return false; // check root

        bool left = areSameTrees(root1->left, root2->left); // check for left subtree
        if(!left) return false;

        bool right = areSameTrees(root1->right, root2->right); // checl for right subtree
        if(!right) return false;

        return true; // if everything satisfies then they are same or identical
    } 

    return false; // this hits means either root1 == null and root2 != null and vice-versa which means they are not same
} // O(N) time and O(N) same

////////////////////////////////////////////////////////////////////////

// a more elegant way to write the same above conditions

bool areSameTreesReadable(Node *root1, Node *root2) {
    if(!root1 || !root2) return (root1 == root2);
    return root1->data == root2->data && areSameTreesReadable(root1->left, root2->left) && areSameTreesReadable(root1->right, root2->right);
}

int main() {
    
    return 0;
}