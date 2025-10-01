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

bool areSameTrees(Node *root1, Node *root2) {
    // literally do any traversal of your choice and if both are exactly identical then the trees are same else not, here we are doing preorder traversal
    if(root1 == nullptr && root2 == nullptr) return true; // both are same as they are null
    if(root1 && root2) {
        if(root1->data != root2->data) return false; // root
        bool left = areSameTrees(root1->left, root2->left); // left
        if(!left) return false;
        bool right = areSameTrees(root1->right, root2->right); // right
        if(!right) return false;
        return true; // if everything satisfies then they are same or identical
    } 
    return false; // if this hits means then either root1 == nullptr and root2 != nullptr or root2 == nulltpr and root1 != nullptr but other is not so we dont have same trees, the case where both are nullptr is already handled at top
}

// if any one of them is nullptr then they are same only if both of them are nullptr else false
bool areSameTreesBetter(Node *root1, Node *root2) {
    if(!root1 || !root2) return (root1 == root2);
    return root1->data == root2->data && areSameTreesBetter(root1->left, root2->left) && areSameTrees(root1->right, root2->right);
}

int main() {
    
    return 0;
}